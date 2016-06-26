// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

/*
	JOGO

	Jogo de desenvolvido para projeto de computacao 1
*/
#include "main.h"
#include "som.h"
#include "config.h"

// Pre carregamento das funcoes
void Roda_Jogo_Singleplayer(SDL_Renderer* renderer, SDL_Event event);
void Roda_Jogo_Multiplayer(SDL_Renderer* renderer, SDL_Event event);
void Movimenta_Jogador(Jogador* jogador);

// ********************************************************************

// Modo de jogo em Single Player
void Roda_Jogo_Singleplayer(SDL_Renderer* renderer, SDL_Event event)
{
	// Toca musica de fundo
	Toca_Musica(MUSICA_DE_FUNDO_DO_JOGO);

	// Variavel para manter loop do jogo
	int singlePlayerRodando = VERDADEIRO;

	// Variavel para carregar imagens
	SDL_Surface* Loading_Surf = NULL;

	// *********************************************************************

	//
	// ****************
	// PLANO DE FUNDO | inicio
	// ****************
	//

	// Variavel para conter plano de fundo
	SDL_Texture* gFundo = NULL;

	// Carrega plano de fundo na memoria
	Loading_Surf = IMG_Load("arte/fundo/fundo.jpg");

	// Carrega imagem na tela
	gFundo = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf);

	// Limpa variavel Loading_Surf
	SDL_FreeSurface(Loading_Surf);

	//
	// ****************
	// PLANO DE FUNDO | inicio
	// ****************
	//

	// *********************************************************************

	//
	// *********
	// JOGADOR | inicio
	// *********
	//

	// Inicializa jogador
	Jogador jogador1 = Carrega_Jogador(1);

	// Define posicao do jogador em tela
	jogador1.posicao.x = SCREEN_WIDTH/2;
	jogador1.posicao.y = SCREEN_HEIGHT/2;

	// Carrega imagem na memoria
	Loading_Surf = IMG_Load(MAGE_W);

	// Carrega imagem na tela
	jogador1.sprite = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf);

	// Limpa memoria
	SDL_FreeSurface (Loading_Surf);

	//
	// *********
	// JOGADOR | fim
	// *********
	//

	// *********************************************************************

	//
	// **************
	// LOOP DO JOGO | inicio
	// **************
	//

	while (singlePlayerRodando)
	{
		// Verifica eventos
		if (SDL_PollEvent (&event))
		{
			// Finaliza o jogo
			if (event.type == SDL_QUIT)
			{
				singlePlayerRodando = FALSO;
				jogoRodando = FALSO;
			}

			// Movimentacao do jogador
			if (event.type == SDL_KEYDOWN)
				Movimenta_Jogador(&jogador1);
		}

		// Limpa tela anterior
		SDL_RenderClear(renderer);

		// Renderiza plano de fundo
		SDL_RenderCopy(renderer, gFundo, NULL, NULL);

		// Renderiza jogador
		SDL_RenderCopy(renderer, jogador1.sprite, &jogador1.frame, &jogador1.posicao);

		// Atualiza tela
		SDL_RenderPresent(renderer);

		// FPS
		SDL_Delay( 1000/FPS );

	}

	// Limpando memoria - imagens
	SDL_DestroyTexture(gFundo);
	SDL_DestroyTexture(jogador1.sprite);

	//
	// **************
	// LOOP DO JOGO | fim
	// **************
	//

	// *********************************************************************
}

// Modo de Jogo em MultiPlayer
void Roda_Jogo_Multiplayer(SDL_Renderer* renderer, SDL_Event event)
{
	// Toca musica de fundo
	Toca_Musica(MUSICA_DE_FUNDO_DO_JOGO);

	// Variavel para manter loop do jogo
	int multiPlayerRodando = VERDADEIRO;

	// Variavel para carregar imagens
	SDL_Surface* Loading_Surf = NULL;

	// *********************************************************************

	//
	// ****************
	// PLANO DE FUNDO | inicio
	// ****************
	//

	// Variavel para conter plano de fundo
	SDL_Texture* gFundo = NULL;

	// Carrega plano de fundo na memoria
	Loading_Surf = IMG_Load("arte/fundo/fundo.jpg");

	// Carrega imagem na tela
	gFundo = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf);

	// Limpa variavel Loading_Surf
	SDL_FreeSurface(Loading_Surf);

	//
	// ****************
	// PLANO DE FUNDO | inicio
	// ****************
	//

	// *********************************************************************

	//
	// ***********
	// JOGADOR 1 | inicio
	// ***********
	//

	// Inicializa jogador
	Jogador jogador1 = Carrega_Jogador(1);

	// Define posicao do jogador em tela
	jogador1.posicao.x = SCREEN_WIDTH/2 + 40;
	jogador1.posicao.y = SCREEN_HEIGHT/2;

	// Carrega imagem na memoria
	Loading_Surf = IMG_Load(MAGE_W);

	// Carrega imagem na tela
	jogador1.sprite = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf);

	// Limpa memoria
	SDL_FreeSurface (Loading_Surf);

	//
	// ***********
	// JOGADOR 1 | fim
	// ***********
	//

	// *********************************************************************

	//
	// ***********
	// JOGADOR 2 | inicio
	// ***********
	//

	// Inicializa jogador
	Jogador jogador2 = Carrega_Jogador(2);

	// Define posicao do jogador em tela
	jogador2.posicao.x = SCREEN_WIDTH/2 - 85;
	jogador2.posicao.y = SCREEN_HEIGHT/2;

	// Carrega imagem na memoria
	Loading_Surf = IMG_Load(ARCHER_W);

	// Carrega imagem na tela
	jogador2.sprite = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf);

	// Limpa memoria
	SDL_FreeSurface (Loading_Surf);

	//
	// ***********
	// JOGADOR 2 | fim
	// ***********
	//

	// *********************************************************************

	//
	// **************
	// LOOP DO JOGO | inicio
	// **************
	//

	while (multiPlayerRodando)
	{
		// Verifica eventos
		if (SDL_PollEvent (&event))
		{
			// Finaliza o jogo
			if (event.type == SDL_QUIT)
			{
				multiPlayerRodando = FALSO;
				jogoRodando = FALSO;
			}

			// Movimentacao dos jogadores
			if (event.type == SDL_KEYDOWN)
			{
				// Jogador 1
				Movimenta_Jogador(&jogador1);

				// Jogador 2
				Movimenta_Jogador(&jogador2);
			}
		}

		// Limpa tela anterior
		SDL_RenderClear(renderer);

		// Renderiza plano de fundo
		SDL_RenderCopy(renderer, gFundo, NULL, NULL);

		// Renderiza jogador 1
		SDL_RenderCopy(renderer, jogador1.sprite, &jogador1.frame, &jogador1.posicao);

		// Renderiza jogador 2
		SDL_RenderCopy(renderer, jogador2.sprite, &jogador2.frame, &jogador2.posicao);

		// Atualiza tela
		SDL_RenderPresent(renderer);

		// FPS
		SDL_Delay( 1000/FPS );

	}

	// Limpando memoria - imagens
	SDL_DestroyTexture(gFundo);
	SDL_DestroyTexture(jogador1.sprite);
	SDL_DestroyTexture(jogador2.sprite);

	//
	// **************
	// LOOP DO JOGO | fim
	// **************
	//

	// *********************************************************************
}

