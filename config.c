// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

/*
	CONFIGURACOES

	Jogo de desenvolvido para projeto de computacao 1
*/

#include "main.h"
#include "config.h"

// Pre carregamento das funcoes
Jogador Carrega_Jogador(int numero);
void Carrega_Teclas_de_Acao(Jogador* jogador);
Fase Inicializa_Fases();
void Carrega_Fase_Memoria(SDL_Renderer* renderer, Fase* fase);
void Troca_portal(SDL_Renderer* renderer, Fase* fase, int portal, int tipo);
void Atualiza_Plano_de_Fundo(SDL_Renderer* renderer, Fase*fase);


// Carrega parametros iniciais do jogador
Jogador Carrega_Jogador(int numero)
{
	// Estrutura com informacoes do jogador
	Jogador jogador;

	// Colisao
	jogador.colisao = FALSO;

	// Numero do jogador
	jogador.numero = numero;

	// Velocidade de movimento do jogador
	jogador.velocidade.x = VEL;
	jogador.velocidade.y = VEL;

	// Dimensoes da imagem do sprite do jogador
	jogador.fullH = SPRITE_FULL_H;
	jogador.fullW = SPRITE_FULL_W;

	// Rect do frame do sprite do jogador
	jogador.frame.x = 0;
	jogador.frame.y = 512;
	jogador.frame.w = SPRITE_FRAME_W;
	jogador.frame.h = SPRITE_FRAME_H;

	// Rect para posisao do jogador em tela
	jogador.posicao.w = SPRITE_FRAME_W;
	jogador.posicao.h = SPRITE_FRAME_H;

	// Variavel para conter imagem do jogador
	jogador.sprite = NULL;

	return jogador;
}

// Carrega teclas de acao do jogador
void Carrega_Teclas_de_Acao(Jogador* jogador)
{
	// Pega estado atual das teclas pressionadas
	const Uint8 *keystates = SDL_GetKeyboardState(NULL);

	// Atribui uma tecla para cada jogador
	switch (jogador->numero)
	{
		case 1: // Jogador 1
			jogador->movimento.cima = keystates[SDL_SCANCODE_UP];
			jogador->movimento.baixo = keystates[SDL_SCANCODE_DOWN];
			jogador->movimento.esquerda = keystates[SDL_SCANCODE_LEFT];
			jogador->movimento.direita = keystates[SDL_SCANCODE_RIGHT];
			jogador->movimento.ataque = keystates[SDL_SCANCODE_RETURN];
			break;

		case 2: // Jogador 2
			jogador->movimento.cima = keystates[SDL_SCANCODE_W];
			jogador->movimento.baixo = keystates[SDL_SCANCODE_S];
			jogador->movimento.esquerda = keystates[SDL_SCANCODE_A];
			jogador->movimento.direita = keystates[SDL_SCANCODE_D];
			jogador->movimento.ataque = keystates[SDL_SCANCODE_BACKSPACE];
			break;
	}
}

// ******************************************************************************

//
// Funcoes relacionadas as fases
//

// Carrega fases do jogo
Fase Inicializa_Fases()
{
	// Inicializa variavel
	Fase fase;

	// Inicia na fase 1
	fase.numero = 0;

	// Define portal tipo 1 para todos os lados
	fase.portal.cima.tipo = 1;
	fase.portal.baixo.tipo = 1;
	fase.portal.esquerda.tipo = 1;
	fase.portal.direita.tipo = 1;

	//
	// Posicao nos frames
	//

	// Cima
	fase.portal.cima.frame.x = 0;
	fase.portal.cima.frame.y = 0;
	fase.portal.cima.frame.w = 59;
	fase.portal.cima.frame.h = 30;

	// Baixo
	fase.portal.baixo.frame.x = 0;
	fase.portal.baixo.frame.y = 0;
	fase.portal.baixo.frame.w = 59;
	fase.portal.baixo.frame.h = 30;

	// Esquerda
	fase.portal.esquerda.frame.x = 0;
	fase.portal.esquerda.frame.y = 0;
	fase.portal.esquerda.frame.w = 30;
	fase.portal.esquerda.frame.h = 59;

	// Direita
	fase.portal.direita.frame.x = 0;
	fase.portal.direita.frame.y = 0;
	fase.portal.direita.frame.w = 30;
	fase.portal.direita.frame.h = 59;

	//
	// Posicao na tela
	//

	// Cima
	fase.portal.cima.posicao.x = 362;
	fase.portal.cima.posicao.y = 0;
	fase.portal.cima.posicao.w = 80;
	fase.portal.cima.posicao.h = 50;

	// Baixo
	fase.portal.baixo.posicao.x = 362;
	fase.portal.baixo.posicao.y = 550;
	fase.portal.baixo.posicao.w = 80;
	fase.portal.baixo.posicao.h = 50;

	// Esquerda
	fase.portal.esquerda.posicao.x = 0;
	fase.portal.esquerda.posicao.y = 280;
	fase.portal.esquerda.posicao.w = 50;
	fase.portal.esquerda.posicao.h = 55;

	// Direita
	fase.portal.direita.posicao.x = 748;
	fase.portal.direita.posicao.y = 265;
	fase.portal.direita.posicao.w = 50;
	fase.portal.direita.posicao.h = 55;

	return fase;
}

