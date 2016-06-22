// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

/*
	JOGO

	Jogo de desenvolvido para projeto de computacao 1
*/
#include "main.h"

// Modo de jogo em Single Player
void roda_JogoSinglePlayer(SDL_Renderer* renderer, SDL_Event event)
{
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

	// Velocidade de movimento
	float velx = 5;
	float vely = 5;

	// Dimensoes da imagem com os sprites
	int jogador_fullW = 832;
	int jogador_fullH = 1344;

	// Dimensoes dos frames dos sprites
	int jogador_frameW = 64;
	int jogador_frameH = 64;

	// Variaveis para o Rect
	SDL_Rect jogador_frame, jogador_posicao;

	// Rect de frame
	jogador_frame.x = 0;
	jogador_frame.y = 512;
	jogador_frame.w = jogador_frameW;
	jogador_frame.h = jogador_frameH;

	// Rect para posicao do jogador
	jogador_posicao.x = SCREEN_WIDTH/2;
	jogador_posicao.y = SCREEN_HEIGHT/2;
	jogador_posicao.w = jogador_frameW;
	jogador_posicao.h = jogador_frameH;

	// Carrega imagem do jogador na memoria
	Loading_Surf = IMG_Load("arte/personagens/jogador1/Mage w.png");

	// Variavel para carregar jogador em tela
	SDL_Texture* gJogador = NULL;

	// Carrega frame do jogador em tela
	gJogador = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf);

	// Limpa memoria
	SDL_FreeSurface(Loading_Surf);

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
			{
				// ********************************************************

				//
				// **********************
				// MOVIMENTO DO JOGADOR | inicio
				// **********************
				//

				// Declaracao de teclas
				const Uint8 *keystates = SDL_GetKeyboardState(NULL);

				int cima_pressionado = keystates[SDL_SCANCODE_UP];
				int baixo_pressionado = keystates[SDL_SCANCODE_DOWN];
				int esquerda_pressionado = keystates[SDL_SCANCODE_LEFT];
				int direita_pressionado = keystates[SDL_SCANCODE_RIGHT];

				//
				// Movimentos diagonais
				//

				// Nordeste
				if (cima_pressionado && esquerda_pressionado)
				{
					// Animacao
					jogador_frame.y = 512;

					if (jogador_frame.x < 512)
						jogador_frame.x += 64;

					else
						jogador_frame.x = 0;

					// Movimentacao
					if (jogador_posicao.y > 0
						&& jogador_posicao.x > 0)
					{
						jogador_posicao.y -= vely;
						jogador_posicao.x -= velx;
					}
				}

				// Noroeste
				else if (cima_pressionado && direita_pressionado)
				{
					// Animacao
					jogador_frame.y = 512;

					if (jogador_frame.x < 512)
						jogador_frame.x += 64;

					else
						jogador_frame.x = 0;

					// Movimentacao
					if (jogador_posicao.y > 0
						&& jogador_posicao.x < SCREEN_WIDTH - jogador_frameW)
					{
						jogador_posicao.y -= vely;
						jogador_posicao.x += velx;
					}
				}

				// Suldeste
				else if (baixo_pressionado && esquerda_pressionado)
				{
					// Animacao
					jogador_frame.y = 640;

					if (jogador_frame.x < 512)
						jogador_frame.x += 64;

					else
						jogador_frame.x = 0;

					// Movimentacao
					if (jogador_posicao.y < SCREEN_HEIGHT
						&& jogador_posicao.x > 0)
					{
						jogador_posicao.y += vely;
						jogador_posicao.x -= velx;
					}
				}

				// Suldoeste
				else if (baixo_pressionado && direita_pressionado)
				{
					// Animacao
					jogador_frame.y = 640;

					if (jogador_frame.x < 512)
						jogador_frame.x += 64;

					else
						jogador_frame.x = 0;

					// Movimentacao
					if (jogador_posicao.y < SCREEN_HEIGHT
						&& jogador_posicao.x < SCREEN_WIDTH - jogador_frameW)
					{
						jogador_posicao.y += vely;
						jogador_posicao.x += velx;
					}
				}

				//
				// Movimentos principais
				//

				// Cima
				else if (cima_pressionado)
				{
					// Animacao
					jogador_frame.y = 512;

					if (jogador_frame.x < 512)
						jogador_frame.x += 64;
					else
						jogador_frame.x = 0;

					// Movimento
					if (jogador_posicao.y > 0)
						jogador_posicao.y -= vely;
				}

				// Baixo
				else if (baixo_pressionado)
				{
					// Animacao
					jogador_frame.y = 640;

					if (jogador_frame.x < 512)
						jogador_frame.x += 64;
					else
						jogador_frame.x = 0;

					// Movimento
					if (jogador_posicao.y < SCREEN_HEIGHT - jogador_frameH)
						jogador_posicao.y += vely;
				}

				// Esquerda
				else if (esquerda_pressionado)
				{
					// Animacao
					jogador_frame.y = 576;

					if (jogador_frame.x < 512)
						jogador_frame.x += 64;
					else
						jogador_frame.x = 0;

					// Movimento
					if (jogador_posicao.x > 0)
						jogador_posicao.x -= velx;
				}

				// Direita
				else if (direita_pressionado)
				{
					// Animacao
					jogador_frame.y = 704;

					if (jogador_frame.x < 512)
						jogador_frame.x += 64;
					else
						jogador_frame.x = 0;

					// Movimento
					if (jogador_posicao.x < SCREEN_WIDTH - jogador_frameW)
						jogador_posicao.x += velx;
				}

				//
				// **********************
				// MOVIMENTO DO JOGADOR | fim
				// **********************
				//

				// ********************************************************
			}
		}

		// Limpa tela anterior
		SDL_RenderClear(renderer);

		// Renderiza plano de fundo
		SDL_RenderCopy(renderer, gFundo, NULL, NULL);

		// Renderiza jogador
		SDL_RenderCopy(renderer, gJogador, &jogador_frame, &jogador_posicao);

		// Atualiza tela
		SDL_RenderPresent(renderer);

		// Delay (15 = 1 segundo)
		SDL_Delay(15);

	}

	// Limpando memoria
	SDL_DestroyTexture(gFundo);
	SDL_DestroyTexture(gJogador);

	//
	// **************
	// LOOP DO JOGO | fim
	// **************
	//

	// *********************************************************************

}

