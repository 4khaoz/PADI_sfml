#include "GameInstance.h"
#include "StateManager.h"

GameInstance::GameInstance(StateManager& sm, sf::RenderWindow* window, int difficulty)
	: Menu(sm, window)
{
	map.setPosition(0, 0);

	view.setCenter(WIN_WIDTH / 2, WIN_HEIGHT / 2);
	view.setSize(sf::Vector2f(WIN_WIDTH, WIN_HEIGHT));

	window->setView(view);

	player = new Player(map.getPlayerspawn());

	difficulty = iClamp(difficulty, 0, 2);
	enemy = new Enemy(map.getEnemyspawn(), difficulty);

	gs = GameState::PLAYING;
	bPlaying = true;

	initUI();

	g_Res->playSoundByName("bgm", g_Res->getBGMVolume(), true);
}

GameInstance::~GameInstance()
{
	delete player;
	delete enemy;
	for (auto it : projectiles)
		delete it;

	delete enemy_HPBar;
	delete player_HPBar;
	delete endButton;
}

void GameInstance::HandleEvents()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || (endButton->isPressed() && getKeyTime()))
	{
		g_Res->stopAllSounds();
		sm.PopMenu();
	}

	player->HandleEvents();
	enemy->HandleEvents();
	if (player->isCharacterAttacking())
		this->projectiles.push_back(new Projectile(player->getPosition(), sf::Vector2f(1, 0), 400.f, dynamic_cast<Actor&>(*player)));

	if (enemy->isCharacterAttacking())
		this->projectiles.push_back(new Projectile(enemy->getPosition(), sf::Vector2f(-1, 0), 325.f, dynamic_cast<Actor&>(*enemy)));

}

void GameInstance::Update(const float& dt)
{
	updateKeyTime(dt);
	if (bPlaying)
	{
		player->Update(dt);
		enemy->Update(dt);

		enemy_HPBar->Update(enemy->GetHealth());
		player_HPBar->Update(player->GetHealth());

		CheckGameState();
	}
	else
	{
		projectiles.clear();
		updateMousePosition();
		endButton->Update(mousePosView);
	}
}

void GameInstance::FixedUpdate(const float& dt)
{
	if (bPlaying)
	{
		player->FixedUpdate(dt);
		enemy->FixedUpdate(dt);
	
		UpdateProjectiles(dt);
	}
}

void GameInstance::Draw()
{
	// Draw Background
	window->draw(map);

	// Draw Actors
	player->Draw(*window);
	enemy->Draw(*window);
	for (auto it : projectiles)
	{
		it->Draw(*window);
	}

	if (!bPlaying)
		endButton->Draw(*window);

	// Draw User Interface
	enemy_HPBar->Draw(*window);
	player_HPBar->Draw(*window);
}

void GameInstance::initUI()
{
	enemy_HPBar = new ProgressBar(
		sf::Vector2f(800, 670),
		sf::Vector2f(400, 30),
		sf::Color::Red,
		enemy->GetHealthMax(),
		false
	);

	player_HPBar = new ProgressBar(
		sf::Vector2f(80, 670),
		sf::Vector2f(400, 30),
		sf::Color::Green,
		player->GetHealthMax(),
		false
	);

	endButton = new Button(
		sf::Vector2f((WIN_WIDTH / 2) - 200, (WIN_HEIGHT / 2) - 50),
		sf::Vector2f(400, 100),
		"", 60,
		sf::Color(70, 70, 70, 200),
		sf::Color(150, 150, 150, 255),
		sf::Color(20, 20, 20, 200)
	);
}

void GameInstance::UpdateProjectiles(const float& dt)
{
	for (auto it : projectiles)
	{
		it->FixedUpdate(dt);

		// Check for enemy hit
		if (it->checkCollision(dynamic_cast<Actor&>(*enemy)))
		{
			enemy->TakeDamage();
			projectiles.erase(std::remove(projectiles.begin(), projectiles.end(), it), projectiles.end());
		}

		// Check for player hit
		if (it->checkCollision(dynamic_cast<Actor&>(*player)))
		{
			player->TakeDamage();
			projectiles.erase(std::remove(projectiles.begin(), projectiles.end(), it), projectiles.end());
		}

		// Remove Projectile if out of bounds
		if (it->getPosition().x > WIN_WIDTH || it->getPosition().x < 0)
		{
			projectiles.erase(std::remove(projectiles.begin(), projectiles.end(), it), projectiles.end());
		}
	}
}

void GameInstance::CheckGameState()
{
	if (!enemy->isAlive() || !player->isAlive())
	{
		bPlaying = false;
		g_Res->stopSoundByName("bgm");
		if (!enemy->isAlive())
		{
			gs = GameState::VICTORY;
			g_Res->playSoundByName("victory", g_Res->getBGMVolume(), false);
			endButton->SetText("VICTORY");
		}
		if (!player->isAlive())
		{
			gs = GameState::DEFEAT;
			g_Res->playSoundByName("defeat", g_Res->getBGMVolume(), false);
			endButton->SetText("DEFEAT");
		}
	}
}
