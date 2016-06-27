// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

/*
	FISICA

	FUNCOES DE COLISAO

	Jogo de desenvolvido para projeto de computacao 1
*/ 


#include "main.h"
#include "fisica.h"
#include "config.h"

// Pre carregamento das funcoes de colisao
int Colisao_Circular(Objeto* Objeto1, Objeto* Objeto2);
int Colisao_Retangular(Objeto* Objeto1, Objeto* Objeto2);
int Colisao_Perimetro(Objeto* objeto1, Objeto* objeto2);
int Colisao_LimiteDeTela(Objeto* objeto);
int Colisao_Jogador_LimiteDeTela(Jogador* jogador);
int Colisao_Entre_Jogadores(Jogador* jogador1, Jogador* jogador2);
int Colisao_Entre_Jogador_Inimigo(Jogador* jogador, Inimigo* inimigo);
int Colisao_Impacto_Jogador(Jogador* jogador, Objeto* objeto);
int Colisao_Impacto_Inimigo(Inimigo* inimigo, Objeto* objeto);

// Sistema de colisao em circulos (verifica tangentes dos circulos)
int Colisao_Circular(Objeto* Objeto1, Objeto* Objeto2)
{

}

// Sistema de colisao de retangulos (verifica se um retangulo esta dentro do outro)
// Pesa muito no processamento
int Colisao_Retangular(Objeto* Objeto1, Objeto* Objeto2)
{
	// Retangulos para analise
	struct
	{
		int x1, x2;
		int y1, y2;
	}objeto1, objeto2;

	// Objeto 1
	objeto1.x1 = Objeto1->posicao.x;
	objeto1.x2 = Objeto1->posicao.x + Objeto1->frame.w;
	objeto1.y1 = Objeto1->posicao.y;
	objeto1.y2 = Objeto1->posicao.y + Objeto1->frame.h;

	// Objeto 2
	objeto2.x1 = Objeto2->posicao.x;
	objeto2.x2 = Objeto2->posicao.x + Objeto2->frame.w;
	objeto2.y1 = Objeto2->posicao.y;
	objeto2.y2 = Objeto2->posicao.y + Objeto2->frame.h;

	int x1, y1, x2, y2;

	for (x1 = objeto1.x1; x1 != objeto1.x2 + 1; x1++)
	{
		for (y1 = objeto1.y1; y1 != objeto1.y2 + 1; y1++)
		{
			for (x2 = objeto2.x1; x2 != objeto2.x2 + 1; x2++)
			{
				for (y2 = objeto2.y1; y2 != objeto2.y2 + 1; y2++)
				{
					if (x1 < x2 && y1 < y2)
						return VERDADEIRO;
				}
			}
		}
	}
	return FALSO;
}

// Sistema de colisao por perimetro (verifica os perimetros)
int Colisao_Perimetro(Objeto* objeto1, Objeto* objeto2)
{
	// Superior
	if ( (objeto1->posicao.y <= objeto2->posicao.y + objeto2->frame.h)
		&& objeto1->posicao.x >= objeto2->posicao.x
		&& objeto1->posicao.x <= objeto2->posicao.x + objeto2->frame.w
		&& objeto1->movimento.cima)
		return VERDADEIRO;

	// Inferior
	else if ( (objeto1->posicao.y + objeto1->frame.h >= objeto2->posicao.y)
		&& objeto1->posicao.x >= objeto2->posicao.x
		&& objeto1->posicao.x <= objeto2->posicao.x + objeto2->frame.w
		&& objeto1->movimento.baixo)
		return VERDADEIRO;

	// Lateral esquerda
	else if ( (objeto1->posicao.x <= objeto2->posicao.x + objeto2->frame.w)
		&& objeto1->posicao.y >= objeto2->posicao.y
		&& objeto1->posicao.y <= objeto2->posicao.y + objeto2->frame.h
		&& objeto1->movimento.esquerda)
		return VERDADEIRO;

	// Lateral direita
	else if ( (objeto1->posicao.x + objeto1->frame.w >= objeto2->posicao.x)
		&& objeto1->posicao.y >= objeto2->posicao.y
		&& objeto1->posicao.y <= objeto2->posicao.y + objeto2->frame.h
		&& objeto1->movimento.direita)
		return VERDADEIRO;

	else
		return FALSO;
}

