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

//			efeito		valor	
#define		CLICK			1
#define		SELECT			2
#define		VOLTAR			3

// *********************************************************************

//
// LISTA DE MUSICAS
//

//			musica							valor
#define		MUSICA_INICIAL						1
#define		MUSICA_DE_SELECAO					2
#define		MUSICA_DE_FUNDO_DO_JOGO				3

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
