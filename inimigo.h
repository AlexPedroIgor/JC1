// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

#ifndef INIMIGO_H
#define INIMIGO_H

#include "main.h"

// Estrutura para inimigos
typedef struct 
{
	// Numero do inimigo
	int numero;

	// Movimentacao
	struct
	{
		int cima;
		int baixo;
		int esquerda;
		int direita;
		int ataque;
	} movimento;

	// Velocidade de movimento
	struct
	{
		float x, y;
	}velocidade;

	// Dimensoes dos sprites da imagem
	int fullW, fullH;

	int animacao;

	// Rect para frame e posicao em tela
	SDL_Rect frame, posicao;

	// Imagem do sprite do inimigo
	SDL_Texture* sprite;
}Inimigo;

// Funcoes
Inimigo Carrega_Inimigo(int numero, SDL_Renderer* renderer);


void Movimenta_Inimigo(Inimigo* inimigo, Jogador* jogador);



#endif

// fim
