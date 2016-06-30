// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

#ifndef INIMIGO_H
#define INIMIGO_H

#include "main.h"

// Estrutura para inimigos
typedef struct 
{
	// Numero do inimigo
	int tipo;

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

// Estrutura para vetor de inimigos
typedef struct
{
	int quantidade;

	Inimigo* inimigo;
}Vetor_de_Inimigos;

// Funcoes
Inimigo Carrega_Inimigo(SDL_Renderer* renderer, int numero);
Vetor_de_Inimigos Cria_Vetor_de_inimigos(SDL_Renderer* renderer, int quantidade, int tipo);
void Movimenta_Inimigo(Inimigo* inimigo);
void IA_de_Movimentacao(Inimigo* inimigo, Jogador* jogador1, Jogador* jogador2);
void Atualiza_Inimigos_em_Tela(SDL_Renderer* renderer, Vetor_de_Inimigos* vetor_de_inimigos);

#endif

// fim