// Modo de Jogo em MultiPlayer
void roda_JogoMultiPlayer(SDL_Renderer* renderer, SDL_Event event)
{
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
	// *********
	// JOGADOR | inicio
	// *********
	//

	// Velocidade de movimento
	float velx = 5;
	float vely = 5;

	// Dimensoes da imagem com os sprites
	int jogador1_fullW = 832;
	int jogador1_fullH = 1344;

	// Dimensoes dos frames dos sprites
	int jogador1_frameW = 64;
	int jogador1_frameH = 64;

	// Variaveis para o Rect
	SDL_Rect jogador1_frame, jogador1_posicao;

	// Rect de frame
	jogador1_frame.x = 0;
	jogador1_frame.y = 512;
	jogador1_frame.w = jogador1_frameW;
	jogador1_frame.h = jogador1_frameH;

	// Rect para posicao do jogador
	jogador1_posicao.x = SCREEN_WIDTH/2 + 40;
	jogador1_posicao.y = SCREEN_HEIGHT/2;
	jogador1_posicao.w = jogador1_frameW;
	jogador1_posicao.h = jogador1_frameH;

	// Carrega imagem do jogador na memoria
	Loading_Surf = IMG_Load("arte/personagens/jogador1/Mage w.png");

	// Variavel para carregar jogador em tela
	SDL_Texture* gJogador1 = NULL;

	// Carrega frame do jogador em tela
	gJogador1 = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf);

	// Limpa memoria
	SDL_FreeSurface(Loading_Surf);

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

	// Dimensoes da imagem com os sprites
	int jogador2_fullW = 832;
	int jogador2_fullH = 1344;

	// Dimensoes dos frames dos sprites
	int jogador2_frameW = 64;
	int jogador2_frameH = 64;

	// Variaveis para o Rect
	SDL_Rect jogador2_frame, jogador2_posicao;

	// Rect de frame
	jogador2_frame.x = 0;
	jogador2_frame.y = 512;
	jogador2_frame.w = jogador2_frameW;
	jogador2_frame.h = jogador2_frameH;

	// Rect para posicao do jogador 2
	jogador2_posicao.x = SCREEN_WIDTH/2 - 85;
	jogador2_posicao.y = SCREEN_HEIGHT/2;
	jogador2_posicao.w = jogador2_frameW;
	jogador2_posicao.h = jogador2_frameH;

	// Carrega imagem do jogador 2 na memoria
	Loading_Surf = IMG_Load("arte/personagens/jogador1/Archer w.png");

	// Variavel para carregar jogador 2 em tela
	SDL_Texture* gJogador2 = NULL;

	// Carrega frame do jogador 2 em tela
	gJogador2 = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf);

	// Limpa memoria
	SDL_FreeSurface(Loading_Surf);

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

			// Movimentacao do jogador
			if (event.type == SDL_KEYDOWN)
			{
				// Struct para movimento
				typedef struct _TECLAS_DE_ACAO
				{
					int cima_pressionado;
					int baixo_pressionado;
					int esquerda_pressionado;
					int direita_pressionado;
				}TECLAS_DE_ACAO;

				// Variaveis de jogador
				TECLAS_DE_ACAO jogador1, jogador2;

				// Declaracao de teclas
				const Uint8 *keystates = SDL_GetKeyboardState(NULL);

				// ********************************************************

				//
				// ************************
				// MOVIMENTO DO JOGADOR 1 | inicio
				// ************************
				//

				jogador1.cima_pressionado = keystates[SDL_SCANCODE_UP];
				jogador1.baixo_pressionado = keystates[SDL_SCANCODE_DOWN];
				jogador1.esquerda_pressionado = keystates[SDL_SCANCODE_LEFT];
				jogador1.direita_pressionado = keystates[SDL_SCANCODE_RIGHT];

				//
				// Movimentos diagonais
				//

				// Nordeste
				if (jogador1.cima_pressionado
					&& jogador1.esquerda_pressionado)
				{
					// Animacao
					jogador1_frame.y = 512;

					if (jogador1_frame.x < 512)
						jogador1_frame.x += 64;

					else
						jogador1_frame.x = 0;

					// Movimentacao
					if (jogador1_posicao.y > 0
						&& jogador1_posicao.x > 0)
					{
						jogador1_posicao.y -= vely;
						jogador1_posicao.x -= velx;
					}
				}

				// Noroeste
				else if (jogador1.cima_pressionado
					&& jogador1.direita_pressionado)
				{
					// Animacao
					jogador1_frame.y = 512;

					if (jogador1_frame.x < 512)
						jogador1_frame.x += 64;

					else
						jogador1_frame.x = 0;

					// Movimentacao
					if (jogador1_posicao.y > 0
						&& jogador1_posicao.x < SCREEN_WIDTH - jogador1_frameW)
					{
						jogador1_posicao.y -= vely;
						jogador1_posicao.x += velx;
					}
				}

				// Suldeste
				else if (jogador1.baixo_pressionado
					&& jogador1.esquerda_pressionado)
				{
					// Animacao
					jogador1_frame.y = 640;

					if (jogador1_frame.x < 512)
						jogador1_frame.x += 64;

					else
						jogador1_frame.x = 0;

					// Movimentacao
					if (jogador1_posicao.y < SCREEN_HEIGHT
						&& jogador1_posicao.x > 0)
					{
						jogador1_posicao.y += vely;
						jogador1_posicao.x -= velx;
					}
				}

				// Suldoeste
				else if (jogador1.baixo_pressionado
					&& jogador1.direita_pressionado)
				{
					// Animacao
					jogador1_frame.y = 640;

					if (jogador1_frame.x < 512)
						jogador1_frame.x += 64;

					else
						jogador1_frame.x = 0;

					// Movimentacao
					if (jogador1_posicao.y < SCREEN_HEIGHT
						&& jogador1_posicao.x < SCREEN_WIDTH - jogador1_frameW)
					{
						jogador1_posicao.y += vely;
						jogador1_posicao.x += velx;
					}
				}

				//
				// Movimentos principais
				//

				// Cima
				else if (jogador1.cima_pressionado)
				{
					// Animacao
					jogador1_frame.y = 512;

					if (jogador1_frame.x < 512)
						jogador1_frame.x += 64;
					else
						jogador1_frame.x = 0;

					// Movimento
					if (jogador1_posicao.y > 0)
						jogador1_posicao.y -= vely;
				}

				// Baixo
				else if (jogador1.baixo_pressionado)
				{
					// Animacao
					jogador1_frame.y = 640;

					if (jogador1_frame.x < 512)
						jogador1_frame.x += 64;
					else
						jogador1_frame.x = 0;

					// Movimento
					if (jogador1_posicao.y < SCREEN_HEIGHT - jogador1_frameH)
						jogador1_posicao.y += vely;
				}

				// Esquerda
				else if (jogador1.esquerda_pressionado)
				{
					// Animacao
					jogador1_frame.y = 576;

					if (jogador1_frame.x < 512)
						jogador1_frame.x += 64;
					else
						jogador1_frame.x = 0;

					// Movimento
					if (jogador1_posicao.x > 0)
						jogador1_posicao.x -= velx;
				}

				// Direita
				else if (jogador1.direita_pressionado)
				{
					// Animacao
					jogador1_frame.y = 704;

					if (jogador1_frame.x < 512)
						jogador1_frame.x += 64;
					else
						jogador1_frame.x = 0;

					// Movimento
					if (jogador1_posicao.x < SCREEN_WIDTH - jogador1_frameW)
						jogador1_posicao.x += velx;
				}

				//
				// ************************
				// MOVIMENTO DO JOGADOR 1 | fim
				// ************************
				//

				// ********************************************************

				//
				// ************************
				// MOVIMENTO DO JOGADOR 2 | inicio
				// ************************
				//

				jogador2.cima_pressionado = keystates[SDL_SCANCODE_W];
				jogador2.baixo_pressionado = keystates[SDL_SCANCODE_S];
				jogador2.esquerda_pressionado = keystates[SDL_SCANCODE_A];
				jogador2.direita_pressionado = keystates[SDL_SCANCODE_D];

				//
				// Movimentos diagonais
				//

				// Nordeste
				if (jogador2.cima_pressionado
					&& jogador2.esquerda_pressionado)
				{
					// Animacao
					jogador2_frame.y = 512;

					if (jogador2_frame.x < 512)
						jogador2_frame.x += 64;

					else
						jogador2_frame.x = 0;

					// Movimentacao
					if (jogador2_posicao.y > 0
						&& jogador2_posicao.x > 0)
					{
						jogador2_posicao.y -= vely;
						jogador2_posicao.x -= velx;
					}
				}

				// Noroeste
				else if (jogador2.cima_pressionado
					&& jogador2.direita_pressionado)
				{
					// Animacao
					jogador2_frame.y = 512;

					if (jogador2_frame.x < 512)
						jogador2_frame.x += 64;

					else
						jogador2_frame.x = 0;

					// Movimentacao
					if (jogador2_posicao.y > 0
						&& jogador2_posicao.x < SCREEN_WIDTH - jogador2_frameW)
					{
						jogador2_posicao.y -= vely;
						jogador2_posicao.x += velx;
					}
				}

				// Suldeste
				else if (jogador2.baixo_pressionado
					&& jogador2.esquerda_pressionado)
				{
					// Animacao
					jogador2_frame.y = 640;

					if (jogador2_frame.x < 512)
						jogador2_frame.x += 64;

					else
						jogador2_frame.x = 0;

					// Movimentacao
					if (jogador2_posicao.y < SCREEN_HEIGHT
						&& jogador2_posicao.x > 0)
					{
						jogador2_posicao.y += vely;
						jogador2_posicao.x -= velx;
					}
				}

				// Suldoeste
				else if (jogador2.baixo_pressionado
					&& jogador2.direita_pressionado)
				{
					// Animacao
					jogador2_frame.y = 640;

					if (jogador2_frame.x < 512)
						jogador2_frame.x += 64;

					else
						jogador2_frame.x = 0;

					// Movimentacao
					if (jogador2_posicao.y < SCREEN_HEIGHT
						&& jogador2_posicao.x < SCREEN_WIDTH - jogador2_frameW)
					{
						jogador2_posicao.y += vely;
						jogador2_posicao.x += velx;
					}
				}

				//
				// Movimentos principais
				//

				// Cima
				else if (jogador2.cima_pressionado)
				{
					// Animacao
					jogador2_frame.y = 512;

					if (jogador2_frame.x < 512)
						jogador2_frame.x += 64;
					else
						jogador2_frame.x = 0;

					// Movimento
					if (jogador2_posicao.y > 0)
						jogador2_posicao.y -= vely;
				}

				// Baixo
				else if (jogador2.baixo_pressionado)
				{
					// Animacao
					jogador2_frame.y = 640;

					if (jogador2_frame.x < 512)
						jogador2_frame.x += 64;
					else
						jogador2_frame.x = 0;

					// Movimento
					if (jogador2_posicao.y < SCREEN_HEIGHT - jogador2_frameH)
						jogador2_posicao.y += vely;
				}

				// Esquerda
				else if (jogador2.esquerda_pressionado)
				{
					// Animacao
					jogador2_frame.y = 576;

					if (jogador2_frame.x < 512)
						jogador2_frame.x += 64;
					else
						jogador2_frame.x = 0;

					// Movimento
					if (jogador2_posicao.x > 0)
						jogador2_posicao.x -= velx;
				}

				// Direita
				else if (jogador2.direita_pressionado)
				{
					// Animacao
					jogador2_frame.y = 704;

					if (jogador2_frame.x < 512)
						jogador2_frame.x += 64;
					else
						jogador2_frame.x = 0;

					// Movimento
					if (jogador2_posicao.x < SCREEN_WIDTH - jogador2_frameW)
						jogador2_posicao.x += velx;
				}

				//
				// ************************
				// MOVIMENTO DO JOGADOR 2 | fim
				// ************************
				//

				// ********************************************************
			}
		}

		// Limpa tela anterior
		SDL_RenderClear(renderer);

		// Renderiza plano de fundo
		SDL_RenderCopy(renderer, gFundo, NULL, NULL);

		// Renderiza jogador 1
		SDL_RenderCopy(renderer, gJogador1, &jogador1_frame, &jogador1_posicao);

		// Renderiza jogador 2
		SDL_RenderCopy(renderer, gJogador2, &jogador2_frame, &jogador2_posicao);

		// Atualiza tela
		SDL_RenderPresent(renderer);

		// Delay (15 = 1 segundo)
		SDL_Delay(15);

	}

	// Limpando memoria
	SDL_DestroyTexture(gFundo);
	SDL_DestroyTexture(gJogador1);
	SDL_DestroyTexture(gJogador2);

	//
	// **************
	// LOOP DO JOGO | fim
	// **************
	//

	// *********************************************************************
}
