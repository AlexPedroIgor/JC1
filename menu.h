// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

#ifndef MENU_H
#define MENU_H

// BIBLIOTECAS INTERNAS
#include "main.h"
#include "base.h"
#include "som.h"

// **********************************************************************************************

//
// CONSTANTES
//

// MENUS
#define TELA_INICIAL					1
#define OPCOES							2
#define QND_DE_JOGADORES				3
#define SELECAO_DE_PERSONAGEM1			4
#define SELECAO_DE_PERSONAGEM2			5

// **********************************************************************************************

//
// FUNCOES
//

void Roda_MenuPrincipal(SDL_Renderer* renderer, SDL_Event event, Jogador* jogador1, Jogador* jogador2);
void Roda_TelaInicial(SDL_Renderer* renderer, SDL_Event event);
void Roda_Escolha_de_jogadores(SDL_Renderer* renderer, SDL_Event event);
void Roda_SelecaoDePersonagem_Singleplayer(SDL_Renderer* renderer, SDL_Event event, Jogador* jogador1);
void Roda_SelecaoDePersonagem_Multiplayer(SDL_Renderer* renderer, SDL_Event event, Jogador* jogador1, Jogador* jogador2);
void Roda_Opcoes(SDL_Renderer* renderer, SDL_Event event, Jogador* jogador1, Jogador* jogador2);

// ***********************************************************************************************

#endif

// FIM