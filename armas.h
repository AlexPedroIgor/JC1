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

void Cria_Fireball(Objeto*, Objeto*);
void Carrega_Fireball(SDL_Renderer*, Objeto*, Objeto*);
void Inicializa_Fireball(SDL_Renderer*, Projeteis*, Objeto*);
void Anima_Fireball(SDL_Renderer*, Objeto*);
void Apaga_Fireball(SDL_Renderer*, Objeto*);

// *********************************************************************

#endif

// FIM
