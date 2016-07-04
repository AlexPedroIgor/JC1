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

Status mago, arqueiro;
Ranking ranking;

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

	// CARREGA STATUS E RANKING
	DATA_Carrega_Informacoes(&mago, &arqueiro, &ranking);

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
								modoDeMenu = SELECAO_DE_PERSONAGEM1;
								escolhaDeJogadoresRodando = FALSO;
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
					modoDeMenu = SELECAO_DE_PERSONAGEM1;
					escolhaDeJogadoresRodando = FALSO;
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
	// Variavel para manter menu
	int selecaoSPRodando = VERDADEIRO;

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
	// ******
	// MAGE | inicio
	// ******
	//

	// Variavel que carrega a opcao de iniciar o jogo
	SDL_Texture* gMage = NULL;

	// Carregando plano de fundo na memoria
	Loading_Surf = IMG_Load("arte/menu/Mage W Selecao.png");

	SDL_SetColorKey(Loading_Surf, 1, SDL_MapRGB(Loading_Surf->format, 255, 255, 255));

	// Carregando imagem na tela
	gMage = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf);

	// Limpando memoria
	SDL_FreeSurface(Loading_Surf);

	// Declarando rect
	SDL_Rect mage, select_mage;

	mage.x = 68;
	mage.y = 93;
	mage.w = 100;
	mage.h = 150;

	select_mage.x = 75;
	select_mage.y = 95;
	select_mage.w = 90;
	select_mage.h = 140;

	//
	// ******
	// Mage | fim
	// ******
	//

	// *********************************************************************

	//
	// ********
	// ARCHER | inicio
	// ********
	//

	// Variavel que carrega a opcao do menu de opcoes
	SDL_Texture* gArcher = NULL;

	// Carregando plano de fundo na memoria
	Loading_Surf = IMG_Load("arte/menu/Archer W Selecao.png");

	SDL_SetColorKey(Loading_Surf, 1, SDL_MapRGB(Loading_Surf->format, 255, 255, 255));

	// Carregando imagem na tela
	gArcher = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf);

	// Limpando memoria
	SDL_FreeSurface(Loading_Surf);

	// Declarando rect
	SDL_Rect archer, select_archer;

	archer.x = 470;
	archer.y = 90;
	archer.w = 100;
	archer.h = 150;

	select_archer.x = 480;
	select_archer.y = 95;
	select_archer.w = 90;
	select_archer.h = 140;

	//
	// ********
	// ARCHER | fim
	// ********
	//


	// *********************************************************************

	//
	// ********
	// SELECAO | inicio
	// ********
	//

	// VERMELHO

	SDL_Texture* gSelecao_v = NULL; // Variavel que carrega a opcao do menu de opcoes

	Loading_Surf = IMG_Load("arte/menu/Selecao-vermelho.png"); // Carregando plano de fundo na memoria
	
	gSelecao_v = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf); // Carregando imagem na tela

	SDL_FreeSurface(Loading_Surf); // Limpando memoria

	// BRANCO
	
	SDL_Texture* gSelecao_b = NULL; // Variavel que carrega a opcao do menu de opcoes

	
	Loading_Surf = IMG_Load("arte/menu/Selecao-branco.png"); // Carregando plano de fundo na memoria

	gSelecao_b = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf); // Carregando imagem na tela

	SDL_FreeSurface(Loading_Surf); // Limpando memoria

	// PRETO

	SDL_Texture* gSelecao_p = NULL; // Variavel que carrega a opcao do menu de opcoes pressionado

	
	Loading_Surf = IMG_Load("arte/menu/Selecao-preto.png"); // Carregando plano de fundo na memoria

	gSelecao_p = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf); // Carregando imagem na tela

	SDL_FreeSurface(Loading_Surf); // Limpando memoria

	SDL_Rect selecao1, selecao2; // Declarando rect

	// AMARELO
	
	SDL_Texture* gSelecao_a = NULL; // Variavel que carrega a opcao do menu de opcoes

	
	Loading_Surf = IMG_Load("arte/menu/Selecao-amarelo.png"); // Carregando plano de fundo na memoria

	gSelecao_a = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf); // Carregando imagem na tela

	SDL_FreeSurface(Loading_Surf); // Limpando memoria

	selecao1.x = 55;
	selecao1.y = 75;
	selecao1.w = 300;
	selecao1.h = 350;

	selecao2.x = 450;
	selecao2.y = 75;
	selecao2.w = 300;
	selecao2.h = 350;

	//
	// ********
	// SELECAO | fim
	// ********
	//

	// *********************************************************************

	//
	// *******
	// TEXTO | inicio
	// *******
	//

	// COR DO TEXTO
	SDL_Color cor_do_texto1 = {178,34,34}; // Cor: Firebrick
	SDL_Color cor_do_texto2 = {245,245,220}; // Cor: Beige
	int grava_texto; // auxiliar para escrita de texto
	char texto_auxiliar[3];

	// CLASSE

	Texto tClasse;

	tClasse.mensagem = "Classe: \0";

	Loading_Surf = TTF_RenderText_Blended (Fonte1,
											tClasse.mensagem,
											cor_do_texto1);

	tClasse.textura = SDL_CreateTextureFromSurface(renderer, Loading_Surf);

	SDL_FreeSurface(Loading_Surf);

	tClasse.posicao1.x = 190;
	tClasse.posicao1.y = 105;
	tClasse.posicao1.w = 60;
	tClasse.posicao1.h = 20;

	tClasse.posicao2.x = 585;
	tClasse.posicao2.y = 105;
	tClasse.posicao2.w = 60;
	tClasse.posicao2.h = 20;

	// *********************************************************************

	// MAGE OU ARCHER

	Texto tMage, tArcher;

	tMage.mensagem = "Mago\0";

	tArcher.mensagem = "Arqueiro\0";

	Loading_Surf = TTF_RenderText_Solid (Fonte1,
											tMage.mensagem,
											cor_do_texto2);

	tMage.textura = SDL_CreateTextureFromSurface(renderer, Loading_Surf);

	SDL_FreeSurface(Loading_Surf);

	Loading_Surf = TTF_RenderText_Solid (Fonte1,
											tArcher.mensagem,
											cor_do_texto2);

	tArcher.textura = SDL_CreateTextureFromSurface(renderer, Loading_Surf);

	SDL_FreeSurface(Loading_Surf);

	tMage.posicao1.x = 252;
	tMage.posicao1.y = 105;
	tMage.posicao1.w = 45;
	tMage.posicao1.h = 20;

	tArcher.posicao2.x = 647;
	tArcher.posicao2.y = 105;
	tArcher.posicao2.w = 70;
	tArcher.posicao2.h = 20;

	// FORCA

	Texto tForca;

	tForca.mensagem = "For: \0";

	Loading_Surf = TTF_RenderText_Blended (Fonte1,
											tForca.mensagem,
											cor_do_texto1);

	tForca.textura = SDL_CreateTextureFromSurface(renderer, Loading_Surf);

	SDL_FreeSurface(Loading_Surf);

	tForca.posicao1.x = 210;
	tForca.posicao1.y = 130;
	tForca.posicao1.w = 40;
	tForca.posicao1.h = 20;

	tForca.posicao2.x = 605;
	tForca.posicao2.y = 130;
	tForca.posicao2.w = 40;
	tForca.posicao2.h = 20;

	// VALOR DA FORCA

	Texto tValorFor1, tValorFor2;

	tValorFor1.valor_numerico = mago.forca;
	tValorFor2.valor_numerico = arqueiro.forca;

	grava_texto = sprintf(texto_auxiliar, "%d", tValorFor1.valor_numerico);
	Loading_Surf = TTF_RenderText_Blended (Fonte2,
											texto_auxiliar,
												cor_do_texto2);
	tValorFor1.textura = SDL_CreateTextureFromSurface(renderer, Loading_Surf);
	SDL_FreeSurface(Loading_Surf);

	grava_texto = sprintf(texto_auxiliar, "%d", tValorFor2.valor_numerico);
	Loading_Surf = TTF_RenderText_Blended (Fonte2,
											texto_auxiliar,
												cor_do_texto2);
	tValorFor2.textura = SDL_CreateTextureFromSurface(renderer, Loading_Surf);
	SDL_FreeSurface(Loading_Surf);

	tValorFor1.posicao1.x = 252;
	tValorFor1.posicao1.y = 130;
	tValorFor1.posicao1.w = 17;
	tValorFor1.posicao1.h = 20;

	tValorFor2.posicao2.x = 647;
	tValorFor2.posicao2.y = 130;
	tValorFor2.posicao2.w = 17;
	tValorFor2.posicao2.h = 20;

	// DESTREZA

	Texto tDestreza;

	tDestreza.mensagem = "Des: \0";

	Loading_Surf = TTF_RenderText_Blended (Fonte1,
											tDestreza.mensagem,
											cor_do_texto1);

	tDestreza.textura = SDL_CreateTextureFromSurface(renderer, Loading_Surf);

	SDL_FreeSurface(Loading_Surf);

	tDestreza.posicao1.x = 210;
	tDestreza.posicao1.y = 155;
	tDestreza.posicao1.w = 40;
	tDestreza.posicao1.h = 20;

	tDestreza.posicao2.x = 605;
	tDestreza.posicao2.y = 155;
	tDestreza.posicao2.w = 40;
	tDestreza.posicao2.h = 20;

	// VALOR DA DESTREZA

	Texto tValorDes1, tValorDes2;

	tValorDes1.valor_numerico = 10;
	tValorDes2.valor_numerico = 16;

	grava_texto = sprintf(texto_auxiliar, "%d", tValorDes1.valor_numerico);
	Loading_Surf = TTF_RenderText_Blended (Fonte2,
											texto_auxiliar,
												cor_do_texto2);
	tValorDes1.textura = SDL_CreateTextureFromSurface(renderer, Loading_Surf);

	SDL_FreeSurface(Loading_Surf);
	grava_texto = sprintf(texto_auxiliar, "%d", tValorDes2.valor_numerico);
	Loading_Surf = TTF_RenderText_Blended (Fonte2,
											texto_auxiliar,
												cor_do_texto2);
	tValorDes2.textura = SDL_CreateTextureFromSurface(renderer, Loading_Surf);
	SDL_FreeSurface(Loading_Surf);

	tValorDes1.posicao1.x = 252;
	tValorDes1.posicao1.y = 155;
	tValorDes1.posicao1.w = 17;
	tValorDes1.posicao1.h = 20;

	tValorDes2.posicao2.x = 647;
	tValorDes2.posicao2.y = 155;
	tValorDes2.posicao2.w = 17;
	tValorDes2.posicao2.h = 20;

	// INTELIGENCIA

	Texto tInteligencia;

	tInteligencia.mensagem = "Int: \0";

	Loading_Surf = TTF_RenderText_Blended (Fonte1,
											tInteligencia.mensagem,
											cor_do_texto1);

	tInteligencia.textura = SDL_CreateTextureFromSurface(renderer, Loading_Surf);

	SDL_FreeSurface(Loading_Surf);

	tInteligencia.posicao1.x = 210;
	tInteligencia.posicao1.y = 180;
	tInteligencia.posicao1.w = 40;
	tInteligencia.posicao1.h = 20;

	tInteligencia.posicao2.x = 605;
	tInteligencia.posicao2.y = 180;
	tInteligencia.posicao2.w = 40;
	tInteligencia.posicao2.h = 20;

	// VALOR DA INTELIGENCIA

	Texto tValorInt1, tValorInt2;

	tValorInt1.valor_numerico = 17;
	tValorInt2.valor_numerico = 10;

	grava_texto = sprintf(texto_auxiliar, "%d", tValorInt1.valor_numerico);
	Loading_Surf = TTF_RenderText_Blended (Fonte2,
											texto_auxiliar,
												cor_do_texto2);
	tValorInt1.textura = SDL_CreateTextureFromSurface(renderer, Loading_Surf);

	SDL_FreeSurface(Loading_Surf);
	grava_texto = sprintf(texto_auxiliar, "%d", tValorInt2.valor_numerico);
	Loading_Surf = TTF_RenderText_Blended (Fonte2,
											texto_auxiliar,
												cor_do_texto2);
	tValorInt2.textura = SDL_CreateTextureFromSurface(renderer, Loading_Surf);
	SDL_FreeSurface(Loading_Surf);

	tValorInt1.posicao1.x = 252;
	tValorInt1.posicao1.y = 180;
	tValorInt1.posicao1.w = 17;
	tValorInt1.posicao1.h = 20;

	tValorInt2.posicao2.x = 647;
	tValorInt2.posicao2.y = 180;
	tValorInt2.posicao2.w = 17;
	tValorInt2.posicao2.h = 20;

	// CONSTITUICAO

	Texto tConstituicao;

	tConstituicao.mensagem = "Con: \0";

	Loading_Surf = TTF_RenderText_Blended (Fonte1,
											tConstituicao.mensagem,
											cor_do_texto1);

	tConstituicao.textura = SDL_CreateTextureFromSurface(renderer, Loading_Surf);

	SDL_FreeSurface(Loading_Surf);

	tConstituicao.posicao1.x = 210;
	tConstituicao.posicao1.y = 205;
	tConstituicao.posicao1.w = 40;
	tConstituicao.posicao1.h = 20;

	tConstituicao.posicao2.x = 605;
	tConstituicao.posicao2.y = 205;
	tConstituicao.posicao2.w = 40;
	tConstituicao.posicao2.h = 20;

	// VALOR DA CONSTITUICAO

	Texto tValorCon1, tValorCon2;

	tValorCon1.valor_numerico = 15;
	tValorCon2.valor_numerico = 12;

	grava_texto = sprintf(texto_auxiliar, "%d", tValorCon1.valor_numerico);
	Loading_Surf = TTF_RenderText_Blended (Fonte2,
											texto_auxiliar,
												cor_do_texto2);
	tValorCon1.textura = SDL_CreateTextureFromSurface(renderer, Loading_Surf);

	SDL_FreeSurface(Loading_Surf);
	grava_texto = sprintf(texto_auxiliar, "%d", tValorCon2.valor_numerico);
	Loading_Surf = TTF_RenderText_Blended (Fonte2,
											texto_auxiliar,
												cor_do_texto2);
	tValorCon2.textura = SDL_CreateTextureFromSurface(renderer, Loading_Surf);
	SDL_FreeSurface(Loading_Surf);

	tValorCon1.posicao1.x = 252;
	tValorCon1.posicao1.y = 205;
	tValorCon1.posicao1.w = 17;
	tValorCon1.posicao1.h = 20;

	tValorCon2.posicao2.x = 647;
	tValorCon2.posicao2.y = 205;
	tValorCon2.posicao2.w = 17;
	tValorCon2.posicao2.h = 20;

	// NIVEL

	Texto tLVL;

	tLVL.mensagem = "Level: \0";

	Loading_Surf = TTF_RenderText_Blended (Fonte1,
											tLVL.mensagem,
											cor_do_texto1);

	tLVL.textura = SDL_CreateTextureFromSurface(renderer, Loading_Surf);

	SDL_FreeSurface(Loading_Surf);

	tLVL.posicao1.x = 85;
	tLVL.posicao1.y = 240;
	tLVL.posicao1.w = 50;
	tLVL.posicao1.h = 20;

	tLVL.posicao2.x = 495;
	tLVL.posicao2.y = 240;
	tLVL.posicao2.w = 50;
	tLVL.posicao2.h = 20;

	// VALOR DO NIVEL

	Texto tValorLVL;

	tValorLVL.valor_numerico = 1;

	grava_texto = sprintf(texto_auxiliar, "%d", tValorLVL.valor_numerico);

	Loading_Surf = TTF_RenderText_Blended (Fonte2,
											texto_auxiliar,
											cor_do_texto2);

	tValorLVL.textura = SDL_CreateTextureFromSurface(renderer, Loading_Surf);

	SDL_FreeSurface(Loading_Surf);

	tValorLVL.posicao1.x = 135;
	tValorLVL.posicao1.y = 240;
	tValorLVL.posicao1.w = 10;
	tValorLVL.posicao1.h = 20;

	tValorLVL.posicao2.x = 545;
	tValorLVL.posicao2.y = 240;
	tValorLVL.posicao2.w = 10;
	tValorLVL.posicao2.h = 20;

	//
	// *******
	// TEXTO | fim
	// *******
	//

	SDL_Texture* nome_escrito;
	SDL_Rect posicao_do_nome;

	posicao_do_nome.x = 50;
	posicao_do_nome.y = 500;
	posicao_do_nome.w = 500;
	posicao_do_nome.h = 20;

	// *********************************************************************

	//
	// **********************
	// Loop do menu rodando | inicio
	// **********************
	//

	// Variavel para uso do som nas selecoes
	int SELECIONADO, SELECAO2;

	#define BOTAO_MAGE					1
	#define BOTAO_ARCHER				2
	#define PERSONAGEM_ESCOLHIDO		3

	SELECIONADO = BOTAO_MAGE;

	// Loop

	while(selecaoSPRodando)
	{
		// ***************************************************************************

		// Salva posicao do mouse
		struct POSICAO_DO_MOUSE
		{
			int x, y;
		}posicao_do_mouse;

		SDL_GetMouseState(&posicao_do_mouse.x, &posicao_do_mouse.y);

		//printf("X: %d\nY: %d\n", posicao_do_mouse.x, posicao_do_mouse.y);

		// ************************************************************

		// Limpa tela anterior
		SDL_RenderClear(renderer);

		// Renderiza plano de fundo
		SDL_RenderCopy(renderer, gFundo, NULL, NULL);

		// ********************************************************************************

		//
		// JOGADOR ESCREVE O NOME
		//

		if (SELECIONADO == PERSONAGEM_ESCOLHIDO)
			Texto_em_Tela_Nome_do_Personagem(renderer, event);

		// **********************************************************************************

		//
		// Animacao das opcoes
		//

		// MAGE - animacao
		if (((posicao_do_mouse.x > 65
					&& posicao_do_mouse.x < 350
					&& posicao_do_mouse.y > 85
					&& posicao_do_mouse.y < 420)
					|| SELECIONADO == BOTAO_MAGE)
						&& SELECIONADO != PERSONAGEM_ESCOLHIDO)
		{
			SDL_RenderCopy(renderer, gSelecao_v, NULL, &selecao1);
			
			// Animacao de som
			if (SELECIONADO != BOTAO_MAGE)
				Efeito_Sonoro(CLICK);
					SELECIONADO = BOTAO_MAGE;
		}
		else
		{
			if (SELECIONADO == PERSONAGEM_ESCOLHIDO && SELECAO2 == BOTAO_MAGE)
				SDL_RenderCopy(renderer, gSelecao_a, NULL, &selecao1);
			else
				SDL_RenderCopy(renderer, gSelecao_p, NULL, &selecao1);
		}

		// ARCHER - animacao
		if (((posicao_do_mouse.x > 460
					&& posicao_do_mouse.x < 745
					&& posicao_do_mouse.y > 85
					&& posicao_do_mouse.y < 420)
					|| SELECIONADO == BOTAO_ARCHER)
						&& SELECIONADO != PERSONAGEM_ESCOLHIDO)
		{
			SDL_RenderCopy(renderer, gSelecao_v, NULL, &selecao2);

			// Animacao de som
			if (SELECIONADO != BOTAO_ARCHER)
				Efeito_Sonoro(CLICK);
			SELECIONADO = BOTAO_ARCHER;
		}
		else
		{
			if (SELECIONADO == PERSONAGEM_ESCOLHIDO && SELECAO2 == BOTAO_ARCHER)
				SDL_RenderCopy(renderer, gSelecao_a, NULL, &selecao2);
			else
				SDL_RenderCopy(renderer, gSelecao_p, NULL, &selecao2);
		}

		// ********************************************************************************

		//
		// PERSONAGENS
		//

		SDL_RenderCopy(renderer, gSelecao_b, NULL, &select_mage);
		SDL_RenderCopy(renderer, gSelecao_b, NULL, &select_archer);

		SDL_RenderCopy(renderer, gMage, NULL, &mage);
		SDL_RenderCopy(renderer, gArcher, NULL, &archer);

		
		// *********************************************************************************

		//
		// TEXTOS
		//

		SDL_RenderCopy(renderer, tClasse.textura, NULL, &tClasse.posicao1); // classe:
		SDL_RenderCopy(renderer, tClasse.textura, NULL, &tClasse.posicao2); // classe:
		SDL_RenderCopy(renderer, tMage.textura, NULL, &tMage.posicao1); // mage
		SDL_RenderCopy(renderer, tArcher.textura, NULL, &tArcher.posicao2); // archer
		SDL_RenderCopy(renderer, tForca.textura, NULL, &tForca.posicao1); // forca:
		SDL_RenderCopy(renderer, tValorFor1.textura, NULL, &tValorFor1.posicao1); // valor forca
		SDL_RenderCopy(renderer, tForca.textura, NULL, &tForca.posicao2); // forca:
		SDL_RenderCopy(renderer, tValorFor2.textura, NULL, &tValorFor2.posicao2); // valor forca
		SDL_RenderCopy(renderer, tDestreza.textura, NULL, &tDestreza.posicao1); // destreza:
		SDL_RenderCopy(renderer, tValorDes1.textura, NULL, &tValorDes1.posicao1); // valor destreza
		SDL_RenderCopy(renderer, tDestreza.textura, NULL, &tDestreza.posicao2); // destreza:
		SDL_RenderCopy(renderer, tValorDes2.textura, NULL, &tValorDes2.posicao2); // valor destreza
		SDL_RenderCopy(renderer, tInteligencia.textura, NULL, &tInteligencia.posicao1); // inteligencia:
		SDL_RenderCopy(renderer, tValorInt1.textura, NULL, &tValorInt1.posicao1); // valor da int
		SDL_RenderCopy(renderer, tInteligencia.textura, NULL, &tInteligencia.posicao2); // inteligencia:
		SDL_RenderCopy(renderer, tValorInt2.textura, NULL, &tValorInt2.posicao2); // valor da int
		SDL_RenderCopy(renderer, tConstituicao.textura, NULL, &tConstituicao.posicao1); // constituicao:
		SDL_RenderCopy(renderer, tValorCon1.textura, NULL, &tValorCon1.posicao1); // valor da con
		SDL_RenderCopy(renderer, tConstituicao.textura, NULL, &tConstituicao.posicao2); // constituicao:
		SDL_RenderCopy(renderer, tValorCon2.textura, NULL, &tValorCon2.posicao2); // valor da con
		SDL_RenderCopy(renderer, tLVL.textura, NULL, &tLVL.posicao1); // level:
		SDL_RenderCopy(renderer, tValorLVL.textura, NULL, &tValorLVL.posicao1); // valor level
		SDL_RenderCopy(renderer, tLVL.textura, NULL, &tLVL.posicao2); // level:
		SDL_RenderCopy(renderer, tValorLVL.textura, NULL, &tValorLVL.posicao2); // valor level

		// *************************************************************************************

		// Verifica eventos
		if (SDL_PollEvent (&event))
		{
			// Finaliza o jogo
			if (event.type == SDL_QUIT)
			{
				menuRodando = FALSO;
				selecaoSPRodando = FALSO;
				mainRodando = FALSO;
			}

			// ************************************************************

			

			// ********************************************************

			//
			// TECLA PRESSIONADA
			//
			if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						if (SELECIONADO == PERSONAGEM_ESCOLHIDO)
						{
							Efeito_Sonoro(VOLTAR);
							SELECAO2 = FALSO;
							SELECIONADO = BOTAO_MAGE;
						}
						else
						{
							Efeito_Sonoro(VOLTAR);
							SDL_Delay(400); // Delay de 0.4 segundos
							modoDeMenu = QND_DE_JOGADORES;
							selecaoSPRodando = FALSO;
							Toca_Musica(MUSICA_INICIAL);
						}
						break;

					case SDLK_LEFT:
						switch (SELECIONADO)
						{
							case BOTAO_MAGE:
								break;

							case BOTAO_ARCHER:
								SELECIONADO = BOTAO_MAGE;
								Efeito_Sonoro(CLICK);
								break;
						}
						break;

					case SDLK_RIGHT:
						switch (SELECIONADO)
						{
							case BOTAO_MAGE:
								SELECIONADO = BOTAO_ARCHER;
								Efeito_Sonoro(CLICK);
								break;

							case BOTAO_ARCHER:
								break;
						}
						break;

					case SDLK_RETURN:
						switch (SELECIONADO)
						{
							case BOTAO_MAGE:
								Efeito_Sonoro(SELECT);
								SDL_Delay(400); // Delay de 0.4 segundos
								SELECIONADO = PERSONAGEM_ESCOLHIDO;
								SELECAO2 = BOTAO_MAGE;
								jogadores->jogador[0].classe = MAGO;
								//menuRodando = FALSO;
								//selecaoSPRodando = FALSO;
								//estadoDeJogo = JOGO;
								break;

							case BOTAO_ARCHER:
								Efeito_Sonoro(SELECT);
								SDL_Delay(400); // Delay de 0.4 segundos
								SELECIONADO = PERSONAGEM_ESCOLHIDO;
								SELECAO2 = BOTAO_ARCHER;
								jogadores->jogador[0].classe = ARQUEIRO;
								break;

							case PERSONAGEM_ESCOLHIDO:
								Efeito_Sonoro(SELECT);
								SDL_Delay(400); // Delay de 0.4 segundos
								menuRodando = FALSO;
								selecaoSPRodando = FALSO;
								estadoDeJogo = JOGO;

						}
						break;
				}
			}

			// ********************************************************

			//
			// CLIQUE DO MOUSE
			//

			if (event.type == SDL_MOUSEBUTTONDOWN)
			{

				//
				// Acoes
				//

				// MAGE
				if ((posicao_do_mouse.x > 65
						&& posicao_do_mouse.x < 350
						&& posicao_do_mouse.y > 85
						&& posicao_do_mouse.y < 420)
							&& SELECIONADO != PERSONAGEM_ESCOLHIDO)
				{
					Efeito_Sonoro(SELECT);
					SDL_Delay(400); // Delay de 0.4 segundos
					SELECIONADO = PERSONAGEM_ESCOLHIDO;
					SELECAO2 = BOTAO_MAGE;
					jogadores->jogador[0].classe = MAGO;
					//menuRodando = FALSO;
					//selecaoSPRodando = FALSO;
					//estadoDeJogo = JOGO;
				}

				// ARCHER
				if ((posicao_do_mouse.x > 460
						&& posicao_do_mouse.x < 745
						&& posicao_do_mouse.y > 85
						&& posicao_do_mouse.y < 420)
							&& SELECIONADO != PERSONAGEM_ESCOLHIDO)
				{
					SELECIONADO = PERSONAGEM_ESCOLHIDO;
					SELECAO2 = BOTAO_ARCHER;
					jogadores->jogador[0].classe = ARQUEIRO;
					Efeito_Sonoro(SELECT);
					SDL_Delay(400); // Delay de 0.4 segundos
				}
			}
			// ********************************************************
		}
		
		// Atualiza tela
		SDL_RenderPresent(renderer);

		// FPS
		SDL_Delay( 1000/FPS );
		
	}

	// Limpando memoria - imagens
	SDL_DestroyTexture(gFundo);
	SDL_DestroyTexture(gMage);
	SDL_DestroyTexture(gArcher);
	SDL_DestroyTexture(gSelecao_v);
	SDL_DestroyTexture(gSelecao_b);
	SDL_DestroyTexture(gSelecao_p);
	SDL_DestroyTexture(gSelecao_a);
	SDL_DestroyTexture(tClasse.textura);
	SDL_DestroyTexture(tMage.textura);
	SDL_DestroyTexture(tArcher.textura);
	SDL_DestroyTexture(tForca.textura);
	SDL_DestroyTexture(tValorFor1.textura);
	SDL_DestroyTexture(tValorFor2.textura);
	SDL_DestroyTexture(tDestreza.textura);
	SDL_DestroyTexture(tValorDes1.textura);
	SDL_DestroyTexture(tValorDes2.textura);
	SDL_DestroyTexture(tInteligencia.textura);
	SDL_DestroyTexture(tValorInt1.textura);
	SDL_DestroyTexture(tValorInt2.textura);
	SDL_DestroyTexture(tConstituicao.textura);
	SDL_DestroyTexture(tValorCon1.textura);
	SDL_DestroyTexture(tValorCon2.textura);
	SDL_DestroyTexture(tLVL.textura);
	SDL_DestroyTexture(tValorLVL.textura);


	//
	// **********************
	// Loop do menu rodando | fim
	// **********************
	//

	// *********************************************************************
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