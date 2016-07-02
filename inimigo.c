// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

/*
	INIMIGO

	Jogo de desenvolvido para projeto de computacao 1
*/

#include "inimigo.h"

//
// PRE CARREGAMENTO DAS FUNCOES
//

Inimigo Carrega_Inimigo(SDL_Renderer* renderer, int numero);
Vetor_de_Inimigos Cria_Vetor_de_inimigos(SDL_Renderer* renderer, int quantidade, int tipo);
void Adiciona_inimigos(SDL_Renderer* renderer,Vetor_de_Inimigos* vetor_de_inimigos, int quantidade, int tipo, int portal, Fase* fase);
void Remove_Inimigos_Mortos(SDL_Renderer* renderer, Vetor_de_Inimigos* vetor_de_inimigos);
void Posiciona_Inimigo(SDL_Renderer* renderer, Inimigo* inimigo, int portal, Fase* fase);
void Posiciona_Vetor_de_Inimigos(SDL_Renderer* renderer, Vetor_de_Inimigos* vetor_de_inimigos, int portal, Fase* fase);
void Movimenta_Inimigo(Inimigo* inimigo);
void IA_de_Movimentacao(Inimigo* inimigo, Jogador* jogador1, Jogador* jogador2);
void Movimentacao_dos_Inimigos(Vetor_de_Inimigos* vetor_de_inimigos, Jogador* jogador1, Jogador* jogador2);
void Atualiza_Inimigos_em_Tela(SDL_Renderer* renderer, Vetor_de_Inimigos* vetor_de_inimigos);
void Atacar_inimigo(Inimigo* inimigo);

// ******************************************************************************************************************************

//
// CARREGAMENTO DE INIMIGOS
//

// Funcao para carregar inimigo
Objeto Cria_Inimigo(SDL_Renderer* renderer, int tipo)
{
	// Estrutura com informacoes do inimigo
	Inimigo inimigo;

	// Estado de colisao
	inimigo.colisao = FALSO;
	inimigo.toma_tiro = FALSO;

	// Posicao de colisoes
	inimigo.quad_colide.cima = FALSO;
	inimigo.quad_colide.baixo = FALSO;
	inimigo.quad_colide.esquerda = FALSO;
	inimigo.quad_colide.direita = FALSO;

	// Inimigo vivo
	inimigo.vivo = VERDADEIRO;

	// Numero do inimigo
	inimigo.tipo = tipo;

	SDL_Surface* Loading_Surf = NULL;

	switch(tipo)
	{
		case 1:
			// Velocidade de movimento do inimigo
			inimigo.velocidade.x = VEL_INIMIGO;
			inimigo.velocidade.y = VEL_INIMIGO;
			Loading_Surf = IMG_Load("arte/personagens/vilao01/esqueleto.png");
			break;

		case 2:
			// Velocidade de movimento do inimigo
			inimigo.velocidade.x = VEL_INIMIGO;
			inimigo.velocidade.y = VEL_INIMIGO;
			Loading_Surf = IMG_Load("arte/personagens/vilao02/orc.png");
			break;

		case 3:
			// Velocidade de movimento do inimigo
			inimigo.velocidade.x = VEL_INIMIGO;
			inimigo.velocidade.y = VEL_INIMIGO;
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

	if (inimigos->quantidade + quantidade <= 64)
	{
		for (i = inimigos->quantidade; i != inimigos->quantidade + quantidade; i++)
		{
			inimigos->inimigo[i].inf = Cria_Inimigo(renderer, tipo);
			Posiciona_Inimigo(renderer, &inimigos->inimigo[i].inf, portal, fase);
		}
	}

	vetor_de_inimigos->quantidade += quantidade;
}

// Remove inimigos mortos
void Remove_Inimigos_Mortos(SDL_Renderer* renderer, Vetor_de_Inimigos* vetor_de_inimigos)
{
	// Verifica se existem inimigos mortos na ultima rodada
	if (vetor_de_inimigos->mortos_rodada > 0)
	{
		Inimigo auxiliar;

		int cortes = 0;

		int i, j;

		for (i = 0; i != vetor_de_inimigos->quantidade; i++)
		{
			for (j = i; j != vetor_de_inimigos->quantidade; j++)
			{
				if (!vetor_de_inimigos->inimigo[i].vivo)
				{
					// Limpa memoria
					free(&vetor_de_inimigos->inimigo[i]);

					vetor_de_inimigos->inimigo[i] = vetor_de_inimigos->inimigo[j];

					cortes++;
				}
			}
		}

		vetor_de_inimigos->quantidade -= cortes;
	}

	// Atualiza lista de mortos
	vetor_de_inimigos->mortos += vetor_de_inimigos->mortos_rodada;
	vetor_de_inimigos->mortos_rodada = 0;
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

	for (i = 0; i != vetor_de_inimigos->quantidade; i++)
	{
		Posiciona_Inimigo(renderer, &inimigos->inimigo[i].inf, rand() %4+1, fase);
	}
}

// **********************************************************************************

//
// LOGICA DE MOVIMENTACAO E ATAQUE
//

// Funcao para determinar qual vai ser a movimentacao do inimigo
void IA_de_Movimentacao(Inimigo* inimigo, Jogador* jogador1, Jogador* jogador2)
{
	// ***************************************************************************

	//
	// Distancia entre jogadores e inimigo
	//

	// Variavel que carrega a distancia
	int distancia, quadrante;
	int* vetor_distancia_quadrante;

	// Caso so tenha um jogador
	if (jogador2 == NULL)
		vetor_distancia_quadrante = Distancia_Inimigo_Jogador(inimigo, jogador1);

	// Caso tenham dois jogadores
	else
	{
		int* d1 = Distancia_Inimigo_Jogador(inimigo, jogador1);

		int* d2 = Distancia_Inimigo_Jogador(inimigo, jogador2);

		// A distancia escolhida sera a do jogador mais proximo
		if (d1[0] < d2[0])
			vetor_distancia_quadrante = d1;
		else
			vetor_distancia_quadrante = d2;
	}

	distancia = &vetor_distancia_quadrante[0];
	quadrante = &vetor_distancia_quadrante[1];

	// *************************************************************************************

	//
	// Decisao de movimentacao
	//

	int randomico = rand() % 8;

	int loucura;
	
	if(distancia < 65)
		Atacar_inimigo(inimigo);

	if(distancia > 150)
		loucura = 10;
	else
		rand() % 100;


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
	if (inimigo->quad_colide.cima)
	{
		inimigo->movimento.cima = FALSO;
		inimigo->movimento.baixo = VERDADEIRO;
		inimigo->movimento.esquerda = FALSO;
		inimigo->movimento.direita = FALSO;
	}

	// Baixo
	else if (inimigo->quad_colide.baixo)
	{
		inimigo->movimento.cima = VERDADEIRO;
		inimigo->movimento.baixo = FALSO;
		inimigo->movimento.esquerda = FALSO;
		inimigo->movimento.direita = FALSO;
	}

	// Esquerda
	else if (inimigo->quad_colide.esquerda)
	{
		inimigo->movimento.cima = FALSO;
		inimigo->movimento.baixo = FALSO;
		inimigo->movimento.esquerda = FALSO;
		inimigo->movimento.direita = VERDADEIRO;
	}	

	// Direita
	else if (inimigo->quad_colide.direita)
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

	Movimenta_Inimigo(inimigo);

	// *************************************************************************************
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
			status.HP -= 20;
			break;

		case 2:
			status.HP -= 50;
			break;
	}

	Inimigo_Animacao_Toma_Dano(renderer, inimigo);
}


// ***********************************************************************************

// FIM