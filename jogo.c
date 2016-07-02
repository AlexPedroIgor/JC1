// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

/*
	JOGO

	Jogo de desenvolvido para projeto de computacao 1
*/

#include "jogo.h"

// Pre carregamento das funcoes
void Roda_Singleplayer(SDL_Renderer* renderer, SDL_Event event, Jogadores* jogadores);
void Roda_Multiplayer(SDL_Renderer* renderer, SDL_Event event, Jogadores* jogadores);
void Movimenta_Jogador(Jogador* jogador, Jogador* jogador2, Inimigos* inimigos);
void Roda_Pause(SDL_Renderer* renderer, SDL_Event event, Fase* fase, Jogadores* jogadores, Inimigos* Inimigos);
void Roda_SairDoPause_SN(int* pauseRodando, SDL_Renderer* renderer, SDL_Event event, Fase* fase, Jogadores* jogadores, Inimigos* inimigos);
void Atirar(SDL_Renderer* renderer, Jogador* jogador, Vetor_de_Tiros* vetor_de_tiros);

// ********************************************************************

int singleplayerRodando, multiplayerRodando;

// Modo de jogo em Single Player
void Roda_Singleplayer(SDL_Renderer* renderer, SDL_Event event, Jogadores* jogadores)
{
	// Toca musica de fundo
	Toca_Musica(MUSICA_DE_FUNDO_DO_JOGO);

	// Variavel para manter loop do jogo
	singleplayerRodando = VERDADEIRO;

	// Variavel para carregar imagens
	SDL_Surface* Loading_Surf = NULL;

	// *********************************************************************

	//
	// ****************
	// PLANO DE FUNDO | inicio
	// ****************
	//

	Fase fase = Inicializa_Fases();

	Carrega_Fase_Memoria(renderer, &fase);

	//
	// ****************
	// PLANO DE FUNDO | fim
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
	// Carrega inimigos
	//

	Vetor_de_Inimigos vetor_de_inimigos = Cria_Vetor_de_inimigos(renderer,
		1, 1);

	Posiciona_Vetor_de_Inimigos(renderer, &vetor_de_inimigos, DIREITA, &fase);

	// *********************************************************************

	//
	// Carrega vetor de tiros
	//

	Vetor_de_Tiros vetor_de_tiros = Cria_Vetor_de_Tiros();

	// *********************************************************************

	//
	// **************
	// LOOP DO JOGO | inicio
	// **************
	//

	int contador;
	while (singleplayerRodando)
	{
		// Movimentacao dos inimigos
		Movimentacao_dos_Inimigos(&vetor_de_inimigos, jogador1, NULL);

		// Adiciona inimigos
		contador++;
		if (contador == 120)
		{
			Adiciona_inimigos(renderer, &vetor_de_inimigos, 1, 1, rand()%4+1, &fase);
			contador = 1;
		}

		// ********************************************************************

		// Verifica eventos
		if (SDL_PollEvent (&event))
		{
			// Finaliza o jogo
			if (event.type == SDL_QUIT)
			{
				singleplayerRodando = FALSO;
				jogoRodando = FALSO;
			}

			// Eventos de tecla pressionada
			if (event.type == SDL_KEYDOWN)
			{
				// Movimento do jogador
				Movimenta_Jogador(jogador1, NULL, &vetor_de_inimigos);

				//Atirar
				Atirar(renderer, jogador1, &vetor_de_tiros);

				// Pause
				if (event.key.keysym.sym == SDLK_ESCAPE)
					Roda_Pause(renderer, event, &fase, jogador1, NULL, &vetor_de_inimigos);
			}
		}

		// Limpa tela anterior
		SDL_RenderClear(renderer);

		// Renderiza plano de fundo
		Atualiza_Plano_de_Fundo(renderer, &fase);

		// Renderiza os Tiros
		Renderiza_Tiros(renderer, &vetor_de_tiros);

		// Renderiza jogador
		SDL_RenderCopy(renderer, jogador1->sprite, &jogador1->frame, &jogador1->posicao);

		// Renderiza inimigos em tela
		Atualiza_Inimigos_em_Tela(renderer, &vetor_de_inimigos);

		// Atualiza tela
		SDL_RenderPresent(renderer);

		// FPS
		SDL_Delay( 1000/FPS );
	}

	// Limpando memoria - imagens
	SDL_DestroyTexture(fase.sprite);
	SDL_DestroyTexture(jogador1->sprite);

	//
	// **************
	// LOOP DO JOGO | fim
	// **************
	//

	// *********************************************************************
}

