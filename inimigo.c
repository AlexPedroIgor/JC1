// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

/*
	INIMIGO

	Jogo de desenvolvido para projeto de computacao 1
*/

#include "main.h"
#include "inimigo.h"
#include "config.h"

Inimigo Carrega_Inimigo(int numero, SDL_Renderer* renderer)
{
	// Estrutura com informacoes do inimigo
	Inimigo inimigo;

	// Numero do inimigo
	inimigo.numero = numero;

	SDL_Surface* Loading_Surf = NULL;

	switch(numero)
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


void Movimenta_Inimigo(Inimigo* inimigo, Jogador* jogador)
{
	// 
	// Movimentos diagonais
	// 

	// Nordeste
	if (jogador->posicao.y < inimigo->posicao.y && jogador->posicao.x < inimigo->posicao.x)
	{

		// Animacao
		inimigo->frame.y = 512;

		if (inimigo->frame.x < 512)
			inimigo->frame.x += 64;

		else
			inimigo->frame.x = 0;

		// Salva movimento de animacao
		inimigo->animacao = QUADRANTE2;

		inimigo->posicao.y -= inimigo->velocidade.y;
		inimigo->posicao.x -= inimigo->velocidade.x;
	}



	// Noroeste
	else if (jogador->posicao.y < inimigo->posicao.y && jogador->posicao.x > inimigo->posicao.x)
	{
		// Animacao
		inimigo->frame.y = 512;

		if (inimigo->frame.x < 512)
			inimigo->frame.x += 64;

		else
			inimigo->frame.x = 0;

		// Salva movimento de animacao
		inimigo->animacao = QUADRANTE1;

		inimigo->posicao.y -= inimigo->velocidade.y;
		inimigo->posicao.x += inimigo->velocidade.x;
	
	}
	// Suldeste
	else if (jogador->posicao.y > inimigo->posicao.y && jogador->posicao.x < inimigo->posicao.x)
	{
		// Animacao
		inimigo->frame.y = 640;

		if (inimigo->frame.x < 512)
			inimigo->frame.x += 64;

		else
			inimigo->frame.x = 0;

		// Salva movimento de animacao
		inimigo->animacao = QUADRANTE3;

		inimigo->posicao.y += inimigo->velocidade.y;
		inimigo->posicao.x -= inimigo->velocidade.x;

	}

	// Suldoeste
	else if (jogador->posicao.y > inimigo->posicao.y && jogador->posicao.x > inimigo->posicao.x)
	{
		// Animacao
		inimigo->frame.y = 640;

		if (inimigo->frame.x < 512)
			inimigo->frame.x += 64;

		else
			inimigo->frame.x = 0;

		// Salva movimento de animacao
		inimigo->animacao = QUADRANTE3;

		inimigo->posicao.y += inimigo->velocidade.y;
		inimigo->posicao.x += inimigo->velocidade.x;

	}

	//
	// Movimentos principais
	//

	// Cima
	else if (jogador->posicao.y < inimigo->posicao.y)
	{
		// Animacao
		inimigo->frame.y = 512;

		if (inimigo->frame.x < 512)
			inimigo->frame.x += 64;
		else
			inimigo->frame.x = 0;

		// Salva movimento de animacao
		inimigo->animacao = CIMA;

		inimigo->posicao.y -= inimigo->velocidade.y;
	}

	// Baixo
	else if (jogador->posicao.y > inimigo->posicao.y)
	{
		// Animacao
		inimigo->frame.y = 640;

		if (inimigo->frame.x < 512)
			inimigo->frame.x += 64;
		else
			inimigo->frame.x = 0;

		// Salva movimento de animacao
		inimigo->animacao = CIMA;

		inimigo->posicao.y += inimigo->velocidade.y;
	}

	//Esquerda
	else if (jogador->posicao.x < inimigo->posicao.x)
	{
		// Animacao
		inimigo->frame.y = 576;

		if (inimigo->frame.x < 512)
			inimigo->frame.x += 64;
		else
			inimigo->frame.x = 0;

		// Salva movimento de animacao
		inimigo->animacao = CIMA;

		inimigo->posicao.x -= inimigo->velocidade.x;
	}

	// Direita
	else if (jogador->posicao.x > inimigo->posicao.x)
	{
		if (jogador->posicao.x > inimigo->posicao.x+ 64)
		{
			// Animacao
			inimigo->frame.y = 704;

			if (inimigo->frame.x < 512)
				inimigo->frame.x += 64;
			else
				inimigo->frame.x = 0;

			// Salva movimento de animacao
			inimigo->animacao = CIMA;

			inimigo->posicao.x += inimigo->velocidade.x;
		}
		/*else
		{
			inimigo->frame.x = 0;
			//inimigo->frame.y = 960;
			inimigo->frame.y = 704;

			while(inimigo->frame.x != 512)
			{
				inimigo->frame.x += 64;
			}

			// Salva movimento de animacao
			inimigo->animacao = CIMA;
		}
		*/
	}
}



// fim