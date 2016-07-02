// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

/*
	CONFIGURACOES

	Jogo de desenvolvido para projeto de computacao 1
*/

#include "config.h"

//
// Pre carregamento das funcoes
//

void Carrega_Teclas_de_Acao(Jogador* jogador);
SDL_Texture* Cria_Texto(SDL_Renderer* renderer, char* texto, TTF_Font* fonte, SDL_Color cor_do_texto);

// *********************************************************************************

// Carrega teclas de acao do jogador
void Carrega_Teclas_de_Acao(Objeto* jogador)
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

// *********************************************************************************

// ******************************************************************************

//
// Funcoes de texto
//

SDL_Texture* Cria_Texto(SDL_Renderer* renderer, char* texto, TTF_Font* fonte, SDL_Color cor_do_texto)
{
	SDL_Surface* Loadind_Surf = NULL;

	Loadind_Surf = TTF_RenderText_Solid (fonte,
		texto,
		cor_do_texto);

	SDL_Texture* texto_em_tela = NULL;

	texto_em_tela = SDL_CreateTextureFromSurface (renderer,
		texto_em_tela);

	SDL_FreeSurface (Loadind_Surf);

	return texto_em_tela;
}

// ******************************************************************************