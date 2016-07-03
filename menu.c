// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

/*
	MENU PRINCIPAL

	Jogo de desenvolvido para projeto de computacao 1
*/
#include "main.h"
#include "config.h"
#include "base.h"

//
// VARIAVEIS GLOBAIS DO MENU
//

// Inicia na tela inicial
int modoDeMenu;
int menuRodando;

// *****************************************************************************************************************

//
// PRE CARREGAMENTO DAS FUNCOES
//

void Roda_MenuPrincipal(SDL_Renderer* renderer, SDL_Event event, Jogadores* jogadores);
void Roda_TelaInicial(SDL_Renderer* renderer, SDL_Event event);
void Roda_Escolha_de_jogadores(SDL_Renderer* renderer, SDL_Event event, Jogadores* jogadores);
void Roda_SelecaoDePersonagem_Singleplayer(SDL_Renderer* renderer, SDL_Event event, Jogadores* jogadores);
void Roda_SelecaoDePersonagem_Multiplayer(SDL_Renderer* renderer, SDL_Event event, Jogadores* jogadores);
void Roda_Opcoes(SDL_Renderer* renderer, SDL_Event event, Jogadores* jogadores);

// *********************************************************************************************************************

//
// MENU
//

void Roda_MenuPrincipal(SDL_Renderer* renderer, SDL_Event event, Jogadores* jogadores)
{
	// Inicia na tela inicial
	modoDeMenu = TELA_INICIAL;
	menuRodando = VERDADEIRO;

	// Toca musica da fundo
	Toca_Musica(MUSICA_INICIAL);

	while (menuRodando)
	{
		switch (modoDeMenu)
		{
			case TELA_INICIAL:
				Roda_TelaInicial(renderer, event);
				break;

			case OPCOES:
				Roda_Opcoes(renderer, event, jogadores);
				break;

			case QND_DE_JOGADORES:
				Toca_Musica(MUSICA_DE_SELECAO);
				Roda_Escolha_de_jogadores(renderer, event, jogadores);
				break;

			case SELECAO_DE_PERSONAGEM1:
				Roda_SelecaoDePersonagem_Singleplayer(renderer, event, jogadores);
				break;

			case SELECAO_DE_PERSONAGEM2:
				Roda_SelecaoDePersonagem_Multiplayer(renderer, event, jogadores);
				break;
		}
	}
}

// *********************************************************************************************************************

//
// TELA INICIAL
//

