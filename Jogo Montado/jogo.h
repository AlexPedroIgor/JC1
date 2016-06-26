// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

#ifndef JOGO_H
#define JOGO_H

#include "main.h"

// Funcoes do jogo
void Roda_Jogo_Singleplayer(SDL_Renderer* renderer, SDL_Event event);
void Roda_Jogo_Multiplayer(SDL_Renderer* renderer, SDL_Event event);
void Movimenta_Jogador(Jogador* jogador);

#endif

// fim