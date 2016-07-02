// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

/*
	FISICA

	FUNCOES DE MOVIMENTACAO DE OBJETOS EM TELA

	Jogo de desenvolvido para projeto de computacao 1
*/ 

#include "fisica.h"

//
// Pre carregamento das funcoes
//



// ********************************************************************************************

//
// Funcoes de movimentacao de jogadores
//

// Movimentacao de um jogador
void Movimentacao_Jogador(Objeto* jogador)
{
	// Carrega teclas de acao
	Carrega_Teclas_de_Acao(jogador);

	//
	// Movimentos diagonais
	//

	// Nordeste
	if ((jogador->movimento.cima && jogador->movimento.esquerda)
	{
		// Animacao
		jogador->frame.y = 512;

		if (jogador->frame.x < 512)
			jogador->frame.x += 64;

		else
			jogador->frame.x = 0;

		// Salva movimento de animacao
		jogador->animacao = QUADRANTE2;

		// Movimentacao
		if (!jogador->colisao.cima && !jogador->colisao.esquerda)
		{
			jogador->posicao.y -= jogador->velocidade.y;
			jogador->posicao.x -= jogador->velocidade.x;
		}
	}

	// Noroeste
	else if (jogador->movimento.cima && jogador->movimento.direita)
	{
		// Animacao
		jogador->frame.y = 512;

		if (jogador->frame.x < 512)
			jogador->frame.x += 64;

		else
			jogador->frame.x = 0;

		// Salva movimento de animacao
		jogador->animacao = QUADRANTE1;

		// Movimentacao
		if (!jogador->colisao.cima && !jogador->colisao.direita)
		{
			jogador->posicao.y -= jogador->velocidade.y;
			jogador->posicao.x += jogador->velocidade.x;
		}
	}

	// Suldeste
	else if (jogador->movimento.baixo && jogador->movimento.esquerda)
	{
		// Animacao
		jogador->frame.y = 640;

		if (jogador->frame.x < 512)
			jogador->frame.x += 64;

		else
			jogador->frame.x = 0;

		// Salva movimento de animacao
		jogador->animacao = QUADRANTE3;

		// Movimentacao
		if (!jogador->colisao.baixo && !jogador->colisao.esquerda)
		{
			jogador->posicao.y += jogador->velocidade.y;
			jogador->posicao.x -= jogador->velocidade.x;
		}
	}

	// Suldoeste
	else if (jogador->movimento.baixo && jogador->movimento.direita)
	{
		// Animacao
		jogador->frame.y = 640;

		if (jogador->frame.x < 512)
			jogador->frame.x += 64;

		else
			jogador->frame.x = 0;

		// Salva movimento de animacao
		jogador->animacao = QUADRANTE4;

		// Movimentacao
		if (!jogador->colisao.baixo && !jogador->colisao.direita)
		{
			jogador->posicao.y += jogador->velocidade.y;
			jogador->posicao.x += jogador->velocidade.x;
		}
	}

	//
	// Movimentos principais
	//

	// Cima
	else if (jogador->movimento.cima)
	{
		// Animacao
		jogador->frame.y = 512;

		if (jogador->frame.x < 512)
			jogador->frame.x += 64;
		else
			jogador->frame.x = 0;

		// Salva movimento de animacao
		jogador->animacao = CIMA;

		// Movimento
		if (!jogador->colisao.cima)
			jogador->posicao.y -= jogador->velocidade.y;
	}

	// Baixo
	else if (jogador->movimento.baixo)
	{
		// Animacao
		jogador->frame.y = 640;

		if (jogador->frame.x < 512)
			jogador->frame.x += 64;
		else
			jogador->frame.x = 0;

		// Salva movimento de animacao
		jogador->animacao = BAIXO;

		// Movimento
		if (!jogador->colisao.baixo)
			jogador->posicao.y += jogador->velocidade.y;
	}

	// Esquerda
	else if (jogador->movimento.esquerda)
	{
		// Animacao
		jogador->frame.y = 576;

		if (jogador->frame.x < 512)
			jogador->frame.x += 64;
		else
			jogador->frame.x = 0;

		// Salva movimento de animacao
		jogador->animacao = ESQUERDA;

		// Movimento
		if (!jogador->colisao.esquerda)
			jogador->posicao.x -= jogador->velocidade.x;
	}

	// Direita
	else if (jogador->movimento.direita)
	{
		// Animacao
		jogador->frame.y = 704;

		if (jogador->frame.x < 512)
			jogador->frame.x += 64;
		else
			jogador->frame.x = 0;

		// Salva movimento de animacao
		jogador->animacao = DIREITA;

		// Movimento
		if (!jogador->colisao.direita)
			jogador->posicao.x += jogador->velocidade.x;
}

// Movimentacao dos jogadores
void Jogadores_Movimentar(Jogadores* jogadores, Inimigos* inimigos)
{

}

// Atirar
void Atirar(SDL_Renderer* renderer, Jogador* jogador, Vetor_de_Tiros* vetor_de_tiros)
{
	// Carrega teclas de acao
	Carrega_Teclas_de_Acao(jogador);

	if (jogador->movimento.ataque)
	{
		Adiciona_Tiro_ao_Vetor(renderer, vetor_de_tiros, jogador);
	}
}

// ********************************************************************************************

// FIM