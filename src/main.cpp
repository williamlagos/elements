/*
 * Exemplo de uso do framework de jogo
 *
 * Cria um jogo com 3 estados: "menu", "play" e "pause"
 *
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>

#include <SDL.h>
#include "CGame.h"
#include "MenuState.h"

#undef main
#ifdef WIN32
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif

int main(int argc, char **argv)
{
    CGame game(5,30);

    game.init("Framework com estados",480,720,0,false);

    game.changeState(MenuState::instance());

	while(game.isRunning())
	{
		game.handleEvents();
		game.update();
		game.draw();
	}

	// cleanup the engine
	game.clean();

    return 0;
}