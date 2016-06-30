// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

/*
	INIMIGO

	Jogo de desenvolvido para projeto de computacao 1
*/

#include "main.h"
#include "inimigo.h"
#include "config.h"
#include "fisica.h"

// Pre carregamento das funcoes
Inimigo Carrega_Inimigo(SDL_Renderer* renderer, int numero);
Vetor_de_Inimigos Cria_Vetor_de_inimigos(SDL_Renderer* renderer, int quantidade, int tipo);
void Movimenta_Inimigo(Inimigo* inimigo);
void IA_de_Movimentacao(Inimigo* inimigo, Jogador* jogador1, Jogador* jogador2);
void Atualiza_Inimigos_em_Tela(SDL_Renderer* renderer, Vetor_de_Inimigos* vetor_de_inimigos);

//
// Funcoes de carregamento
//

// Funcao para carregar inimigo
Inimigo Carrega_Inimigo(SDL_Renderer* renderer, int tipo)
{
	// Estrutura com informacoes do inimigo
	Inimigo inimigo;

	// Numero do inimigo
	inimigo.tipo = tipo;

	SDL_Surface* Loading_Surf = NULL;

	switch(tipo)
	{
		case 1:
			// Velocidade de movimento do inimigo
			inimigo.velocidade.x = 2.5;
			inimigo.velocidade.y = 2.5;
			Loading_Surf = IMG_Load("arte/personagens/vilao01/esqueleto.png");
			break;

		case 2:
			// Velocidade de movimento do inimigo
			inimigo.velocidade.x = 2.5;
			inimigo.velocidade.y = 2.5;
			Loading_Surf = IMG_Load("arte/personagens/vilao02/orc.png");
			break;

		case 3:
			// Velocidade de movimento do inimigo
			inimigo.velocidade.x = 2.5;
			inimigo.velocidade.y = 2.5;
			Loading_Surf = IMG_Load("arte/personagens/vilao03/blackelf.png");
			break;
	}

	inimigo.sprite = SDL_CreateTextureFromSurface(renderer, Loading_Surf);

	// Dimensoes da imagem do sprite do inimigo
	inimigo.fullH = SPRITE_FULL_H;
	inimigo.fullW = SPRITE_FULL_W;

	// Rect do frame do sprite do inimigo
	inimigo.frame.x = 0;
	inimigo.frame.y = 512;
	inimigo.frame.w = SPRITE_FRAME_W;
	inimigo.frame.h = SPRITE_FRAME_H;

	// Rect para posisao do inimigo em tela
	inimigo.posicao.w = SPRITE_FRAME_W;
	inimigo.posicao.h = SPRITE_FRAME_H;

	SDL_FreeSurface(Loading_Surf);

	return inimigo;
}

// Funcao para criar vetor de inimigos
Vetor_de_Inimigos Cria_Vetor_de_inimigos(SDL_Renderer* renderer, int quantidade, int tipo)
{
	Vetor_de_Inimigos vetor_de_inimigos;

	vetor_de_inimigos.quantidade = quantidade;

	int i;

	for (i = 0; i != quantidade; i++)
	{
		vetor_de_inimigos.inimigo[i] = Carrega_Inimigo(renderer, tipo);
	}

	return vetor_de_inimigos;
}

// **********************************************************************************

//
// Funcoes de movimento
//

