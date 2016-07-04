// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

/*
	ANIMACAO

	FUNCOES DE ANIMACAO DOS SPRITES DO JOGO

	Jogo de desenvolvido para projeto de computacao 1
*/ 

#include "animacao.h"

//
// PRE CARREGAMENTO DAS FUNCOES
//

void Inimigo_Animacao_Ataque(Objeto* inimigo);
void Inimigo_Animacao_Toma_Dano(SDL_Renderer* renderer, Objeto* inimigo);
void Projetil_Fireball_Animacao(SDL_Renderer* renderer, Objeto* tiro);
void Fase_Animacao_Portal(Fase* fase);

// **************************************************************************************

//
// JOGADORES
//



// **************************************************************************************

//
// INIMIGOS
//

// ANIMACAO DE ATAQUE DO INIMIGO
void Inimigo_Animacao_Ataque(Objeto* inimigo)
{
		inimigo->frame.y +256; //diferença entre animação normal e ataque
			inimigo->frame.x = 0;
			

			if (inimigo->frame.x < 320)
				inimigo->frame.x += 64;
			else
				inimigo->frame.x = 0;
			
}

// ANIMACAO DE INIMIGO TOMANDO DANO
void Inimigo_Animacao_Toma_Dano(SDL_Renderer* renderer, Objeto* inimigo)
{

}

// **************************************************************************************

//
// PROJETEIS
//

// FIREBALL
void Projetil_Fireball_Animacao(SDL_Renderer* renderer, Objeto* tiro)
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

// ***************************************************************************************

//
// OBJETOS FIXOS NAS FASES
//

// GERENCIA ANIMACAO DOS PORTAIS
void Fase_Animacao_Portal(Fase* fase)
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

// ***************************************************************************************

// FIM
