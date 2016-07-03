// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

/*
	ARMAS

	FUNCOES DE RENDERIZACAO E ORGANIZACAO DE ARMAS

	Jogo de desenvolvido para projeto de computacao 1
*/ 

#include "armas.h"
#include "base.h"

//
// PRE CARREGAMENTO DAS FUNCOES
//

Objeto Cria_Fireball(Objeto* jogador);
void Carrega_Fireball(SDL_Renderer* renderer, Objeto* fireball, Objeto* jogador);
void Inicializa_Fireball(SDL_Renderer* renderer, Projeteis* projeteis, Objeto* jogador);

// **************************************************************************************************************

//
// FIREBALL
//

// CRIA FIREBALL NA MEMORIA
Objeto Cria_Fireball(Objeto* jogador)
{
	// Carrega teclas de acao
	Carrega_Teclas_de_Acao(jogador);


	// Inicializa tiro
	Objeto fireball;

	fireball.tipo = FIREBALL; // Tipo de objeto

	fireball.animacao = 1; // Animacao

	// Tamanho real de referencia para colisao e posicionamento em tela
	fireball.tamanho_real.centro.x = 10;
	fireball.tamanho_real.centro.y = 32;
	fireball.tamanho_real.v = 6;
	fireball.tamanho_real.h = 7;

	// Recebe posicao do jogador
	fireball.posicao.x = jogador->posicao.x;
	fireball.posicao.y = jogador->posicao.y;

	// Posicao X sera a mesma
	fireball.frame.x = 0;

	// Tamanho dos frames do fireball
	fireball.frame.w = 64;
	fireball.frame.h = 64;

	// Tamanho do fireball em tela
	fireball.posicao.w = 64;
	fireball.posicao.h = 64;

	switch(jogador->animacao)
	{
		case CIMA:
			fireball.frame.y = 128; // Frame

		case BAIXO:
			fireball.frame.y = 384; // Frame
			break;

		case DIREITA:
			fireball.frame.y = 256; // Frame
			break;

		case ESQUERDA:
			fireball.frame.y = 0; // Frame
			break;

		case QUADRANTE1:
			fireball.frame.y = 192; // Frame
			break;

		case QUADRANTE2:
			fireball.frame.y = 64; // Frame
			break;

		case QUADRANTE3:
			fireball.frame.y = 448; // Frame
			break;

		case QUADRANTE4:
			fireball.frame.y = 320; // Frame;
			break;
	}

	return fireball;
}

// CARREGA SPRITE
void Carrega_Fireball(SDL_Renderer* renderer, Objeto* fireball, Objeto* jogador)
{
	SDL_Surface* Loading_Surf;
	

	Loading_Surf = IMG_Load("arte/ataques/fireball.png"); 

	fireball->sprite = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf);

	SDL_FreeSurface(Loading_Surf);

	fireball->animacao = jogador->animacao;



	// Posicao do fireball em tela
	switch(jogador->animacao)
	{
		case CIMA:
			fireball->posicao.y -= 20;

			break;

		case BAIXO:
			fireball->posicao.y += 20;
			break;

		case DIREITA:
			fireball->posicao.x += 20;
			break;

		case ESQUERDA:
			fireball->posicao.x -= 20;
			break;

		case QUADRANTE1:
			fireball->posicao.x += 20;
			fireball->posicao.y -= 20;
			break;

		case QUADRANTE2:
			fireball->posicao.x -= 20;	
			fireball->posicao.y -= 20;
			break;

		case QUADRANTE3:
			fireball->posicao.x -= 20;
			fireball->posicao.y += 20;
			break;

		case QUADRANTE4:
			fireball->posicao.x += 20;
			fireball->posicao.y += 20;
			break;
	}
}

// ADICIONA AO VETOR DE PROJETEIS
void Inicializa_Fireball(SDL_Renderer* renderer, Projeteis* projeteis, Objeto* jogador)
{

	if (projeteis->quantidade < 64)
	{
		// Cria um novo tiro
		projeteis->tiro[projeteis->quantidade].inf = Cria_Fireball(jogador);

		// Adiciona tiro na memoria
		Carrega_Fireball(renderer, &projeteis->tiro[projeteis->quantidade].inf, jogador);

		// Soma o contador de tiros em tela
		projeteis->quantidade++;

	}
	else
		projeteis->quantidade = 0;
}

void Anima_Fireball(SDL_Renderer* renderer, Objeto* tiro)
{
	printf("%d\n", tiro->animacao);
	switch (tiro->animacao)
	{
		//CIMA
		case 1:

			tiro->frame.y = 128;// Frame
			if(tiro->frame.x < 448)
			{
				tiro->frame.x += 64;
			}
			else
				tiro->frame.x = 0;

			tiro->posicao.y -= 15;

			break;

		//BAIXO
		case 2:
			tiro->frame.y = 384; // Frame
			if(tiro->frame.x < 448)
			{
				tiro->frame.x += 64;
			}
			else
				tiro->frame.x = 0;

			tiro->posicao.y += 15;
			


			break;

		//ESQUERDA
		case 3:
			tiro->frame.y = 0; // Frame
			if(tiro->frame.x < 448)
			{
				tiro->frame.x += 64;
			}
			else
				tiro->frame.x = 0;
			
			tiro->posicao.x -= 15;


			break;

		//DIREITA
		case 4:
			tiro->frame.y = 256; // Frame
			if(tiro->frame.x < 448)
			{
				tiro->frame.x += 64;
			}
			else
				tiro->frame.x = 0;

			tiro->posicao.x += 15;

			break;

		//CIMA DIREITA
		case 5:
			tiro->frame.y = 192; // Frame
			if(tiro->frame.x < 448)
			{
				tiro->frame.x += 64;
			}
			else
				tiro->frame.x = 0;

			tiro->posicao.x += 15;
			tiro->posicao.y -= 15;


			break;

		//CIMA ESQUERDA
		case 6:
			tiro->frame.y = 64; // Frame
			if(tiro->frame.x < 448)
			{
				tiro->frame.x += 64;
			}
			else
				tiro->frame.x = 0;

			tiro->posicao.x -= 15;
			tiro->posicao.y -= 15;


			break;

		//BAIXO ESQUERDA
		case 7:
			tiro->frame.y = 448; // Frame
			if(tiro->frame.x < 448)
			{
				tiro->frame.x += 64;
			}
			else
				tiro->frame.x = 0;

			tiro->posicao.x -= 15;
			tiro->posicao.y += 15;


			break;

		//BAIXO DIREITA
		case 8:
			tiro->frame.y = 320; // Frame
			if(tiro->frame.x < 448)
			{
				tiro->frame.x += 64;
			}
			else
				tiro->frame.x = 0;

			tiro->posicao.x += 15;
			tiro->posicao.y += 15;


			break;
	}
}
// ***************************************************************************************************************

//
// FLECHA
//



// ***************************************************************************************************************

// FIM