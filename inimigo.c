// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

/*
	INIMIGO

	Jogo de desenvolvido para projeto de computacao 1
*/

#include "main.h"
#include "inimigo.h"
#include "config.h"
#include "fisica.h"

// Pre carregamento das funcoes
Inimigo Carrega_Inimigo(SDL_Renderer* renderer, int numero);
Vetor_de_Inimigos Cria_Vetor_de_inimigos(SDL_Renderer* renderer, int quantidade, int tipo);
void Adiciona_inimigos(SDL_Renderer* renderer,Vetor_de_Inimigos* vetor_de_inimigos, int quantidade, int tipo, int portal);
void Remove_Inimigos_Mortos(SDL_Renderer* renderer, Vetor_de_Inimigos* vetor_de_inimigos);
void Posiciona_Inimigo(SDL_Renderer* renderer, Inimigo* inimigo, int portal);
void Posiciona_Vetor_de_Inimigos(SDL_Renderer* renderer, Vetor_de_Inimigos* vetor_de_inimigos, int portal);
void Movimenta_Inimigo(Inimigo* inimigo);
void IA_de_Movimentacao(Inimigo* inimigo, Jogador* jogador1, Jogador* jogador2);
void Movimentacao_dos_Inimigos(Vetor_de_Inimigos* vetor_de_inimigos, Jogador* jogador1, Jogador* jogador2);
void Atualiza_Inimigos_em_Tela(SDL_Renderer* renderer, Vetor_de_Inimigos* vetor_de_inimigos);

//
// Funcoes de carregamento
//

