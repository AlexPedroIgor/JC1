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

//
// ESTRUTURAS
//

/*typedef struct
{
	float HP, MP, HP_Max, MP_Max;
	int forca, destreza, inteligencia, constituicao;
	int ataque, defesa, lvl;
	int cooldown;
}Status;*/


// *****************************************************************************

//
// FUNCOES
//
void carrega_HUD(SDL_Renderer* renderer, Jogadores* jogadores);
void Definir_status_iniciais(Jogadores* jogadores);
void Manter_status(Jogadores* jogadores);



// ******************************************************************************

#endif

// FIM
