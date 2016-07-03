// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

#ifndef INIMIGO_H
#define INIMIGO_H

// BIBLIOTECAS DO SDL
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

// BIBLIOTECAS INTERNAS
#include "base.h"
#include "config.h"
#include "fisica.h"
#include "colisao.h"

// ***************************************************************************************

//
// FUNCOES
//

Objeto Cria_Inimigo(SDL_Renderer* renderer, int tipo);
void Adiciona_Inimigos(SDL_Renderer* renderer, Inimigos* vetor_de_inimigos, int quantidade, int tipo, int portal, Fase* fase);
void Remove_Inimigos_Mortos(SDL_Renderer* renderer, Inimigos* vetor_de_inimigos);
void Posiciona_Inimigo(SDL_Renderer* renderer, Objeto* inimigo, int portal, Fase* fase);
void Posiciona_Inimigos(SDL_Renderer* renderer, Inimigos* vetor_de_inimigos, int portal, Fase* fase);
void IA_de_Movimentacao(Objeto* inimigo, Jogadores* jogadores);
void Inimigo_Ataque(Objeto* inimigo, Objeto* jogador);
void Inimigo_Toma_Dano(SDL_Renderer* renderer, Objeto* inimigo, Status* status, int tipo);

// ********************************************************************************************

#endif

// FIM
