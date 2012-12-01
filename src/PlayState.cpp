/*
 *  PlayState.cpp
 *  Normal "play" state
 *
 *  Created by Marcelo Cohen on 04/11.
 *  Copyright 2011 PUCRS. All rights reserved.
 *
 */

#include <iostream>
#include <SDL.h>
#include "Graphics.h"
#include <cmath>
#include "CGame.h"
#include "PlayState.h"

PlayState PlayState::m_PlayState;

#define SPEED 150

void PlayState::init()
{
	vertical = 1;
	count = 0;
	background = new CImage();
    background->loadImage("data/maps/black.png");
	while(count != ENEMIES_LIMIT){
		CSprite* enemy = new CSprite();
		enemy->loadSpriteSparrowXML("data/img/bug.xml");
		if(count == (ENEMIES_LIMIT-1)/2) vertical = 3;
		enemy->setPosition((count%6)*60,30*vertical);
		enemy->setAnimRate(0);
		enemy->setScale(0.5);
		enemies[count] = enemy;
		count++;
	}
    player = new CSprite();
    player->loadSpriteSparrowXML("data/img/spaceship.xml");
    player->setPosition(172,550);
    player->setAnimRate(0);
    player->setScale(0.5);
    dirx = 0; // direção do personagem: para a direita (5), esquerda (-5)
    diry = 0; // direção do personagem: para cima (5), baixo (-5)

    bullet = NULL;

    keyState = SDL_GetKeyState(0); // get key state array
    cout << "PlayState Init Successful" << endl;
}

void PlayState::cleanup()
{
    delete player;
	cout << "PlayState Clean Successful" << endl;
}

void PlayState::pause()
{
	cout << "PlayState Paused" << endl;
}

void PlayState::resume()
{
	cout << "PlayState Resumed" << endl;
}

void PlayState::handleEvents(CGame* game)
{
	SDL_Event event;
	int x,y;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				game->quit();
				break;
            case SDL_KEYDOWN:
				switch(event.key.keysym.sym){
                    case SDLK_ESCAPE:
                        game->quit();
                        break;
                    case SDLK_SPACE:
                    	bullet = new CSprite();
                    	bullet->loadSpriteSparrowXML("data/img/bullet.xml");
                    	x = player->getX();
                    	y = player->getY();
                    	bullet->setPosition(x,y);
                    	bullet->setYspeed(-150.0);
                    	cout << "Fire!" << endl;
                    	break;
                    default:
                        break;
                }
                break;
            case SDL_VIDEORESIZE:
                game->resize(event.resize.w, event.resize.h);
        }
        dirx = keyState[SDLK_RIGHT]*SPEED + keyState[SDLK_LEFT]*-SPEED;
        diry = keyState[SDLK_DOWN] *SPEED + keyState[SDLK_UP]  *-SPEED;
    }

    player->setXspeed(dirx);
    //player->setYspeed(diry);

    if(dirx || diry)
        player->setAnimRate(30);
    else {
        player->setAnimRate(0);
        player->setCurrentFrame(3);
    }

    if(dirx > 0)
        player->setMirror(false);
    else if(dirx < 0)
        player->setMirror(true);
}

void PlayState::update(CGame* game)
{
	int bottom,x;
	x = (int) enemies[0]->getX();
	count = 0;
	while(count != ENEMIES_LIMIT){
		if(find(destroyed.begin(),destroyed.end(),count) == destroyed.end()){
			if(x == 0) enemies[count]->setXspeed(100);
			else if(x == 100) enemies[count]->setXspeed(-100);
			enemies[count]->setAnimRate(30);
			enemies[count]->update(game->getUpdateInterval());
			if(bullet != NULL){
				if(enemies[count]->bboxCollision(bullet)){
					cout << "Hit!" << endl;
					destroyed.push_back(count);
					//enemies[count] = new CSprite();
				}
			}
		}
		count++;
	}
    player->update(game->getUpdateInterval());
    if(bullet != NULL) bullet->update(game->getUpdateInterval());

}

void PlayState::draw(CGame* game)
{
    glClearColor(0.8,0.8,0.8,1); // light gray
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Agora o mapa e' responsavel por desenhar o jogador, imediatamente depois
    // da camada 0 (primeira camada do mapa)
    count = 0;
    background->draw();
    player->draw();
    if(bullet != NULL) bullet->draw();
    while(count != ENEMIES_LIMIT){
    	if(find(destroyed.begin(),destroyed.end(),count) == destroyed.end()){
    		enemies[count]->draw();
    	}
    	count++;
    }

    SDL_GL_SwapBuffers();
}
