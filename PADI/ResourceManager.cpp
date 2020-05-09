#include "ResourceManager.h"

ResourceManager* g_Res;

ResourceManager::ResourceManager()
{
	font = new sf::Font();
	if (!font->loadFromFile("..\\Resources\\astron_boy.ttf"))
		std::cout << "Failed to load font" << std::endl;

	LoadTextures();
}

void ResourceManager::SaveSettings()
{
	std::ofstream settingsfile;
	settingsfile.open("settings.cfg");

	// Loop through all settings 
	// to write into file
	for (auto it = def_settings.rbegin(); it != def_settings.rend(); it++)
	{
		std::string line = it->first + ":" + std::to_string(it->second) + "\n";
		settingsfile << line;
	}

	settingsfile.close();
}

void ResourceManager::LoadSettings()
{

}

void ResourceManager::LoadTextures()
{
	if (!textures["background"].loadFromFile("..\\Resources\\background.png"))
		std::cout << "Failed to load background texture" << std::endl;

	if (!textures["projectile"].loadFromFile("..\\Resources\\projectile.png"))
		std::cout << "Failed to load projectiles texture" << std::endl;

	if (!textures["map"].loadFromFile("..\\Resources\\set.png"))
		std::cout << "Failed to load map texture" << std::endl;

	//if (!textures["trollface"].loadFromFile("..\\Resources\\trollface.png"));
}

sf::Texture ResourceManager::getTextureByName(std::string name)
{
	return textures[name];
}
