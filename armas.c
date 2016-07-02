// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

/*
	ARMAS

	FUNCOES DE RENDERIZACAO E ORGANIZACAO DE ARMAS

	Jogo de desenvolvido para projeto de computacao 1
*/ 

#include "armas.h"

//
// Funcoes da firebal
//

// Cria um tiro em tela
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
	fireball.posicao.x = fireball.tamanho_real.x - jogador->posicao.x + jogador->tamanho_real.x;
	fireball.posicao.y = fireball.tamanho_real.y - jogador->posicao.y + jogador->tamanho_real.y;

	// Posicao X sera a mesma
	fireball.frame.x = 0;

	// Tamanho dos frames do fireball
	fireball.frame.w = 64;
	fireball.frame.h = 64;

	// Tamanho do fireball em tela
	fireball.posicao.w = 64;
	fireball.posicao.h = 64;

	if(jogador->movimento.cima && jogador->movimento.esquerda)
		fireball.frame.y = 64; // Frame

	else if(jogador->movimento.cima && jogador->movimento.direita)
		fireball.frame.y = 192; // Frame

	else if(jogador->movimento.baixo && jogador->movimento.esquerda)
		fireball.frame.y = 448; // Frame
	
	else if(jogador->movimento.baixo && jogador->movimento.direita)
		fireball.frame.y = 320; // Frame
	
	else if(jogador->movimento.cima)
		fireball.frame.y = 128; // Frame
		
	else if(jogador->movimento.baixo)
		fireball.frame.y = 384; // Frame
		
	else if(jogador->movimento.esquerda)
		fireball.frame.y = 0; // Frame
		
	else if(jogador->movimento.direita)
		fireball.frame.y = 256; // Frame

	return fireball;
}

// Carrega o tiro na memoria
void Carrega_Fireball(SDL_Renderer* renderer, Objeto* fireball, Objeto* jogador)
{
	SDL_Surface* Loading_Surf;

	Loading_Surf = IMG_Load("arte/ataques/fireball.png"); 

	tiro->sprite = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf);

	SDL_FreeSurface(Loading_Surf);

	fireball->animacao = jogador->animacao;


	// Posicao do tiro em tela
	switch(jogador->animacao)
	{
		case CIMA:
			tiro->posicao.y -= 20;
			break;

		case BAIXO:
			tiro->posicao.y += 20;
			break;

		case DIREITA:
			tiro->posicao.x += 20;
			break;

		case ESQUERDA:
			tiro->posicao.x -= 20;
			break;

		case QUADRANTE1:
			tiro->posicao.x += 20;
			tiro->posicao.y -= 20;
			break;

		case QUADRANTE2:
			tiro->posicao.x -= 20;	
			tiro->posicao.y -= 20;
			break;

		case QUADRANTE3:
			tiro->posicao.x -= 20;
			tiro->posicao.y += 20;
			break;

		case QUADRANTE4:
			tiro->posicao.x += 20;
			tiro->posicao.y += 20;
			break;
	}
}

// Adiciona um novo tiro ao vetor de tiros
void Inicializa_Fireball(SDL_Renderer* renderer, Projeteis* projeteis, Objeto* jogador)
{
	if (vetor_de_tiros->quantidade < 64)
	{
		// Cria um novo tiro
		projeteis->tiro[vetor_de_tiros->quantidade].inf = Cria_Fireball(jogador);

		// Adiciona tiro na memoria
		Carrega_Fireball(renderer, &projeteis->tiro[vetor_de_tiros->quantidade]inf, jogador);

		// Soma o contador de tiros em tela
		vetor_de_tiros->quantidade++;
	}
}

// **************************************************************************************************************

//
// Funcoes de renderizacao
//


// Renderiza projeteis em tela
void Renderiza_Projeteis(SDL_Renderer* renderer, Projeteis* projeteis)
{
	int i;

	if (projeteis->quantidade > 0)
	{

		//Anima_Tiro(renderer, &projeteis->tiro[i].inf);

		for (i = 0; i != vetor_de_tiros->quantidade; i++)
		{
			SDL_RenderCopy(renderer,
				projeteis->tiro[i]inf.sprite,
				&projeteis->tiro[i]inf.frame,
				&projeteis->tiro[i]inf.posicao);

			if (i == 64)
				break;

			//vetor_de_tiros->tiro[i].animacao++;

			//printf("Animcacao: \n", vetor_de_tiros->tiro[i].animacao);

			//if (vetor_de_tiros->tiro[i].animacao > 8)
			//	vetor_de_tiros->tiro[i].animacao = 1;
		}

		
	}
}

// Animacao dos tiros
void Anima_Tiro(SDL_Renderer* renderer, Objeto* tiro)
{
	switch (tiro->animacao)
	{
		case 1:
			tiro->frame.x = 0; // Frame
			break;

		case 2:
			tiro->frame.x = 64; // Frame
			break;

		case 3:
			tiro->frame.x = 128; // Frame
			break;

		case 4:
			tiro->frame.x = 192; // Frame
			break;

		case 5:
			tiro->frame.x = 256; // Frame
			break;

		case 6:
			tiro->frame.x = 320; // Frame
			break;

		case 7:
			tiro->frame.x = 384; // Frame
			break;

		case 8:
			tiro->frame.x = 448; // Frame
			break;
	}
}


// ***************************************************************************************************************

// fim