#pragma once
#include "../global.h"
#include "Player.h"
#include "Enemy.h"
#include "Projectile.h"

const int level[] =
{
	28, 28, 28, 19, 28, 28, 28, 28, 19, 28, 28, 28, 28, 19, 28, 28, 28, 28, 19, 28,
	28, 28, 28, 26, 28, 28, 28, 28, 26, 28, 28, 28, 28, 26, 28, 28, 28, 28, 26, 28,
	28, 28, 28, 26, 28, 28, 28, 28, 26, 28, 28, 28, 28, 26, 28, 28, 28, 28, 26, 28,
	28, 28, 28, 26, 28, 28, 28, 28, 26, 28, 28, 28, 28, 26, 28, 28, 28, 28, 26, 28,
	28, 28, 28, 26, 28, 28, 28, 28, 26, 28, 28, 28, 28, 26, 28, 28, 28, 28, 26, 28,
	28, 28, 28, 26, 28, 28, 28, 28, 26, 28, 28, 28, 28, 26, 28, 28, 28, 28, 26, 28,
	28, 28, 28, 26, 28, 28, 28, 28, 26, 28, 28, 28, 28, 26, 28, 28, 28, 28, 26, 28,
	28, 28, 28, 26, 28, 28, 28, 28, 26, 28, 28, 28, 28, 26, 28, 28, 28, 28, 26, 28,
	28, 28, 28, 26, 28, 28, 28, 28, 26, 28, 28, 28, 28, 26, 28, 28, 28, 28, 26, 28,
	28, 29, 28, 33, 28, 28, 28, 28, 33, 28, 28, 28, 28, 33, 28, 28, 28, 28, 33, 28,
	02, 03, 03, 02, 03, 02, 02, 03, 03, 02, 03, 02, 02, 03, 03, 02, 03, 02, 02, 03,
	00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00,
};

class Map : public sf::Drawable, public sf::Transformable
{
public:
	Map();
	~Map();

	sf::Vector2f getPlayerspawn() { return playerspawn; }
	sf::Vector2f getEnemyspawn() { return enemyspawn; }

private:
	//Player* player;
	//Enemy* enemy;
	//std::vector<Projectile*> projectiles;
	sf::Vector2f playerspawn;
	sf::Vector2f enemyspawn;
	
	bool LoadMap(
		const std::string& tileset, 
		sf::Vector2u tileSize,
		const int* tiles,
		unsigned int mapwidth, 
		unsigned int mapheight
	);

	sf::VertexArray vertices;
	sf::Texture m_tileset;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};