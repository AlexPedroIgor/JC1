// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

#ifndef CONFIG_H
#define CONFIG_H

// BIBLIOTECAS DO SDL
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

// BIBLIOTECAS DO C
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// BIBLIOTECAS INTERNAS
#include "base.h"

// ***************************************************************************************

//
// CONSTANTES
//

// MODOS DE JOGO
#define	MENU			1
#define	JOGO			2

// NOME DO JOGO
#define NOME_DO_JOGO "SUPER SMASH ARANHA-MORCEGO"

// TAMANHO DA TELA
#define SCREEN_WIDTH	800
#define SCREEN_HEIGHT	600

// FRAMERATE DO JOGO
#define FPS				30

// ****************************************************************************************

//
// VARIAVEIS GLOBAIS
//

// VARIAVEIS DE GERENCIAMENTO DO MAIN
int mainRodando, estadoDeJogo;

// ****************************************************************************************

//
// TEXTO
//

typedef struct
{
	char* mensagem;
	int valor_numerico;
	SDL_Rect posicao1, posicao2;
	SDL_Texture* textura;
}Texto;

// PONTEIRO PARA GUARDAR FONTE
TTF_Font* Fonte1;
TTF_Font* Fonte2;

/*
// CORES DE TEXTO
SDL_Color branco = {255,255,255};
SDL_Color preto = {0,0,0};
SDL_Color amarelo = {255,255,0};
SDL_Color vermelho = {255,0,0};
SDL_Color verde = {51,255,0};
*/

// ****************************************************************************************

//
// FUNCOES
//

void Carrega_Teclas_de_Acao(Objeto* jogador);
SDL_Texture* Cria_Texto(SDL_Renderer* renderer, char* texto, TTF_Font* fonte, SDL_Color cor_do_texto);
void Texto_em_Tela_Nome_do_Personagem(SDL_Renderer* renderer, SDL_Event event);
FILE* DATA_Carrega_Save_Game();
void DATA_Salva_Informacoes_Basicas(FILE* save_game);
void DATA_Carrega_Informacoes(Status* mago, Status* arqueiro, Ranking* ranking);

// *****************************************************************************************

//
// SAVE GAME
//

FILE* Save_Game;

/*
	ORDEM DOS ARQUIVOS GRAVADOS NA MEMORIA

	1		STRUCT DE STATUS DO MAGO
	2		STRUCT DE STATUS DO ARQUEIRO
	3		RANKING DE PONTUACAO DOS JOGADORES
	4		STRUCT DE TECLAS DE ACAO DO JOGADOR 1
	5		STRUCT DE TECLAS DE ACAO DO JOGADOR 2

*/

// *****************************************************************************************

#endif

// FIM
