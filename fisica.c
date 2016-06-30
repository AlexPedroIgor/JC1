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
int Colisao_Circular(Objeto* objeto1, Objeto* objeto2);
int Colisao_Retangular(Objeto* Objeto1, Objeto* Objeto2);
int Colisao_Perimetro(Objeto* objeto1, Objeto* objeto2);
int Colisao_LimiteDeTela(Objeto* objeto);
int Colisao_Jogador_LimiteDeTela(Jogador* jogador);
int Colisao_Inimigo_LimiteDeTela(Inimigo* inimigo);
int Colisao_Entre_Jogadores(Jogador* jogador1, Jogador* jogador2);
int Colisao_Entre_Jogador_Inimigo(Jogador* jogador, Inimigo* inimigo);
int Colisao_Impacto_Jogador(Jogador* jogador, Objeto* objeto);
int Colisao_Entre_Inimigo_Jogador(Inimigo* inimigo, Jogador* jogador);
int Colisao_Entre_Inimigos(Inimigo* inimigo1, Inimigo* inimigo2);
int Colisao_Impacto_Inimigo(Inimigo* inimigo, Objeto* objeto);
int* Distancia(Objeto* objeto1, Objeto* objeto2);
int* Distancia_Inimigo_Jogador(Inimigo* inimigo, Jogador* jogador);
Objeto Converte_Jogador_Objeto(Jogador* Jogador);
Objeto Converte_Inimigo_Objeto(Inimigo* inimigo);
void Teste_de_Colisao_Jogador(Jogador* jogador, Vetor_de_Inimigos* vetor_de_inimigos);
Objeto Cria_Tiro(Jogador* jogador);
void CarregaTiro(SDL_Renderer* renderer, Objeto* tiro, Jogador* jogador);
Vetor_de_Tiros Cria_Vetor_de_Tiros();
void Adiciona_Tiro_ao_Vetor(SDL_Renderer* renderer, Vetor_de_Tiros* vetor_de_tiros, Jogador* jogador);
void Renderiza_Tiros(SDL_Renderer* renderer, Vetor_de_Tiros* vetor_de_tiros);

// ********************************************************************************************

// Sistema de colisao em circulos (verifica tangentes dos circulos)
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
	/*
	// Imprime posicao dos objetos
	printf("Objeto 1\n");
	printf("X: %d\nY: %d\n", objeto1->posicao.x, objeto1->posicao.y);
	printf("Objeto 2\n");
	printf("X: %d\nY: %d\n", objeto2->posicao.x, objeto2->posicao.y);
	*/

	// Superior
	if ( (objeto1->posicao.y >= objeto2->posicao.y )
		&& objeto1->posicao.y <= objeto2->posicao.y + objeto2->frame.h
		&& objeto1->posicao.x + 30 >= objeto2->posicao.x
		&& objeto1->posicao.x <= objeto2->posicao.x + 30
		&& objeto1->movimento.cima)
		return VERDADEIRO;

	// Inferior
	else if ( (objeto1->posicao.y <= objeto2->posicao.y)
		&& objeto1->posicao.y   + objeto1->frame.h  >= objeto2->posicao.y
		&& objeto1->posicao.x + 30 >= objeto2->posicao.x
		&& objeto1->posicao.x <= objeto2->posicao.x + 30
		&& objeto1->movimento.baixo)
		return VERDADEIRO;

	// Lateral esquerda
	else if ( (objeto1->posicao.x <= objeto2->posicao.x + 35)
		&& objeto1->posicao.x >= objeto2->posicao.x 
		&& objeto1->posicao.y + 35 >= objeto2->posicao.y
		&& objeto1->posicao.y <= objeto2->posicao.y + 35
		&& objeto1->movimento.esquerda)
		return VERDADEIRO;

	// Lateral direita
	else if ( (objeto1->posicao.x + 35 >= objeto2->posicao.x )
		&& objeto1->posicao.x <= objeto2->posicao.x
		&& objeto1->posicao.y + 35 >= objeto2->posicao.y
		&& objeto1->posicao.y <= objeto2->posicao.y + 35
		&& objeto1->movimento.direita)
		return VERDADEIRO;

	else
		return FALSO;
}

// Verificacao de colisao de limite de tela
int Colisao_LimiteDeTela(Objeto* objeto)
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

