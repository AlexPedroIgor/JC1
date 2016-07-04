// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

#ifndef SOM_H
#define SOM_H

// BIBLIOTECAS DO SDL
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

//
// LISTA DE EFEITOS SONOROS
//

//			efeito			valor	
#define		FX_CLICK			1
#define		FX_SELECT			2
#define		FX_VOLTAR			3
#define		FX_CURA				4
#define		FX_TAPA				5
#define		FX_SOCO				6
#define		FX_HULK_ESMAGA		7
#define		FX_FIREBALL			8
#define		FX_ESQUELETO		9
#define		FX_ORC				10
#define		FX_PASSO_1			11

// *********************************************************************

//
// LISTA DE MUSICAS
//

//			musica							valor
#define		MUSICA_INICIAL						1
#define		MUSICA_DE_SELECAO					2
#define		MUSICA_DE_FUNDO_DO_JOGO				3
#define		MUSICA_BOSS							4
#define		MUSICA_FIELD_1						5
#define 	MUSICA_FEILD_2						6

// **********************************************************************

//
// FUNCOES
//

void Efeito_Sonoro(int nome_do_efeito);
Mix_Chunk* Carrega_Efeito_Sonoro(int nome_do_efeito);
void Toca_Musica(int nome_da_musica);
Mix_Music* Carrega_Musica(int nome_da_musica);

// **********************************************************************

#endif

// FIM
