// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

/*
	INIMIGO

	Jogo de desenvolvido para projeto de computacao 1
*/

#include "inimigo.h"
#include "base.h"
#include "config.h"
#include "fisica.h"


//
// PRE CARREGAMENTO DAS FUNCOES
//

Objeto Cria_Inimigo(SDL_Renderer* renderer, int tipo);
void Adiciona_Inimigos(SDL_Renderer* renderer, Inimigos* vetor_de_inimigos, int quantidade, int tipo, int portal, Fase* fase);
void Remove_Inimigos_Mortos(SDL_Renderer* renderer, Inimigos* vetor_de_inimigos);
void Posiciona_Inimigo(SDL_Renderer* renderer, Objeto* inimigo, int portal, Fase* fase);
void Posiciona_Inimigos(SDL_Renderer* renderer, Inimigos* vetor_de_inimigos, int portal, Fase* fase);
void IA_de_Movimentacao(Objeto* inimigo, Jogadores* jogadores);
void Inimigo_Ataque(Objeto* inimigo, Objeto* jogador);
void Inimigo_Toma_Dano(SDL_Renderer* renderer, Objeto* inimigo, Status* status, int tipo);

// ******************************************************************************************************************************

//
// CARREGAMENTO DE INIMIGOS
//

// Funcao para carregar inimigo
Objeto Cria_Inimigo(SDL_Renderer* renderer, int tipo)
{
	// Estrutura com informacoes do inimigo
	Objeto inimigo;

	// Posicao de colisoes
	inimigo.colisao.cima = FALSO;
	inimigo.colisao.baixo = FALSO;
	inimigo.colisao.esquerda = FALSO;
	inimigo.colisao.direita = FALSO;

	SDL_Surface* Loading_Surf = NULL;

	switch(tipo)
	{
		case 1:
			// Velocidade de movimento do inimigo
			inimigo.velocidade.x = VEL_INIMIGO_1;
			inimigo.velocidade.y = VEL_INIMIGO_1;
			Loading_Surf = IMG_Load("arte/personagens/vilao01/esqueleto.png");
			break;

		case 2:
			// Velocidade de movimento do inimigo
			inimigo.velocidade.x = VEL_INIMIGO_2;
			inimigo.velocidade.y = VEL_INIMIGO_2;
			Loading_Surf = IMG_Load("arte/personagens/vilao02/orc.png");
			break;

		case 3:
			// Velocidade de movimento do inimigo
			inimigo.velocidade.x = VEL_INIMIGO_3;
			inimigo.velocidade.y = VEL_INIMIGO_3;
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

// Adiciona inimigos
void Adiciona_Inimigos(SDL_Renderer* renderer, Inimigos* inimigos,
	int quantidade, int tipo, int portal, Fase* fase)
{
	int i;

	if (inimigos->quantidade + quantidade < 64)
	{
		for (i = inimigos->quantidade; i != inimigos->quantidade + quantidade; i++)
		{
			inimigos->inimigo[i].tipo = tipo;
			inimigos->inimigo[i].vivo = VERDADEIRO;
			inimigos->inimigo[i].inf = Cria_Inimigo(renderer, tipo);
			Posiciona_Inimigo(renderer, &inimigos->inimigo[i].inf, portal, fase);
		}
	}

	inimigos->quantidade += quantidade;
}

// Remove inimigos mortos
void Remove_Inimigos_Mortos(SDL_Renderer* renderer, Inimigos* inimigos)
{
	// Verifica se existem inimigos mortos na ultima rodada
	if (inimigos->mortos > 0)
	{
		int cortes = 0;

		int i, j;

		for (i = 0; i != inimigos->quantidade; i++)
		{
			for (j = i; j != inimigos->quantidade; j++)
			{
				if (!inimigos->inimigo[i].vivo)
				{
					// Limpa memoria
					free(&inimigos->inimigo[i]);

					inimigos->inimigo[i] = inimigos->inimigo[j];

					cortes++;
				}
			}
		}

		inimigos->quantidade -= cortes;
	}

	// Atualiza lista de mortos
	inimigos->mortos += inimigos->mortos;
	inimigos->mortos = 0;
}

// **********************************************************************************

//
// POSICIONAMENTO EM TELA
//

// INIMIGO UNICO
void Posiciona_Inimigo(SDL_Renderer* renderer, Objeto* inimigo, int portal, Fase* fase)
{
	// Troca portal
	if (fase->portal.cima.inimigos == 0)
		portal = BAIXO;
	if (fase->portal.cima.inimigos == 0)
		portal = ESQUERDA;
	if (fase->portal.cima.inimigos == 0)
		portal = DIREITA;
	if (fase->portal.cima.inimigos == 0)
		portal = CIMA;

	switch (portal)
	{
		case CIMA:
			fase->portal.cima.inimigos--;
			inimigo->posicao.x = SCREEN_WIDTH/2 - 30;
			inimigo->posicao.y = 51;
			break;

		case BAIXO:
			fase->portal.cima.inimigos--;
			inimigo->posicao.x = SCREEN_WIDTH/2 - 30;
			inimigo->posicao.y = 500;
			break;

		case ESQUERDA:
			fase->portal.cima.inimigos--;
			inimigo->posicao.x = 51;
			inimigo->posicao.y = SCREEN_HEIGHT/2-30;
			break;

		case DIREITA:
			fase->portal.cima.inimigos--;
			inimigo->posicao.x = 700;
			inimigo->posicao.y = SCREEN_HEIGHT/2-30;
			break;
	}
}

// SERIE DE INIMIGOS
void Posiciona_Inimigos(SDL_Renderer* renderer, Inimigos* inimigos, int portal, Fase* fase)
{
	int i;

	for (i = 0; i != inimigos->quantidade; i++)
	{
		Posiciona_Inimigo(renderer, &inimigos->inimigo[i].inf, rand() %4+1, fase);
	}
}

// **********************************************************************************

//
// LOGICA DE MOVIMENTACAO E ATAQUE
//

// Funcao para determinar qual vai ser a movimentacao do inimigo
void IA_de_Movimentacao(Objeto* inimigo, Jogadores* jogadores)
{
	// ***************************************************************************

	//
	// Distancia entre jogadores e inimigo
	//

	// Variavel que carrega a distancia
	int distancia, quadrante;

	int jogador_proximo;

	int* vetor_distancia_quadrante;

	vetor_distancia_quadrante = (int*) malloc(2*sizeof(int));


	vetor_distancia_quadrante = Vetor_Distancia_Quadrante(inimigo, &jogadores->jogador[0].inf);
	distancia = vetor_distancia_quadrante[0];
	quadrante = vetor_distancia_quadrante[1];
	jogador_proximo = 1;

	if (jogadores->quantidade == 2)
	{
		vetor_distancia_quadrante = Vetor_Distancia_Quadrante(inimigo, &jogadores->jogador[1].inf);
		if (distancia < vetor_distancia_quadrante[0])
		{
			distancia = vetor_distancia_quadrante[0];
			quadrante = vetor_distancia_quadrante[1];
			jogador_proximo = 2;
		}
	}

	free(vetor_distancia_quadrante);

	// *************************************************************************************

	//
	// Decisao de movimentacao
	//

	int randomico = rand() % 8;

	int loucura;
	
	if(distancia < 65)
		Inimigo_Ataque(inimigo, &jogadores->jogador[jogador_proximo-1].inf);

	if(distancia > 150)
		loucura = 10;
	else
		loucura = rand() % 100;


	switch (loucura)
	{
		case 10: // Aproxima
		case 20:
		case 30:
		case 40:
		case 50:
			if (distancia >= 50)
			{
				switch (quadrante)
				{
					case CIMA:
						inimigo->movimento.cima = FALSO;
						inimigo->movimento.baixo = VERDADEIRO;
						inimigo->movimento.esquerda = FALSO;
						inimigo->movimento.direita = FALSO;
						break;

					case BAIXO:
						inimigo->movimento.cima = VERDADEIRO;
						inimigo->movimento.baixo = FALSO;
						inimigo->movimento.esquerda = FALSO;
						inimigo->movimento.direita = FALSO;
						break;

					case ESQUERDA:
						inimigo->movimento.cima = FALSO;
						inimigo->movimento.baixo = FALSO;
						inimigo->movimento.esquerda = FALSO;
						inimigo->movimento.direita = VERDADEIRO;
						break;

					case DIREITA:
						inimigo->movimento.cima = FALSO;
						inimigo->movimento.baixo = FALSO;
						inimigo->movimento.esquerda = VERDADEIRO;
						inimigo->movimento.direita = FALSO;
						break;

					case QUADRANTE1:
						inimigo->movimento.cima = FALSO;
						inimigo->movimento.baixo = VERDADEIRO;
						inimigo->movimento.esquerda = FALSO;
						inimigo->movimento.direita = VERDADEIRO;
						break;

					case QUADRANTE2:
						inimigo->movimento.cima = FALSO;
						inimigo->movimento.baixo = VERDADEIRO;
						inimigo->movimento.esquerda = VERDADEIRO;
						inimigo->movimento.direita = FALSO;
						break;

					case QUADRANTE3:
						inimigo->movimento.cima = VERDADEIRO;
						inimigo->movimento.baixo = FALSO;
						inimigo->movimento.esquerda = VERDADEIRO;
						inimigo->movimento.direita = FALSO;
						break;

					case QUADRANTE4:
						inimigo->movimento.cima = VERDADEIRO;
						inimigo->movimento.baixo = FALSO;
						inimigo->movimento.esquerda = FALSO;
						inimigo->movimento.direita = VERDADEIRO;
						break;
				}
			}
			break;

		case 60: // Movimento randomico
		case 70:
		case 80:
		case 90:
			switch (randomico)
			{
				case 1:
					inimigo->movimento.cima = FALSO;
					inimigo->movimento.baixo = VERDADEIRO;
					inimigo->movimento.esquerda = FALSO;
					inimigo->movimento.direita = FALSO;
					break;

				case 2:
					inimigo->movimento.cima = VERDADEIRO;
					inimigo->movimento.baixo = FALSO;
					inimigo->movimento.esquerda = FALSO;
					inimigo->movimento.direita = FALSO;
					break;

				case 3:
					inimigo->movimento.cima = FALSO;
					inimigo->movimento.baixo = FALSO;
					inimigo->movimento.esquerda = FALSO;
					inimigo->movimento.direita = VERDADEIRO;
					break;	

				case 4:
					inimigo->movimento.cima = FALSO;
					inimigo->movimento.baixo = FALSO;
					inimigo->movimento.esquerda = VERDADEIRO;
					inimigo->movimento.direita = FALSO;
					break;

				case 5:
					inimigo->movimento.cima = FALSO;
					inimigo->movimento.baixo = VERDADEIRO;
					inimigo->movimento.esquerda = FALSO;
					inimigo->movimento.direita = VERDADEIRO;
					break;

				case 6:
					inimigo->movimento.cima = FALSO;
					inimigo->movimento.baixo = VERDADEIRO;
					inimigo->movimento.esquerda = VERDADEIRO;
					inimigo->movimento.direita = FALSO;
					break;

				case 7:
					inimigo->movimento.cima = VERDADEIRO;
					inimigo->movimento.baixo = FALSO;
					inimigo->movimento.esquerda = VERDADEIRO;
					inimigo->movimento.direita = FALSO;
					break;

				case 8:
					inimigo->movimento.cima = VERDADEIRO;
					inimigo->movimento.baixo = FALSO;
					inimigo->movimento.esquerda = FALSO;
					inimigo->movimento.direita = VERDADEIRO;
					break;
			}
			break;
	}

	// ***************************************************************************

	// Caso tenha colisao vai afastar
		
	// Cima
	if (inimigo->colisao.cima)
	{
		inimigo->movimento.cima = FALSO;
		inimigo->movimento.baixo = VERDADEIRO;
		inimigo->movimento.esquerda = FALSO;
		inimigo->movimento.direita = FALSO;
	}

	// Baixo
	else if (inimigo->colisao.baixo)
	{
		inimigo->movimento.cima = VERDADEIRO;
		inimigo->movimento.baixo = FALSO;
		inimigo->movimento.esquerda = FALSO;
		inimigo->movimento.direita = FALSO;
	}

	// Esquerda
	else if (inimigo->colisao.esquerda)
	{
		inimigo->movimento.cima = FALSO;
		inimigo->movimento.baixo = FALSO;
		inimigo->movimento.esquerda = FALSO;
		inimigo->movimento.direita = VERDADEIRO;
	}	

	// Direita
	else if (inimigo->colisao.direita)
	{
		inimigo->movimento.cima = FALSO;
		inimigo->movimento.baixo = FALSO;
		inimigo->movimento.esquerda = VERDADEIRO;
		inimigo->movimento.direita = FALSO;
	}
	
	// *************************************************************************************

	//
	// Execucao de movimentacao
	//

	Inimigo_Movimentar(inimigo);

	// *************************************************************************************
}


// ATAQUE DE UM INIMIGO
void Inimigo_Ataque(Objeto* inimigo, Objeto* jogador)
{

}

// ***********************************************************************************

//
// EFEITOS DE DANO
//

void Inimigo_Toma_Dano(SDL_Renderer* renderer, Objeto* inimigo, Status* status, int tipo)
{
	switch (tipo)
	{
		case 1:
			status->HP -= 20;
			break;

		case 2:
			status->HP -= 50;
			break;
	}

	Inimigo_Animacao_Toma_Dano(renderer, inimigo);
}


// ***********************************************************************************

// FIM
