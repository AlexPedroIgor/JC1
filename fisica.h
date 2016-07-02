// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

#ifndef FISICA_H
#define FISICA_H

// BIBLIOTECAS DO SDL
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

// BIBLIOTECAS INTERNAS
#include "base.h"
#include "rpg.h"
#include "colisao.h"
#include "armas.h"

// *************************************************************************************************

//
// Funcoes
//

void Jogador_Movimentar(Objeto* jogador);
void Ataque_dos_Jogadores(SDL_Renderer* renderer, Jogadores* jogadores, Projeteis* projeteis);
void Movimentacao_dos_Jogadores(Jogadores* jogadores, Inimigos* inimigos);
void Inimigo_Movimentar(Objeto* inimigo);
void Movimentacao_dos_Inimigos(Inimigos* inimigos, Jogadores* jogadores);

// *************************************************************************************************

#endif

// FIM
