// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

#ifndef RPG_H
#define RPG_H

// BIBLIOTECAS DO SDL
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

// BIBLIOTECAS INTERNAS
#include "base.h"

// ******************************************************************************

//
// ESTRUTURAS
//



// *****************************************************************************

//
// FUNCOES
//

void RPG_Renderiza_HUD(SDL_Renderer*, Jogadores*);
void RPG_Carrega_Status_Inicial(Jogadores*);
void Atualiza_Status_Geral(Jogadores*);
void Manter_status(Jogadores*);
void Tomar_dano(Objeto*, Status*, Jogadores*, int);
void Define_Status_Inimigo(Status*, int);

// ******************************************************************************

#endif

// FIM
