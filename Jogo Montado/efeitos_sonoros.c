// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

/*
	EFEITOS SONOROS

	Jogo de desenvolvido para projeto de computacao 1
*/ 

#include "main.h"
#include "efeitos_sonoros.h"

// Pre carregamento
Mix_Chunk* carrega_efeito_sonoro(int efeito);

// Roda efeitos sonoros
void efeito_sonoro(int efeito)
{
	// Carrega e recebe o efeito sonoro da funcao de carregamento
	Mix_Chunk* som = NULL;
	som = carrega_efeito_sonoro(efeito);

	// Toca o efeito sonoro
	Mix_PlayChannel (-1, som, 0);
}

// Carrega efeitos sonoros na memoria
Mix_Chunk* carrega_efeito_sonoro(int efeito)
{
	// Variavel para conter o efeito sonoro
	Mix_Chunk* som = NULL;

	// Selecao de efeitos
	switch (efeito)
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