// Carrega sprites das fases no jogo
void Carrega_Fase_Memoria(SDL_Renderer* renderer, Fase* fase)
{
	// Variavel para carregar imagens
	SDL_Surface* Loading_Surf = NULL;

	switch (fase->numero)
	{
		case 0:
			Loading_Surf = IMG_Load(MAPA_1);
			break;

		case 1:
			Loading_Surf = IMG_Load(MAPA_2);
			break;

		case 2:
			Loading_Surf = IMG_Load(MAPA_3);
			break;

		case 3:
			Loading_Surf = IMG_Load(MAPA_4);
			break;
	}

	// Carrega sprite na textura
	fase->sprite = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf);

	// Limpa memoria
	SDL_FreeSurface (Loading_Surf);

	// *****************************************************************************

	//
	// Carrega portais tipo 1
	//

	fase->portal.animacao = 1;

	// Cima
	Loading_Surf = IMG_Load("arte/portal/vermelho_cima.png");

	// Carregando na textura
	fase->portal.cima.sprite = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf);

	// Limpando memoria
	SDL_FreeSurface(Loading_Surf);

	// ******************************************************************

	// Baixo
	Loading_Surf = IMG_Load("arte/portal/vermelho_baixo.png");

	// Carrega na textura
	fase->portal.baixo.sprite = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf);

	// Limpando memoria
	SDL_FreeSurface(Loading_Surf);

	// **************************************************************************

	// Esquerda
	Loading_Surf = IMG_Load("arte/portal/vermelho_esquerda.png");

	// Carregando na textura
	fase->portal.esquerda.sprite = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf);

	// Limpando memoria
	SDL_FreeSurface(Loading_Surf);

	// ********************************************************************

	// Direita
	Loading_Surf = IMG_Load("arte/portal/vermelho_direita.png");

	// Carrega na textura
	fase->portal.direita.sprite = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf);

	// Limpando memoria
	SDL_FreeSurface(Loading_Surf);

	//*********************************************************************
}

// Altera tipo de portal
void Troca_portal(SDL_Renderer* renderer, Fase* fase, int portal, int tipo)
{
	// Variavel para carregar imagens
	SDL_Surface* Loading_Surf = NULL;

	switch (portal)
	{
		case CIMA:
			// Seleciona o tipo de portal
			switch (tipo)
			{
				case 1:
					Loading_Surf = IMG_Load("arte/portal/vermelho_cima.png");
					break;

				case 2:
					Loading_Surf = IMG_Load("arte/portal/azul_cima.png");
					break;

				case 3:
					Loading_Surf = IMG_Load("arte/portal/cinza_cima.png");
					break;
			}

			fase->portal.cima.sprite = SDL_CreateTextureFromSurface(renderer,
				Loading_Surf);
			break;

			// ***********************************************************************


		case BAIXO:
			// Seleciona o tipo de portal
			switch (tipo)
			{
				case 1:
					Loading_Surf = IMG_Load("arte/portal/vermelho_baixo.png");
					break;

				case 2:
					Loading_Surf = IMG_Load("arte/portal/azul_baixo.png");
					break;

				case 3:
					Loading_Surf = IMG_Load("arte/portal/cinza_baixo.png");
					break;
			}

			fase->portal.baixo.sprite = SDL_CreateTextureFromSurface(renderer,
				Loading_Surf);
			break;

			// *****************************************************************

		case ESQUERDA:
			// Seleciona o tipo de portal
			switch (tipo)
			{
				case 1:
					Loading_Surf = IMG_Load("arte/portal/vermelho_esquerda.png");
					break;

				case 2:
					Loading_Surf = IMG_Load("arte/portal/azul_esquerda.png");
					break;

				case 3:
					Loading_Surf = IMG_Load("arte/portal/cinza_esquerda.png");
					break;
			}

			fase->portal.esquerda.sprite = SDL_CreateTextureFromSurface(renderer,
				Loading_Surf);
			break;

			// ***********************************************************************

		case DIREITA:
			// Seleciona o tipo de portal
			switch (tipo)
			{
				case 1:
					Loading_Surf = IMG_Load("arte/portal/vermelho_direita.png");
					break;

				case 2:
					Loading_Surf = IMG_Load("arte/portal/azul_direita.png");
					break;

				case 3:
					Loading_Surf = IMG_Load("arte/portal/cinza_direita.png");
					break;
			}

			fase->portal.direita.sprite = SDL_CreateTextureFromSurface(renderer,
				Loading_Surf);
			break;

			// ***********************************************************************
	}

	// Limpa memoria
	SDL_FreeSurface(Loading_Surf);
}