// Verificacao de colisao de limite de tela
int Colisao_LimiteDeTela(Objeto* objeto)
{
	// Superior
	if (objeto->posicao.y == 0
		&& objeto->movimento.cima)
		return VERDADEIRO;

	// Inferior
	else if ( ( (objeto->posicao.y + objeto->frame.h) >= SCREEN_HEIGHT)
		&& objeto->movimento.baixo)
		return VERDADEIRO;

	// Lateral esquerda
	else if (objeto->posicao.x == 0
		&& objeto->movimento.esquerda)
		return VERDADEIRO;

	// Lateral direita
	else if ( ( (objeto->posicao.x + objeto->frame.w) >= SCREEN_WIDTH)
		&& objeto->movimento.direita)
		return VERDADEIRO;

	else
		return FALSO;
}

// Verificacao de colisao entre jogador e limite de tela
int Colisao_Jogador_LimiteDeTela(Jogador* jogador)
{
	Objeto objeto;
	
	objeto.posicao.x = jogador->posicao.x;
	objeto.posicao.y = jogador->posicao.y;
	objeto.frame.w = jogador->frame.w;
	objeto.frame.h = jogador->frame.h;
	objeto.movimento.cima = jogador->movimento.cima;
	objeto.movimento.baixo = jogador->movimento.baixo;
	objeto.movimento.esquerda = jogador->movimento.esquerda;
	objeto.movimento.direita = jogador->movimento.direita;

	if (Colisao_LimiteDeTela(&objeto))
		return VERDADEIRO;
	
	else
		return FALSO;
}

// Verificacao de colisao entre jogadores
int Colisao_Entre_Jogadores(Jogador* jogador1, Jogador* jogador2)
{
	// Conversao de jogadores em objetos
	Objeto objeto1, objeto2;

	// Jogador 1
	objeto1.posicao.x = jogador1->posicao.x;
	objeto1.posicao.y = jogador1->posicao.y;
	objeto1.frame.w = jogador1->frame.w;
	objeto1.frame.h = jogador1->frame.h;
	objeto1.movimento.cima = jogador1->movimento.cima;
	objeto1.movimento.baixo = jogador1->movimento.baixo;
	objeto1.movimento.esquerda = jogador1->movimento.esquerda;
	objeto1.movimento.direita = jogador1->movimento.direita;

	// Jogador 2
	objeto2.posicao.x = jogador2->posicao.x;
	objeto2.posicao.y = jogador2->posicao.y;
	objeto2.frame.w = jogador2->frame.w;
	objeto2.frame.h = jogador2->frame.h;

	printf("Jogador %d\n", jogador1->numero);
	printf("X: %d\nY: %d\n", objeto1.posicao.x, objeto1.posicao.y);
	printf("Jogador %d\n", jogador2->numero);
	printf("X: %d\nY: %d\n", objeto2.posicao.x, objeto2.posicao.y);

	// Verificacao por meio da funcao de colisao de objetos
	if (Colisao_Perimetro(&objeto1, &objeto2))
		return VERDADEIRO;
	else
		return FALSO;
}

// Verificacao de colisao entre jogador e inimigo
int Colisao_Entre_Jogador_Inimigo(Jogador* jogador, Inimigo* inimigo)
{

}

// Verificacao de impacto entre arma do inimigo e jogador
int Colisao_Impacto_Jogador(Jogador* jogador, Objeto* objeto)
{

}

// Verificacao de impacto entre arma do jogador e inimigo
int Colisao_Impacto_Inimigo(Inimigo* inimigo, Objeto* objeto)
{

}