void Roda_TelaInicial(SDL_Renderer* renderer, SDL_Event event)
{
	// Variavel para manter menu
	int telaInicialRodando = VERDADEIRO;

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

	// Variavel para uso do som nas selecoes
	int SELECIONADO;

	#define BOTAO_INICIAR_JOGO		1
	#define BOTAO_OPCOES			2
	#define BOTAO_SAIR				3

	SELECIONADO = BOTAO_INICIAR_JOGO;

	// Loop do jogo

	while(telaInicialRodando)
	{

		// Salva posicao do mouse
		struct POSICAO_DO_MOUSE
		{
			int x, y;
		}posicao_do_mouse;

		SDL_GetMouseState(&posicao_do_mouse.x, &posicao_do_mouse.y);

		// ***********************************************************************

		// Limpa tela anterior
		SDL_RenderClear(renderer);

		// Renderiza plano de fundo
		SDL_RenderCopy(renderer, gFundo, NULL, NULL);

		//
		// Animacao das opcoes
		//

		// Iniciar jogo - animacao
		if ((posicao_do_mouse.x > 465
			&& posicao_do_mouse.x < 685
			&& posicao_do_mouse.y > 250
			&& posicao_do_mouse.y < 300)
			|| SELECIONADO == BOTAO_INICIAR_JOGO)
		{
			SDL_RenderCopy(renderer, gIniciar_Jogo_pressionado, NULL, &iniciar_jogo);

			// Animacao de som
			if (SELECIONADO != BOTAO_INICIAR_JOGO)
				Efeito_Sonoro(CLICK);
			SELECIONADO = BOTAO_INICIAR_JOGO;
		}
		else
			SDL_RenderCopy(renderer, gIniciar_Jogo, NULL, &iniciar_jogo);

		// Menu de opcoes - animacao
		if ((posicao_do_mouse.x > 500
			&& posicao_do_mouse.x < 650
			&& posicao_do_mouse.y > 300
			&& posicao_do_mouse.y < 350)
			|| SELECIONADO == BOTAO_OPCOES)
		{
			SDL_RenderCopy(renderer, gOpcoes_pressionado, NULL, &opcoes);

			// Animacao de som
			if (SELECIONADO != BOTAO_OPCOES)
				Efeito_Sonoro(CLICK);
			SELECIONADO = BOTAO_OPCOES;
		}
		else
			SDL_RenderCopy(renderer, gOpcoes, NULL, &opcoes);

		// Sair do jogo - animacao
		if ((posicao_do_mouse.x > 535
			&& posicao_do_mouse.x < 620
			&& posicao_do_mouse.y > 350
			&& posicao_do_mouse.y < 400)
			|| SELECIONADO == BOTAO_SAIR)
		{
			SDL_RenderCopy(renderer, gSair_pressionado, NULL, &sair);

			// Animacao de som
			if (SELECIONADO != BOTAO_SAIR)
				Efeito_Sonoro(CLICK);
			SELECIONADO = BOTAO_SAIR;
		}
		else
			SDL_RenderCopy(renderer, gSair, NULL, &sair);

		// ***********************************************************************

		// Verifica eventos
		if (SDL_PollEvent (&event))
		{
			// Finaliza o jogo
			if (event.type == SDL_QUIT)
			{
				menuRodando = FALSO;
				telaInicialRodando = FALSO;
				mainRodando = FALSO;
			}

			//
			// Eventos de tecla pressionada
			//
			if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)
				{
					case SDLK_UP:
						switch (SELECIONADO)
						{
							case BOTAO_INICIAR_JOGO:
								break;

							case BOTAO_OPCOES:
								SELECIONADO = BOTAO_INICIAR_JOGO;
								Efeito_Sonoro(CLICK);
								break;

							case BOTAO_SAIR:
								SELECIONADO = BOTAO_OPCOES;
								Efeito_Sonoro(CLICK);
								break;
						}
						break;

					case SDLK_DOWN:
						switch (SELECIONADO)
						{
							case BOTAO_INICIAR_JOGO:
								SELECIONADO = BOTAO_OPCOES;
								Efeito_Sonoro(CLICK);
								break;

							case BOTAO_OPCOES:
								SELECIONADO = BOTAO_SAIR;
								Efeito_Sonoro(CLICK);
								break;

							case BOTAO_SAIR:
							break;
						}
						break;

					case SDLK_RETURN:
						switch (SELECIONADO)
						{
							case BOTAO_INICIAR_JOGO:
								Efeito_Sonoro(SELECT);
								SDL_Delay(400); // Delay de 0.4 segundos
								telaInicialRodando = FALSO;
								modoDeMenu = QND_DE_JOGADORES;
								break;

							case BOTAO_OPCOES:
								Efeito_Sonoro(SELECT);
								break;

							case BOTAO_SAIR:
								Efeito_Sonoro(VOLTAR);
								SDL_Delay(500); // Delay de 0.5 segundos
								menuRodando = FALSO;
								telaInicialRodando = FALSO;
								mainRodando = FALSO;
								break;
						}
						break;
				}
			}

			//
			// Eventos de clique do mouse
			//

			SDL_GetMouseState(&posicao_do_mouse.x, &posicao_do_mouse.y);

			if (event.type == SDL_MOUSEBUTTONDOWN)
			{

				//
				// Acoes
				//

				// Iniciar jogo
				if (posicao_do_mouse.x > 465
					&& posicao_do_mouse.x < 685
					&& posicao_do_mouse.y > 250
					&& posicao_do_mouse.y < 300)
				{
					Efeito_Sonoro(SELECT);
					SDL_Delay(300); // Delay de 0.4 segundos
					telaInicialRodando = FALSO;
					modoDeMenu = QND_DE_JOGADORES;
				}

				// Menu de opcoes
				if (posicao_do_mouse.x > 500
					&& posicao_do_mouse.x < 650
					&& posicao_do_mouse.y > 300
					&& posicao_do_mouse.y < 350)
				{
					Efeito_Sonoro(SELECT);
					SDL_Delay(400); // Delay de 0.4 segundos
				}

				// Sair do jogo
				if (posicao_do_mouse.x > 535
					&& posicao_do_mouse.x < 620
					&& posicao_do_mouse.y > 350
					&& posicao_do_mouse.y < 400)
				{
					Efeito_Sonoro(VOLTAR);
					SDL_Delay(400); // Delay de 0.5 segundos
					menuRodando = FALSO;
					telaInicialRodando = FALSO;
					mainRodando = FALSO;
				}
			}
		}
		
		// Atualiza tela
		SDL_RenderPresent(renderer);

		// FPS
		SDL_Delay( 1000/FPS );
		
	}

	// Limpando memoria - imagens
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

// *********************************************************************************************************************

//
// QUANTIDADE DE JOGADORES
//

