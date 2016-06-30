// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

#ifndef JOGO_H
#define JOGO_H

#include "main.h"
#include "inimigo.h"

// Funcoes do jogo
void Roda_Jogo_Singleplayer(SDL_Renderer* renderer, SDL_Event event, Jogador* jogador1);
void Roda_Jogo_Multiplayer(SDL_Renderer* renderer, SDL_Event event, Jogador* jogador1, Jogador* jogador2);
void Movimenta_Jogador(Jogador* jogador, Jogador* jogador2, Vetor_de_Inimigos* vetor_de_inimigos);
void Roda_Pause(SDL_Renderer* renderer, SDL_Event event, Fase* fase, Jogador* jogador1, Jogador* jogador2, Vetor_de_Inimigos* vetor_de_inimigos);
void Roda_SairDoPause_SN(int* pauseRodando, SDL_Renderer* renderer, SDL_Event event, Fase* fase, Jogador* jogador1, Jogador* jogador2, Vetor_de_Inimigos* vetor_de_inimigos);

#endif

// fim