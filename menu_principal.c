// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

/*
	MENU PRINCIPAL

	Jogo de desenvolvido para projeto de computacao 1
*/
#include "main.h"

// Estado de jogo em Menu Principal
void roda_MenuPrincipal(SDL_Renderer* renderer, SDL_Event event)
{
	// Variavel para manter menu
	int menuRodando = VERDADEIRO;

	// *********************************************************************

	//
	// ****************
	// PLANO DE FUNDO | inicio
	// ****************
	//

	// Variavel que carrega a imagem de fundo
	SDL_Surface* Loading_Surf = NULL;

	// Variavel que carrega a imagem no plano de fundo
	SDL_Texture* gFundo = NULL;

	// Carregando plano de fundo na memoria
	Loading_Surf = IMG_Load("arte/fundo/menu_principal.jpg");

	// Carregando imagem na tela
	gFundo = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf);

	// Limpando memoria
	SDL_FreeSurface(Loading_Surf);

	//
	// ****************
	// PLANO DE FUNDO | fim
	// ****************
	//

	// *********************************************************************

	//
	// **********************
	// Loop do menu rodando | inicio
	// **********************
	//

	while(menuRodando)
	{

		// Verifica eventos
		if (SDL_PollEvent (&event))
		{
			// Finaliza o jogo
			if (event.type == SDL_QUIT)
			{
				menuRodando = FALSO;
				jogoRodando = FALSO;
			}
		}


		// Limpa tela anterior
		SDL_RenderClear(renderer);

		// Renderiza plano de fundo
		SDL_RenderCopy(renderer, gFundo, NULL, NULL);

		// Atualiza tela
		SDL_RenderPresent(renderer);

		// Esperar por 2 segundos
		SDL_Delay(30);
	}

	//
	// **********************
	// Loop do menu rodando | fim
	// **********************
	//

	// *********************************************************************


}