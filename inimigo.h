// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

#ifndef INIMIGO_H
#define INIMIGO_H

// BIBLIOTECAS INTERNAS
#include "main.h"
#include "base.h"
#include "rpg.h"
#include "fisica.h"
#include "colisao.h"

// ***************************************************************************************

//
// FUNCOES
//

Objeto Cria_Inimigo(SDL_Renderer* renderer, int tipo);
void Adiciona_Inimigos(SDL_Renderer* renderer, Inimigos* inimigos, int quantidade, int tipo, int portal, Fase* fase);
void Remove_Inimigos_Mortos(SDL_Renderer* renderer, Inimigos* inimigos);
void Posiciona_Inimigo(SDL_Renderer* renderer, Objeto* inimigo, int portal, Fase* fase);
void Posiciona_Inimigos(SDL_Renderer* renderer, Inimigos* inimigos, int portal, Fase* fase);
void IA_de_Movimentacao(Inimigo* inimigo, Jogadores* jogadores);
void Inimigo_Toma_Dano(SDL_Renderer* renderer, Objeto* inimigo, Status* status, int tipo);

// ********************************************************************************************

#endif

// FIM
