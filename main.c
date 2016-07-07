// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

/*
	Jogo de desenvolvido para projeto de computacao 1
*/

#include "main.h"

//
// PRE CARREGAMENTO DAS FUNCOES
//

void ERRO (int codigo);

// *******************************************************************************************

//
// MAIN
//

// INICIALIZA JOGO NO MENU PRINCIPAL
int estadoDeJogo = MENU;

// VARIAVEL PARA LOOP DO JOGO
int mainRodando = VERDADEIRO;

// FUNCAO PRINCIPAL
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

	// Inicializa leitor de fontes
	if (TTF_Init() != 0)
		ERRO(2);

	// Variavel que representa a janela
	SDL_Window* window = NULL;

	// Criando a janela
	window = SDL_CreateWindow(NOME_DO_JOGO,
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH, SCREEN_HEIGHT,
		SDL_WINDOW_RESIZABLE);

	// Variavel que representa o render
	SDL_Renderer* renderer = NULL;

	// Inicia o render
	renderer = SDL_CreateRenderer(window, -1, 0);

	// Resolucao virtual
	SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

	// Inicial o mixer de som
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);

	// Carrega informacoes dde fontes
	Fonte1 = TTF_OpenFont("data/fontes/SHERWOOD.TTF", 28);
	Fonte2 = TTF_OpenFont("data/fontes/OpenSans-Regular.ttf", 28);

	TTF_GetFontStyle(Fonte1);
	TTF_GetFontStyle(Fonte2);

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

	Save_Game = DATA_Carrega_Save_Game();

	// Carrega jogadores
	Jogadores* jogadores = Inicializa_Jogadores();

	while (mainRodando)
	{
		switch (estadoDeJogo)
		{
			case MENU:
				Roda_MenuPrincipal(renderer, jogadores);
				break;

			case JOGO:
				Roda_Jogo(renderer, jogadores);
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

	fclose(Save_Game);

	Finaliza_Jogadores(jogadores); // Libera jogadores da memoria
	TTF_CloseFont(Fonte1); // Fecha a fonte 1
	TTF_CloseFont(Fonte2); // Fecha a fonte 2
	TTF_Quit(); // Finaliza o leitor de fontes
	Mix_CloseAudio(); // Finaliza o mixer de som
	SDL_DestroyRenderer(renderer); // Finaliza o renderer
	SDL_DestroyWindow(window); // Fecha a janela

	//
	// *****************
	// Finaliza o jogo | fim
	// *****************
	//

	// *********************************************************************

	return 0;
}

// *******************************************************************************************

//
// ERROS
//

void ERRO (int codigo)
{
	switch (codigo)
	{
		case 1: // Falha na inicializacao do SDL
			printf("Nao foi possivel inicializar o SDL.\n");
			printf("Falha no SDL_INIT_EVERYTHING: %s\n", SDL_GetError() );
			break;

		case 2: // Falha na inicializacao do TTF
			printf("Nao foi possivel inicializar o TTF.\n");
			break;
	}
}

// *******************************************************************************************

// FIM