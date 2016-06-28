// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

/*
	JOGO

	Jogo de desenvolvido para projeto de computacao 1
*/
#include "main.h"
#include "jogo.h"
#include "som.h"
#include "config.h"
#include "fisica.h"

// Pre carregamento das funcoes
void Roda_Jogo_Singleplayer(SDL_Renderer* renderer, SDL_Event event, Jogador* jogador1);
void Roda_Jogo_Multiplayer(SDL_Renderer* renderer, SDL_Event event, Jogador* jogador1, Jogador* jogador2);
void Movimenta_Jogador(Jogador* jogador, Jogador* jogador2);
void Roda_Pause(SDL_Renderer* renderer, SDL_Event event, SDL_Texture* gFundo, Jogador* jogador1, Jogador* jogador2);

// ********************************************************************

int singlePlayerRodando, multiPlayerRodando;

// Modo de jogo em Single Player
void Roda_Jogo_Singleplayer(SDL_Renderer* renderer, SDL_Event event, Jogador* jogador1)
{
	// Toca musica de fundo
	Toca_Musica(MUSICA_DE_FUNDO_DO_JOGO);

	// Variavel para manter loop do jogo
	singlePlayerRodando = VERDADEIRO;

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

	// Define posicao do jogador em tela
	jogador1->posicao.x = SCREEN_WIDTH/2;
	jogador1->posicao.y = SCREEN_HEIGHT/2;

	// Carrega imagem na memoria
	Loading_Surf = IMG_Load(MAGE_W);

	// Carrega imagem na tela
	jogador1->sprite = SDL_CreateTextureFromSurface(renderer,
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

			// Eventos de tecla pressionada
			if (event.type == SDL_KEYDOWN)
			{
				// Pause
				if (event.key.keysym.sym == SDLK_ESCAPE)
					Roda_Pause(renderer, event, gFundo, jogador1, NULL);
				// Movimento do jogador
				Movimenta_Jogador(jogador1, NULL);
			}
		}

		// Limpa tela anterior
		SDL_RenderClear(renderer);

		// Renderiza plano de fundo
		SDL_RenderCopy(renderer, gFundo, NULL, NULL);

		// Renderiza jogador
		SDL_RenderCopy(renderer, jogador1->sprite, &jogador1->frame, &jogador1->posicao);

		// Atualiza tela
		SDL_RenderPresent(renderer);

		// FPS
		SDL_Delay( 1000/FPS );

	}

	// Limpando memoria - imagens
	SDL_DestroyTexture(gFundo);
	SDL_DestroyTexture(jogador1->sprite);

	//
	// **************
	// LOOP DO JOGO | fim
	// **************
	//

	// *********************************************************************
}