// Funcao para executar movimentacao do inimigo
void Movimenta_Inimigo(Inimigo* inimigo)
{
	// Verifica colisao de tela
	int movimento_permitido;
	if (Colisao_Inimigo_LimiteDeTela(inimigo))
		movimento_permitido = FALSO;
	else
		movimento_permitido = VERDADEIRO;

	// ******************************************************************************

	//
	// Movimentos diagonais
	//

	// Nordeste
	if (inimigo->movimento.cima && inimigo->movimento.esquerda)
	{
		// Animacao
		inimigo->frame.y = 512;

		if (inimigo->frame.x < 512)
			inimigo->frame.x += 64;

		else
			inimigo->frame.x = 0;

		// Salva movimento de animacao
		inimigo->animacao = QUADRANTE2;

		// Movimentacao
		if (movimento_permitido)
		{
			inimigo->posicao.y -= inimigo->velocidade.y;
			inimigo->posicao.x -= inimigo->velocidade.x;
		}
	}

	// Noroeste
	else if (inimigo->movimento.cima && inimigo->movimento.direita)
	{
		// Animacao
		inimigo->frame.y = 512;

		if (inimigo->frame.x < 512)
			inimigo->frame.x += 64;

		else
			inimigo->frame.x = 0;

		// Salva movimento de animacao
		inimigo->animacao = QUADRANTE1;

		// Movimentacao
		if (movimento_permitido)
		{
			inimigo->posicao.y -= inimigo->velocidade.y;
			inimigo->posicao.x += inimigo->velocidade.x;
		}
	}

	// Suldeste
	else if (inimigo->movimento.baixo && inimigo->movimento.esquerda)
	{
		// Animacao
		inimigo->frame.y = 640;

		if (inimigo->frame.x < 512)
			inimigo->frame.x += 64;

		else
			inimigo->frame.x = 0;

		// Salva movimento de animacao
		inimigo->animacao = QUADRANTE3;

		// Movimentacao
		if (movimento_permitido)
		{
			inimigo->posicao.y += inimigo->velocidade.y;
			inimigo->posicao.x -= inimigo->velocidade.x;
		}
	}

	// Suldoeste
	else if (inimigo->movimento.baixo && inimigo->movimento.direita)
	{
		// Animacao
		inimigo->frame.y = 640;

		if (inimigo->frame.x < 512)
			inimigo->frame.x += 64;

		else
			inimigo->frame.x = 0;

		// Salva movimento de animacao
		inimigo->animacao = QUADRANTE4;

		// Movimentacao
		if (movimento_permitido)
		{
			inimigo->posicao.y += inimigo->velocidade.y;
			inimigo->posicao.x += inimigo->velocidade.x;
		}
	}

	//
	// Movimentos principais
	//

	// Cima
	else if (inimigo->movimento.cima)
	{
		// Animacao
		inimigo->frame.y = 512;

		if (inimigo->frame.x < 512)
			inimigo->frame.x += 64;
		else
			inimigo->frame.x = 0;

		// Salva movimento de animacao
		inimigo->animacao = CIMA;

		// Movimento
		if (movimento_permitido)
			inimigo->posicao.y -= inimigo->velocidade.y;
	}

	// Baixo
	else if (inimigo->movimento.baixo)
	{
		// Animacao
		inimigo->frame.y = 640;

		if (inimigo->frame.x < 512)
			inimigo->frame.x += 64;
		else
			inimigo->frame.x = 0;

		// Salva movimento de animacao
		inimigo->animacao = BAIXO;

		// Movimento
		if (movimento_permitido)
			inimigo->posicao.y += inimigo->velocidade.y;
	}

	// Esquerda
	else if (inimigo->movimento.esquerda)
	{
		// Animacao
		inimigo->frame.y = 576;

		if (inimigo->frame.x < 512)
			inimigo->frame.x += 64;
		else
			inimigo->frame.x = 0;

		// Salva movimento de animacao
		inimigo->animacao = ESQUERDA;

		// Movimento
		if (movimento_permitido)
			inimigo->posicao.x -= inimigo->velocidade.x;
	}

	// Direita
	else if (inimigo->movimento.direita)
	{
		// Animacao
		inimigo->frame.y = 704;

		if (inimigo->frame.x < 512)
			inimigo->frame.x += 64;
		else
			inimigo->frame.x = 0;

		// Salva movimento de animacao
		inimigo->animacao = DIREITA;

		// Movimento
		if (movimento_permitido)
			inimigo->posicao.x += inimigo->velocidade.x;
	}
}

