// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

#ifndef CONFIG_H
#define CONFIG_H

#include "main.h"

// Velocidade de movimento dos jogadores
#define VEL		5.0

// Localizacao dos sprites de jogador
#define MAGE_W "arte/personagens/jogador1/Mage w.png"
#define MAGE_M "arte/personagens/jogador2/Mage m.png"
#define ARCHER_W "arte/personagens/jogador1/Archer w.png"
#define ARTHER_M "arte/personagens/jogador2/Archer m.png"

// Caracteristicas dos sprites de jogador
#define SPRITE_FULL_W		832
#define SPRITE_FULL_H		1344
#define SPRITE_FRAME_W		64
#define SPRITE_FRAME_H		64

// Movimentos de animacao
#define CIMA			1
#define BAIXO			2
#define ESQUERDA		3
#define DIREITA			4
#define QUADRANTE1		5
#define QUADRANTE2		6
#define QUADRANTE3		7
#define QUADRANTE4		8

// Estrutura para jogador
typedef struct 
{
	// Jogador 1 ou Jogador 2
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

	// Animacao de movimentacao
	int animacao;

	// Velocidade de movimento
	struct
	{
		float x, y;
	}velocidade;

	// Dimensoes dos sprites da imagem
	int fullW, fullH;

	// Rect para o jogador
	SDL_Rect frame, posicao;

	// Imagem do jogador
	SDL_Texture* sprite;
}Jogador;

// Estrutura para objetos
typedef struct 
{
	// Numero do objeto
	int numero;

	// Movimentacao
	struct
	{
		int cima;
		int baixo;
		int esquerda;
		int direita;
	} movimento;

	// Velocidade de movimento
	struct
	{
		float x, y;
	}velocidade;

	// Dimensoes dos sprites da imagem
	int fullW, fullH;

	// Rect para frame e posicao em tela
	SDL_Rect frame, posicao;

	// Imagem do sprite do objeto
	SDL_Texture* sprite;
}Objeto;

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

	// Rect para frame e posicao em tela
	SDL_Rect frame, posicao;

	// Imagem do sprite do inimigo
	SDL_Texture* sprite;
}Inimigo;

// Funcoes
Jogador Carrega_Jogador(int numero);
void Carrega_Teclas_de_Acao(Jogador* jogador);

#endif

// fim
