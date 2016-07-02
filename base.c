// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

/*
	FUNCOES E VARIAVEIS BASICAS DO JOGO

	Jogo de desenvolvido para projeto de computacao 1
*/

#include "base.h"

//
// PRE CARREGAMENTO DAS FUCOES
//

Jogadores* Inicializa_Jogadores();
Inimigos* Inicializa_Inimigos();
Projeteis* Inicializa_Projeteis();
Boss* Inicializa_Boss();
Fase* Inicializa_Fases();
void Finaliza_Jogadores(Jogadores* jogadores);
void Finaliza_Inimigos(Inimigos* inimigos);
void Finaliza_Projeteis(Projeteis* projeteis);
void Finaliza_Boss(Boss* boss);
void Finaliza_Fases(Fase* fase);
void Carrega_Fase_Memoria(SDL_Renderer* renderer, Fase* fase);
void Fase_Troca_Portal(SDL_Renderer* renderer, Fase* fase, int portal, int tipo);
void Renderiza_Plano_de_Fundo(SDL_Renderer* renderer, Fase* fase);

// ***************************************************************************

//
// CARREGAMENTO DE OBJETOS
//

Jogadores* Inicializa_Jogadores()
{
	Jogadores* jogadores;

	jogadores = (Jogadores*) malloc(sizeof(Jogadores));

	int i;

	for (i = 0; i != 2; i++) // Loop para jogadores
	{
		// Armazena o numero do jogador
		jogadores->jogador[i].inf.numero = i + 1;

		jogadores->jogador[i].inf.animacao = NULL;

		jogadores->jogador[i].tipo_de_ataque = 1;

		// Marca estado de colisao inicial como sem colisao
		jogadores->jogador[i].inf.colisao.cima = FALSO;
		jogadores->jogador[i].inf.colisao.baixo = FALSO;
		jogadores->jogador[i].inf.colisao.esquerda = FALSO;
		jogadores->jogador[i].inf.colisao.direita = FALSO;

		// Tipo de objeto
		jogadores->jogador[i].inf.tipo = JOGADOR;

		// Dimensoes da imagem do sprite do jogador
		jogadores->jogador[i].inf.fullH = SPRITE_FULL_H;
		jogadores->jogador[i].inf.fullW = SPRITE_FULL_W;

		// Rect do frame do sprite do jogador
		jogadores->jogador[i].inf.frame.x = 0;
		jogadores->jogador[i].inf.frame.y = 512;
		jogadores->jogador[i].inf.frame.w = SPRITE_FRAME_W;
		jogadores->jogador[i].inf.frame.h = SPRITE_FRAME_H;

		// Rect para posisao do jogador em tela
		jogadores->jogador[i].inf.posicao.w = SPRITE_FRAME_W;
		jogadores->jogador[i].inf.posicao.h = SPRITE_FRAME_H;

		// Dimensoes reais para colisao
		jogadores->jogador[i].tamanho_real.centro.x = 32;
		jogadores->jogador[i].tamanho_real.centro.y = 38;
		jogadores->jogador[i].tamanho_real.v = 24;
		jogadores->jogador[i].tamanho_real.h = 12;

		// Variavel para conter imagem do jogador
		jogadores->jogador[i].inf.sprite = NULL;
	}
	return jogadores;
}

Inimigos* Inicializa_Inimigos()
{
	Inimigos* inimigos;

	inimigos = (Inimigos*) malloc(sizeof(Inimigos));

	inimigos->quantidade = 0;
	inimigos->mortos = 0;
	inimigos->rodada = 0;

	int i;

	for (i = 0; i != 64; i++) // Loop para jogadores
	{
		inimigos->inimigo[i].vivo = NULL;

		inimigos->inimigo[i].inf.animacao = NULL;

		// Marca estado de colisao inicial como sem colisao
		inimigos->inimigo[i].inf.colisao.cima = FALSO;
		inimigos->inimigo[i].inf.colisao.baixo = FALSO;
		inimigos->inimigo[i].inf.colisao.esquerda = FALSO;
		inimigos->inimigo[i].inf.colisao.direita = FALSO;

		// Dimensoes da imagem do sprite do inimigo
		inimigos->inimigo[i].inf.fullH = SPRITE_FULL_H;
		inimigos->inimigo[i].inf.fullW = SPRITE_FULL_W;

		// Rect do frame do sprite do inimigo
		inimigos->inimigo[i].inf.frame.x = 0;
		inimigos->inimigo[i].inf.frame.y = 512;
		inimigos->inimigo[i].inf.frame.w = SPRITE_FRAME_W;
		inimigos->inimigo[i].inf.frame.h = SPRITE_FRAME_H;

		// Rect para posisao do inimigo em tela
		inimigos->inimigo[i].inf.posicao.w = SPRITE_FRAME_W;
		inimigos->inimigo[i].inf.posicao.h = SPRITE_FRAME_H;

		// Variavel para conter imagem do inimigo
		inimigos->inimigo[i].inf.sprite = NULL;
	}
	return inimigos;
}

