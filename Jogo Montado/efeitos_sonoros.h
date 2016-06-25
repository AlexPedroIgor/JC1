// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

#ifndef EFEITOS_SONOROS_H
#define EFEITOS_SONOROS_H

#include "main.h"

// Lista de efeitos sonoros

//			efeito		valor	
#define		CLICK			1
#define		SELECT			2
#define		VOLTAR			3

// Funcoes
void efeito_sonoro(int efeito);
Mix_Chunk* carrega_efeito_sonoro(int efeito);

#endif

// fim 
