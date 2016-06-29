// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

/*
	CONFIGURACOES

	Jogo de desenvolvido para projeto de computacao 1
*/

#include "main.h"
#include "config.h"

// Pre carregamento das funcoes
Jogador Carrega_Jogador(int numero);
void Carrega_Teclas_de_Acao(Jogador* jogador);


// Carrega parametros iniciais do jogador
Jogador Carrega_Jogador(int numero)
{
	// Estrutura com informacoes do jogador
	Jogador jogador;

	// Numero do jogador
	jogador.numero = numero;

	// Velocidade de movimento do jogador
	jogador.velocidade.x = VEL;
	jogador.velocidade.y = VEL;

	// Dimensoes da imagem do sprite do jogador
	jogador.fullH = SPRITE_FULL_H;
	jogador.fullW = SPRITE_FULL_W;

	// Rect do frame do sprite do jogador
	jogador.frame.x = 0;
	jogador.frame.y = 512;
	jogador.frame.w = SPRITE_FRAME_W;
	jogador.frame.h = SPRITE_FRAME_H;

	// Rect para posisao do jogador em tela
	jogador.posicao.w = SPRITE_FRAME_W;
	jogador.posicao.h = SPRITE_FRAME_H;

	// Variavel para conter imagem do jogador
	jogador.sprite = NULL;

	return jogador;
}

// Carrega teclas de acao do jogador
void Carrega_Teclas_de_Acao(Jogador* jogador)
{
	// Pega estado atual das teclas pressionadas
	const Uint8 *keystates = SDL_GetKeyboardState(NULL);

	// Atribui uma tecla para cada jogador
	switch (jogador->numero)
	{
		case 1: // Jogador 1
			jogador->movimento.cima = keystates[SDL_SCANCODE_UP];
			jogador->movimento.baixo = keystates[SDL_SCANCODE_DOWN];
			jogador->movimento.esquerda = keystates[SDL_SCANCODE_LEFT];
			jogador->movimento.direita = keystates[SDL_SCANCODE_RIGHT];
			jogador->movimento.ataque = keystates[SDL_SCANCODE_RETURN];
			break;

		case 2: // Jogador 2
			jogador->movimento.cima = keystates[SDL_SCANCODE_W];
			jogador->movimento.baixo = keystates[SDL_SCANCODE_S];
			jogador->movimento.esquerda = keystates[SDL_SCANCODE_A];
			jogador->movimento.direita = keystates[SDL_SCANCODE_D];
			jogador->movimento.ataque = keystates[SDL_SCANCODE_BACKSPACE];
			break;
	}
}

// Carrega fases do jogo
Fase Inicializa_Fases(SDL_Renderer* renderer)
{
	// Inicializa variavel
	Fase fase;

	// Variaveis dos portais
	int i;
	for (i = 0; i != 4; i++)
	{
		// Define portal tipo 1 para todos os lados
		fase.mapa[i].portal.cima.tipo = 1;
		fase.mapa[i].portal.baixo.tipo = 1;
		fase.mapa[i].portal.esquerda.tipo = 1;
		fase.mapa[i].portal.direita.tipo = 1;

		//
		// Posicao nos frames
		//

		// Cima
		fase.mapa[i].portal.cima.frame.x = 0;
		fase.mapa[i].portal.cima.frame.y = 0;
		fase.mapa[i].portal.cima.frame.w = 0;
		fase.mapa[i].portal.cima.frame.h = 0;

		// Baixo
		fase.mapa[i].portal.baixo.frame.x = 0;
		fase.mapa[i].portal.baixo.frame.y = 0;
		fase.mapa[i].portal.baixo.frame.w = 0;
		fase.mapa[i].portal.baixo.frame.h = 0;

		// Esquerda
		fase.mapa[i].portal.esquerda.frame.x = 0;
		fase.mapa[i].portal.esquerda.frame.y = 0;
		fase.mapa[i].portal.esquerda.frame.w = 0;
		fase.mapa[i].portal.esquerda.frame.h = 0;

		// Direita
		fase.mapa[i].portal.direita.frame.x = 0;
		fase.mapa[i].portal.direita.frame.y = 0;
		fase.mapa[i].portal.direita.frame.w = 0;
		fase.mapa[i].portal.direita.frame.h = 0;

		//
		// Posicao na tela
		//

		// Cima
		fase.mapa[i].portal.cima.posicao.x = 0;
		fase.mapa[i].portal.cima.posicao.y = 0;
		fase.mapa[i].portal.cima.posicao.w = 0;
		fase.mapa[i].portal.cima.posicao.h = 0;

		// Baixo
		fase.mapa[i].portal.baixo.posicao.x = 0;
		fase.mapa[i].portal.baixo.posicao.y = 0;
		fase.mapa[i].portal.baixo.posicao.w = 0;
		fase.mapa[i].portal.baixo.posicao.h = 0;

		// Esquerda
		fase.mapa[i].portal.esquerda.posicao.x = 0;
		fase.mapa[i].portal.esquerda.posicao.y = 0;
		fase.mapa[i].portal.esquerda.posicao.w = 0;
		fase.mapa[i].portal.esquerda.posicao.h = 0;

		// Direita
		fase.mapa[i].portal.direita.posicao.x = 0;
		fase.mapa[i].portal.direita.posicao.y = 0;
		fase.mapa[i].portal.direita.posicao.w = 0;
		fase.mapa[i].portal.direita.posicao.h = 0;
	}

	return fase;
}