Projeteis* Inicializa_Projeteis()
{
	Projeteis* inimigos;

	projeteis = (Projeteis*) malloc(sizeof(Projeteis));

	projeteis->quantidade = 0;
	projeteis->remover = 0;

	int i;

	for (i = 0; i != 64; i++) // Loop para jogadores
	{
		projeteis->tiro[i].em_tela = NULL;

		projeteis->tiro[i].inf.animacao = 1;

		// Marca estado de colisao inicial como sem colisao
		projeteis->tiro[i].inf.colisao.cima = FALSO;
		projeteis->tiro[i].inf.colisao.baixo = FALSO;
		projeteis->tiro[i].inf.colisao.esquerda = FALSO;
		projeteis->tiro[i].inf.colisao.direita = FALSO;

		// Dimensoes da imagem do sprite do projetil
		projeteis->tiro[i].inf.fullH = SPRITE_FULL_H;
		projeteis->tiro[i].inf.fullW = SPRITE_FULL_W;

		// Rect do frame do sprite do projetil
		projeteis->tiro[i].inf.frame.x = 0;
		projeteis->tiro[i].inf.frame.y = 512;
		projeteis->tiro[i].inf.frame.w = SPRITE_FRAME_W;
		projeteis->tiro[i].inf.frame.h = SPRITE_FRAME_H;

		// Rect para posisao do projetil em tela
		projeteis->tiro[i].inf.posicao.w = SPRITE_FRAME_W;
		projeteis->tiro[i].inf.posicao.h = SPRITE_FRAME_H;

		// Variavel para conter imagem do projetil
		projeteis->tiro[i].inf.sprite = NULL;
	}
	return projeteis;
}

Boss* Inicializa_Boss()
{
	Boss* boss;

	boss = (Boss*) malloc(sizeof(Boss));

	boss->quantidade = 0;
	boss->mortos = 0;
	boss->rodada = 0;

	int i;

	for (i = 0; i != 1; i++) // Loop para jogadores
	{
		boss->chefe[i].vivo = NULL;

		boss->chefe[i].inf.animacao = NULL;

		// Tipo de objeto
		boss->chefe[i].inf.tipo = BOSS;

		// Marca estado de colisao inicial como sem colisao
		boss->chefe[i].inf.colisao.cima = FALSO;
		boss->chefe[i].inf.colisao.baixo = FALSO;
		boss->chefe[i].inf.colisao.esquerda = FALSO;
		boss->chefe[i].inf.colisao.direita = FALSO;

		// Dimensoes da imagem do sprite do inimigo
		boss->chefe[i].inf.fullH = 288;
		boss->chefe[i].inf.fullW = 192;

		// Rect do frame do sprite do inimigo
		boss->chefe[i].inf.frame.x = 0;
		boss->chefe[i].inf.frame.y = 0;
		boss->chefe[i].inf.frame.w = 96;
		boss->chefe[i].inf.frame.h = 48;

		// Rect para posisao do inimigo em tela
		boss->chefe[i].inf.posicao.w = 96;
		boss->chefe[i].inf.posicao.h = 48;

		// Dimensoes reais para colisao
		boss->chefe[i].tamanho_real.centro.x = 48;
		boss->chefe[i].tamanho_real.centro.y = 20;
		boss->chefe[i].tamanho_real.v = 45;
		boss->chefe[i].tamanho_real.h = 18;

		// Variavel para conter imagem do inimigo
		boss->chefe[i].inf.sprite = NULL;
	}
	return boss;
}