// Modo de Jogo em MultiPlayer
void Roda_Multiplayer(SDL_Renderer* renderer, SDL_Event event, Jogadores* jogadores)
{
	// Toca musica de fundo
	Toca_Musica(MUSICA_DE_FUNDO_DO_JOGO);

	// Variavel para manter loop do jogo
	multiplayerRodando = VERDADEIRO;

	// Variavel para carregar imagens
	SDL_Surface* Loading_Surf = NULL;

	// *********************************************************************

	//
	// ****************
	// PLANO DE FUNDO | inicio
	// ****************
	//

	Fase fase = Inicializa_Fases();
	
	Carrega_Fase_Memoria(renderer, &fase);

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
	Loading_Surf = IMG_Load(MAGE_M);

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
	// Carrega inimigos
	//

	Vetor_de_Inimigos vetor_de_inimigos = Cria_Vetor_de_inimigos(renderer,
		1, 1);

	Posiciona_Vetor_de_Inimigos(renderer, &vetor_de_inimigos, DIREITA, &fase);

	// *********************************************************************

	//
	// **************
	// LOOP DO JOGO | inicio
	// **************
	//

	int contador;

	while (multiplayerRodando)
	{
		// Movimentacao dos inimigos
		Movimentacao_dos_Inimigos(&vetor_de_inimigos, jogador1, jogador2);

		// Adiciona inimigos
		contador++;
		if (contador == 120)
		{
			Adiciona_inimigos(renderer, &vetor_de_inimigos, 1, 1, rand()%4+1, &fase);
			contador = 1;
		}

		// ********************************************************************

		// Verifica eventos
		if (SDL_PollEvent (&event))
		{
			// Finaliza o jogo
			if (event.type == SDL_QUIT)
			{
				multiplayerRodando = FALSO;
				jogoRodando = FALSO;
			}

			// Eventos de tecla pressionada
			if (event.type == SDL_KEYDOWN)
			{
				// Pause
				if (event.key.keysym.sym == SDLK_ESCAPE)
					Roda_Pause(renderer, event, &fase, jogador1, jogador2, &vetor_de_inimigos);

				// Movimentacao do Jogador 1
				Movimenta_Jogador(jogador1, jogador2, &vetor_de_inimigos);

				// Movimentacao do Jogador 2
				Movimenta_Jogador(jogador2, jogador1, &vetor_de_inimigos);
			}
		}

		// Limpa tela anterior
		SDL_RenderClear(renderer);

		// Renderiza plano de fundo
		Atualiza_Plano_de_Fundo(renderer, &fase);

		// Renderiza jogador 1
		SDL_RenderCopy(renderer, jogador1->sprite, &jogador1->frame, &jogador1->posicao);

		// Renderiza jogador 2
		SDL_RenderCopy(renderer, jogador2->sprite, &jogador2->frame, &jogador2->posicao);

		// Renderiza inimigos em tela
		Atualiza_Inimigos_em_Tela(renderer, &vetor_de_inimigos);

		// Atualiza tela
		SDL_RenderPresent(renderer);

		// FPS
		SDL_Delay( 1000/FPS );

	}

	// Limpando memoria - imagens
	SDL_DestroyTexture(fase.sprite);
	SDL_DestroyTexture(jogador1->sprite);
	SDL_DestroyTexture(jogador2->sprite);

	//
	// **************
	// LOOP DO JOGO | fim
	// **************
	//

	// *********************************************************************
}

