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

void RPG_Renderiza_HUD(SDL_Renderer* renderer, Jogadores* jogadores);
void RPG_Carrega_Status_Inicial(Jogadores* jogadores);
void Atualiza_Status_Geral(Jogadores* jogadores);
void Manter_status(Jogadores* jogadores);
void Tomar_dano(Inimigos* inimigo, Status* inimigo_status, Jogadores* jogadores, int jogador_proximo);
void Define_Status_Inimigo(Status* status, int tipo);

// ******************************************************************************

#endif

// FIM