// Funcao para determinar qual vai ser a movimentacao do inimigo
void IA_de_Movimentacao(Inimigo* inimigo, Jogador* jogador1, Jogador* jogador2)
{
	// ***************************************************************************

	//
	// Distancia entre jogadores e inimigo
	//

	// Variavel que carrega a distancia
	int distancia, quadrante;
	int* vetor_distancia_quadrante;

	// Caso so tenha um jogador
	if (jogador2 == NULL)
		vetor_distancia_quadrante = Distancia_Inimigo_Jogador(inimigo, jogador1);

	// Caso tenham dois jogadores
	else
	{
		int* d1 = Distancia_Inimigo_Jogador(inimigo, jogador1);

		int* d2 = Distancia_Inimigo_Jogador(inimigo, jogador2);

		// A distancia escolhida sera a do jogador mais proximo
		if (d1[0] < d2[0])
			vetor_distancia_quadrante = d1;
		else
			vetor_distancia_quadrante = d2;
	}

	distancia = vetor_distancia_quadrante[0];
	quadrante = vetor_distancia_quadrante[1];

	// *************************************************************************************

	//
	// Decisao de movimentacao
	//

	switch (quadrante)
	{
		case CIMA:
			inimigo->movimento.cima = VERDADEIRO;
			inimigo->movimento.baixo = FALSO;
			inimigo->movimento.esquerda = FALSO;
			inimigo->movimento.direita = FALSO;
			break;

		case BAIXO:
			inimigo->movimento.cima = FALSO;
			inimigo->movimento.baixo = VERDADEIRO;
			inimigo->movimento.esquerda = FALSO;
			inimigo->movimento.direita = FALSO;
			break;

		case ESQUERDA:
			inimigo->movimento.cima = FALSO;
			inimigo->movimento.baixo = FALSO;
			inimigo->movimento.esquerda = VERDADEIRO;
			inimigo->movimento.direita = FALSO;
			break;

		case DIREITA:
			inimigo->movimento.cima = FALSO;
			inimigo->movimento.baixo = FALSO;
			inimigo->movimento.esquerda = FALSO;
			inimigo->movimento.direita = VERDADEIRO;
			break;

		case QUADRANTE1:
			inimigo->movimento.cima = VERDADEIRO;
			inimigo->movimento.baixo = FALSO;
			inimigo->movimento.esquerda = FALSO;
			inimigo->movimento.direita = VERDADEIRO;
			break;

		case QUADRANTE2:
			inimigo->movimento.cima = VERDADEIRO;
			inimigo->movimento.baixo = FALSO;
			inimigo->movimento.esquerda = VERDADEIRO;
			inimigo->movimento.direita = FALSO;
			break;

		case QUADRANTE3:
			inimigo->movimento.cima = FALSO;
			inimigo->movimento.baixo = VERDADEIRO;
			inimigo->movimento.esquerda = FALSO;
			inimigo->movimento.direita = VERDADEIRO;
			break;

		case QUADRANTE4:
			inimigo->movimento.cima = FALSO;
			inimigo->movimento.baixo = VERDADEIRO;
			inimigo->movimento.esquerda = VERDADEIRO;
			inimigo->movimento.direita = FALSO;
			break;
	}

	// *************************************************************************************

	//
	// Execucao de movimentacao
	//

	Movimenta_Inimigo(inimigo);

	// *************************************************************************************
}

// ***********************************************************************************

//
// Funcoes de renderizacao em tela
//

// Funcao para renderizar um vetor de inimigos em tela
void Atualiza_Inimigos_em_Tela(SDL_Renderer* renderer, Vetor_de_Inimigos* vetor_de_inimigos)
{
	int i;

	for (i = 0; i != vetor_de_inimigos->quantidade; i++)
	{
		SDL_RenderCopy(renderer, vetor_de_inimigos->inimigo[i].sprite,
			&vetor_de_inimigos->inimigo[i].frame,
			&vetor_de_inimigos->inimigo[i].posicao);
	}
}

// fim