// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

/*
	COLISAO

	FUNCOES DE COLISAO

	Jogo de desenvolvido para projeto de computacao 1
*/ 

#include "colisao.h"
#include "inimigo.h"

//
// PRE CARREGAMENTO DAS FUNCOES
//

int Colisao_Circular(Objeto* objeto1, Objeto* objeto2);
int Colisao_Circular2(Objeto* objeto1, Objeto* objeto2);
int Colisao_Perimetro(Objeto* objeto1, Objeto* objeto2);
int Colisao_Perimetro2(Objeto* objeto1, Objeto* objeto2);
int Colisao_LimiteDeTela(Objeto* objeto);
int Colisao_LimiteDeTela2(Objeto* objeto);
void Teste_de_Colisao(Inimigos* inimigos, Jogadores* jogadores);
void Teste_de_Impacto_Inimigos(SDL_Renderer* renderer, Projeteis* projeteis, Inimigos* inimigos);


// ***********************************************************************************************

//
// SISTEMAS BASICOS DE COLISAO
//

// VERIFICA RAIOS E DISTANCIA
int Colisao_Circular(Objeto* objeto1, Objeto* objeto2)
{
	struct
	{
		int raio;
		struct
		{
			int x, y;
		}centro;
	}circulo1, circulo2;

	circulo1.centro.x = objeto1->posicao.x + objeto1->tamanho_real.centro.x;
	circulo1.centro.y = objeto1->posicao.y + objeto1->tamanho_real.centro.y;
	circulo1.raio = objeto1->tamanho_real.v;

	circulo2.centro.x = objeto2->posicao.x + objeto2->tamanho_real.centro.x;
	circulo2.centro.y = objeto2->posicao.y + objeto2->tamanho_real.centro.y;
	circulo2.raio = objeto2->tamanho_real.v;

	int raios = circulo1.raio + circulo2.raio;

	int distancia, quadrante;

	// Calculo da distancia

	// Eixo X
	if (circulo1.centro.x == circulo2.centro.x)
	{
		distancia = abs(circulo1.centro.y - circulo2.centro.y);
	}
	// Eixo Y
	else if (circulo1.centro.y == circulo2.centro.y)
		{
			distancia = abs(circulo1.centro.x - circulo2.centro.x);
		}
	// Quadrante 1
	else if (circulo1.centro.x > circulo2.centro.x
		&& circulo1.centro.y > circulo2.centro.y)
	{
		quadrante = 1;
		distancia = sqrt( pow(circulo1.centro.x - circulo2.centro.x, 2)
			+ pow(circulo1.centro.y - circulo2.centro.y, 2) );
	}
	// Quadrante 2
	else if (circulo1.centro.x < circulo2.centro.x
		&& circulo1.centro.y > circulo2.centro.y)
	{
		quadrante = 2;
		distancia = sqrt( pow(circulo2.centro.x - circulo1.centro.x, 2)
			+ pow(circulo1.centro.y - circulo2.centro.y, 2) );
	}
	// Quatrande 3
	else if (circulo1.centro.x < circulo2.centro.x
		&& circulo1.centro.y < circulo2.centro.y)
	{
		quadrante = 3;
		distancia = sqrt( pow(circulo2.centro.x - circulo1.centro.x, 2)
			+ pow(circulo2.centro.y - circulo1.centro.y, 2) );
	}
	// Quadrante 4
	else if (circulo1.centro.x > circulo2.centro.x
		&& circulo1.centro.y < circulo2.centro.y)
	{
		quadrante = 4;
		distancia = sqrt( pow(circulo1.centro.x - circulo2.centro.x, 2)
			+ pow(circulo2.centro.y - circulo1.centro.y, 2) );
	}

	// Testes de posicao

	// Cima
	if (objeto1->movimento.cima
		&& (quadrante == 3 || quadrante == 4))
	{
		if (circulo1.centro.y <= circulo2.centro.y)
		{
			if (distancia <= raios)
				return VERDADEIRO;
			else
				return FALSO;
		}
	}

	// Baixo
	else if (objeto1->movimento.baixo
		&& (quadrante == 1 || quadrante == 2))
	{
		if (circulo1.centro.y >= circulo2.centro.y)
		{
			if (distancia <= raios)
				return VERDADEIRO;
			else
				return FALSO;
		}
	}

	// Esquerda
	else if (objeto1->movimento.esquerda
		&& (quadrante == 1 || quadrante == 4))
	{
		if (circulo1.centro.x <= circulo2.centro.x)
		{
			if (distancia <= raios)
				return VERDADEIRO;
			else
				return FALSO;
		}
	}

	// Direita
	else if (objeto1->movimento.direita
		&& (quadrante == 2 || quadrante == 3))
	{
		if (circulo1.centro.x >= circulo2.centro.x)
		{
			if (distancia <= raios)
				return VERDADEIRO;
			else
				return FALSO;
		}
	}
	else
		return FALSO;
}

