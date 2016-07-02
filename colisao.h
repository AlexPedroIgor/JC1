// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

#ifndef COLISAO_H
#define COLISAO_H

#include "main.h"
#include "base.h"

// Funcoes do menu principal
void Roda_MenuPrincipal(SDL_Renderer* renderer, SDL_Event event, Jogador* jogador1, Jogador* jogador2);
void Roda_TelaInicial(SDL_Renderer* renderer, SDL_Event event);
void Roda_Escolha_de_jogadores(SDL_Renderer* renderer, SDL_Event event);
void Roda_SelecaoDePersonagem_Singleplayer(SDL_Renderer* renderer, SDL_Event event, Jogador* jogador1);
void Roda_SelecaoDePersonagem_Multiplayer(SDL_Renderer* renderer, SDL_Event event, Jogador* jogador1, Jogador* jogador2);
void Roda_Opcoes(SDL_Renderer* renderer, SDL_Event event, Jogador* jogador1, Jogador* jogador2);

#endif

// fim