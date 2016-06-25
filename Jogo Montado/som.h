// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

#ifndef SOM_H
#define SOM_H

#include "main.h"

//
// Lista de efeitos sonoros
//

//			efeito		valor	
#define		CLICK			1
#define		SELECT			2
#define		VOLTAR			3

//
// Lista de musicas
//

//			musica							valor
#define		MUSICA_INICIAL						1
#define		MUSICA_DE_SELECAO					2
#define		MUSICA_DE_FUNDO_DO_JOGO				3

// Funcoes
void efeito_sonoro(int nome_do_efeito);
Mix_Chunk* carrega_efeito_sonoro(int nome_do_efeito);
void toca_musica(int nome_da_musica);
Mix_Music* carrega_musica(int nome_da_musica);

#endif

// fim 
