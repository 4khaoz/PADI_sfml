#pragma once
#include "global.h"
#include <fstream>

class ResourceManager
{
public:
	ResourceManager();

	void SaveSettings();
	void LoadSettings();

	void LoadTextures();

	sf::Texture getTextureByName(std::string name);

	sf::Font* getFont() { return font; }

private:
	sf::Font* font;
	const std::string str_settings = "settings.cfg";
	const std::string str_savegame = "save.cfg";

	std::map<std::string, int> user_settings;

	std::map<std::string, sf::Texture> textures;
};

const std::map<std::string, int> def_settings
{
	{"width", 1280},
	{"height", 720},
	{"fpscap", 60}
};