void Roda_Escolha_de_jogadores(SDL_Renderer* renderer, SDL_Event event, Jogadores* jogadores)
{
	// Variavel para manter menu
	int escolhaDeJogadoresRodando = VERDADEIRO;

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
	// ***********
	// 1 JOGADOR | inicio
	// ***********
	//

	// Variavel que carrega a opcao de iniciar o jogo
	SDL_Texture* g1Jogador = NULL;

	// Carregando plano de fundo na memoria
	Loading_Surf = IMG_Load("arte/menu/1_jogador.png");

	// Carregando imagem na tela
	g1Jogador = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf);

	// Limpando memoria
	SDL_FreeSurface(Loading_Surf);

	// Variavel que carrega a opcao de iniciar o jogo pressionado
	SDL_Texture* g1Jogador_pressionado = NULL;

	// Carregando plano de fundo na memoria
	Loading_Surf = IMG_Load("arte/menu/1_jogador_pressionado.png");

	// Carregando imagem na tela
	g1Jogador_pressionado = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf);

	// Limpando memoria
	SDL_FreeSurface(Loading_Surf);

	// Declarando rect
	SDL_Rect iniciar_jogo;

	iniciar_jogo.x = 275;
	iniciar_jogo.y = 250;
	iniciar_jogo.w = 250;
	iniciar_jogo.h = 50;

	//
	// ***********
	// 1 JOGADOR | fim
	// ***********
	//

	// *********************************************************************

	//
	// *************
	// 2 JOGADORES | inicio
	// *************
	//

	// Variavel que carrega a opcao do menu de opcoes
	SDL_Texture* g2Jogadores = NULL;

	// Carregando plano de fundo na memoria
	Loading_Surf = IMG_Load("arte/menu/2_jogadores.png");

	// Carregando imagem na tela
	g2Jogadores = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf);

	// Limpando memoria
	SDL_FreeSurface(Loading_Surf);

	// Variavel que carrega a opcao do menu de opcoes pressionado
	SDL_Texture* g2Jogadores_pressionado = NULL;

	// Carregando plano de fundo na memoria
	Loading_Surf = IMG_Load("arte/menu/2_jogadores_presionado.png");

	// Carregando imagem na tela
	g2Jogadores_pressionado = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf);

	// Limpando memoria
	SDL_FreeSurface(Loading_Surf);

	// Declarando rect
	SDL_Rect opcoes;

	opcoes.x = 275;
	opcoes.y = 300;
	opcoes.w = 250;
	opcoes.h = 50;

	//
	// *************
	// 2 JOGADORES | fim
	// *************
	//

	// *********************************************************************

	//
	// **********************
	// Loop do menu rodando | inicio
	// **********************
	//

	// Variavel para uso do som nas selecoes
	int SELECIONADO;

	#define BOTAO_1JOGADOR		1
	#define BOTAO_2JOGADORES	2

	SELECIONADO = BOTAO_1JOGADOR;

	// Loop

	while(escolhaDeJogadoresRodando)
	{

		// Salva posicao do mouse
		struct POSICAO_DO_MOUSE
		{
			int x, y;
		}posicao_do_mouse;

		SDL_GetMouseState(&posicao_do_mouse.x, &posicao_do_mouse.y);

		// ************************************************************

		// Limpa tela anterior
		SDL_RenderClear(renderer);

		// Renderiza plano de fundo
		SDL_RenderCopy(renderer, gFundo, NULL, NULL);

		//
		// Animacao das opcoes
		//

		// 1 Jogador - animacao
		if ((posicao_do_mouse.x > 310
			&& posicao_do_mouse.x < 500
			&& posicao_do_mouse.y > 250
			&& posicao_do_mouse.y < 300)
			|| SELECIONADO == BOTAO_1JOGADOR)
		{
			SDL_RenderCopy(renderer, g1Jogador_pressionado, NULL, &iniciar_jogo);
			
			// Animacao de som
			if (SELECIONADO != BOTAO_1JOGADOR)
				Efeito_Sonoro(CLICK);
			SELECIONADO = BOTAO_1JOGADOR;
		}
		else
			SDL_RenderCopy(renderer, g1Jogador, NULL, &iniciar_jogo);

		// 2 Jogadores - animacao
		if ((posicao_do_mouse.x > 285
			&& posicao_do_mouse.x < 520
			&& posicao_do_mouse.y > 300
			&& posicao_do_mouse.y < 350)
			|| SELECIONADO == BOTAO_2JOGADORES)
		{
			SDL_RenderCopy(renderer, g2Jogadores_pressionado, NULL, &opcoes);

			// Animacao de som
			if (SELECIONADO != BOTAO_2JOGADORES)
				Efeito_Sonoro(CLICK);
			SELECIONADO = BOTAO_2JOGADORES;
		}
		else
			SDL_RenderCopy(renderer, g2Jogadores, NULL, &opcoes);

		// ************************************************************

		// Verifica eventos
		if (SDL_PollEvent (&event))
		{
			// Finaliza o jogo
			if (event.type == SDL_QUIT)
			{
				menuRodando = FALSO;
				escolhaDeJogadoresRodando = FALSO;
				mainRodando = FALSO;
			}

			//
			// Eventos de tecla pressionada
			//
			if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						Efeito_Sonoro(VOLTAR);
						SDL_Delay(400); // Delay de 0.4 segundos
						modoDeMenu = TELA_INICIAL;
						escolhaDeJogadoresRodando = FALSO;
						Toca_Musica(MUSICA_INICIAL);
						break;

					case SDLK_UP:
						switch (SELECIONADO)
						{
							case BOTAO_1JOGADOR:
								break;

							case BOTAO_2JOGADORES:
								SELECIONADO = BOTAO_1JOGADOR;
								Efeito_Sonoro(CLICK);
								break;
						}
						break;

					case SDLK_DOWN:
						switch (SELECIONADO)
						{
							case BOTAO_1JOGADOR:
								SELECIONADO = BOTAO_2JOGADORES;
								Efeito_Sonoro(CLICK);
								break;

							case BOTAO_2JOGADORES:
								break;
						}
						break;

					case SDLK_RETURN:
						switch (SELECIONADO)
						{
							case BOTAO_1JOGADOR:
								Efeito_Sonoro(SELECT);
								SDL_Delay(400); // Delay de 0.4 segundos
								jogadores->quantidade = 1;
								menuRodando = FALSO;
								escolhaDeJogadoresRodando = FALSO;
								estadoDeJogo = JOGO;
								break;

							case BOTAO_2JOGADORES:
								Efeito_Sonoro(SELECT);
								SDL_Delay(400); // Delay de 0.4 segundos
								jogadores->quantidade = 2;
								menuRodando = FALSO;
								escolhaDeJogadoresRodando = FALSO;
								estadoDeJogo = JOGO;
								break;
						}
						break;
				}
			}

			//
			// Eventos de clique do mouse
			//

			if (event.type == SDL_MOUSEBUTTONDOWN)
			{

				//
				// Acoes
				//

				// 1 Jogador
				if (posicao_do_mouse.x > 310
					&& posicao_do_mouse.x < 500
					&& posicao_do_mouse.y > 250
					&& posicao_do_mouse.y < 300)
				{
					Efeito_Sonoro(SELECT);
					SDL_Delay(400); // Delay de 0.4 segundos
					jogadores->quantidade = 1;
					menuRodando = FALSO;
					escolhaDeJogadoresRodando = FALSO;
					estadoDeJogo = JOGO;
				}

				// 2 Jogadores
				if (posicao_do_mouse.x > 285
					&& posicao_do_mouse.x < 520
					&& posicao_do_mouse.y > 300
					&& posicao_do_mouse.y < 350)
				{
					Efeito_Sonoro(SELECT);
					SDL_Delay(400); // Delay de 0.4 segundos
					jogadores->quantidade = 2;
					menuRodando = FALSO;
					escolhaDeJogadoresRodando = FALSO;
					estadoDeJogo = JOGO;
				}
			}
		}
		
		// Atualiza tela
		SDL_RenderPresent(renderer);

		// FPS
		SDL_Delay( 1000/FPS );
		
	}

	// Limpando memoria - imagens
	SDL_DestroyTexture(gFundo);
	SDL_DestroyTexture(g1Jogador);
	SDL_DestroyTexture(g1Jogador_pressionado);
	SDL_DestroyTexture(g2Jogadores);
	SDL_DestroyTexture(g2Jogadores_pressionado);


	//
	// **********************
	// Loop do menu rodando | fim
	// **********************
	//

	// *********************************************************************
}

// *********************************************************************************************************************

//
// SELECAO DE PERSONAGENS
//

// SINGLEPLAYER
void Roda_SelecaoDePersonagem_Singleplayer(SDL_Renderer* renderer, SDL_Event event, Jogadores* jogadores)
{

}

// MULTIPLAYER
void Roda_SelecaoDePersonagem_Multiplayer(SDL_Renderer* renderer, SDL_Event event, Jogadores* jogadores)
{

}

// *********************************************************************************************************************

//
// OPCOES
//

void Roda_Opcoes(SDL_Renderer* renderer, SDL_Event event, Jogadores* jogadores)
{

}

// *********************************************************************************************************************

// FIM