void Movimenta_Jogador(Jogador* jogador)
{
	// Carrega teclas de acao
	Carrega_Teclas_de_Acao(jogador);

	//
	// Movimentos diagonais
	//

	// Nordeste
	if (jogador->tecla_de_acao.cima && jogador->tecla_de_acao.esquerda)
	{
		// Animacao
		jogador->frame.y = 512;

		if (jogador->frame.x < 512)
			jogador->frame.x += 64;

		else
			jogador->frame.x = 0;

		// Movimentacao
		if (jogador->posicao.y > 0
			&& jogador->posicao.x > 0)
		{
			jogador->posicao.y -= jogador->movimento.y;
			jogador->posicao.x -= jogador->movimento.x;
		}
	}

	// Noroeste
	else if (jogador->tecla_de_acao.cima && jogador->tecla_de_acao.direita)
	{
		// Animacao
		jogador->frame.y = 512;

		if (jogador->frame.x < 512)
			jogador->frame.x += 64;

		else
			jogador->frame.x = 0;

		// Movimentacao
		if (jogador->posicao.y > 0
			&& jogador->posicao.x < SCREEN_WIDTH - jogador->frame.w)
		{
			jogador->posicao.y -= jogador->movimento.y;
			jogador->posicao.x += jogador->movimento.x;
		}
	}

	// Suldeste
	else if (jogador->tecla_de_acao.baixo && jogador->tecla_de_acao.esquerda)
	{
		// Animacao
		jogador->frame.y = 640;

		if (jogador->frame.x < 512)
			jogador->frame.x += 64;

		else
			jogador->frame.x = 0;

		// Movimentacao
		if (jogador->posicao.y < SCREEN_HEIGHT
			&& jogador->posicao.x > 0)
		{
			jogador->posicao.y += jogador->movimento.y;
			jogador->posicao.x -= jogador->movimento.x;
		}
	}

	// Suldoeste
	else if (jogador->tecla_de_acao.baixo && jogador->tecla_de_acao.direita)
	{
		// Animacao
		jogador->frame.y = 640;

		if (jogador->frame.x < 512)
			jogador->frame.x += 64;

		else
			jogador->frame.x = 0;

		// Movimentacao
		if (jogador->posicao.y < SCREEN_HEIGHT
			&& jogador->posicao.x < SCREEN_WIDTH - jogador->frame.w)
		{
			jogador->posicao.y += jogador->movimento.y;
			jogador->posicao.x += jogador->movimento.x;
		}
	}

	//
	// Movimentos principais
	//

	// Cima
	else if (jogador->tecla_de_acao.cima)
	{
		// Animacao
		jogador->frame.y = 512;

		if (jogador->frame.x < 512)
			jogador->frame.x += 64;
		else
			jogador->frame.x = 0;

		// Movimento
		if (jogador->posicao.y > 0)
			jogador->posicao.y -= jogador->movimento.y;
	}

	// Baixo
	else if (jogador->tecla_de_acao.baixo)
	{
		// Animacao
		jogador->frame.y = 640;

		if (jogador->frame.x < 512)
			jogador->frame.x += 64;
		else
			jogador->frame.x = 0;

		// Movimento
		if (jogador->posicao.y < SCREEN_HEIGHT - jogador->frame.h)
			jogador->posicao.y += jogador->movimento.y;
	}

	// Esquerda
	else if (jogador->tecla_de_acao.esquerda)
	{
		// Animacao
		jogador->frame.y = 576;

		if (jogador->frame.x < 512)
			jogador->frame.x += 64;
		else
			jogador->frame.x = 0;

		// Movimento
		if (jogador->posicao.x > 0)
			jogador->posicao.x -= jogador->movimento.x;
	}

	// Direita
	else if (jogador->tecla_de_acao.direita)
	{
		// Animacao
		jogador->frame.y = 704;

		if (jogador->frame.x < 512)
			jogador->frame.x += 64;
		else
			jogador->frame.x = 0;

		// Movimento
		if (jogador->posicao.x < SCREEN_WIDTH - jogador->frame.w)
			jogador->posicao.x += jogador->movimento.x;
	}
}