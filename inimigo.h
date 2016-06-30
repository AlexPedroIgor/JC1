// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

#ifndef INIMIGO_H
#define INIMIGO_H

#include "main.h"

// Velocidade de movimentacao dos inimigos
#define VEL_INIMIGO 1.5

// Maximo de inimigos em tela
#define MAX 64

// Estrutura para inimigos
typedef struct 
{
	// Numero do inimigo
	int tipo;

	// Variavel para receber estado de colisao
	int colisao, toma_tiro;

	// Variavel para guardar estado de vida do inimigo
	int vivo;

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
	// Quantidade de inimigos em tela
	int quantidade;

	// Quantidade de inimigos mortos
	int mortos;

	// Quanditades de inimigos mortos na rodada
	int mortos_rodada;

	Inimigo inimigo[MAX];
}Vetor_de_Inimigos;

// Funcoes
Inimigo Carrega_Inimigo(SDL_Renderer* renderer, int numero);
Vetor_de_Inimigos Cria_Vetor_de_inimigos(SDL_Renderer* renderer, int quantidade, int tipo);
void Adiciona_inimigos(SDL_Renderer* renderer,Vetor_de_Inimigos* vetor_de_inimigos, int quantidade, int tipo, int portal);
void Remove_Inimigos_Mortos(SDL_Renderer* renderer, Vetor_de_Inimigos* vetor_de_inimigos);
void Posiciona_Inimigo(SDL_Renderer* renderer, Inimigo* inimigo, int portal);
void Posiciona_Vetor_de_Inimigos(SDL_Renderer* renderer, Vetor_de_Inimigos* vetor_de_inimigos, int portal);
void Movimenta_Inimigo(Inimigo* inimigo);
void IA_de_Movimentacao(Inimigo* inimigo, Jogador* jogador1, Jogador* jogador2);
void Movimentacao_dos_Inimigos(Vetor_de_Inimigos* vetor_de_inimigos, Jogador* jogador1, Jogador* jogador2);
void Atualiza_Inimigos_em_Tela(SDL_Renderer* renderer, Vetor_de_Inimigos* vetor_de_inimigos);

#endif

// fim
