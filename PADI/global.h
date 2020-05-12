#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include <map>
#include <vector>
#include <iostream>
#include <stack>

const unsigned short PORT = 54000;
const std::string TITLE = "PADI Project";

#define WIN_WIDTH 1280
#define WIN_HEIGHT 720
#define WIN_FRAMECAP 60
#define DELTA_MAX 0.15f
#define KEYTIME 15.f

class InputManager;
class ResourceManager;
extern InputManager* g_Input;
extern ResourceManager* g_Res;

inline float fClamp(const float val, const float min, const float max)
{
	if (val < min) return min;
	if (val > max) return max;

	return val;
}

inline int iClamp(const int val, const int min, const int max)
{
	if (val < min) return min;
	if (val > max) return max;

	return val;
}