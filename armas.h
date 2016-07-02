// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

#ifndef ARMAS_H
#define ARMAS_H

// BIBLIOTECAS INTERNAS
#include "main.h"
#include "base.h"
#include "animacao.h"

//
// FUNCOES
//

Objeto Cria_Fireball(Objeto* jogador);
void Carrega_Fireball(SDL_Renderer* renderer, Objeto* fireball, Objeto* jogador);
void Inicializa_Fireball(SDL_Renderer* renderer, Projeteis* projeteis, Objeto* jogador);

// *********************************************************************

#endif

// FIM