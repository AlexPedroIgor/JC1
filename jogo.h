// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

#ifndef JOGO_H
#define JOGO_H

// Bicliotecas internas
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


//
// Funcoes do jogo
//

void Roda_Singleplayer(SDL_Renderer* renderer, SDL_Event event, Jogador* jogador1);
void Roda_Multiplayer(SDL_Renderer* renderer, SDL_Event event, Jogador* jogador1, Jogador* jogador2);
void Roda_Pause(SDL_Renderer* renderer, SDL_Event event, Fase* fase, Jogadores* jogadores, Inimigos* inimigos, Projeteis* projeteis);
void Roda_SairDoPause_SN(int* pauseRodando, SDL_Renderer* renderer, SDL_Event event, Fase* fase, Jogadores* jogadores, Inimigos* inimigos, Projeteis* projeteis);
void Atirar(SDL_Renderer* renderer, Jogador* jogador, Vetor_de_Tiros* vetor_de_tiros);

// **********************************************************************************************************************************

#endif

// fim