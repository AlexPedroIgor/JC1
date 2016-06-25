// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

/*
	Jogo de desenvolvido para projeto de computacao 1
*/

#include "main.h"
#include "menu_principal.h"
#include "jogo.h"

#include <stdio.h>
#include <stdlib.h>

// Pre carregamento das funcoes
int main (int argc, char **argv);
void ERRO (int codigo);

// Inicia programa no Menu Principal
int estadoDeJogo = MENU_PRINCIPAL;

// Evento de jogo rodando para loop
int jogoRodando = VERDADEIRO;

// Iniciando o programa
int main (int argc, char **argv)
{
	//
	// **********************
	// INICIALIZACAO DO SDL | inicio
	// **********************
	//

	// Inicializa SDL completo
	if (SDL_Init (SDL_INIT_EVERYTHING) != 0)
		ERRO(1);

	// Variavel que representa a janela
	SDL_Window* window = NULL;

	// Criando a janela
	window = SDL_CreateWindow(NOME_DO_JOGO,
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH, SCREEN_HEIGHT, 0);

	// Variavel que representa o render
	SDL_Renderer* renderer = NULL;

	// Inicia o render
	renderer = SDL_CreateRenderer(window, -1, 0);

	// Inicial o mixer de som
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 1024);

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

			case JOGO_SINGLEPAYER:
				roda_JogoSinglePlayer(renderer, event);
				break;
			
			case JOGO_MULTIPLAYER:
				roda_JogoMultiPlayer(renderer, event);
				break;
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

	SDL_DestroyRenderer(renderer); // Finaliza o renderer
	Mix_CloseAudio(); // Finaliza o mixer de som
	SDL_DestroyWindow(window); // Fecha a janela

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
			printf("Nao foi possivel inicializar o SDL.\n");
			printf("Falha no SDL_INIT_EVERYTHING: %s\n", SDL_GetError() );
			break;
	}
}