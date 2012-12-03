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
#include <unistd.h>
#include "CGame.h"
#include "PlayState.h"
#include "PauseState.h"

PlayState PlayState::m_PlayState;

#define SPEED 150

void PlayState::init()
{
	snd = new CSound();
	bug_speed = 100;
	won = defeated = false;
	vertical = 1;
	next = count = 0;
	background = new CImage();
    background->loadImage("data/maps/black.png");
	while(count != ENEMIES_LIMIT){
		CSprite* enemy = new CSprite();
		enemy->loadSpriteSparrowXML("data/img/bug.xml");
		if(count == (ENEMIES_LIMIT-1)/2) vertical = 3;
		enemy->setPosition((count%6)*60,30*vertical);
		enemy->setAnimRate(0);
		enemy->setScale(0.5);
		enemy->setXspeed(bug_speed);
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
						if(!defeated){
							bullet = new CSprite();
							snd->PlaySound("data/snd/shot.wav");
							bullet->loadSpriteSparrowXML("data/img/bullet.xml");
							x = player->getX();
							y = player->getY();
							bullet->setPosition(x+(player->getWidth()/2),y);
							bullet->setYspeed(-150.0);
						}
						break;
					case SDLK_p:
						if(!defeated){
							game->pushState(PauseState::instance());
						}
						break;
					case SDLK_n:
						if(won){
							count = 0; bug_speed *= 1.5;
							won = defeated = false;
						    background->loadImage("data/maps/black.png");
							destroyed.clear();
						}
						break;
					default:
						break;
				}
				break;
			case SDL_VIDEORESIZE:
				game->resize(event.resize.w, event.resize.h);
		}
		if(!defeated){
			dirx = keyState[SDLK_RIGHT]*SPEED + keyState[SDLK_LEFT]*-SPEED;
			diry = keyState[SDLK_DOWN] *SPEED + keyState[SDLK_UP]  *-SPEED;
		}
	}

	player->setXspeed(dirx);

	if(dirx || diry)
		player->setAnimRate(30);
	else {
		player->setAnimRate(0);
		player->setCurrentFrame(3);
	}
}

void PlayState::update(CGame* game)
{
	CSprite *enem,*nexe;
	int left,right,bottom,top;
	count = 0;
	if(won){
		snd->PlaySound("data/snd/won.wav");
		usleep(5000000);
	}
	while(count != ENEMIES_LIMIT-1){
		if(find(destroyed.begin(),destroyed.end(),count) == destroyed.end()){
			enem = enemies[count];
			nexe = enemies[next];
			top = nexe->getY(); left = enem->getX();
			bottom = nexe->getY()+nexe->getHeight();
			right = enem->getX()+enem->getWidth();
			if(left <= 0) enemies[count]->setXspeed(bug_speed);
			else if(top <= 30) enemies[next]->setYspeed(bug_speed/2);
			else if(right >= 480) enemies[count]->setXspeed(-bug_speed);
			else if(bottom >= 720) enemies[next]->setYspeed(-bug_speed/2);
			enemies[count]->setAnimRate(30);
			enemies[count]->update(game->getUpdateInterval());
			if(bullet != NULL)
				if(enemies[count]->bboxCollision(bullet)){
					snd->PlaySound("data/snd/destroy.wav");
					if(count == 0) enemies[count]->setX(0);
					destroyed.push_back(count);
					bullet = NULL;
				}
			if(enemies[count]->bboxCollision(player)){
				background->loadImage("data/img/game_over.png");
				defeated = true;
			}else if(destroyed.size() == 2){
				background->loadImage("data/img/game_win.png");
				won = true;
			}
		}
		count++;
	}
    if(bullet != NULL) bullet->update(game->getUpdateInterval());
    player->setY(550);
    player->update(game->getUpdateInterval());
    next++; next %= ENEMIES_LIMIT;
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
    if(bullet != NULL) bullet->draw();
    while(count != ENEMIES_LIMIT-1){
    	if(find(destroyed.begin(),destroyed.end(),count) == destroyed.end()){
    		enemies[count]->draw();
    	}
    	count++;
    }
    player->draw();
    SDL_GL_SwapBuffers();
}
