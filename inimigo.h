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

void Cria_Inimigo(SDL_Renderer*, Objeto*, int);
void Adiciona_Inimigos(SDL_Renderer*, Inimigos*, int, int, int, Fase*);
void Remove_Inimigos_Mortos(SDL_Renderer*, Inimigos*);
void Posiciona_Inimigo(SDL_Renderer*, Objeto*, int, Fase*);
void Posiciona_Inimigos(SDL_Renderer*, Inimigos*, int, Fase*);
void IA_de_Movimentacao(Objeto*, Status*, Jogadores*, int);
void Inimigo_Toma_Dano(SDL_Renderer*, Objeto*, Status*, int);

// ********************************************************************************************

#endif

// FIM
