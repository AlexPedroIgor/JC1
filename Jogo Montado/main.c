// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

/*
	Jogo de desenvolvido para projeto de computacao 1
*/

#include "main.h"
#include "menu_principal.h"

#include <stdio.h>
#include <stdlib.h>

// Tamanho de Tela
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

// Modos de jogo
#define	MENU_PRINCIPAL		1
#define	JOGO_SINGLEPAYER	2
#define	JOGO_MULTIPLAYER	3
#define OPCOES				4

int estadoDeJogo = MENU_PRINCIPAL;

// Evento de jogo rodando para loop
jogoRodando = VERDADEIRO;

// Iniciando o programa
int main (int argc, char **argv)
{
	//
	// **********************
	// INICIALIZACAO DO SDL | inicio
	// **********************
	//

	// Inicializa video
	if (SDL_Init (SDL_INIT_VIDEO) != 0)
		ERRO(1);

	// Variavel que representa a janela
	SDL_Window* window = NULL;

	// Criando a janela
	window = SDL_CreateWindow("JOGO SEM NOME",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH, SCREEN_HEIGHT, 0);

	// Variavel que representa o render
	SDL_Renderer* renderer = NULL;

	// Inicia o render
	renderer = SDL_CreateRenderer(window, -1, 0);

	//
	// **********************
	// INICIALIZACAO DO SDL | fim
	// **********************
	//

	// *********************************************************************

	//
	// **********************
	// Loop do jogo rodando | inicio
	// **********************
	//

	// Inicializa teste de eventos
	SDL_Event event;

	while (jogoRodando)
	{
		switch (estadoDeJogo)
		{
			case MENU_PRINCIPAL:
				roda_MenuPrincipal(renderer, event);
				break;

			/*
			case JOGO_SINGLEPAYER:
				roda_JogoSinglePlayer(renderer, event);
				break;

			case JOGO_MULTIPLAYER:
				roda_JogoMultiPlayer(renderer, event);
				break;

			case OPCOES:
				roda_Opcoes(renderer, event);
				break;
			*/
		}
	}

	//
	// **********************
	// Loop do jogo rodando | fim
	// **********************
	//

	// *********************************************************************

	//
	// *****************
	// Finaliza o jogo | inicio
	// *****************
	//

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	//
	// *****************
	// Finaliza o jogo | fim
	// *****************
	//

	// *********************************************************************

	return 0;
}

// Erros
void ERRO (int codigo)
{
	switch (codigo)
	{
		case 1: // Falha na inicializacao do SDL_INIT_VIDEO
			printf("Nao foi possivel inicializar o video.\n");
			printf("Falha no SDL_INIT_VIDEO: %s\n", SDL_GetError() );
			break;
	}
}