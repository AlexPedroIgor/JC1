// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

/*
	EFEITOS SONOROS

	Jogo de desenvolvido para projeto de computacao 1
*/

#include "som.h"

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
		case FX_CLICK:
			som = Mix_LoadWAV("sons/efeitos/menu/click.wav");
			break;

		case FX_SELECT:
			som = Mix_LoadWAV("sons/efeitos/menu/select.wav");
			break;

		case FX_VOLTAR:
			som = Mix_LoadWAV("sons/efeitos/menu/voltar.wav");
			break;

		case FX_CURA:
			som = Mix_LoadWAV("sons/efeitos/magia/cura.wav");
			break;

		case FX_TAPA:
			som = Mix_LoadWAV("sons/efeitos/dano/tapa.wav");
			break;

		case FX_SOCO:
			som = Mix_LoadWAV("sons/efeitos/dano/soco.wav");
			break;

		case FX_HULK_ESMAGA:
			som = Mix_LoadWAV("sons/efeitos/dano/hulk_esmaga.wav");
			break;

		case FX_FIREBALL:
			som = Mix_LoadWAV("sons/efeitos/dano/fireball.ogg");
			break;

		case FX_ESQUELETO:
			som = Mix_LoadWAV("sons/efeitos/inimigo/esqueleto.wav");
			break;

		case FX_ORC:
			som = Mix_LoadWAV("sons/efeitos/inimigo/orc.wav");
			break;

		case FX_PASSO_1:
			som = Mix_LoadWAV("sons/efeitos/passo/passo-1.wav");
			break;
	}

	// Retorna o efeito para ser tocado
	return som;
}

// VOLUME
void Efeito_Sonoro_Volume(int volume)
{
    /*
        VOLUME MIN:     0
        VOLUME MAX:     128
    */
    Mix_Volume(0,volume);
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

		case MUSICA_BOSS:
			musica = Mix_LoadMUS("sons/musicas/boss.mp3");
			break;

		case MUSICA_FIELD_1:
			musica = Mix_LoadMUS("sons/musicas/field01.mp3");
			break;

		case MUSICA_FEILD_2:
			musica = Mix_LoadMUS("sons/musicas/field03.mp3");
			break;
	}

	// Retorna musica para ser tocada
	return musica;
}

// VOLUME
void Musica_Volume(int volume)
{
    /*
        VOLUME MIN:     0
        VOLUME MAX:     128
    */
    Mix_VolumeMusic(volume);
}

// *****************************************************************

// FIM
