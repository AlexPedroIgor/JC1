// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

/*
	FISICA

	FUNCOES DE MOVIMENTACAO DE OBJETOS EM TELA

	Jogo de desenvolvido para projeto de computacao 1
*/ 

#include "fisica.h"

//
// PRE CARREGAMENTO DAS FUNCOES
//

void Jogador_Movimentar(Objeto* jogador);
void Ataque_dos_Jogadores(SDL_Renderer* renderer, Jogadores* jogadores, Projeteis* projeteis);
void Movimentacao_dos_Jogadores(Jogadores* jogadores, Inimigos* inimigos);
void Inimigo_Movimentar(Objeto* inimigo);
void Movimentacao_dos_Inimigos(Inimigos* inimigos, Jogadores* jogadores);


// ********************************************************************************************

//
// FUNCOES DE MOVIMENTACAO E ATAQUE DOS JOGADORES
//

// MOVIMENTACAO DE UM UNICO JOGADOR
void Jogador_Movimentar(Objeto* jogador)
{
	// Carrega teclas de acao
	Carrega_Teclas_de_Acao(jogador);

	//
	// Movimentos diagonais
	//


	// Nordeste
	if (jogador->movimento.cima && jogador->movimento.esquerda)
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
}

// COMANDO DE ATAQUE DE UM UNICO JOGADOR
void Ataque_dos_Jogadores(SDL_Renderer* renderer, Jogadores* jogadores, Projeteis* projeteis)
{
	int i;

	for (i = 0; i != jogadores->quantidade; i++) // LOOP PARA OS JOGADORES
	{
		Carrega_Teclas_de_Acao(jogadores->jogador[i].inf); // CARREGA TECLAS DE ACAO

		if (jogadores->jogador[i].inf.movimento.ataque) // VERIFICA SE TEM ATAQUE
		{
			switch (jogadores->jogador[i].classe) // VERIFICA A CLASSE DO PERSONAGEM
			{
				case MAGO:
					switch (jogadores->jogador[i].ataque_tipo) // VERIFICA O TIPO DE ATAQUE SELECIONADO
					{
						case 1: // FIREBALL
							Inicializa_Fireball(renderer,
								projeteis,
								&jogadores->jogador[i].inf);
							break;

						case 2:
							break
					}
					break;

				case ARQUEIRO:
					switch (jogadores->jogador[i].ataque_tipo)
					{
						case 1: // FLECHA

						case 2:
							break;
					}
					break;
			}
		}
	}

	
	

	if (jogador->movimento.ataque)
	{
		if (jogador->)
		Adiciona_Tiro_ao_Vetor(renderer, projeteis, jogador);
	}
}

// MOVIMENTACAO GERAL DOS JOGADORES
void Movimentacao_dos_Jogadores(Jogadores* jogadores, Inimigos* inimigos)
{
	Teste_de_Colisao(Jogadores* jogadores, Inimigos* inimigos);

	int i;

	for (i = 0; i != jogadores->quantidade; i++)
	{
		Jogador_Movimentar(&jogadores->jogador[i].inf);
	}
}

// ********************************************************************************************

//
// FUNCOES DE MOVIMENTACAO E ATAQUE DOS INIMIGOS
//

// Funcao para executar movimentacao do inimigo
void Inimigo_Movimentar(Objeto* inimigo)
{
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
		if (!inimigo->colisao.cima && !inimigo->colisao.esquerda)
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
		if (!inimigo->colisao.cima && !inimigo->colisao.direita)
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
		if (!inimigo->colisao.baixo && !inimigo->colisao.esquerda)
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
		if (!inimigo->colisao.baixo && !inimigo->colisao.direita)
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
		if (!inimigo->colisao.cima)
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
		if (!inimigo->colisao.baixo)
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
		if (!inimigo->colisao.esquerda)
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
		if (!inimigo->colisao.direita)
			inimigo->posicao.x += inimigo->velocidade.x;
	}
}

// Movimentando vetor de inimigos
void Movimentacao_dos_Inimigos(Inimigos* inimigos, Jogadores* jogadores)
{
	// Teste de colisao
	Teste_de_Colisao(jogadores, inimigos);

	int i;
	if (inimigos->quantidade > 0)
	{
		for (i = 0; i != inimigos->quantidade; i++)
		{
			IA_de_Movimentacao(&inimigos->inimigo[i].inf, Jogadores* jogadores);
		}
	}
}

// ********************************************************************************************

// FIM