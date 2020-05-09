#include "Map.h"
#include "../ResourceManager.h"

Map::Map()
{
	// Load Map
	if (LoadMap("../Resources/set.png", sf::Vector2u(16, 16), level, 20, 12))
		return;
}

Map::~Map()
{
}

bool Map::LoadMap(
	const std::string& tileset, 
	sf::Vector2u tileSize, 
	const int* tiles,
	unsigned int width, 
	unsigned int height)
{
	// Load tileset
	m_tileset = g_Res->getTextureByName("map");
		
	// Vertex Array
	vertices.setPrimitiveType(sf::Quads);
	vertices.resize(width * height * 4);

	for (unsigned int i = 0; i < width; ++i)
	{
		for (unsigned int j = 0; j < height; ++j)
		{
			int tileNumber = tiles[i + j * width];
			int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
			int tv = tileNumber / (m_tileset.getSize().y / tileSize.y);

			sf::Vertex* quad = &vertices[(i+j * width) * 4];

			// Scaling
			sf::Vector2u scaleSize = sf::Vector2u(tileSize.x * 4, tileSize.y * 4);

			// define its 4 corners
			quad[0].position = sf::Vector2f(i * scaleSize.x, j * scaleSize.y);
			quad[1].position = sf::Vector2f((i + 1) * scaleSize.x, j * scaleSize.y);
			quad[2].position = sf::Vector2f((i + 1) * scaleSize.x, (j + 1) * scaleSize.y);
			quad[3].position = sf::Vector2f(i * scaleSize.x, (j + 1) * scaleSize.y);

			// define its 4 texture coordinates
			quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
			quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
			quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
			quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);

			if (tileNumber == 29)
			{
				playerspawn = sf::Vector2f(i * scaleSize.x + (scaleSize.x / 2), j * scaleSize.y + (scaleSize.y / 2));
			}
			if (tileNumber == 24)
			{
				enemyspawn = sf::Vector2f(i * scaleSize.x + (scaleSize.x / 2), j * scaleSize.y + (scaleSize.y / 2));
			}
		}
	}

	return true;
}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// apply the transform
	states.transform *= getTransform();

	// apply the tileset texture
	states.texture = &m_tileset;

	// draw the vertex array
	target.draw(vertices, states);
}