int Colisao_Circular2(Objeto* objeto1, Objeto* objeto2)
{
	struct
	{
		int raio;
		struct
		{
			int x, y;
		}centro;
	}circulo1, circulo2;

	circulo1.centro.x = objeto1->posicao.x + (objeto1->frame.w/2);
	circulo1.centro.y = objeto1->posicao.y + (objeto1->frame.h/2);
	circulo1.raio = objeto1->frame.w/2;

	circulo2.centro.x = objeto2->posicao.x + (objeto2->frame.w/2);
	circulo2.centro.y = objeto2->posicao.y + (objeto2->frame.h/2);
	circulo2.raio = objeto2->frame.w/2;

	int raios = circulo1.raio + circulo2.raio;

	int distancia, quadrante;

	// Calculo da distancia

	// Eixo X
	if (circulo1.centro.x == circulo2.centro.x)
	{
		distancia = abs(circulo1.centro.y - circulo2.centro.y);
	}
	// Eixo Y
	else if (circulo1.centro.y == circulo2.centro.y)
		{
			distancia = abs(circulo1.centro.x - circulo2.centro.x);
		}
	// Quadrante 1
	else if (circulo1.centro.x > circulo2.centro.x
		&& circulo1.centro.y > circulo2.centro.y)
	{
		quadrante = 1;
		distancia = sqrt( pow(circulo1.centro.x - circulo2.centro.x, 2)
			+ pow(circulo1.centro.y - circulo2.centro.y, 2) );
	}
	// Quadrante 2
	else if (circulo1.centro.x < circulo2.centro.x
		&& circulo1.centro.y > circulo2.centro.y)
	{
		quadrante = 2;
		distancia = sqrt( pow(circulo2.centro.x - circulo1.centro.x, 2)
			+ pow(circulo1.centro.y - circulo2.centro.y, 2) );
	}
	// Quatrande 3
	else if (circulo1.centro.x < circulo2.centro.x
		&& circulo1.centro.y < circulo2.centro.y)
	{
		quadrante = 3;
		distancia = sqrt( pow(circulo2.centro.x - circulo1.centro.x, 2)
			+ pow(circulo2.centro.y - circulo1.centro.y, 2) );
	}
	// Quadrante 4
	else if (circulo1.centro.x > circulo2.centro.x
		&& circulo1.centro.y < circulo2.centro.y)
	{
		quadrante = 4;
		distancia = sqrt( pow(circulo1.centro.x - circulo2.centro.x, 2)
			+ pow(circulo2.centro.y - circulo1.centro.y, 2) );
	}

	printf("Posicao 1\n");
	printf("X: %d\nY: %d\n", circulo1.centro.x, circulo1.centro.y);
	printf("Posicao 2\n");
	printf("X: %d\nY: %d\n", circulo2.centro.x, circulo2.centro.y);
	printf("Distancia: %d\n", distancia);
	printf("Raios: %d\n", raios);

	// Testes de posicao

	// Cima
	if (objeto1->movimento.cima
		&& (quadrante == 3 || quadrante == 4))
	{
		if (circulo1.centro.y <= circulo2.centro.y)
		{
			if (distancia <= raios)
				return VERDADEIRO;
			else
				return FALSO;
		}
	}

	// Baixo
	else if (objeto1->movimento.baixo
		&& (quadrante == 1 || quadrante == 2))
	{
		if (circulo1.centro.y >= circulo2.centro.y)
		{
			if (distancia <= raios)
				return VERDADEIRO;
			else
				return FALSO;
		}
	}

	// Esquerda
	else if (objeto1->movimento.esquerda
		&& (quadrante == 1 || quadrante == 4))
	{
		if (circulo1.centro.x <= circulo2.centro.x)
		{
			if (distancia <= raios)
				return VERDADEIRO;
			else
				return FALSO;
		}
	}

	// Direita
	else if (objeto1->movimento.direita
		&& (quadrante == 2 || quadrante == 3))
	{
		if (circulo1.centro.x >= circulo2.centro.x)
		{
			if (distancia <= raios)
				return VERDADEIRO;
			else
				return FALSO;
		}
	}
	else
		return FALSO;
}

