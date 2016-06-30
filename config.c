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


// Carrega parametros iniciais do jogador
Jogador Carrega_Jogador(int numero)
{
	// Estrutura com informacoes do jogador
	Jogador jogador;

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
	fase.portal.cima.frame.w = 0;
	fase.portal.cima.frame.h = 0;

	// Baixo
	fase.portal.baixo.frame.x = 0;
	fase.portal.baixo.frame.y = 0;
	fase.portal.baixo.frame.w = 0;
	fase.portal.baixo.frame.h = 0;

	// Esquerda
	fase.portal.esquerda.frame.x = 0;
	fase.portal.esquerda.frame.y = 0;
	fase.portal.esquerda.frame.w = 0;
	fase.portal.esquerda.frame.h = 0;

	// Direita
	fase.portal.direita.frame.x = 0;
	fase.portal.direita.frame.y = 0;
	fase.portal.direita.frame.w = 0;
	fase.portal.direita.frame.h = 0;

	//
	// Posicao na tela
	//

	// Cima
	fase.portal.cima.posicao.x = 0;
	fase.portal.cima.posicao.y = 0;
	fase.portal.cima.posicao.w = 0;
	fase.portal.cima.posicao.h = 0;

	// Baixo
	fase.portal.baixo.posicao.x = 0;
	fase.portal.baixo.posicao.y = 0;
	fase.portal.baixo.posicao.w = 0;
	fase.portal.baixo.posicao.h = 0;

	// Esquerda
	fase.portal.esquerda.posicao.x = 0;
	fase.portal.esquerda.posicao.y = 0;
	fase.portal.esquerda.posicao.w = 0;
	fase.portal.esquerda.posicao.h = 0;

	// Direita
	fase.portal.direita.posicao.x = 0;
	fase.portal.direita.posicao.y = 0;
	fase.portal.direita.posicao.w = 0;
	fase.portal.direita.posicao.h = 0;

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
			SDL_DestroyTexture(fase->mapa[0].sprite);
			break;

		case 2:
			Loading_Surf = IMG_Load(MAPA_3);
			SDL_DestroyTexture(fase->mapa[1].sprite);
			break;

		case 3:
			Loading_Surf = IMG_Load(MAPA_4);
			SDL_DestroyTexture(fase->mapa[2].sprite);
			break;
	}

	// Carrega sprite na textura
	fase->mapa[fase->numero].sprite = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf);

	// Limpa memoria
	SDL_FreeSurface (Loading_Surf);

	// *****************************************************************************

	//
	// Carrega portais
	//

	// Cima
	switch (fase->portal.cima.tipo)
	{
		case 1:
			Loading_Surf = IMG_Load(PORTAL_1D);
			break;

		case 2:
			Loading_Surf = IMG_Load(PORTAL_2D);
			break;

		case 3:
			Loading_Surf = IMG_Load(PORTAL_3D);
			break;
	}

	// Carregando na textura
	fase->portal.cima.sprite = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf);

	// Limpando memoria
	SDL_FreeSurface(Loading_Surf);

	// ******************************************************************

	// Baixo
	switch (fase->portal.baixo.tipo)
	{
		case 1:
			Loading_Surf = IMG_Load(PORTAL_1D);
			break;

		case 2:
			Loading_Surf = IMG_Load(PORTAL_2D);
			break;

		case 3:
			Loading_Surf = IMG_Load(PORTAL_3D);
			break;
	}

	// Carrega na textura
	fase->portal.baixo.sprite = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf);

	// Limpando memoria
	SDL_FreeSurface(Loading_Surf);

	// **************************************************************************

	// Esquerda
	switch (fase->portal.esquerda.tipo)
	{
		case 1:
			Loading_Surf = IMG_Load(PORTAL_1L);
			break;

		case 2:
			Loading_Surf = IMG_Load(PORTAL_2L);
			break;

		case 3:
			Loading_Surf = IMG_Load(PORTAL_3L);
			break;
	}

	// Carregando na textura
	fase->portal.esquerda.sprite = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf);

	// Limpando memoria
	SDL_FreeSurface(Loading_Surf);

	// Esquerda e direita
	switch (fase->portal.direita.tipo)
	{
		case 1:
			Loading_Surf = IMG_Load(PORTAL_1L);
			break;

		case 2:
			Loading_Surf = IMG_Load(PORTAL_2L);
			break;

		case 3:
			Loading_Surf = IMG_Load(PORTAL_3L);
			break;
	}

	// Carrega na textura
	fase->portal.direita.sprite = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf);

	// Limpando memoria
	SDL_FreeSurface(Loading_Surf);
}