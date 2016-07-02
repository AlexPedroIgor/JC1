// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

#ifndef ARMAS_H
#define ARMAS_H

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

Objeto Cria_Fireball(Objeto* jogador);
void Carrega_Fireball(SDL_Renderer* renderer, Objeto* fireball, Objeto* jogador);
void Inicializa_Fireball(SDL_Renderer* renderer, Projeteis* projeteis, Objeto* jogador);

// *********************************************************************

#endif

// FIM