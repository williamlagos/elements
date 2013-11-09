/*
 * CSound.cpp
 *
 *  Created on: 03/12/2012
 *      Author: william
 */
#include "CSound.h"

#define NUM_SOUNDS 2
struct sample {
    Uint8 *data;
    int dpos;
    int dlen;
} sounds[NUM_SOUNDS];

using namespace std;

CSound::CSound()
{

}

CSound::~CSound()
{

}

void CSound::PlaySound(char *wav)
{
    Mix_Chunk *music;
    Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 2048);
    music = Mix_LoadWAV(wav);
    Mix_PlayChannel(1,music,0);
}

void CSound::PlayMP3(char *mp3){
    Mix_Music *music;
    Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 2048);
    music = Mix_LoadMUS(mp3);
    Mix_VolumeMusic(100);
    Mix_PlayMusic(music,-1);
}