// Modo de Jogo em MultiPlayer
void Roda_Jogo_Multiplayer(SDL_Renderer* renderer, SDL_Event event, Jogador* jogador1, Jogador* jogador2)
{
	// Toca musica de fundo
	Toca_Musica(MUSICA_DE_FUNDO_DO_JOGO);

	// Variavel para manter loop do jogo
	multiPlayerRodando = VERDADEIRO;

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

	// Define posicao do jogador em tela
	jogador1->posicao.x = SCREEN_WIDTH/2 + 40;
	jogador1->posicao.y = SCREEN_HEIGHT/2;

	// Carrega imagem na memoria
	Loading_Surf = IMG_Load(MAGE_W);

	// Carrega imagem na tela
	jogador1->sprite = SDL_CreateTextureFromSurface(renderer,
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

	// Define posicao do jogador em tela
	jogador2->posicao.x = SCREEN_WIDTH/2 - 85;
	jogador2->posicao.y = SCREEN_HEIGHT/2;

	// Carrega imagem na memoria
	Loading_Surf = IMG_Load(ARCHER_W);

	// Carrega imagem na tela
	jogador2->sprite = SDL_CreateTextureFromSurface(renderer,
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

			// Eventos de tecla pressionada
			if (event.type == SDL_KEYDOWN)
			{
				// Pause
				if (event.key.keysym.sym == SDLK_ESCAPE)
					Roda_Pause(renderer, event, gFundo, jogador1, jogador2);

				// Movimentacao do Jogador 1
				Movimenta_Jogador(jogador1, jogador2);

				// Movimentacao do Jogador 2
				Movimenta_Jogador(jogador2, jogador1);
			}
		}

		// Limpa tela anterior
		SDL_RenderClear(renderer);

		// Renderiza plano de fundo
		SDL_RenderCopy(renderer, gFundo, NULL, NULL);

		// Renderiza jogador 1
		SDL_RenderCopy(renderer, jogador1->sprite, &jogador1->frame, &jogador1->posicao);

		// Renderiza jogador 2
		SDL_RenderCopy(renderer, jogador2->sprite, &jogador2->frame, &jogador2->posicao);

		// Atualiza tela
		SDL_RenderPresent(renderer);

		// FPS
		SDL_Delay( 1000/FPS );

	}

	// Limpando memoria - imagens
	SDL_DestroyTexture(gFundo);
	SDL_DestroyTexture(jogador1->sprite);
	SDL_DestroyTexture(jogador2->sprite);

	//
	// **************
	// LOOP DO JOGO | fim
	// **************
	//

	// *********************************************************************
}

void Movimenta_Jogador(Jogador* jogador, Jogador* jogador2)
{
	// Verifica colisao de jogadores caso esteja no multiplayer
	int movimento_permitido_jogador;
	if (jogador2 == NULL)
		movimento_permitido_jogador = VERDADEIRO;

	else
	{
		if (Colisao_Entre_Jogadores(jogador, jogador2))
			movimento_permitido_jogador = FALSO;
		else
			movimento_permitido_jogador = VERDADEIRO;
	}


	// Carrega teclas de acao
	Carrega_Teclas_de_Acao(jogador);

	// Verifica colisao de tela
	int movimento_permitido;
	if (Colisao_Jogador_LimiteDeTela(jogador))
		movimento_permitido = FALSO;
	else
		movimento_permitido = VERDADEIRO;

	//
	// Movimentos diagonais
	//

	// Nordeste
	if (jogador->movimento.cima && jogador->movimento.esquerda)
	{
		// Animacao
		jogador->frame.y = 512;

		if (jogador->frame.x < 512)
			jogador->frame.x += 64;

		else
			jogador->frame.x = 0;

		// Salva movimento de animacao
		jogador->animacao = QUADRANTE2;

		// Movimentacao
		if (movimento_permitido && movimento_permitido_jogador)
		{
			jogador->posicao.y -= jogador->velocidade.y;
			jogador->posicao.x -= jogador->velocidade.x;
		}
	}

	// Noroeste
	else if (jogador->movimento.cima && jogador->movimento.direita)
	{
		// Animacao
		jogador->frame.y = 512;

		if (jogador->frame.x < 512)
			jogador->frame.x += 64;

		else
			jogador->frame.x = 0;

		// Salva movimento de animacao
		jogador->animacao = QUADRANTE1;

		// Movimentacao
		if (movimento_permitido && movimento_permitido_jogador)
		{
			jogador->posicao.y -= jogador->velocidade.y;
			jogador->posicao.x += jogador->velocidade.x;
		}
	}

	// Suldeste
	else if (jogador->movimento.baixo && jogador->movimento.esquerda)
	{
		// Animacao
		jogador->frame.y = 640;

		if (jogador->frame.x < 512)
			jogador->frame.x += 64;

		else
			jogador->frame.x = 0;

		// Salva movimento de animacao
		jogador->animacao = QUADRANTE3;

		// Movimentacao
		if (movimento_permitido && movimento_permitido_jogador)
		{
			jogador->posicao.y += jogador->velocidade.y;
			jogador->posicao.x -= jogador->velocidade.x;
		}
	}

	// Suldoeste
	else if (jogador->movimento.baixo && jogador->movimento.direita)
	{
		// Animacao
		jogador->frame.y = 640;

		if (jogador->frame.x < 512)
			jogador->frame.x += 64;

		else
			jogador->frame.x = 0;

		// Salva movimento de animacao
		jogador->animacao = QUADRANTE4;

		// Movimentacao
		if (movimento_permitido && movimento_permitido_jogador)
		{
			jogador->posicao.y += jogador->velocidade.y;
			jogador->posicao.x += jogador->velocidade.x;
		}
	}

	//
	// Movimentos principais
	//

	// Cima
	else if (jogador->movimento.cima)
	{
		// Animacao
		jogador->frame.y = 512;

		if (jogador->frame.x < 512)
			jogador->frame.x += 64;
		else
			jogador->frame.x = 0;

		// Salva movimento de animacao
		jogador->animacao = CIMA;

		// Movimento
		if (movimento_permitido && movimento_permitido_jogador)
			jogador->posicao.y -= jogador->velocidade.y;
	}

	// Baixo
	else if (jogador->movimento.baixo)
	{
		// Animacao
		jogador->frame.y = 640;

		if (jogador->frame.x < 512)
			jogador->frame.x += 64;
		else
			jogador->frame.x = 0;

		// Salva movimento de animacao
		jogador->animacao = BAIXO;

		// Movimento
		if (movimento_permitido && movimento_permitido_jogador)
			jogador->posicao.y += jogador->velocidade.y;
	}

	// Esquerda
	else if (jogador->movimento.esquerda)
	{
		// Animacao
		jogador->frame.y = 576;

		if (jogador->frame.x < 512)
			jogador->frame.x += 64;
		else
			jogador->frame.x = 0;

		// Salva movimento de animacao
		jogador->animacao = ESQUERDA;

		// Movimento
		if (movimento_permitido && movimento_permitido_jogador)
			jogador->posicao.x -= jogador->velocidade.x;
	}

	// Direita
	else if (jogador->movimento.direita)
	{
		// Animacao
		jogador->frame.y = 704;

		if (jogador->frame.x < 512)
			jogador->frame.x += 64;
		else
			jogador->frame.x = 0;

		// Salva movimento de animacao
		jogador->animacao = DIREITA;

		// Movimento
		if (movimento_permitido && movimento_permitido_jogador)
			jogador->posicao.x += jogador->velocidade.x;
	}
}

