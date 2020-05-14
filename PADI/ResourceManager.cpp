#include "ResourceManager.h"

ResourceManager* g_Res;

ResourceManager::ResourceManager()
	: bgmVolume(30), sfxVolume(100)
{
	font = new sf::Font();
	if (!font->loadFromFile("..\\Resources\\astron_boy.ttf"))
		std::cout << "Failed to load font" << std::endl;

	LoadTextures();
	LoadSounds();
}

ResourceManager::~ResourceManager()
{
	for (auto it : soundbuffers)
		delete it.second;

	for (auto it : textures)
		delete it.second;

	soundbuffers.clear();
	textures.clear();
	sounds.clear();
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
	LoadTexture("background", "..\\Resources\\background.png");
	LoadTexture("projectile", "..\\Resources\\projectile.png");
	LoadTexture("kappa", "..\\Resources\\kappa.png");
	LoadTexture("map", "..\\Resources\\set.png");
	LoadTexture("troll", "..\\Resources\\troll.png");
	LoadTexture("jojo", "..\\Resources\\jojo.png");
}

void ResourceManager::LoadSounds()
{
	LoadSound("bgm", "..\\Resources\\bgm.wav");
	LoadSound("clap", "..\\Resources\\clap.wav");
	LoadSound("defeat", "..\\Resources\\wry.wav");
	LoadSound("victory", "..\\Resources\\coffin.wav");
	LoadSound("ahh", "..\\Resources\\ahh.wav");
}

sf::Texture* ResourceManager::getTextureByName(std::string name)
{
	return textures[name];
}

void ResourceManager::playSoundByName(std::string name, int volume, bool loop)
{
	sounds[name].setVolume(volume);
	sounds[name].setLoop(loop);
	sounds[name].play();
}

void ResourceManager::stopSoundByName(std::string name)
{
	sounds[name].stop();
}

void ResourceManager::stopAllSounds()
{
	for (auto& it : sounds)
		it.second.stop();
}

void ResourceManager::LoadTexture(std::string key, std::string filepath)
{
	textures[key] = new sf::Texture();
	if (!textures[key]->loadFromFile(filepath))
		std::cout << "Failed to load " << filepath << std::endl;
}

void ResourceManager::LoadSound(std::string key, std::string filepath)
{
	soundbuffers[key] = new sf::SoundBuffer();
	if (!soundbuffers[key]->loadFromFile(filepath))
		std::cout << "Failed to load " << filepath << std::endl;
	sounds[key] = sf::Sound(*soundbuffers[key]);
}