// Carrega fundo da fase em tela
void Atualiza_Plano_de_Fundo(SDL_Renderer* renderer, Fase*fase)
{
	// Carrega fundo da fase
	SDL_RenderCopy(renderer, fase->sprite, NULL, NULL);

	//
	// Carrega portais
	//

	Anima_Portal(fase);

	// Cima
	SDL_RenderCopy(renderer, fase->portal.cima.sprite,
		&fase->portal.cima.frame, &fase->portal.cima.posicao);

	// Baixo
	SDL_RenderCopy(renderer, fase->portal.baixo.sprite,
		&fase->portal.baixo.frame, &fase->portal.baixo.posicao);

	// Esquerda
	SDL_RenderCopy(renderer, fase->portal.esquerda.sprite,
		&fase->portal.esquerda.frame, &fase->portal.esquerda.posicao);

	// Direita
	SDL_RenderCopy(renderer, fase->portal.direita.sprite,
		&fase->portal.direita.frame, &fase->portal.direita.posicao);

	fase->portal.animacao++;

	if (fase->portal.animacao > 17)
		fase->portal.animacao = 1;
}

void Anima_Portal(Fase *fase)
{
	switch (fase->portal.animacao)
	{
		case 1:
			fase->portal.cima.frame.x = 0;
			fase->portal.baixo.frame.x = 0;
			fase->portal.esquerda.frame.y = 0;
			fase->portal.direita.frame.y = 0;
			break;

		case 3:
			fase->portal.cima.frame.x = 59;
			fase->portal.baixo.frame.x = 59;
			fase->portal.esquerda.frame.y = 59;
			fase->portal.direita.frame.y = 59;
			break;

		case 5:
			fase->portal.cima.frame.x = 118;
			fase->portal.baixo.frame.x = 118;
			fase->portal.esquerda.frame.y = 118;
			fase->portal.direita.frame.y = 118;
			break;

		case 7:
			fase->portal.cima.frame.x = 177;
			fase->portal.baixo.frame.x = 177;
			fase->portal.esquerda.frame.y = 177;
			fase->portal.direita.frame.y = 177;
			break;

		case 9:
			fase->portal.cima.frame.x = 236;
			fase->portal.baixo.frame.x = 236;
			fase->portal.esquerda.frame.y = 236;
			fase->portal.direita.frame.y = 236;
			break;

		case 11:
			fase->portal.cima.frame.x = 295;
			fase->portal.baixo.frame.x = 295;
			fase->portal.esquerda.frame.y = 295;
			fase->portal.direita.frame.y = 295;
			break;

		case 13:
			fase->portal.cima.frame.x = 354;
			fase->portal.baixo.frame.x = 354;
			fase->portal.esquerda.frame.y = 354;
			fase->portal.direita.frame.y = 354;
			break;

		case 15:
			fase->portal.cima.frame.x = 413;
			fase->portal.baixo.frame.x = 413;
			fase->portal.esquerda.frame.y = 413;
			fase->portal.direita.frame.y = 413;
			break;

		case 17:
			fase->portal.cima.frame.x = 472;
			fase->portal.baixo.frame.x = 472;
			fase->portal.esquerda.frame.y = 472;
			fase->portal.direita.frame.y = 472;
			break;
	}
}