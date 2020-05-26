#pragma once
#include "global.h"
#include <fstream>

class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();

	void SaveSettings();
	void LoadSettings();

	void LoadTextures();
	void LoadSounds();

	sf::Texture* getTextureByName(std::string name);

	void playSoundByName(std::string name, int volume, bool loop);
	void stopSoundByName(std::string name);
	void stopAllSounds();

	sf::Font* getFont() { return font; }

	/*
	i = Volume Level
	0 -> Low
	1 -> Medium
	2 -> High
	*/
	void setBGMVolume(int i);
	void setSFXVolume(int i);

	int getBGMVolume() { return bgmVolume; }
	int getSFXVolume() { return sfxVolume; }

private:
	sf::Font* font;

	int sndIndex;
	int bgmVolume;
	int sfxVolume;

	const std::string str_settings = "settings.cfg";
	const std::string str_savegame = "save.cfg";

	std::map<std::string, int> user_settings;

	std::map<std::string, sf::Texture*> textures;
	std::map<std::string, sf::SoundBuffer*> soundbuffers;
	std::map<std::string, sf::Sound> sounds;

	void LoadTexture(std::string key, std::string filepath);
	void LoadSound(std::string key, std::string filepath);
};

const std::map<std::string, int> def_settings
{
	{"width", 1280},
	{"height", 720},
	{"fpscap", 60}
};