Fase* Inicializa_Fases()
{
	Fase* fase;

	fase = (Fase*) malloc(sizeof(Fase));

	// Inicia na fase 1
	fase->numero = 0;

	// Seta 16 inimigos para cada portal
	fase->portal.cima.inimigos = 16;
	fase->portal.baixo.inimigos = 16;
	fase->portal.esquerda.inimigos = 16;
	fase->portal.direita.inimigos = 16;

	// Define portal tipo 1 para todos os lados
	fase->portal.cima.tipo = 1;
	fase->portal.baixo.tipo = 1;
	fase->portal.esquerda.tipo = 1;
	fase->portal.direita.tipo = 1;

	//
	// Posicao nos frames
	//

	// Cima
	fase->portal.cima.frame.x = 0;
	fase->portal.cima.frame.y = 0;
	fase->portal.cima.frame.w = 59;
	fase->portal.cima.frame.h = 30;

	// Baixo
	fase->portal.baixo.frame.x = 0;
	fase->portal.baixo.frame.y = 0;
	fase->portal.baixo.frame.w = 59;
	fase->portal.baixo.frame.h = 30;

	// Esquerda
	fase->portal.esquerda.frame.x = 0;
	fase->portal.esquerda.frame.y = 0;
	fase->portal.esquerda.frame.w = 30;
	fase->portal.esquerda.frame.h = 59;

	// Direita
	fase->portal.direita.frame.x = 0;
	fase->portal.direita.frame.y = 0;
	fase->portal.direita.frame.w = 30;
	fase->portal.direita.frame.h = 59;

	//
	// Posicao na tela
	//

	// Cima
	fase->portal.cima.posicao.x = 362;
	fase->portal.cima.posicao.y = 0;
	fase->portal.cima.posicao.w = 80;
	fase->portal.cima.posicao.h = 50;

	// Baixo
	fase->portal.baixo.posicao.x = 362;
	fase->portal.baixo.posicao.y = 550;
	fase->portal.baixo.posicao.w = 80;
	fase->portal.baixo.posicao.h = 50;

	// Esquerda
	fase->portal.esquerda.posicao.x = 0;
	fase->portal.esquerda.posicao.y = 280;
	fase->portal.esquerda.posicao.w = 50;
	fase->portal.esquerda.posicao.h = 55;

	// Direita
	fase->portal.direita.posicao.x = 748;
	fase->portal.direita.posicao.y = 265;
	fase->portal.direita.posicao.w = 50;
	fase->portal.direita.posicao.h = 55;

	return fase;
}

// *****************************************************************************

//
// FINALIZACAO DE OBJETOS
//

void Finaliza_Jogadores(Jogadores* jogadores)
{
	free(jogadores);
}

void Finaliza_Inimigos(Inimigos* inimigos)
{
	free(inimigos);
}

void Finaliza_Projeteis(Projeteis* projeteis)
{
	free(projeteis);
}

void Finaliza_Boss(Boss* boss)
{
	free(boss);
}

void Finaliza_Fases(Fase* fase)
{
	free(fase);
}

// *****************************************************************************

//
// CARREGAMENTO DAS FASES
//

// CARREGA SPRITES DA FASE
void Carrega_Fase_Memoria(SDL_Renderer* renderer, Fase* fase)
{
	// Variavel para carregar imagens
	SDL_Surface* Loading_Surf = NULL;

	switch (fase->numero)
	{
		case 0:
			Loading_Surf = IMG_Load(MAPA_1);
			break;

		case 1:
			Loading_Surf = IMG_Load(MAPA_2);
			break;

		case 2:
			Loading_Surf = IMG_Load(MAPA_3);
			break;

		case 3:
			Loading_Surf = IMG_Load(MAPA_4);
			break;
	}

	// Carrega sprite na textura
	fase->sprite = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf);

	// Limpa memoria
	SDL_FreeSurface (Loading_Surf);

	// *****************************************************************************

	//
	// Carrega portais tipo 1
	//

	fase->portal.animacao = 1;

	// Cima
	Loading_Surf = IMG_Load("arte/portal/vermelho_cima.png");

	// Carregando na textura
	fase->portal.cima.sprite = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf);

	// Limpando memoria
	SDL_FreeSurface(Loading_Surf);

	// ******************************************************************

	// Baixo
	Loading_Surf = IMG_Load("arte/portal/vermelho_baixo.png");

	// Carrega na textura
	fase->portal.baixo.sprite = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf);

	// Limpando memoria
	SDL_FreeSurface(Loading_Surf);

	// **************************************************************************

	// Esquerda
	Loading_Surf = IMG_Load("arte/portal/vermelho_esquerda.png");

	// Carregando na textura
	fase->portal.esquerda.sprite = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf);

	// Limpando memoria
	SDL_FreeSurface(Loading_Surf);

	// ********************************************************************

	// Direita
	Loading_Surf = IMG_Load("arte/portal/vermelho_direita.png");

	// Carrega na textura
	fase->portal.direita.sprite = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf);

	// Limpando memoria
	SDL_FreeSurface(Loading_Surf);

	//*********************************************************************
}