void Roda_Pause(SDL_Renderer* renderer, SDL_Event event, SDL_Texture* gFundo,
	Jogador* jogador1, Jogador* jogador2)
{
	int pauseRodando = VERDADEIRO;

	// Loop do pause
	while (pauseRodando)
	{
		// Verifica eventos
		if (SDL_PollEvent (&event))
		{
			// Finaliza o jogo
			if (event.type == SDL_QUIT)
			{
				pauseRodando = FALSO;
				singlePlayerRodando = FALSO;
				multiPlayerRodando = FALSO;
				jogoRodando = FALSO;
			}

			// Eventos de tecla pressionada
			if (event.type == SDL_KEYDOWN)
			{
				// Encerra o pause
				if (event.key.keysym.sym == SDLK_ESCAPE)
					pauseRodando = FALSO;
			}
		}

		// Limpa tela anterior
		SDL_RenderClear(renderer);

		// Renderiza plano de fundo
		SDL_RenderCopy(renderer, gFundo, NULL, NULL);

		// Renderiza jogador 1
		SDL_RenderCopy(renderer, jogador1->sprite, &jogador1->frame, &jogador1->posicao);

		// Renderiza Jogador 2 caso exista
		if (jogador2 != NULL)
			SDL_RenderCopy(renderer, jogador2->sprite, &jogador2->frame, &jogador2->posicao);

		// Atualiza tela
		SDL_RenderPresent(renderer);

		// FPS
		SDL_Delay( 1000/FPS );
	}	
}