// VERIFICA PONTOS DO RETANGULO
int Colisao_Perimetro(Objeto* objeto1, Objeto* objeto2)
{
	int x1, x2, x3, x4;
	int y1, y2, y3, y4;

	// Objeto 1
	x1 = objeto1->posicao.x + objeto1->tamanho_real.centro.x - objeto1->tamanho_real.v;
	x2 = objeto1->posicao.x + objeto1->tamanho_real.centro.x + objeto1->tamanho_real.v;
	y1 = objeto1->posicao.y + objeto1->tamanho_real.centro.y - objeto1->tamanho_real.h;
	y2 = objeto1->posicao.y + objeto1->tamanho_real.centro.y + objeto1->tamanho_real.h;

	// Objeto 2
	x3 = objeto2->posicao.x + objeto2->tamanho_real.centro.x - objeto2->tamanho_real.v;
	x4 = objeto2->posicao.x + objeto2->tamanho_real.centro.x + objeto2->tamanho_real.v;
	y3 = objeto2->posicao.y + objeto2->tamanho_real.centro.y - objeto2->tamanho_real.h;
	y4 = objeto2->posicao.y + objeto2->tamanho_real.centro.y + objeto2->tamanho_real.h;

	
	
	// Superior
	if (objeto1->movimento.cima
		&& ((x3 < x2 && x2 < x4) || (x3 < x1 && x1 < x4)))
	{
		objeto1->colisao.cima = VERDADEIRO;
		objeto1->colisao.baixo = FALSO;
		objeto1->colisao.esquerda = FALSO;
		objeto1->colisao.direita = FALSO;
		return VERDADEIRO;
	}
	

	// Inferior
	else if (objeto1->movimento.baixo
		&& ((x1 > x3 && x1 < x4) || (x2 > x3 && x2 < x4)))
	{
		objeto1->colisao.cima = FALSO;
		objeto1->colisao.baixo = VERDADEIRO;
		objeto1->colisao.esquerda = FALSO;
		objeto1->colisao.direita = FALSO;
		return VERDADEIRO;
	}
	

	// Lateral esquerda
	else if (objeto1->movimento.esquerda
		&& ((y1 < y4 && y3 < y1) || (y2 > y3 && y2 < y4)))
	{
		objeto1->colisao.cima = FALSO;
		objeto1->colisao.baixo = FALSO;
		objeto1->colisao.esquerda = VERDADEIRO;
		objeto1->colisao.direita = FALSO;
		return VERDADEIRO;
	}
	

	// Lateral direita
	else if (objeto1->movimento.direita
		&& ((y2 > y3 && y1 < y4) || (y2 > y3 && y2 < y4)))
	{
		objeto1->colisao.cima = FALSO;
		objeto1->colisao.baixo = FALSO;
		objeto1->colisao.esquerda = FALSO;
		objeto1->colisao.direita = VERDADEIRO;
		return VERDADEIRO;
	}
	

	else
	{
		objeto1->colisao.cima = FALSO;
		objeto1->colisao.baixo = FALSO;
		objeto1->colisao.esquerda = FALSO;
		objeto1->colisao.direita = FALSO;
		return FALSO;
	}
}

