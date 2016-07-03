// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

#ifndef ANIMACAO_H
#define ANIMACAO_H

// BIBLIOTECAS DO SDL
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

// BIBLIOTECAS INTERNAS
#include "base.h"
#include "config.h"

//
// FUNCOES
//

void Inimigo_Animacao_Ataque(Objeto* inimigo);
void Inimigo_Animacao_Toma_Dano(SDL_Renderer* renderer, Objeto* inimigo);
void Projetil_Fireball_Animacao(SDL_Renderer* renderer, Objeto* tiro);
void Fase_Animacao_Portal(Fase* fase);

// *********************************************************************

#endif

// FIM