// Verificacao de colisao entre inimigo e limite de tela
int Colisao_Inimigo_LimiteDeTela(Inimigo* inimigo)
{
	Objeto objeto;
	
	objeto.posicao.x = inimigo->posicao.x;
	objeto.posicao.y = inimigo->posicao.y;
	objeto.frame.w = inimigo->frame.w;
	objeto.frame.h = inimigo->frame.h;
	objeto.movimento.cima = inimigo->movimento.cima;
	objeto.movimento.baixo = inimigo->movimento.baixo;
	objeto.movimento.esquerda = inimigo->movimento.esquerda;
	objeto.movimento.direita = inimigo->movimento.direita;

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

	objeto1.numero = jogador1->numero;
	objeto2.numero = jogador2->numero;

	// Verificacao por meio da funcao de colisao de objetos
	if (Colisao_Perimetro(&objeto1, &objeto2))
	{
		return VERDADEIRO;
	}
	else
		return FALSO;
}

// Verificacao de colisao entre jogador e inimigo
int Colisao_Entre_Jogador_Inimigo(Jogador* jogador, Inimigo* inimigo)
{
	// Conversao de jogadores em objetos
	Objeto objeto1, objeto2;

	// Jogador 1
	objeto1.posicao.x = jogador->posicao.x;
	objeto1.posicao.y = jogador->posicao.y;
	objeto1.frame.w = jogador->frame.w;
	objeto1.frame.h = jogador->frame.h;
	objeto1.movimento.cima = jogador->movimento.cima;
	objeto1.movimento.baixo = jogador->movimento.baixo;
	objeto1.movimento.esquerda = jogador->movimento.esquerda;
	objeto1.movimento.direita = jogador->movimento.direita;

	// Jogador 2
	objeto2.posicao.x = inimigo->posicao.x;
	objeto2.posicao.y = inimigo->posicao.y;
	objeto2.frame.w = inimigo->frame.w;
	objeto2.frame.h = inimigo->frame.h;

	// Verificacao por meio da funcao de colisao de objetos
	if (Colisao_Perimetro(&objeto1, &objeto2))
	{
		return VERDADEIRO;
	}
	else
		return FALSO;
}

// Verificacao de colisao entre inimigo e jogador
int Colisao_Entre_Inimigo_Jogador(Inimigo* inimigo, Jogador* jogador)
{
	// Conversao de jogadores em objetos
	Objeto objeto1, objeto2;

	// Inimigo
	objeto1.posicao.x = inimigo->posicao.x;
	objeto1.posicao.y = inimigo->posicao.y;
	objeto1.frame.w = inimigo->frame.w;
	objeto1.frame.h = inimigo->frame.h;
	objeto1.movimento.cima = inimigo->movimento.cima;
	objeto1.movimento.baixo = inimigo->movimento.baixo;
	objeto1.movimento.esquerda = inimigo->movimento.esquerda;
	objeto1.movimento.direita = inimigo->movimento.direita;

	// Jogador
	objeto2.posicao.x = jogador->posicao.x;
	objeto2.posicao.y = jogador->posicao.y;
	objeto2.frame.w = jogador->frame.w;
	objeto2.frame.h = jogador->frame.h;

	// Verificacao por meio da funcao de colisao de objetos
	if (Colisao_Perimetro(&objeto1, &objeto2))
	{
		return VERDADEIRO;
	}
	else
		return FALSO;
}

// Verificacao de colisao entre inimigos
int Colisao_Entre_Inimigos(Inimigo* inimigo1, Inimigo* inimigo2)
{
	// Conversao de jogadores em objetos
	Objeto objeto1, objeto2;

	// Inimigo 1
	objeto1.posicao.x = inimigo1->posicao.x;
	objeto1.posicao.y = inimigo1->posicao.y;
	objeto1.frame.w = inimigo1->frame.w;
	objeto1.frame.h = inimigo1->frame.h;
	objeto1.movimento.cima = inimigo1->movimento.cima;
	objeto1.movimento.baixo = inimigo1->movimento.baixo;
	objeto1.movimento.esquerda = inimigo1->movimento.esquerda;
	objeto1.movimento.direita = inimigo1->movimento.direita;

	// Inimigo 2
	objeto2.posicao.x = inimigo2->posicao.x;
	objeto2.posicao.y = inimigo2->posicao.y;
	objeto2.frame.w = inimigo2->frame.w;
	objeto2.frame.h = inimigo2->frame.h;

	// Verificacao por meio da funcao de colisao de objetos
	if (Colisao_Perimetro(&objeto1, &objeto2))
	{
		return VERDADEIRO;
	}
	else
		return FALSO;
}

// Verificacao de impacto entre arma do inimigo e jogador
int Colisao_Impacto_Jogador(Jogador* jogador, Objeto* objeto)
{

}

// Verificacao de impacto entre arma do jogador e inimigo
int Colisao_Impacto_Inimigo(Inimigo* inimigo, Objeto* objeto)
{

}

