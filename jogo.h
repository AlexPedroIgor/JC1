// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

#ifndef JOGO_H
#define JOGO_H

// BIBLIOTECAS DO SDL
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

// BIBLIOTECAS INTERNAS
#include "base.h"
#include "config.h"
#include "rpg.h"

// ***********************************************************************************************

//
// FUNCOES
//

void Roda_Jogo(SDL_Renderer* renderer, SDL_Event event, Jogadores* jogadores);
void Roda_Pause(SDL_Renderer* renderer, SDL_Event event, Fase* fase, Jogadores* jogadores, Inimigos* inimigos, Projeteis* projeteis);
void Roda_SairDoPause_SN(int* pauseRodando, SDL_Renderer* renderer, SDL_Event event, Fase* fase, Jogadores* jogadores, Inimigos* inimigos, Projeteis* projeteis);

// **********************************************************************************************************************************

#endif

// FIM