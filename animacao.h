// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

#ifndef ANIMACAO_H
#define ANIMACAO_H

// BIBLIOTECAS INTERNAS
#include "main.h"
#include "base.h"
#include "config.h"

//
// FUNCOES
//

void Inimigo_Animacao_Ataque(Objeto* inimigo);
void Projetil_Fireball_Animacao(SDL_Renderer* renderer, Objeto* tiro);
void Fase_Animacao_Portal(Fase* fase);

// *********************************************************************

#endif

// fim