// Estado de pause
void Roda_Pause(SDL_Renderer* renderer, SDL_Event event, Fase* fase,
	Jogador* jogador1, Jogador* jogador2, Vetor_de_Inimigos* vetor_de_inimigos)
{
	// Variavel para manter o loop do pause
	int pauseRodando = VERDADEIRO;

	// Variavel para carregar imagens
	SDL_Surface* Loading_Surf = NULL;

	// *********************************************************************

	//
	// ******************
	//	Esucrecer a tela| inicio
	//	*****************
	//

	SDL_Texture* gEscurecer = NULL	;

	Loading_Surf = IMG_Load("arte/fundo/escurecer.png"); 

	gEscurecer = SDL_CreateTextureFromSurface(renderer, Loading_Surf);

	SDL_FreeSurface(Loading_Surf);

	SDL_Rect escurecer;

	escurecer.x = 0;
	escurecer.y = 0;
	escurecer.w = SCREEN_WIDTH;
	escurecer.h = SCREEN_HEIGHT;

	//
	// ******************
	//	Esucrecer a tela| fim
	// ******************
	//

	// *********************************************************************

	//
	// *******
	// PAUSE | inicio
	// *******
	//

	// Variavel para conter plano de fundo
	SDL_Texture* gPause = NULL;

	// Carrega plano de fundo na memoria
	Loading_Surf = IMG_Load("arte/menu/pause.png");

	// Carrega imagem na tela
	gPause = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf);

	// Limpa variavel Loading_Surf
	SDL_FreeSurface(Loading_Surf);

	// Declarando rect
	SDL_Rect pause;

	pause.x = 275;
	pause.y = 150;
	pause.w = 250;
	pause.h = 50;

	//
	// *******
	// PAUSE | fim
	// *******
	//

	// *********************************************************************

	//
	// ****************
	// CONTINUAR JOGO | inicio
	// ****************
	//

	// Variavel que carrega a opcao de iniciar o jogo
	SDL_Texture* gContinuar = NULL;

	// Carregando plano de fundo na memoria
	Loading_Surf = IMG_Load("arte/menu/continuar.png");

	// Carregando imagem na tela
	gContinuar = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf);

	// Limpando memoria
	SDL_FreeSurface(Loading_Surf);

	// Variavel que carrega a opcao de iniciar o jogo pressionado
	SDL_Texture* gContinuar_pressionado = NULL;

	// Carregando plano de fundo na memoria
	Loading_Surf = IMG_Load("arte/menu/continuar_pressionado.png");

	// Carregando imagem na tela
	gContinuar_pressionado = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf);

	// Limpando memoria
	SDL_FreeSurface(Loading_Surf);

	// Declarando rect
	SDL_Rect continuar;

	continuar.x = 275;
	continuar.y = 250;
	continuar.w = 250;
	continuar.h = 50;

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

	opcoes.x = 275;
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

	sair.x = 275;
	sair.y = 350;
	sair.w = 250;
	sair.h = 50;

	//
	// **************
	// SAIR DO JOGO | fim
	// **************
	//

	// *********************************************************************

	// Variavel para uso do som nas selecoes
	int SELECIONADO;

	#define BOTAO_CONTINUAR			1
	#define BOTAO_OPCOES			2
	#define BOTAO_SAIR				3

	SELECIONADO = BOTAO_CONTINUAR;

	// Loop do pause
	while (pauseRodando)
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
				pauseRodando = FALSO;
				singleplayerRodando = FALSO;
				multiplayerRodando = FALSO;
				jogoRodando = FALSO;
			}

			// Eventos de tecla pressionada
			if (event.type == SDL_KEYDOWN)
			{
				
				switch (event.key.keysym.sym)
				{
					case SDLK_ESCAPE: // Encerra o pause
						Efeito_Sonoro(SELECT);
						SDL_Delay(400); // Delay de 0.4 segundos
						pauseRodando = FALSO;
						break;

					case SDLK_UP:
						switch (SELECIONADO)
						{
							case BOTAO_CONTINUAR:
								break;

							case BOTAO_OPCOES:
								SELECIONADO = BOTAO_CONTINUAR;
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
							case BOTAO_CONTINUAR:
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
							case BOTAO_CONTINUAR:
								Efeito_Sonoro(SELECT);
								SDL_Delay(400); // Delay de 0.4 segundos
								pauseRodando = FALSO;
								break;

							case BOTAO_OPCOES:
								Efeito_Sonoro(SELECT);
								break;

							case BOTAO_SAIR:
								Efeito_Sonoro(VOLTAR);
								SDL_Delay(500); // Delay de 0.5 segundos
								Roda_SairDoPause_SN(&pauseRodando, renderer, event, fase, jogador1, jogador2, vetor_de_inimigos);
								break;
						}
						break;
				}
			}

			// Eventos de mouse
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				//
				// Acoes
				//

				// Continuar jogo
				if (posicao_do_mouse.x > 300
					&& posicao_do_mouse.x < 500
					&& posicao_do_mouse.y > 250
					&& posicao_do_mouse.y < 300)
				{
					Efeito_Sonoro(SELECT);
					SDL_Delay(400); // Delay de 0.4 segundos
					pauseRodando = FALSO;
				}

				// Opcoes
				if (posicao_do_mouse.x > 325
					&& posicao_do_mouse.x < 475
					&& posicao_do_mouse.y > 300
					&& posicao_do_mouse.y < 350)
				{
					Efeito_Sonoro(SELECT);
					SDL_Delay(400); // Delay de 0.4 segundos
				}

				// Sair
				if (posicao_do_mouse.x > 360
					&& posicao_do_mouse.x < 440
					&& posicao_do_mouse.y > 350
					&& posicao_do_mouse.y < 400)
				{
					Efeito_Sonoro(VOLTAR);
					SDL_Delay(500); // Delay de 0.5 segundos
					Roda_SairDoPause_SN(&pauseRodando, renderer, event, fase, jogador1, jogador2, vetor_de_inimigos);
				}
			}
		}

		// Limpa tela anterior
		SDL_RenderClear(renderer);

		//
		// Rendezira jogo pausado
		//

		// Renderiza plano de fundo
		Atualiza_Plano_de_Fundo(renderer, fase);

		// Renderiza jogador 1
		SDL_RenderCopy(renderer, jogador1->sprite, &jogador1->frame, &jogador1->posicao);

		// Renderiza Jogador 2 caso exista
		if (jogador2 != NULL)
			SDL_RenderCopy(renderer, jogador2->sprite, &jogador2->frame, &jogador2->posicao);

		// Renderiza inimigos em tela
		Atualiza_Inimigos_em_Tela(renderer, vetor_de_inimigos);

		// **********************************************************************************

		//
		// Renderiza partes da tela do pause
		//

		// Escurecer tela
		SDL_RenderCopy(renderer, gEscurecer, NULL, &escurecer);

		// Pause escrito em tela
		SDL_RenderCopy(renderer, gPause, NULL, &pause);

		//
		// Animacao das opcoes
		//

		// Continuar jogo - animacao
		if ((posicao_do_mouse.x > 300
			&& posicao_do_mouse.x < 500
			&& posicao_do_mouse.y > 250
			&& posicao_do_mouse.y < 300)
			|| SELECIONADO == BOTAO_CONTINUAR)
		{
			SDL_RenderCopy(renderer, gContinuar_pressionado, NULL, &continuar);

			// Animacao de som
			if (SELECIONADO != BOTAO_CONTINUAR)
				Efeito_Sonoro(CLICK);
			SELECIONADO = BOTAO_CONTINUAR;
		}
		else
			SDL_RenderCopy(renderer, gContinuar, NULL, &continuar);

		// Menu de opcoes - animacao
		if ((posicao_do_mouse.x > 325
			&& posicao_do_mouse.x < 475
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
		if ((posicao_do_mouse.x > 360
			&& posicao_do_mouse.x < 440
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

		// **********************************************************************************

		// Atualiza tela
		SDL_RenderPresent(renderer);

		// FPS
		SDL_Delay( 1000/FPS );
	}

	// Limpando memoria - imagens
	SDL_DestroyTexture(gEscurecer);
	SDL_DestroyTexture(gPause);
	SDL_DestroyTexture(gContinuar);
	SDL_DestroyTexture(gContinuar_pressionado);
	SDL_DestroyTexture(gOpcoes);
	SDL_DestroyTexture(gOpcoes_pressionado);
	SDL_DestroyTexture(gSair);
	SDL_DestroyTexture(gSair_pressionado);
}

// Estado de pause - certeza de sair
void Roda_SairDoPause_SN(int* pauseRodando, SDL_Renderer* renderer, SDL_Event event, Fase* fase,
	Jogador* jogador1, Jogador* jogador2, Vetor_de_Inimigos* vetor_de_inimigos)
{
	// Variavel para manter o loop do pause
	int pauseRodandoSair = VERDADEIRO;

	// Variavel para carregar imagens
	SDL_Surface* Loading_Surf = NULL;

	// *********************************************************************

	//
	// ******************
	//	Esucrecer a tela| inicio
	//	*****************
	//

	SDL_Texture* gEscurecer = NULL	;

	Loading_Surf = IMG_Load("arte/fundo/escurecer.png"); 

	gEscurecer = SDL_CreateTextureFromSurface(renderer, Loading_Surf);

	SDL_FreeSurface(Loading_Surf);

	SDL_Rect escurecer;

	escurecer.x = 0;
	escurecer.y = 0;
	escurecer.w = SCREEN_WIDTH;
	escurecer.h = SCREEN_HEIGHT;

	//
	// ******************
	//	Esucrecer a tela| fim
	// ******************
	//

	// *********************************************************************

	//
	// ******
	// SAIR | inicio
	// ******
	//

	// Variavel para conter plano de fundo
	SDL_Texture* gSair = NULL;

	// Carrega plano de fundo na memoria
	Loading_Surf = IMG_Load("arte/menu/sair.png");

	// Carrega imagem na tela
	gSair = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf);

	// Limpa variavel Loading_Surf
	SDL_FreeSurface(Loading_Surf);

	// Declarando rect
	SDL_Rect sair;

	sair.x = 275;
	sair.y = 150;
	sair.w = 250;
	sair.h = 50;

	//
	// ******
	// SAIR | fim
	// ******
	//

	// *********************************************************************

	//
	// *************
	// TEM CERTEZA | inicio
	// *************
	//

	// Variavel para conter plano de fundo
	SDL_Texture* gTem_certeza = NULL;

	// Carrega plano de fundo na memoria
	Loading_Surf = IMG_Load("arte/menu/tem_certeza.png");

	// Carrega imagem na tela
	gTem_certeza = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf);

	// Limpa variavel Loading_Surf
	SDL_FreeSurface(Loading_Surf);

	// Declarando rect
	SDL_Rect tem_certeza;

	tem_certeza.x = 250;
	tem_certeza.y = 225;
	tem_certeza.w = 300;
	tem_certeza.h = 50;

	//
	// *************
	// TEM CERTEZA | fim
	// *************
	//

	// *********************************************************************

	//
	// *****
	// SIM | inicio
	// *****
	//

	// Variavel que carrega a opcao de iniciar o jogo
	SDL_Texture* gSim = NULL;

	// Carregando plano de fundo na memoria
	Loading_Surf = IMG_Load("arte/menu/sim.png");

	// Carregando imagem na tela
	gSim = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf);

	// Limpando memoria
	SDL_FreeSurface(Loading_Surf);

	// Variavel que carrega a opcao de iniciar o jogo pressionado
	SDL_Texture* gSim_pressionado = NULL;

	// Carregando plano de fundo na memoria
	Loading_Surf = IMG_Load("arte/menu/sim_pressionado.png");

	// Carregando imagem na tela
	gSim_pressionado = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf);

	// Limpando memoria
	SDL_FreeSurface(Loading_Surf);

	// Declarando rect
	SDL_Rect sim;

	sim.x = 150;
	sim.y = 300;
	sim.w = 250;
	sim.h = 50;

	//
	// *****
	// SIM | fim
	// *****
	//

	// ********************************************************************************

	//
	// *****
	// NAO | inicio
	// *****
	//

	// Variavel que carrega a opcao de sair do jogo
	SDL_Texture* gNao = NULL;

	// Carregando plano de fundo na memoria
	Loading_Surf = IMG_Load("arte/menu/nao.png");

	// Carregando imagem na tela
	gNao = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf);

	// Limpando memoria
	SDL_FreeSurface(Loading_Surf);

	// Variavel que carrega a opcao de sair do jogo
	SDL_Texture* gNao_pressionado = NULL;

	// Carregando plano de fundo na memoria
	Loading_Surf = IMG_Load("arte/menu/nao_pressionado.png");

	// Carregando imagem na tela
	gNao_pressionado = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf);

	// Limpando memoria
	SDL_FreeSurface(Loading_Surf);

	// Declarando rect
	SDL_Rect nao;

	nao.x = 400;
	nao.y = 300;
	nao.w = 250;
	nao.h = 50;

	//
	// *****
	// NAO | fim
	// *****
	//

	// *********************************************************************

	// Variavel para uso do som nas selecoes
	int SELECIONADO;

	#define BOTAO_SIM			1
	#define BOTAO_NAO			2

	SELECIONADO = BOTAO_CONTINUAR;

	// Loop do pause
	while (pauseRodandoSair)
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
				pauseRodando = FALSO;
				pauseRodandoSair = FALSO;
				singleplayerRodando = FALSO;
				multiplayerRodando = FALSO;
				jogoRodando = FALSO;
			}

			// Eventos de tecla pressionada
			if (event.type == SDL_KEYDOWN)
			{
				
				switch (event.key.keysym.sym)
				{
					case SDLK_ESCAPE: // Encerra o pause
						Efeito_Sonoro(SELECT);
						SDL_Delay(400); // Delay de 0.4 segundos
						pauseRodandoSair = FALSO;
						break;

					case SDLK_LEFT:
						switch (SELECIONADO)
						{
							case BOTAO_SIM:
								break;

							case BOTAO_NAO:
								SELECIONADO = BOTAO_SIM;
								Efeito_Sonoro(CLICK);
								break;
						}
						break;

					case SDLK_RIGHT:
						switch (SELECIONADO)
						{
							case BOTAO_SIM:
								SELECIONADO = BOTAO_NAO;
								Efeito_Sonoro(CLICK);
								break;

							case BOTAO_NAO:
							break;
						}
						break;

					case SDLK_RETURN:
						switch (SELECIONADO)
						{
							case BOTAO_NAO:
								Efeito_Sonoro(SELECT);
								SDL_Delay(400); // Delay de 0.4 segundos
								pauseRodandoSair = FALSO;
								break;

							case BOTAO_SIM:
								Efeito_Sonoro(VOLTAR);
								SDL_Delay(500); // Delay de 0.5 segundos
								pauseRodandoSair = FALSO;
								*pauseRodando = FALSO;
								singleplayerRodando = FALSO;
								multiplayerRodando = FALSO;
								estadoDeJogo = MENU;
								break;
						}
						break;
				}
			}

			// Eventos de mouse
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				//
				// Acoes
				//

				// Nao
				if (posicao_do_mouse.x > 485
					&& posicao_do_mouse.x < 570
					&& posicao_do_mouse.y > 300
					&& posicao_do_mouse.y < 350)
				{
					Efeito_Sonoro(SELECT);
					SDL_Delay(400); // Delay de 0.4 segundos
					pauseRodandoSair = FALSO;
				}

				// Sim
				if (posicao_do_mouse.x > 240
					&& posicao_do_mouse.x < 320
					&& posicao_do_mouse.y > 300
					&& posicao_do_mouse.y < 350)
				{
					Efeito_Sonoro(VOLTAR);
					SDL_Delay(500); // Delay de 0.5 segundos
					SDL_Delay(500); // Delay de 0.5 segundos
					pauseRodandoSair = FALSO;
					*pauseRodando = FALSO;
					singleplayerRodando = FALSO;
					multiplayerRodando = FALSO;
					estadoDeJogo = MENU;

				}
			}
		}

		// Limpa tela anterior
		SDL_RenderClear(renderer);

		//
		// Rendezira jogo pausado
		//

		// Renderiza plano de fundo
		Atualiza_Plano_de_Fundo(renderer, fase);

		// Renderiza jogador 1
		SDL_RenderCopy(renderer, jogador1->sprite, &jogador1->frame, &jogador1->posicao);

		// Renderiza Jogador 2 caso exista
		if (jogador2 != NULL)
			SDL_RenderCopy(renderer, jogador2->sprite, &jogador2->frame, &jogador2->posicao);

		// Renderiza inimigos em tela
		Atualiza_Inimigos_em_Tela(renderer, vetor_de_inimigos);

		// **********************************************************************************

		//
		// Renderiza partes da tela do pause
		//

		// Escurecer tela
		SDL_RenderCopy(renderer, gEscurecer, NULL, &escurecer);

		// Pause escrito em tela
		SDL_RenderCopy(renderer, gSair, NULL, &sair);

		// Tem certeza escrito em tela
		SDL_RenderCopy(renderer, gTem_certeza, NULL, &tem_certeza);

		//
		// Animacao das opcoes
		//

		// Sim - animacao
		if ((posicao_do_mouse.x > 240
			&& posicao_do_mouse.x < 320
			&& posicao_do_mouse.y > 300
			&& posicao_do_mouse.y < 350)
			|| SELECIONADO == BOTAO_SIM)
		{
			SDL_RenderCopy(renderer, gSim_pressionado, NULL, &sim);

			// Animacao de som
			if (SELECIONADO != BOTAO_SIM)
				Efeito_Sonoro(CLICK);
			SELECIONADO = BOTAO_SIM;
		}
		else
			SDL_RenderCopy(renderer, gSim, NULL, &sim);

		// Nao - animacao
		if ((posicao_do_mouse.x > 485
			&& posicao_do_mouse.x < 570
			&& posicao_do_mouse.y > 300
			&& posicao_do_mouse.y < 350)
			|| SELECIONADO == BOTAO_NAO)
		{
			SDL_RenderCopy(renderer, gNao_pressionado, NULL, &nao);

			// Animacao de som
			if (SELECIONADO != BOTAO_NAO)
				Efeito_Sonoro(CLICK);
			SELECIONADO = BOTAO_NAO;
		}
		else
			SDL_RenderCopy(renderer, gNao, NULL, &nao);


		// **********************************************************************************

		// Atualiza tela
		SDL_RenderPresent(renderer);

		// FPS
		SDL_Delay( 1000/FPS );
	}

	// Limpando memoria - imagens
	SDL_DestroyTexture(gEscurecer);
	SDL_DestroyTexture(gSair);
	SDL_DestroyTexture(gTem_certeza);
	SDL_DestroyTexture(gSim);
	SDL_DestroyTexture(gSim_pressionado);
	SDL_DestroyTexture(gNao);
	SDL_DestroyTexture(gNao_pressionado);
}

