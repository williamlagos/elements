/*
 * CSound.h
 *
 *  Created on: 03/12/2012
 *      Author: william
 */

#ifndef CSOUND_H_
#define CSOUND_H_ 1

#include <cstring>
#include <cstdlib>
#include <iostream>
#include <SDL.h>
#include <SDL_mixer.h>

class CSound
{
public:
	CSound();
	~CSound();
	void PlayMP3(char *mp3);
	void PlaySound(char *wav);
};

#endif /* CSOUND_H_ */
