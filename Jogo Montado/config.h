// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

#ifndef CONFIG_H
#define CONFIG_H

#include "main.h"

// Velocidade de movimento dos jogadores
#define VEL 5.0

// Localizacao dos sprites
#define MAGE_W "arte/personagens/jogador1/Mage w.png"
#define MAGE_M "arte/personagens/jogador2/Mage m.png"
#define ARCHER_W "arte/personagens/jogador1/Archer w.png"
#define ARTHER_M "arte/personagens/jogador2/Archer m.png"

// Caracteristicas dos sprites
#define SPRITE_FULL_W 832
#define SPRITE_FULL_H 1344
#define SPRITE_FRAME_W 64
#define SPRITE_FRAME_H 64

// Estrutura para jogador
typedef struct 
{
	// Jogador 1 ou Jogador 2
	int jogador;

	// Teclas de acao
	struct
	{
		int cima;
		int baixo;
		int esquerda;
		int direita;
		int ataque;
	} tecla_de_acao;

	// Velocidade de movimento
	struct
	{
		float x, y;
	}movimento;

	// Dimensoes dos sprites da imagem
	int fullW, fullH;

	// Rect para o jogador
	SDL_Rect frame, posicao;

	// Imagem do jogador
	SDL_Texture* sprite;
}Jogador;

// Funcoes
Jogador Carrega_Jogador(int numero);
void Carrega_Teclas_de_Acao(Jogador* jogador);

#endif

// fim
