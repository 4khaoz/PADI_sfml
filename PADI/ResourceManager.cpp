#include "ResourceManager.h"

ResourceManager* g_Res;

ResourceManager::ResourceManager()
{
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
	if (textures["projectile"].loadFromFile("..\\Resources\\projectile.png"))
		return;
}

sf::Texture ResourceManager::getTextureByName(std::string name)
{
	return textures[name];
}
