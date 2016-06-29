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