// Verifica distancia entre dois objetos
// Retorna um vetor com a distancia e o quadrante
int* Distancia(Objeto* objeto1, Objeto* objeto2)
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
		if (circulo1.centro.y < circulo2.centro.y)
			quadrante = BAIXO;
		else
			quadrante = CIMA;
	}

	// Eixo Y
	else if (circulo1.centro.y == circulo2.centro.y)
		{
			distancia = abs(circulo1.centro.x - circulo2.centro.x);
			if (circulo1.centro.x < circulo2.centro.x)
				quadrante = DIREITA;
			else
				quadrante = ESQUERDA;
		}

	// Quadrante 1
	else if (circulo1.centro.x > circulo2.centro.x
		&& circulo1.centro.y > circulo2.centro.y)
	{
		quadrante = QUADRANTE1;
		distancia = sqrt( pow(circulo1.centro.x - circulo2.centro.x, 2)
			+ pow(circulo1.centro.y - circulo2.centro.y, 2) );
	}
	// Quadrante 2
	else if (circulo1.centro.x < circulo2.centro.x
		&& circulo1.centro.y > circulo2.centro.y)
	{
		quadrante = QUADRANTE2;
		distancia = sqrt( pow(circulo2.centro.x - circulo1.centro.x, 2)
			+ pow(circulo1.centro.y - circulo2.centro.y, 2) );
	}
	// Quatrande 3
	else if (circulo1.centro.x < circulo2.centro.x
		&& circulo1.centro.y < circulo2.centro.y)
	{
		quadrante = QUADRANTE3;
		distancia = sqrt( pow(circulo2.centro.x - circulo1.centro.x, 2)
			+ pow(circulo2.centro.y - circulo1.centro.y, 2) );
	}
	// Quadrante 4
	else if (circulo1.centro.x > circulo2.centro.x
		&& circulo1.centro.y < circulo2.centro.y)
	{
		quadrante = QUADRANTE4;
		distancia = sqrt( pow(circulo1.centro.x - circulo2.centro.x, 2)
			+ pow(circulo2.centro.y - circulo1.centro.y, 2) );
	}

	int vetor_distancia_quadrante[2];
	vetor_distancia_quadrante[0] = distancia;
	vetor_distancia_quadrante[1] = quadrante;

	return vetor_distancia_quadrante;
}

// Verifica distancia entre inimigo e jogador
// Retorna um vetor com a distancia e o quadrante
int* Distancia_Inimigo_Jogador(Inimigo* inimigo, Jogador* jogador)
{
	// Conversao de jogador em objeto
	Objeto objeto1;

	// Jogador 1
	objeto1.posicao.x = jogador->posicao.x;
	objeto1.posicao.y = jogador->posicao.y;
	objeto1.frame.w = jogador->frame.w;
	objeto1.frame.h = jogador->frame.h;
	objeto1.movimento.cima = jogador->movimento.cima;
	objeto1.movimento.baixo = jogador->movimento.baixo;
	objeto1.movimento.esquerda = jogador->movimento.esquerda;
	objeto1.movimento.direita = jogador->movimento.direita;

	// Conversao de iniigo em objetos
	Objeto objeto2;

	// Jogador 1
	objeto2.posicao.x = inimigo->posicao.x;
	objeto2.posicao.y = inimigo->posicao.y;
	objeto2.frame.w = inimigo->frame.w;
	objeto2.frame.h = inimigo->frame.h;
	objeto2.movimento.cima = inimigo->movimento.cima;
	objeto2.movimento.baixo = inimigo->movimento.baixo;
	objeto2.movimento.esquerda = inimigo->movimento.esquerda;
	objeto2.movimento.direita = inimigo->movimento.direita;

	return Distancia(&objeto1, &objeto2);
}

// Converte jogador em objeto
Objeto Converte_Jogador_Objeto(Jogador* jogador)
{
	// Conversao de jogadores em objetos
	Objeto objeto;

	// Jogador 1
	objeto.posicao.x = jogador->posicao.x;
	objeto.posicao.y = jogador->posicao.y;
	objeto.frame.w = jogador->frame.w;
	objeto.frame.h = jogador->frame.h;
	objeto.movimento.cima = jogador->movimento.cima;
	objeto.movimento.baixo = jogador->movimento.baixo;
	objeto.movimento.esquerda = jogador->movimento.esquerda;
	objeto.movimento.direita = jogador->movimento.direita;

	return objeto;
}

// Converte inimigo em objeto
Objeto Converte_Inimigo_Objeto(Inimigo* inimigo)
{
	// Conversao de inimigo em objeto
	Objeto objeto;

	// Inimigo
	objeto.posicao.x = inimigo->posicao.x;
	objeto.posicao.y = inimigo->posicao.y;
	objeto.frame.w = inimigo->frame.w;
	objeto.frame.h = inimigo->frame.h;
	objeto.movimento.cima = inimigo->movimento.cima;
	objeto.movimento.baixo = inimigo->movimento.baixo;
	objeto.movimento.esquerda = inimigo->movimento.esquerda;
	objeto.movimento.direita = inimigo->movimento.direita;

	return objeto;
}

