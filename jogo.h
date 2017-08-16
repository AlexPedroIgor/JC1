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

void Roda_Jogo(SDL_Renderer*, Jogadores*);
void Roda_Pause(SDL_Renderer*, Fase*, Jogadores*, Inimigos*, Projeteis*);
void Roda_SairDoPause_SN(int*, SDL_Renderer*, Fase*, Jogadores*, Inimigos*, Projeteis*);
void Roda_Game_Over(SDL_Renderer*);

// **********************************************************************************************************************************

#endif

// FIM