// Funcao para carregar inimigo
Inimigo Carrega_Inimigo(SDL_Renderer* renderer, int tipo)
{
	// Estrutura com informacoes do inimigo
	Inimigo inimigo;

	// Estado de colisao
	inimigo.colisao = FALSO;
	inimigo.toma_tiro = FALSO;

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

// Funcao para criar vetor de inimigos
Vetor_de_Inimigos Cria_Vetor_de_inimigos(SDL_Renderer* renderer, int quantidade, int tipo)
{
	// Inicializa variavel
	Vetor_de_Inimigos vetor_de_inimigos;

	// Salva quantidade inivial de inimigos gerados
	vetor_de_inimigos.quantidade = quantidade;

	// Zera o numero de inimigos mortos
	vetor_de_inimigos.mortos = 0;
	vetor_de_inimigos.mortos_rodada = 0;

	int i;

	for (i = 0; i != quantidade; i++)
	{
		vetor_de_inimigos.inimigo[i] = Carrega_Inimigo(renderer, tipo);
	}

	return vetor_de_inimigos;
}

// Adiciona inimigos
void Adiciona_inimigos(SDL_Renderer* renderer,Vetor_de_Inimigos* vetor_de_inimigos,
	int quantidade, int tipo, int portal)
{
	int i;

	if (vetor_de_inimigos->quantidade + quantidade <= 64)
	{
		for (i = vetor_de_inimigos->quantidade; i != vetor_de_inimigos->quantidade + quantidade; i++)
		{
			vetor_de_inimigos->inimigo[i] = Carrega_Inimigo(renderer, tipo);
			Posiciona_Inimigo(renderer, &vetor_de_inimigos->inimigo[i], portal);
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
// Funcoes de movimento
//

// Funcao para posicionar inimigo em tela
void Posiciona_Inimigo(SDL_Renderer* renderer, Inimigo* inimigo, int portal)
{
	switch (portal)
	{
		case CIMA:
			inimigo->posicao.x = SCREEN_WIDTH/2 - 30;
			inimigo->posicao.y = 51;
			break;

		case BAIXO:
			inimigo->posicao.x = SCREEN_WIDTH/2 - 30;
			inimigo->posicao.y = 500;
			break;

		case ESQUERDA:
			inimigo->posicao.x = 51;
			inimigo->posicao.y = SCREEN_HEIGHT/2-30;
			break;

		case DIREITA:
			inimigo->posicao.x = 700;
			inimigo->posicao.y = SCREEN_HEIGHT/2-30;
			break;
	}
}

// Funcao para posicionar vetor de inimigos em tela
void Posiciona_Vetor_de_Inimigos(SDL_Renderer* renderer, Vetor_de_Inimigos* vetor_de_inimigos, int portal)
{
	int i;

	for (i = 0; i != vetor_de_inimigos->quantidade; i++)
	{
		Posiciona_Inimigo(renderer, &vetor_de_inimigos->inimigo[i], rand() %4 +1);
	}
}

// Funcao para executar movimentacao do inimigo
void Movimenta_Inimigo(Inimigo* inimigo)
{
	// Verifica colisao de tela
	int movimento_permitido;
	if (Colisao_Inimigo_LimiteDeTela(inimigo) || inimigo->colisao)
		movimento_permitido = FALSO;
	else
		movimento_permitido = VERDADEIRO;

	// ******************************************************************************

	//
	// Movimentos diagonais
	//

	// Nordeste
	if (inimigo->movimento.cima && inimigo->movimento.esquerda)
	{
		// Animacao
		inimigo->frame.y = 512;

		if (inimigo->frame.x < 512)
			inimigo->frame.x += 64;

		else
			inimigo->frame.x = 0;

		// Salva movimento de animacao
		inimigo->animacao = QUADRANTE2;

		// Movimentacao
		if (movimento_permitido)
		{
			inimigo->posicao.y -= inimigo->velocidade.y;
			inimigo->posicao.x -= inimigo->velocidade.x;
		}
	}

	// Noroeste
	else if (inimigo->movimento.cima && inimigo->movimento.direita)
	{
		// Animacao
		inimigo->frame.y = 512;

		if (inimigo->frame.x < 512)
			inimigo->frame.x += 64;

		else
			inimigo->frame.x = 0;

		// Salva movimento de animacao
		inimigo->animacao = QUADRANTE1;

		// Movimentacao
		if (movimento_permitido)
		{
			inimigo->posicao.y -= inimigo->velocidade.y;
			inimigo->posicao.x += inimigo->velocidade.x;
		}
	}

	// Suldeste
	else if (inimigo->movimento.baixo && inimigo->movimento.esquerda)
	{
		// Animacao
		inimigo->frame.y = 640;

		if (inimigo->frame.x < 512)
			inimigo->frame.x += 64;

		else
			inimigo->frame.x = 0;

		// Salva movimento de animacao
		inimigo->animacao = QUADRANTE3;

		// Movimentacao
		if (movimento_permitido)
		{
			inimigo->posicao.y += inimigo->velocidade.y;
			inimigo->posicao.x -= inimigo->velocidade.x;
		}
	}

	// Suldoeste
	else if (inimigo->movimento.baixo && inimigo->movimento.direita)
	{
		// Animacao
		inimigo->frame.y = 640;

		if (inimigo->frame.x < 512)
			inimigo->frame.x += 64;

		else
			inimigo->frame.x = 0;

		// Salva movimento de animacao
		inimigo->animacao = QUADRANTE4;

		// Movimentacao
		if (movimento_permitido)
		{
			inimigo->posicao.y += inimigo->velocidade.y;
			inimigo->posicao.x += inimigo->velocidade.x;
		}
	}

	//
	// Movimentos principais
	//

	// Cima
	else if (inimigo->movimento.cima)
	{
		// Animacao
		inimigo->frame.y = 512;

		if (inimigo->frame.x < 512)
			inimigo->frame.x += 64;
		else
			inimigo->frame.x = 0;

		// Salva movimento de animacao
		inimigo->animacao = CIMA;

		// Movimento
		if (movimento_permitido
			&& !inimigo->colisao)
			inimigo->posicao.y -= inimigo->velocidade.y;
	}

	// Baixo
	else if (inimigo->movimento.baixo)
	{
		// Animacao
		inimigo->frame.y = 640;

		if (inimigo->frame.x < 512)
			inimigo->frame.x += 64;
		else
			inimigo->frame.x = 0;

		// Salva movimento de animacao
		inimigo->animacao = BAIXO;

		// Movimento
		if (movimento_permitido)
			inimigo->posicao.y += inimigo->velocidade.y;
	}

	// Esquerda
	else if (inimigo->movimento.esquerda)
	{
		// Animacao
		inimigo->frame.y = 576;

		if (inimigo->frame.x < 512)
			inimigo->frame.x += 64;
		else
			inimigo->frame.x = 0;

		// Salva movimento de animacao
		inimigo->animacao = ESQUERDA;

		// Movimento
		if (movimento_permitido)
			inimigo->posicao.x -= inimigo->velocidade.x;
	}

	// Direita
	else if (inimigo->movimento.direita)
	{
		// Animacao
		inimigo->frame.y = 704;

		if (inimigo->frame.x < 512)
			inimigo->frame.x += 64;
		else
			inimigo->frame.x = 0;

		// Salva movimento de animacao
		inimigo->animacao = DIREITA;

		// Movimento
		if (movimento_permitido)
			inimigo->posicao.x += inimigo->velocidade.x;
	}
}

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

	distancia = vetor_distancia_quadrante[0];
	quadrante = vetor_distancia_quadrante[1];

	// *************************************************************************************

	//
	// Decisao de movimentacao
	//

	int randomico = rand() % 8;

	int loucura = rand() % 100;

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

	// *************************************************************************************

	//
	// Execucao de movimentacao
	//

	Movimenta_Inimigo(inimigo);

	// *************************************************************************************
}

// Movimentando vetor de inimigos
void Movimentacao_dos_Inimigos(Vetor_de_Inimigos* vetor_de_inimigos, Jogador* jogador1, Jogador* jogador2)
{
	// Teste de colisao
	Teste_de_Colisao_Inimigos(vetor_de_inimigos, jogador1, jogador2);

	int i;

	for (i = 0; i != vetor_de_inimigos->quantidade; i++)
	{
		IA_de_Movimentacao(&vetor_de_inimigos->inimigo[i], jogador1, jogador2);
	}
}

// ***********************************************************************************

//
// Testes de colisao
//

void Teste_de_Colisao_Inimigos(Vetor_de_Inimigos* vetor_de_inimigos, Jogador* jogador1, Jogador* jogador2)
{
	int i, j;

	int teve_colisao = FALSO;

	for (i = 0; i != vetor_de_inimigos->quantidade; i++)
	{
		// Testa colisao entre inimigos
		for (j = 0; j != vetor_de_inimigos->quantidade; j++)
		{
			if (j != i)
			{
				if (Colisao_Entre_Inimigos(&vetor_de_inimigos->inimigo[i], &vetor_de_inimigos->inimigo[j]))
				{
					vetor_de_inimigos->inimigo[i].colisao = VERDADEIRO;
					teve_colisao = VERDADEIRO;
					break;
				}
			}
		}

		// Testa colisao entre jogadores
		if (Colisao_Entre_Inimigo_Jogador(&vetor_de_inimigos->inimigo[i], jogador1))
		{
			vetor_de_inimigos->inimigo[i].colisao = VERDADEIRO;
			teve_colisao = VERDADEIRO;
		}
		// Caso tenha um segundo jogador
		if (jogador2 != NULL)
		{
			if (Colisao_Entre_Inimigo_Jogador(&vetor_de_inimigos->inimigo[i], jogador2))
			{
				vetor_de_inimigos->inimigo[i].colisao = VERDADEIRO;
				teve_colisao = VERDADEIRO;
			}
		}

		if (!teve_colisao)
			vetor_de_inimigos->inimigo[i].colisao = FALSO;
	}
}

// ***********************************************************************************

//
// Funcoes de renderizacao em tela
//

// Funcao para renderizar um vetor de inimigos em tela
void Atualiza_Inimigos_em_Tela(SDL_Renderer* renderer, Vetor_de_Inimigos* vetor_de_inimigos)
{
	int i;

	for (i = 0; i != vetor_de_inimigos->quantidade; i++)
	{
		SDL_RenderCopy(renderer, vetor_de_inimigos->inimigo[i].sprite,
			&vetor_de_inimigos->inimigo[i].frame,
			&vetor_de_inimigos->inimigo[i].posicao);
	}
}

// fim