int Colisao_Perimetro2(Objeto* objeto1, Objeto* objeto2)
{
	
	// Imprime posicao dos objetos
	//printf("Objeto 1\n");
	//printf("X: %d\nY: %d\n", objeto1->posicao.x, objeto1->posicao.y);
	//printf("Objeto 2\n");
	//printf("X: %d\nY: %d\n", objeto2->posicao.x, objeto2->posicao.y);
	

	// Superior
	if ( (objeto1->posicao.y >= objeto2->posicao.y )
		&& objeto1->posicao.y <= objeto2->posicao.y + objeto2->frame.h -7
		&& objeto1->posicao.x + 30 >= objeto2->posicao.x
		&& objeto1->posicao.x <= objeto2->posicao.x + 30
		&& objeto1->movimento.cima)
		return VERDADEIRO;

	// Inferior
	else if ( (objeto1->posicao.y <= objeto2->posicao.y)
		&& objeto1->posicao.y   + objeto1->frame.h >= objeto2->posicao.y +7
		&& objeto1->posicao.x + 30 >= objeto2->posicao.x
		&& objeto1->posicao.x <= objeto2->posicao.x + 30
		&& objeto1->movimento.baixo)
		return VERDADEIRO;

	// Lateral esquerda
	else if ( (objeto1->posicao.x <= objeto2->posicao.x + 37)
		&& objeto1->posicao.x >= objeto2->posicao.x 
		&& objeto1->posicao.y + 35 >= objeto2->posicao.y
		&& objeto1->posicao.y <= objeto2->posicao.y + 35
		&& objeto1->movimento.esquerda)
		return VERDADEIRO;

	// Lateral direita
	else if ( (objeto1->posicao.x + 37 >= objeto2->posicao.x )
		&& objeto1->posicao.x <= objeto2->posicao.x
		&& objeto1->posicao.y + 35 >= objeto2->posicao.y
		&& objeto1->posicao.y <= objeto2->posicao.y + 35
		&& objeto1->movimento.direita)
		return VERDADEIRO;

	else
		return FALSO;
}

// VERIFICA LIMITES DE TELA
int Colisao_LimiteDeTela(Objeto* objeto)
{
	int x1, x2, y1, y2;

	// Objeto 1
	x1 = objeto->posicao.x + objeto->tamanho_real.centro.x - objeto->tamanho_real.v;
	x2 = objeto->posicao.x + objeto->tamanho_real.centro.x + objeto->tamanho_real.v;
	y1 = objeto->posicao.y + objeto->tamanho_real.centro.y - objeto->tamanho_real.h;
	y2 = objeto->posicao.y + objeto->tamanho_real.centro.y + objeto->tamanho_real.h;

	// Superior
	if (objeto->movimento.cima && y1 <= 40)
	{
		/*objeto->colisao.cima = VERDADEIRO;
		objeto->colisao.baixo = FALSO;
		objeto->colisao.esquerda = FALSO;
		objeto->colisao.direita = FALSO;*/
		return VERDADEIRO;
	}

	// Inferior
	else if (objeto->movimento.baixo && y2 >= 545)
	{
		/*objeto->colisao.cima = FALSO;
		objeto->colisao.baixo = VERDADEIRO;
		objeto->colisao.esquerda = FALSO;
		objeto->colisao.direita = FALSO;*/
		return VERDADEIRO;
	}

	// Lateral esquerda
	else if (objeto->movimento.esquerda && x1 <= 50)
	{
		/*objeto->colisao.cima = FALSO;
		objeto->colisao.baixo = FALSO;
		objeto->colisao.esquerda = VERDADEIRO;
		objeto->colisao.direita = FALSO;*/
		return VERDADEIRO;
	}

	// Lateral direita
	else if (objeto->movimento.direita && x2 >= 741)
	{
		/*objeto->colisao.cima = FALSO;
		objeto->colisao.baixo = FALSO;
		objeto->colisao.esquerda = FALSO;
		objeto->colisao.direita = VERDADEIRO;*/
		return VERDADEIRO;
	}

	// Sem colisao
	else
	{
		/*objeto->colisao.cima = FALSO;
		objeto->colisao.baixo = FALSO;
		objeto->colisao.esquerda = FALSO;
		objeto->colisao.direita = FALSO;*/
		return FALSO;
	}
}

