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

// Localizacao dos mapas
#define MAPA_1 "arte/fundo/fundo01.jpg"
#define MAPA_2 "arte/fundo/fundo02.jpg"
#define MAPA_3 "arte/fundo/fundo03.jpg"
#define MAPA_4 "arte/fundo/fundoB1.jpg"

// Estrutura para jogador
typedef struct 
{
	// Jogador 1 ou Jogador 2
	int numero;

	// Variavel para guardar estado de colisao
	int colisao, toma_tiro;

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

	// Animação do movimento
	int animacao;

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

// Vetor de tiros
typedef struct
{
	// Quantidade de tiros em tela
	int quantidade;

	// Tiros que devem sair de tela
	int corta_tiro;

	// Vetor de tiros
	Objeto tiro[64];
}Vetor_de_Tiros;

// Struct para mapas
typedef struct
{
	// Numero da fase
	int numero;

	// Sprite
	SDL_Texture* sprite;

	// Portais
	struct
	{
		// Animacao do portal
		int animacao;

		struct
		{		
			// Tipo de portal
			int tipo;
			/*
			Portal 1 - Portal Vermelho		- Inimigos saindo do portal
			Portal 2 - Portal Azul			- Jogadores podem passar
			Portal 3 - Portal Cinza			- Portal desativado
			*/

			// Sprite dos portais
			SDL_Texture* sprite;

			// Rect para portais
			SDL_Rect frame, posicao;

		}cima, baixo, esquerda, direita;
	}portal;
}Fase;

// Funcoes
Jogador Carrega_Jogador(int numero);
void Carrega_Teclas_de_Acao(Jogador* jogador);
Fase Inicializa_Fases();
void Carrega_Fase_Memoria(SDL_Renderer* renderer, Fase* fase);
void Troca_portal(SDL_Renderer* renderer, Fase* fase, int portal, int tipo);
void Atualiza_Plano_de_Fundo(SDL_Renderer* renderer, Fase*fase);

#endif

// fim
