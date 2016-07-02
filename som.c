// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

/*
	EFEITOS SONOROS

	Jogo de desenvolvido para projeto de computacao 1
*/ 

#include "som.h"

//
// PRE CARREGAMENTO DAS FUNCOES
//

void Efeito_Sonoro(int nome_do_efeito);
Mix_Chunk* Carrega_Efeito_Sonoro(int nome_do_efeito);
void Toca_Musica(int nome_da_musica);
Mix_Music* Carrega_Musica(int nome_da_musica);

// ****************************************************************

//
// EFEITOS SONOROS
//

// Roda efeitos sonoros
void Efeito_Sonoro(int nome_do_efeito)
{
	// Carrega e recebe o efeito sonoro da funcao de carregamento
	Mix_Chunk* som = NULL;
	som = Carrega_Efeito_Sonoro(nome_do_efeito);

	// Toca o efeito sonoro
	Mix_PlayChannel (-1, som, 0);
}

// Carrega efeitos sonoros na memoria
Mix_Chunk* Carrega_Efeito_Sonoro(int nome_do_efeito)
{
	// Variavel para conter o efeito sonoro
	Mix_Chunk* som = NULL;

	// Selecao de efeitos
	switch (nome_do_efeito)
	{
		case CLICK:
			som = Mix_LoadWAV("sons/efeitos/click.wav");
			break;

		case SELECT:
			som = Mix_LoadWAV("sons/efeitos/select.wav");
			break;

		case VOLTAR:
			som = Mix_LoadWAV("sons/efeitos/voltar.wav");
			break;
	}

	// Retorna o efeito para ser tocado
	return som;
}

// ****************************************************************

//
// MUSICAS
//

void Toca_Musica(int nome_da_musica)
{
	// Carrega e recebe a musica da funcao de carregamento
	Mix_Music* musica = NULL;
	musica = Carrega_Musica(nome_da_musica);

	// Toca a musica
	Mix_PlayMusic (musica, -1);
}

Mix_Music* Carrega_Musica(int nome_da_musica)
{
	// Variavel para conter a musica
	Mix_Music* musica = NULL;

	// Selecao de efeitos
	switch (nome_da_musica)
	{
		case MUSICA_INICIAL:
			musica = Mix_LoadMUS("sons/musicas/menu.mp3");
			break;

		case MUSICA_DE_SELECAO:
			musica = Mix_LoadMUS("sons/musicas/selecao.mp3");
			break;

		case MUSICA_DE_FUNDO_DO_JOGO:
			musica = Mix_LoadMUS("sons/musicas/jogo.mid");
			break;
	}

	// Retorna musica para ser tocada
	return musica;
}

// *****************************************************************

// FIM