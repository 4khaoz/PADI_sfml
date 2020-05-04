#include "Game.h"
#include "ResourceManager.h"

int main()
{
	g_Input = new InputManager();
	g_Res = new ResourceManager();

	Game game;
	game.run();

	delete g_Input;
	delete g_Res;

	return 0;
}