// ALTERNA O TIPO DE PORTAL
void Fase_Troca_Portal(SDL_Renderer* renderer, Fase* fase, int portal, int tipo)
{
	// Variavel para carregar imagens
	SDL_Surface* Loading_Surf = NULL;

	switch (portal)
	{
		case CIMA:
			// Seleciona o tipo de portal
			switch (tipo)
			{
				case 1:
					Loading_Surf = IMG_Load("arte/portal/vermelho_cima.png");
					break;

				case 2:
					Loading_Surf = IMG_Load("arte/portal/azul_cima.png");
					break;

				case 3:
					Loading_Surf = IMG_Load("arte/portal/cinza_cima.png");
					break;
			}

			fase->portal.cima.sprite = SDL_CreateTextureFromSurface(renderer,
				Loading_Surf);
			break;

			// ***********************************************************************


		case BAIXO:
			// Seleciona o tipo de portal
			switch (tipo)
			{
				case 1:
					Loading_Surf = IMG_Load("arte/portal/vermelho_baixo.png");
					break;

				case 2:
					Loading_Surf = IMG_Load("arte/portal/azul_baixo.png");
					break;

				case 3:
					Loading_Surf = IMG_Load("arte/portal/cinza_baixo.png");
					break;
			}

			fase->portal.baixo.sprite = SDL_CreateTextureFromSurface(renderer,
				Loading_Surf);
			break;

			// *****************************************************************

		case ESQUERDA:
			// Seleciona o tipo de portal
			switch (tipo)
			{
				case 1:
					Loading_Surf = IMG_Load("arte/portal/vermelho_esquerda.png");
					break;

				case 2:
					Loading_Surf = IMG_Load("arte/portal/azul_esquerda.png");
					break;

				case 3:
					Loading_Surf = IMG_Load("arte/portal/cinza_esquerda.png");
					break;
			}

			fase->portal.esquerda.sprite = SDL_CreateTextureFromSurface(renderer,
				Loading_Surf);
			break;

			// ***********************************************************************

		case DIREITA:
			// Seleciona o tipo de portal
			switch (tipo)
			{
				case 1:
					Loading_Surf = IMG_Load("arte/portal/vermelho_direita.png");
					break;

				case 2:
					Loading_Surf = IMG_Load("arte/portal/azul_direita.png");
					break;

				case 3:
					Loading_Surf = IMG_Load("arte/portal/cinza_direita.png");
					break;
			}

			fase->portal.direita.sprite = SDL_CreateTextureFromSurface(renderer,
				Loading_Surf);
			break;

			// ***********************************************************************
	}

	// Limpa memoria
	SDL_FreeSurface(Loading_Surf);
}

// CARREGA IMAGEM EM TELA
void Renderiza_Plano_de_Fundo(SDL_Renderer* renderer, Fase* fase)
{
	// Carrega fundo da fase
	SDL_RenderCopy(renderer, fase->sprite, NULL, NULL);

	//
	// Carrega portais
	//

	Fase_Animacao_Portal(fase);

	// Troca portais
	if (fase->portal.cima.inimigos == 0)
		Fase_Troca_Portal(renderer, fase, CIMA, 3);
	if (fase->portal.baixo.inimigos == 0)
		Fase_Troca_Portal(renderer, fase, BAIXO, 3);
	if (fase->portal.esquerda.inimigos == 0)
		Fase_Troca_Portal(renderer, fase, ESQUERDA, 3);
	if (fase->portal.direita.inimigos == 0)
		Fase_Troca_Portal(renderer, fase, DIREITA, 3);

	// Cima
	SDL_RenderCopy(renderer,
		fase->portal.cima.sprite,
		&fase->portal.cima.frame,
		&fase->portal.cima.posicao);

	// Baixo
	SDL_RenderCopy(renderer,
		fase->portal.baixo.sprite,
		&fase->portal.baixo.frame,
		&fase->portal.baixo.posicao);

	// Esquerda
	SDL_RenderCopy(renderer,
		fase->portal.esquerda.sprite,
		&fase->portal.esquerda.frame,
		&fase->portal.esquerda.posicao);

	// Direita
	SDL_RenderCopy(renderer,
		fase->portal.direita.sprite,
		&fase->portal.direita.frame,
		&fase->portal.direita.posicao);

	fase->portal.animacao++;

	if (fase->portal.animacao > 17)
		fase->portal.animacao = 1;
}

// *****************************************************************************

//
// RENDERIZACAO DOS OBJETOS
//

// JOGADORES


// INIMIGOS


// PROJETEIS
void Renderiza_Projeteis(SDL_Renderer* renderer, Projeteis* projeteis)
{
	int i;

	if (projeteis->quantidade > 0)
	{

		//Anima_Tiro(renderer, &projeteis->tiro[i].inf);

		for (i = 0; i != vetor_de_tiros->quantidade; i++)
		{
			SDL_RenderCopy(renderer,
				projeteis->tiro[i]inf.sprite,
				&projeteis->tiro[i]inf.frame,
				&projeteis->tiro[i]inf.posicao);

			if (i == 64)
				break;

			//vetor_de_tiros->tiro[i].animacao++;

			//printf("Animcacao: \n", vetor_de_tiros->tiro[i].animacao);

			//if (vetor_de_tiros->tiro[i].animacao > 8)
			//	vetor_de_tiros->tiro[i].animacao = 1;
		}

		
	}
}

// BOSS


// *****************************************************************************

// FIM