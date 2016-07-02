// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

#ifndef CONFIG_H
#define CONFIG_H

#include "main.h"
#include "base.h"

// ****************************************************************************************

//
// Constantes de configuracao
//

// Velocidade de movimento dos objetos
#define VEL_MAGO		4.0 // Jogador - Mago
#define VEL_ARQUEIRO	5.0 // Jogador - Arqueiro
#define VEL_INIMIGO_1	2.5 // Inimigo - Esqueleto
#define VEL_INIMIGO_2	3.0	// Inimigo - Orc
#define VEL_INIMIGO_3	4.5	// Inimigo - Blackelf
#define VEL_BOSS		6.0 // Boss - Aranha-Morcego
#define VEL_FIREBALL	3.0 // Projetil - Fireball
#define VEL_FLECHA		3.0 // Projetil - Flecha
#define VEL_TEIA		4.0 // Projetil - Teia da Aranha-Morcego

// Localizacao dos sprites de jogador
#define MAGE_W "arte/personagens/jogador1/Mage w.png"
#define MAGE_M "arte/personagens/jogador2/Mage m.png"
#define ARCHER_W "arte/personagens/jogador1/Archer w.png"
#define ARTHER_M "arte/personagens/jogador2/Archer m.png"

// Caracteristicas dos sprites de jogadores e inimigos
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

// ****************************************************************************************

// Estrutura para guardar informacoes sobre a fonte
TTF_Font* Fonte;

SDL_Color branco = {255,255,255};
SDL_Color preto = {0,0,0};
SDL_Color amarelo = {255,255,0};
SDL_Color vermelho = {255,0,0};
SDL_Color verde = {51,255,0};

// ****************************************************************************************

//
// Funcoes
//

void Carrega_Teclas_de_Acao(Jogador* jogador);
SDL_Texture* Cria_Texto(SDL_Renderer* renderer, char* texto, TTF_Font* fonte, SDL_Color cor_do_texto);

// *****************************************************************************************

#endif

// fim
