// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

/*
	FISICA

	FUNCOES DE MOVIMENTACAO DE OBJETOS EM TELA

	Jogo de desenvolvido para projeto de computacao 1
*/ 


// BIBLIOTECAS INTERNAS
#include "fisica.h"
#include "inimigo.h"
#include "jogo.h"
#include "som.h"

// ******************************************************************************************

//
// PRE CARREGAMENTO DAS FUNCOES
//

void Jogador_Movimentar(Objeto* jogador, int movimento_permitido);
void Ataque_dos_Jogadores(SDL_Renderer* renderer, Jogadores* jogadores, Projeteis* projeteis);
void Movimentacao_dos_Jogadores(Jogadores* jogadores, Inimigos* inimigos);
void Inimigo_Movimentar(Objeto* inimigo, int movimento_permitido);
void Movimentacao_dos_Inimigos(Inimigos* inimigos, Jogadores* jogadores);
Vetor_Distancia_Quadrante Distancia_Quadrante(Objeto* objeto1, Objeto* objeto2);


// ********************************************************************************************

//
// FUNCOES DE MOVIMENTACAO E ATAQUE DOS JOGADORES
//

// MOVIMENTACAO DE UM UNICO JOGADOR
void Jogador_Movimentar(Objeto* jogador, int movimento_permitido)
{
	//
	// Movimentos diagonais
	//
	int atirando = 0;
		
	if (jogador->movimento.ataque)
		atirando = 256;


	// Nordeste
	if (jogador->movimento.cima && jogador->movimento.esquerda)
	{
		// Animacao
		jogador->frame.y = 576 + atirando;

		if (jogador->frame.x < 512 - atirando*3/4)
			jogador->frame.x += 64;

		else
			jogador->frame.x = 0;

		// Salva movimento de animacao
		jogador->animacao = QUADRANTE2;

		// Movimentacao
		if (!jogador->colisao.cima && !jogador->colisao.esquerda
			&& !Colisao_LimiteDeTela(jogador)
			&& movimento_permitido)
		{
			if (jogador->cooldown == 10)
			{
				Efeito_Sonoro(FX_PASSO_1);
				jogador->cooldown = 1;
			}
			jogador->cooldown++;			
			jogador->posicao.y -= jogador->velocidade.y;
			jogador->posicao.x -= jogador->velocidade.x;
		}
	}

	// Noroeste
	else if (jogador->movimento.cima && jogador->movimento.direita)
	{
		// Animacao
		jogador->frame.y = 704 + atirando;

		if (jogador->frame.x < 512 - atirando*3/4)
			jogador->frame.x += 64;

		else
			jogador->frame.x = 0;

		// Salva movimento de animacao
		jogador->animacao = QUADRANTE1;

		// Movimentacao
		if (!jogador->colisao.cima && !jogador->colisao.direita
			&& !Colisao_LimiteDeTela(jogador)
			&& movimento_permitido)
		{
			if (jogador->cooldown == 10)
			{
				Efeito_Sonoro(FX_PASSO_1);
				jogador->cooldown = 1;
			}
			jogador->cooldown++;
			jogador->posicao.y -= jogador->velocidade.y;
			jogador->posicao.x += jogador->velocidade.x;
		}
	}

	// Suldeste
	else if (jogador->movimento.baixo && jogador->movimento.esquerda)
	{
		// Animacao
		jogador->frame.y = 576 + atirando;

		if (jogador->frame.x < 512 - atirando*3/4)
			jogador->frame.x += 64;

		else
			jogador->frame.x = 0;

		// Salva movimento de animacao
		jogador->animacao = QUADRANTE3;

		// Movimentacao
		if (!jogador->colisao.baixo && !jogador->colisao.esquerda
			&& !Colisao_LimiteDeTela(jogador)
			&& movimento_permitido)
		{
			if (jogador->cooldown == 10)
			{
				Efeito_Sonoro(FX_PASSO_1);
				jogador->cooldown = 1;
			}
			jogador->cooldown++;
			jogador->posicao.y += jogador->velocidade.y;
			jogador->posicao.x -= jogador->velocidade.x;
		}
	}

	// Suldoeste
	else if (jogador->movimento.baixo && jogador->movimento.direita)
	{
		// Animacao
		jogador->frame.y = 704 + atirando;

		if (jogador->frame.x < 512 - atirando*3/4)
			jogador->frame.x += 64;

		else
			jogador->frame.x = 0;

		// Salva movimento de animacao
		jogador->animacao = QUADRANTE4;

		// Movimentacao
		if (!jogador->colisao.baixo && !jogador->colisao.direita
			&& !Colisao_LimiteDeTela(jogador)
			&& movimento_permitido)
		{
			if (jogador->cooldown == 10)
			{
				Efeito_Sonoro(FX_PASSO_1);
				jogador->cooldown = 1;
			}
			jogador->cooldown++;
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
		jogador->frame.y = 512 + atirando;

		if (jogador->frame.x < 512 - atirando*3/4)
			jogador->frame.x += 64;
		else
			jogador->frame.x = 0;

		// Salva movimento de animacao
		jogador->animacao = CIMA;

		// Movimento
		if (!jogador->colisao.cima && !Colisao_LimiteDeTela(jogador)
			&& movimento_permitido)
		{
			if (jogador->cooldown == 10)
			{
				Efeito_Sonoro(FX_PASSO_1);
				jogador->cooldown = 1;
			}
			jogador->cooldown++;
			jogador->posicao.y -= jogador->velocidade.y;
		}

	}

	// Baixo
	else if (jogador->movimento.baixo)
	{
		// Animacao
		jogador->frame.y = 640 + atirando;

		if (jogador->frame.x < 512 - atirando*3/4)
			jogador->frame.x += 64;
		else
			jogador->frame.x = 0;

		// Salva movimento de animacao
		jogador->animacao = BAIXO;

		// Movimento
		if (!jogador->colisao.baixo && !Colisao_LimiteDeTela(jogador)
			&& movimento_permitido)
		{
			if (jogador->cooldown == 10)
			{
				Efeito_Sonoro(FX_PASSO_1);
				jogador->cooldown = 1;
			}
			jogador->cooldown++;
			jogador->posicao.y += jogador->velocidade.y;
		}

	}

	// Esquerda
	else if (jogador->movimento.esquerda)
	{
		// Animacao
		jogador->frame.y = 576 + atirando;

		if (jogador->frame.x < 512 - atirando*3/4)
			jogador->frame.x += 64;
		else
			jogador->frame.x = 0;

		// Salva movimento de animacao
		jogador->animacao = ESQUERDA;

		// Movimento
		if (!jogador->colisao.esquerda && !Colisao_LimiteDeTela(jogador)
			&& movimento_permitido)
		{
			if (jogador->cooldown == 10)
			{
				Efeito_Sonoro(FX_PASSO_1);
				jogador->cooldown = 1;
			}
			jogador->cooldown++;
			jogador->posicao.x -= jogador->velocidade.x;
		}
	}

	// Direita
	else if (jogador->movimento.direita)
	{
		// Animacao
		jogador->frame.y = 704 + atirando;

		if (jogador->frame.x < 512 - atirando*3/4)
			jogador->frame.x += 64;
		else
			jogador->frame.x = 0;

		// Salva movimento de animacao
		jogador->animacao = DIREITA;

		// Movimento
		if (!jogador->colisao.direita && !Colisao_LimiteDeTela(jogador)
			&& movimento_permitido)
		{
			if (jogador->cooldown == 10)
			{
				Efeito_Sonoro(FX_PASSO_1);
				jogador->cooldown = 1;
			}
			jogador->cooldown++;
			jogador->posicao.x += jogador->velocidade.x;
		}
	}

	else if(jogador->movimento.ataque)
	{	
		if (jogador->frame.y < 768)
			jogador->frame.y += atirando;

		if (jogador->frame.x < 512 - atirando*3/4)
			jogador->frame.x += 64;

		else 
			jogador->frame.x = 0;
	}
}

// COMANDO DE ATAQUE DE UM UNICO JOGADOR
void Ataque_dos_Jogadores(SDL_Renderer* renderer, Jogadores* jogadores, Projeteis* projeteis)
{
	int i;

	for (i = 0; i != jogadores->quantidade; i++) // LOOP PARA OS JOGADORES
	{
		Carrega_Teclas_de_Acao(&jogadores->jogador[i].inf); // CARREGA TECLAS DE ACAO
		if (jogadores->jogador[i].inf.movimento.ataque) // VERIFICA SE TEM ATAQUE
		{

			switch (jogadores->jogador[i].classe) // VERIFICA A CLASSE DO PERSONAGEM
			{
				case MAGO:
					switch (jogadores->jogador[i].tipo_de_ataque) // VERIFICA O TIPO DE ATAQUE SELECIONADO
					{
						case 1: // FIREBALL	
							if(jogadores->jogador[i].inf.movimento.ataque && jogadores->jogador[i].status.MP > 20)
							{	
								Inicializa_Fireball(renderer,
													projeteis,
													&jogadores->jogador[i].inf);
								jogadores->jogador[i].status.atk_cooldown = 0;
								jogadores->jogador[i].status.MP-=20;
							}			
							break;

						case 2:
							break;
					}
					break;

				case ARQUEIRO:
					switch (jogadores->jogador[i].tipo_de_ataque)
					{
						case 1: // FLECHA
							break;

						case 2:
							break;
					}
					break;
			}
		}
	}
}

// MOVIMENTACAO GERAL DOS JOGADORES
void Movimentacao_dos_Jogadores(Jogadores* jogadores, Inimigos* inimigos)
{
	//Teste_de_Colisao(inimigos, jogadores);

	int i, j;

	int movimento_permitido;

	for (i = 0; i != jogadores->quantidade; i++)
	{
		if (inimigos->quantidade > 0)
		{
			for (j = 0; j != inimigos->quantidade; j++)
			{
				if (Colisao_Perimetro2(&jogadores->jogador[i].inf, &inimigos->inimigo[j].inf))
				{
						movimento_permitido = FALSO;
						break;
				}
			}
		}
		if (jogadores->quantidade == 2)
		{
			if (i == 0)
			{
				if ((Colisao_Perimetro2(&jogadores->jogador[0].inf, &jogadores->jogador[1].inf)))
					movimento_permitido = FALSO;
			}
			else if (i == 1)
			{
				if (Colisao_Perimetro2(&jogadores->jogador[1].inf, &jogadores->jogador[0].inf))
					movimento_permitido = FALSO;
			}	
		}
		Carrega_Teclas_de_Acao(&jogadores->jogador[i].inf);
		Jogador_Movimentar(&jogadores->jogador[i].inf, movimento_permitido);
	}
}

// ********************************************************************************************

//
// FUNCOES DE MOVIMENTACAO E ATAQUE DOS INIMIGOS
//

// Funcao para executar movimentacao do inimigo
void Inimigo_Movimentar(Objeto* inimigo, int movimento_permitido)
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
		if (movimento_permitido
			&& !Colisao_LimiteDeTela2(inimigo))
		{
			if (inimigo->cooldown == 10)
			{
				Efeito_Sonoro(FX_PASSO_1);
				inimigo->cooldown = 1;
			}
			inimigo->cooldown++;
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
		if (movimento_permitido
			&& !Colisao_LimiteDeTela2(inimigo))
		{
			if (inimigo->cooldown == 10)
			{
				Efeito_Sonoro(FX_PASSO_1);
				inimigo->cooldown = 1;
			}
			inimigo->cooldown++;
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
		if (movimento_permitido
			&& !Colisao_LimiteDeTela2(inimigo))
		{
			if (inimigo->cooldown == 10)
			{
				Efeito_Sonoro(FX_PASSO_1);
				inimigo->cooldown = 1;
			}
			inimigo->cooldown++;
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
		if (movimento_permitido
			&& !Colisao_LimiteDeTela2(inimigo))
		{
			if (inimigo->cooldown == 10)
			{
				Efeito_Sonoro(FX_PASSO_1);
				inimigo->cooldown = 1;
			}
			inimigo->cooldown++;
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
			&& !Colisao_LimiteDeTela2(inimigo))
		{
			if (inimigo->cooldown == 10)
			{
				Efeito_Sonoro(FX_PASSO_1);
				inimigo->cooldown = 1;
			}
			inimigo->cooldown++;
			inimigo->posicao.y -= inimigo->velocidade.y;
		}
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
		if (movimento_permitido
			&& !Colisao_LimiteDeTela2(inimigo))
		{
			if (inimigo->cooldown == 10)
			{
				Efeito_Sonoro(FX_PASSO_1);
				inimigo->cooldown = 1;
			}
			inimigo->cooldown++;
			inimigo->posicao.y += inimigo->velocidade.y;
		}

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
		if (movimento_permitido
			&& !Colisao_LimiteDeTela2(inimigo))
		{
			if (inimigo->cooldown == 10)
			{
				Efeito_Sonoro(FX_PASSO_1);
				inimigo->cooldown = 1;
			}
			inimigo->cooldown++;
			inimigo->posicao.x -= inimigo->velocidade.x;
		}

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
		if (movimento_permitido
			&& !Colisao_LimiteDeTela2(inimigo))
			inimigo->posicao.x += inimigo->velocidade.x;
	}
}

// Movimentando vetor de inimigos
void Movimentacao_dos_Inimigos(Inimigos* inimigos, Jogadores* jogadores)
{
	int movimento_permitido[inimigos->quantidade];

	int i, j;
	if (inimigos->quantidade > 0)
	{
		//printf("%d\n", movimento_permitido[inimigos->quantidade]);

		for (i = 0; i < inimigos->quantidade; i++)
		{
			if (Colisao_Perimetro2(&inimigos->inimigo[i].inf, &jogadores->jogador[0].inf));
				{
					movimento_permitido[i] = FALSO;
					//printf("1st\n");
					//printf("movimento = %d", movimento_permitido[1]);
					
				}

				if (jogadores->quantidade == 2)
				{
					if (Colisao_Perimetro2(&inimigos->inimigo[i].inf, &jogadores->jogador[1].inf));
					{
						movimento_permitido[i] = FALSO;
						//printf("2nd\n");
						//printf("movimento = %d", movimento_permitido[1]);
					}
				}

			for (j = 0; j != inimigos->quantidade; j++)
			{
				if (i != j)
				{
					if (Colisao_Perimetro2(&inimigos->inimigo[i].inf, &inimigos->inimigo[j].inf))
					{
						movimento_permitido[i] = FALSO;
						//printf("3rd\n");
						break;
					}
					else
						//printf("4th\n");
						movimento_permitido[i] = VERDADEIRO;
						//printf("movimento = %d", movimento_permitido[1]);
				}
			}

			if (inimigos->quantidade == 1)
			{
				movimento_permitido[0] = VERDADEIRO;
			}
			//printf("movimento = %d", movimento_permitido[1]);
			IA_de_Movimentacao(&inimigos->inimigo[i].inf,
								&inimigos->inimigo[i].status,
									jogadores,
										movimento_permitido[i]);
		}
	}
}

// ********************************************************************************************

//
// DISTANCIA
//

Vetor_Distancia_Quadrante Distancia_Quadrante(Objeto* objeto1, Objeto* objeto2)
{
	Vetor_Distancia_Quadrante vetor_distancia_quadrante;

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
		if (circulo1.centro.y < circulo2.centro.y)
			quadrante = CIMA;
		else
			quadrante = BAIXO;
	}
	// Eixo Y
	else if (circulo1.centro.y == circulo2.centro.y)
		{
			distancia = abs(circulo1.centro.x - circulo2.centro.x);
			if (circulo1.centro.x < circulo2.centro.x)
			quadrante = CIMA;
		else
			quadrante = BAIXO;
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

	vetor_distancia_quadrante.distancia = distancia;
	vetor_distancia_quadrante.quadrante = quadrante;

	return vetor_distancia_quadrante;
}

// ********************************************************************************************

// FIM
