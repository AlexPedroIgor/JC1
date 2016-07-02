// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

#ifndef JOGO_H
#define JOGO_H

// BIBLIOTECAS INTERNAS
#include "main.h"
#include "base.h"
#include "config.h"
#include "inimigo.h"
#include "animacao.h"
#include "rpg.h"
#include "armas.h"
#include "fisica.h"
#include "colisao.h"
#include "som.h"

// ***********************************************************************************************

//
// FUNCOES
//

void Roda_Jogo(SDL_Renderer* renderer, SDL_Event event, Jogadores* jogadores);
void Roda_Pause(SDL_Renderer* renderer, SDL_Event event, Fase* fase, Jogadores* jogadores, Inimigos* inimigos);
void Roda_SairDoPause_SN(int* pauseRodando, SDL_Renderer* renderer, SDL_Event event, Fase* fase, Jogadores* jogadores, Inimigos* inimigos);

// **********************************************************************************************************************************

#endif

// FIM