int Colisao_LimiteDeTela2(Objeto* objeto)
{
	// Superior
	if (objeto->posicao.y <= 10
		&& objeto->movimento.cima)
		return VERDADEIRO;

	// Inferior
	else if ( (objeto->posicao.y + objeto->frame.h >= 560)
		&& objeto->movimento.baixo)
		return VERDADEIRO;

	// Lateral esquerda
	else if (objeto->posicao.x <= 45
		&& objeto->movimento.esquerda)
		return VERDADEIRO;

	// Lateral direita
	else if ( (objeto->posicao.x + objeto->frame.w >= 750)
		&& objeto->movimento.direita)
		return VERDADEIRO;

	else
		return FALSO;
}

// **************************************************************************************************

//
// TESTES DE COLISAO
//

// COLISAO ENTRE PERSONAGENS
void Teste_de_Colisao(Inimigos* inimigos, Jogadores* jogadores)
{
	int i, j;

	// COLISAO ENTRE INIMIGOS E JOGADORES
	if (inimigos->quantidade > 0)
	{
		for (i = 0; i != inimigos->quantidade; i++)
		{
			// ENTRE OS JOGADORES
			for (j = 0; j != jogadores->quantidade; j++)
			{
				if (Colisao_Perimetro(&inimigos->inimigo[i].inf,
										&jogadores->jogador[j].inf))
											break;
			}

			// ENTRE OS INIMIGOS
			for (j = 0; j != inimigos->quantidade; j++)
			{
				if (i != j)
				{
					if (Colisao_Perimetro(&inimigos->inimigo[i].inf,
											&inimigos->inimigo[j].inf))
												break;
				}
			}
		}
	}
}

// COLISAO ENTRE PROJETEIS E INIMIGOS
void Teste_de_Impacto_Inimigos(SDL_Renderer* renderer, Projeteis* projeteis, Inimigos* inimigos)
{
	if (projeteis->tiro[projeteis->quantidade-1].inf.posicao.x > 800
		|| projeteis->tiro[projeteis->quantidade-1].inf.posicao.x <= 0
		|| projeteis->tiro[projeteis->quantidade-1].inf.posicao.y > 600
		|| projeteis->tiro[projeteis->quantidade-1].inf.posicao.y < 0)
	{
		projeteis->quantidade = 0; // TIRA PROJETEIS FORA DE TELA
	}

	if (projeteis->quantidade > 0)
	{
		int i, j;

		if (inimigos->quantidade > 0)
		{
			for (i = 0; i != projeteis->quantidade; i++)
			{
				for (j = 1; j != inimigos->quantidade; j++)
				{
					if (Colisao_Perimetro2(&projeteis->tiro[i].inf,
								&inimigos->inimigo[j].inf));
					{
						printf("COLISAO FOI VERDADEIRA %d %d\n", i, j);
						Inimigo_Toma_Dano(renderer,
								&inimigos->inimigo[j].inf,
								&inimigos->inimigo[j].status,
								projeteis->tiro[i].tipo);
					}
				}
			}
		}
	}
}

// *********************************************************************************************************************

// FIM
