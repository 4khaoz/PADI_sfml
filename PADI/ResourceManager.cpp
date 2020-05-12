#include "ResourceManager.h"

ResourceManager* g_Res;

ResourceManager::ResourceManager()
{
	font = new sf::Font();
	if (!font->loadFromFile("..\\Resources\\astron_boy.ttf"))
		std::cout << "Failed to load font" << std::endl;

	LoadTextures();
	LoadSounds();
}

ResourceManager::~ResourceManager()
{
	for (auto it : sounds)
	{
		delete it.second;
	}
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
	textures["background"] = new sf::Texture();
	if (!textures["background"]->loadFromFile("..\\Resources\\background.png"))
		std::cout << "Failed to load background texture" << std::endl;

	textures["projectile"] = new sf::Texture();
	if (!textures["projectile"]->loadFromFile("..\\Resources\\projectile.png"))
		std::cout << "Failed to load projectiles texture" << std::endl;

	textures["kappa"] = new sf::Texture();
	if (!textures["kappa"]->loadFromFile("..\\Resources\\kappa.png"))
		std::cout << "Failed to load map texture" << std::endl;

	textures["map"] = new sf::Texture();
	if (!textures["map"]->loadFromFile("..\\Resources\\set.png"))
		std::cout << "Failed to load map texture" << std::endl;
}

void ResourceManager::LoadSounds()
{
	sounds["bgm"] = new sf::SoundBuffer();
	if (!sounds["bgm"]->loadFromFile("..\\Resources\\bgm.wav"))
		std::cout << "Failed to load bgm sound" << std::endl;
	
	sounds["clap"] = new sf::SoundBuffer();
	if (!sounds["clap"]->loadFromFile("..\\Resources\\clap.wav"))
		std::cout << "Failed to load clap sound" << std::endl;
	
	sounds["defeat"] = new sf::SoundBuffer();
	if (!sounds["defeat"]->loadFromFile("..\\Resources\\wry.wav"))
		std::cout << "Failed to load wry sound" << std::endl;

	sounds["victory"] = new sf::SoundBuffer();
	if (!sounds["victory"]->loadFromFile("..\\Resources\\coffin.wav"))
		std::cout << "Failed to load wry sound" << std::endl;

	sounds["ahh"] = new sf::SoundBuffer();
	if (!sounds["ahh"]->loadFromFile("..\\Resources\\ahh.wav"))
		std::cout << "" << std::endl;
}

sf::Texture* ResourceManager::getTextureByName(std::string name)
{
	return textures[name];
}

sf::SoundBuffer* ResourceManager::getSoundByName(std::string name)
{
	return sounds[name];
}
