#include "GameInstance.h"
#include "StateManager.h"

GameInstance::GameInstance(StateManager& sm, sf::RenderWindow* window)
	: Menu(sm, window)
{
	map.setPosition(0, 0);

	view.setCenter(WIN_WIDTH / 2, WIN_HEIGHT / 2);
	view.setSize(sf::Vector2f(WIN_WIDTH, WIN_HEIGHT));

	window->setView(view);

	player = new Player(map.getPlayerspawn());
	enemy = new Enemy(map.getEnemyspawn());

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
}

GameInstance::~GameInstance()
{
	delete player;
	delete enemy;
	for (auto it : projectiles)
		delete it;

	delete enemy_HPBar;
}

void GameInstance::HandleEvents()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		sm.PopMenu();

	player->HandleEvents();
	enemy->HandleEvents();
	if (player->isCharacterAttacking())
		this->projectiles.push_back(new Projectile(player->getPosition(), sf::Vector2f(1, 0), 400.f, dynamic_cast<Actor&>(*player)));

	if (enemy->isCharacterAttacking())
		this->projectiles.push_back(new Projectile(enemy->getPosition(), sf::Vector2f(-1, 0), 250.f, dynamic_cast<Actor&>(*enemy)));
}

void GameInstance::Update(const float& dt)
{
	player->Update(dt);
	enemy->Update(dt);
	for (auto it : projectiles)
	{
		it->Update(dt);

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

	enemy_HPBar->Update(enemy->GetHealth());
	player_HPBar->Update(player->GetHealth());
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

	// Draw User Interface
	enemy_HPBar->Draw(*window);
	player_HPBar->Draw(*window);
}