// Realiza teste de colisao geral entre jogador e inimigos
void Teste_de_Colisao_Jogador(Jogador* jogador, Vetor_de_Inimigos* vetor_de_inimigos)
{
	int i;

	int teve_colisao = FALSO;

	for (i = 0; i != vetor_de_inimigos->quantidade; i++)
	{
		if (Colisao_Entre_Jogador_Inimigo(jogador, &vetor_de_inimigos->inimigo[i]))
		{
			jogador->colisao = VERDADEIRO;
			teve_colisao = VERDADEIRO;
			break;
		}
	}

	if (!teve_colisao)
		jogador->colisao = FALSO;
}

// ***********************************************************************************

//
// Funcoes relacionadas aos tiros
//

// Cria um tiro em tela
Objeto Cria_Tiro(Jogador* jogador)
{
	// Carrega teclas de acao
	Carrega_Teclas_de_Acao(jogador);

	// Inicializa tiro
	Objeto tiro;

	// Verifica ataque
	if(jogador->movimento.ataque)
	{
		tiro.movimento.cima 		= 	jogador->movimento.cima;
		tiro.movimento.esquerda 	= 	jogador->movimento.esquerda;
		tiro.movimento.direita 		= 	jogador->movimento.direita;
		tiro.movimento.baixo 		=	jogador->movimento.baixo;
	}

	// Recebe posicao do jogador
	tiro.posicao.x = (jogador->posicao.x+jogador->frame.w)/2;
	tiro.posicao.y = (jogador->posicao.y+jogador->frame.h)/2;

	// Posicao y sera a mesma
	tiro.frame.y = 0;

	// Tamanho dos frames do tiro
	tiro.frame.w = 64;
	tiro.frame.h = 64;

	// Tamanho do tiro em tela
	tiro.posicao.w = 64;
	tiro.posicao.h = 64;

	if(jogador->movimento.cima && jogador->movimento.esquerda)
		tiro.frame.x = 64; // Frame

	else if(jogador->movimento.cima && jogador->movimento.direita)
		tiro.frame.x = 192; // Frame

	else if(jogador->movimento.baixo && jogador->movimento.esquerda)
		tiro.frame.x = 448; // Frame
	
	else if(jogador->movimento.baixo && jogador->movimento.direita)
		tiro.frame.x = 320; // Frame
	
	else if(jogador->movimento.cima)
		tiro.frame.x = 128; // Frame
		
	else if(jogador->movimento.baixo)
		tiro.frame.x = 384; // Frame
		
	else if(jogador->movimento.esquerda)
		tiro.frame.x = 0; // Frame
		
	else if(jogador->movimento.direita)
		tiro.frame.x = 256; // Frame

	return tiro;
}

// Carrega o tiro na memoria
void CarregaTiro(SDL_Renderer* renderer, Objeto* tiro, Jogador* jogador)
{
	SDL_Surface* Loading_Surf;

	Loading_Surf = IMG_Load("arte/ataques/fireball.png"); 

	tiro->sprite = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf);

	SDL_FreeSurface(Loading_Surf);


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

// Cria um vetor de tiros
Vetor_de_Tiros Cria_Vetor_de_Tiros()
{
	Vetor_de_Tiros vetor_de_tiros;

	vetor_de_tiros.quantidade = 0;
	vetor_de_tiros.corta_tiro = 0;

	return vetor_de_tiros;
}

// Adiciona um novo tiro ao vetor de tiros
void Adiciona_Tiro_ao_Vetor(SDL_Renderer* renderer, Vetor_de_Tiros* vetor_de_tiros, Jogador* jogador)
{
	// Cria um novo tiro
	vetor_de_tiros->tiro[vetor_de_tiros->quantidade] = Cria_Tiro(jogador);

	// Adiciona tiro na memoria
	CarregaTiro(renderer, &vetor_de_tiros->tiro[vetor_de_tiros->quantidade], jogador);

	// Soma o contador de tiros em tela
	vetor_de_tiros->quantidade++;
}

// Renderiza tiros em tela
void Renderiza_Tiros(SDL_Renderer* renderer, Vetor_de_Tiros* vetor_de_tiros)
{
	int i;

	if (vetor_de_tiros->quantidade > 0)
	{
		for (i = 0; i != vetor_de_tiros->quantidade; i++)
		{
			SDL_RenderCopy(renderer,
				vetor_de_tiros->tiro[i].sprite,
				&vetor_de_tiros->tiro[i].frame,
				&vetor_de_tiros->tiro[i].posicao);
		}
	}
}