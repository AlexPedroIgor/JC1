// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

#ifndef BASE_H
#define BASE_H

// BIBLIOTECAS DO SDL
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

// BIBLIOTECAS INTERNAS
#include "rpg.h"

// ******************************************************************************************

// CONDICIONAIS
#define VERDADEIRO		1
#define FALSO			0

// ******************************************************************************************

//
// TIPOS DE OBJETOS
//

#define JOGADOR			1
#define INIMIGO_1		2
#define INIMIGO_2		3
#define INIMIGO_3		4
#define BOSS_1			5
#define FIREBALL		6
#define FLECHA			7

// *****************************************************************************************

//
// CLASSES DE JOGADORES
//

#define MAGO		1
#define ARQUEIRO	2

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
#define ARCHER_M	"arte/personagens/jogador2/Archer m.png"
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

// ***************************************************************************

/*

TIPOS DE ATAQUE

MAGO:

1 - FIREBALL

ARQUEIRO:

1 - FLECHA

*/

// ***************************************************************************

//
// ESTRUTURAS BASICAS
//

// OBJETOS EM TELA
typedef struct 
{
	int tipo; // Armazena tipo de objeto

	int numero; // Armazena o numero do objeto

	struct
	{
		int cima, baixo, esquerda, direita;
	}colisao; // Estado de colisao no momento

	struct
	{
		int cima, baixo, esquerda, direita, ataque;
	} movimento; // Armazena estado de movimentacao no momento

	int animacao; // Variavel para auxiliar na animacao do sprite

	struct
	{
		float x, y; // Velocidade de movimento em x e y
	}velocidade;

	int fullW, fullH; // Dimensoes dos sprites da imagem

	SDL_Rect frame, posicao; // Rect para corte no frame e posicao em tela

	struct
	{
		struct
		{
			int x,y; // Coordenadas do ponto central
		}centro; // Variaveis das dimensoes utilizadas para colisao

		int v,h; // Distancia entre o centro e os limites verticais e horizontais

	}tamanho_real;

	SDL_Texture* sprite; // Imagem do sprite do objeto
}Objeto;

// VETOR DE JOGADORES
typedef struct
{
	int quantidade; // Armazena se esta no modo multi ou singleplayer
	struct
	{
		int classe; // Armazena se e mago ou arqueiro
		int tipo_de_ataque; // Armazena o tipo de ataque
		Objeto inf; // Informacoes basicas do objeto
		Status status; // Status do jogador
	}jogador[2]; // Maximo de dois jogadores
}Jogadores;

// VETOR DE INIMIGOS
typedef struct
{
	int quantidade; // Guarda quantos inimigos estao em tela
	int mortos; // Guarda quantos inimigos foram mortos no total
	int rodada; // guarda quantos inimigos morreram na rodada para limpar a memoria
	struct
	{
		int tipo; // Guarda tipo de inimigo
		int vivo; // Guarda se o inimigo estavivo ou morto
		Objeto inf; // Informacoes basicas do objeto
		Status status; // Informacoes de status do inimigo
	}inimigo[64]; // Máximo de 64 inimigos em tela
}Inimigos;

// VETOR PARA O BOSS
typedef struct
{
	int quantidade; // Guarda quantos inimigos estao em tela
	int mortos; // Guarda quantos inimigos foram mortos no total
	int rodada; // guarda quantos inimigos morreram na rodada para limpar a memoria
	struct
	{
		int vivo; // Guarda se o inimigo estavivo ou morto
		Objeto inf; // Informacoes do objeto
		Status status; // Informacoes de status do boss
	}chefe[1]; // Quantidade de chefes em tela
}Boss;

// VETOR DE PROJETEIS
typedef struct
{
	int quantidade; // Guarda quantos projeteis estao em tela
	int remover; // Guarda quantos projeteis ja sairam de tela para serem removidos da memoria
	struct
	{
		int em_tela; // Guarda se o projetil esta em tela ou nao
		int tipo; // Guarda tipo do projetil
		Objeto inf; // Informacoes basicas do objeto
	}tiro[64]; // Maximo de 64 projetis em tela
}Projeteis;

// ARMAZENAMENTO DAS INFORMACOES DA FASE
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

			// Quantidade de inimigos saindo do portal
			int inimigos;

			// Sprite dos portais
			SDL_Texture* sprite;

			// Rect para portais
			SDL_Rect frame, posicao;

		}cima, baixo, esquerda, direita;
	}portal;
}Fase;


// **************************************************************************

//
// FUNCOES
//

Jogadores* Inicializa_Jogadores();
Inimigos* Inicializa_Inimigos();
Projeteis* Inicializa_Projeteis();
Boss* Inicializa_Boss();
Fase* Inicializa_Fases();
void Finaliza_Jogadores(Jogadores* jogadores);
void Finaliza_Inimigos(Inimigos* inimigos);
void Finaliza_Projeteis(Projeteis* projeteis);
void Finaliza_Boss(Boss* boss);
void Finaliza_Fases(Fase* fase);
void Carrega_Fase_Memoria(SDL_Renderer* renderer, Fase* fase);
void Fase_Troca_Portal(SDL_Renderer* renderer, Fase* fase, int portal, int tipo);
void Posiciona_Jogadores(Jogadores* jogadores);
void Carrega_Jogadores_Memoria(SDL_Renderer* renderer, Jogadores* jogadores);
void Renderiza_Plano_de_Fundo(SDL_Renderer* renderer, Fase* fase);
void Renderiza_Jogadores(SDL_Renderer* renderer, Jogadores* jogadores);
void Renderiza_Inimigos(SDL_Renderer* renderer, Inimigos* inimigos);
void Renderiza_Projeteis(SDL_Renderer* renderer, Projeteis* projeteis);
void Renderiza_Boss(SDL_Renderer* renderer, Boss* boss);


// **************************************************************************

#endif

// FIM