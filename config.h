// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

#ifndef CONFIG_H
#define CONFIG_H

// BIBLIOTECAS INTERNAS
#include "main.h"
#include "base.h"
#include "rpg.h"

// ****************************************************************************************

//
// CONSTANTES DE CONFIGURACAO
//

// VELOCIDADE DE MOVIMENTACAO DOS OBJETOS
#define VEL_MAGO		4.0 // Jogador - Mago
#define VEL_ARQUEIRO	5.0 // Jogador - Arqueiro
#define VEL_INIMIGO_1	2.5 // Inimigo - Esqueleto
#define VEL_INIMIGO_2	3.0	// Inimigo - Orc
#define VEL_INIMIGO_3	4.5	// Inimigo - Blackelf
#define VEL_BOSS		6.0 // Boss - Aranha-Morcego
#define VEL_FIREBALL	3.0 // Projetil - Fireball
#define VEL_FLECHA		3.0 // Projetil - Flecha
#define VEL_TEIA		4.0 // Projetil - Teia da Aranha-Morcego

// LOCALIZACAO DOS SPRITES DOS PERSONAGENS
#define MAGE_W		"arte/personagens/jogador1/Mage w.png"
#define MAGE_M		"arte/personagens/jogador2/Mage m.png"
#define ARCHER_W	"arte/personagens/jogador1/Archer w.png"
#define ARTHER_M	"arte/personagens/jogador2/Archer m.png"
#define ESQUELETO	"arte/personagens/vilao01/esqueleto.png"
#define ORC			"arte/personagens/vilao02/orc.png"
#define BLACKELF	"arte/personagens/vilao03/blackelf.png"
#define BOSS		"arte/personagens/boss01/boss.png"

// DIMENSOES DOS SPRITES DE PERSONAGENS
#define SPRITE_FULL_W		832
#define SPRITE_FULL_H		1344
#define SPRITE_FRAME_W		64
#define SPRITE_FRAME_H		64

// MOVIMENTOS DE ANIMACAO
#define CIMA			1
#define BAIXO			2
#define ESQUERDA		3
#define DIREITA			4
#define QUADRANTE1		5
#define QUADRANTE2		6
#define QUADRANTE3		7
#define QUADRANTE4		8

// LOCALIZACAO DOS MAPAS
#define MAPA_1 "arte/fundo/fundo01.jpg"
#define MAPA_2 "arte/fundo/fundo02.jpg"
#define MAPA_3 "arte/fundo/fundo03.jpg"
#define MAPA_4 "arte/fundo/fundoB1.jpg"

// ****************************************************************************************

//
// TEXTO
//

// PONTEIRO PARA GUARDAR FONTE
TTF_Font* Fonte;

// CORES DE TEXTO
SDL_Color branco = {255,255,255};
SDL_Color preto = {0,0,0};
SDL_Color amarelo = {255,255,0};
SDL_Color vermelho = {255,0,0};
SDL_Color verde = {51,255,0};

// ****************************************************************************************

//
// FINCOES
//

void Carrega_Teclas_de_Acao(Objeto* jogador);
SDL_Texture* Cria_Texto(SDL_Renderer* renderer, char* texto, TTF_Font* fonte, SDL_Color cor_do_texto);

// *****************************************************************************************

#endif

// FIM
