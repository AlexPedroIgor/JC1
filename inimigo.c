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
		inimigo.velocidade.x = 2;
		inimigo.velocidade.y = 2;
		Loading_Surf = IMG_Load("arte/personagens/vilao01/esqueleto.png");
		break;

		case 2:
		// Velocidade de movimento do inimigo
		inimigo.velocidade.x = 4;
		inimigo.velocidade.y = 4;
		Loading_Surf = IMG_Load("arte/personagens/vilao02/orc.png");

		case 3:
		// Velocidade de movimento do inimigo
		inimigo.velocidade.x = 6;
		inimigo.velocidade.y = 6;
		Loading_Surf = IMG_Load("arte/personagens/vilao03/blackelf.png");
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



// fim