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

	// Variavel que carrega a imagens
	SDL_Surface* Loading_Surf = NULL;

	// *********************************************************************

	//
	// ****************
	// PLANO DE FUNDO | inicio
	// ****************
	//

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
	// **************
	// INICIAR JOGO | inicio
	// **************
	//

	// Variavel que carrega a opcao de iniciar o jogo
	SDL_Texture* gIniciar_Jogo = NULL;

	// Carregando plano de fundo na memoria
	Loading_Surf = IMG_Load("arte/menu/iniciar_jogo.png");

	// Carregando imagem na tela
	gIniciar_Jogo = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf);

	// Limpando memoria
	SDL_FreeSurface(Loading_Surf);

	// Variavel que carrega a opcao de iniciar o jogo pressionado
	SDL_Texture* gIniciar_Jogo_pressionado = NULL;

	// Carregando plano de fundo na memoria
	Loading_Surf = IMG_Load("arte/menu/iniciar_jogo_pressionado.png");

	// Carregando imagem na tela
	gIniciar_Jogo_pressionado = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf);

	// Limpando memoria
	SDL_FreeSurface(Loading_Surf);

	// Declarando rect
	SDL_Rect iniciar_jogo;

	iniciar_jogo.x = 450;
	iniciar_jogo.y = 250;
	iniciar_jogo.w = 250;
	iniciar_jogo.h = 50;

	//
	// **************
	// INICIAR JOGO | fim
	// **************
	//

	// *********************************************************************

	//
	// ********
	// OPCOES | inicio
	// ********
	//

	// Variavel que carrega a opcao do menu de opcoes
	SDL_Texture* gOpcoes = NULL;

	// Carregando plano de fundo na memoria
	Loading_Surf = IMG_Load("arte/menu/opcoes.png");

	// Carregando imagem na tela
	gOpcoes = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf);

	// Limpando memoria
	SDL_FreeSurface(Loading_Surf);

	// Variavel que carrega a opcao do menu de opcoes pressionado
	SDL_Texture* gOpcoes_pressionado = NULL;

	// Carregando plano de fundo na memoria
	Loading_Surf = IMG_Load("arte/menu/opcoes_pressionado.png");

	// Carregando imagem na tela
	gOpcoes_pressionado = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf);

	// Limpando memoria
	SDL_FreeSurface(Loading_Surf);

	// Declarando rect
	SDL_Rect opcoes;

	opcoes.x = 450;
	opcoes.y = 300;
	opcoes.w = 250;
	opcoes.h = 50;

	//
	// ********
	// OPCOES | fim
	// ********
	//

	// *********************************************************************

	//
	// **************
	// SAIR DO JOGO | inicio
	// **************
	//

	// Variavel que carrega a opcao de sair do jogo
	SDL_Texture* gSair = NULL;

	// Carregando plano de fundo na memoria
	Loading_Surf = IMG_Load("arte/menu/sair.png");

	// Carregando imagem na tela
	gSair = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf);

	// Limpando memoria
	SDL_FreeSurface(Loading_Surf);

	// Variavel que carrega a opcao de sair do jogo
	SDL_Texture* gSair_pressionado = NULL;

	// Carregando plano de fundo na memoria
	Loading_Surf = IMG_Load("arte/menu/sair_pressionado.png");

	// Carregando imagem na tela
	gSair_pressionado = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf);

	// Limpando memoria
	SDL_FreeSurface(Loading_Surf);

	// Declarando rect
	SDL_Rect sair;

	sair.x = 450;
	sair.y = 350;
	sair.w = 250;
	sair.h = 50;

	//
	// **************
	// SAIR DO JOGO | fim
	// **************
	//

	// *********************************************************************

	//
	// **********************
	// Loop do menu rodando | inicio
	// **********************
	//

	while(menuRodando)
	{

		// Salva posicao do mouse
		struct POSICAO_DO_MOUSE
		{
			int x, y;
		}posicao_do_mouse;

		SDL_GetMouseState(&posicao_do_mouse.x, &posicao_do_mouse.y);

		// Verifica eventos
		if (SDL_PollEvent (&event))
		{
			// Finaliza o jogo
			if (event.type == SDL_QUIT)
			{
				menuRodando = FALSO;
				jogoRodando = FALSO;
			}

			//
			// Eventos de clique do mouse
			//

			if (event.type == SDL_MOUSEBUTTONDOWN)
			{

				//
				// Acoes
				//

				// Iniciar jogo
				if (posicao_do_mouse.x > 450
					&& posicao_do_mouse.x < 700
					&& posicao_do_mouse.y > 250
					&& posicao_do_mouse.y < 300)
				{
					menuRodando = FALSO;
					estadoDeJogo = JOGO_SINGLEPAYER;
				}

				// Menu de opcoes
				if (posicao_do_mouse.x > 450
					&& posicao_do_mouse.x < 700
					&& posicao_do_mouse.y > 300
					&& posicao_do_mouse.y < 350)
				{
					
				}

				// Sair do jogo
				if (posicao_do_mouse.x > 450
					&& posicao_do_mouse.x < 700
					&& posicao_do_mouse.y > 350
					&& posicao_do_mouse.y < 400)
				{
					menuRodando = FALSO;
					jogoRodando = FALSO;
				}
			}
		}
		// Limpa tela anterior
		SDL_RenderClear(renderer);

		// Renderiza plano de fundo
		SDL_RenderCopy(renderer, gFundo, NULL, NULL);

		//
		// Animacao das opcoes
		//

		// Iniciar jogo - animacao
		if (posicao_do_mouse.x > 450
			&& posicao_do_mouse.x < 700
			&& posicao_do_mouse.y > 250
			&& posicao_do_mouse.y < 300)
				SDL_RenderCopy(renderer, gIniciar_Jogo_pressionado, NULL, &iniciar_jogo);
		else
			SDL_RenderCopy(renderer, gIniciar_Jogo, NULL, &iniciar_jogo);

		// Menu de opcoes - animacao
		if (posicao_do_mouse.x > 450
			&& posicao_do_mouse.x < 700
			&& posicao_do_mouse.y > 300
			&& posicao_do_mouse.y < 350)
				SDL_RenderCopy(renderer, gOpcoes_pressionado, NULL, &opcoes);
		else
			SDL_RenderCopy(renderer, gOpcoes, NULL, &opcoes);

		// Sair do jogo - animacao
		if (posicao_do_mouse.x > 450
			&& posicao_do_mouse.x < 700
			&& posicao_do_mouse.y > 350
			&& posicao_do_mouse.y < 400)
				SDL_RenderCopy(renderer, gSair_pressionado, NULL, &sair);
		else
			SDL_RenderCopy(renderer, gSair, NULL, &sair);

		// Atualiza tela
		SDL_RenderPresent(renderer);
		
	}

	// Limpando memoria
	SDL_DestroyTexture(gFundo);
	SDL_DestroyTexture(gIniciar_Jogo);
	SDL_DestroyTexture(gIniciar_Jogo_pressionado);
	SDL_DestroyTexture(gOpcoes);
	SDL_DestroyTexture(gOpcoes_pressionado);
	SDL_DestroyTexture(gSair);
	SDL_DestroyTexture(gSair_pressionado);

	//
	// **********************
	// Loop do menu rodando | fim
	// **********************
	//

	// *********************************************************************


}