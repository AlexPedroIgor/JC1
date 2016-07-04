// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

/*
	CONFIGURACOES

	Jogo de desenvolvido para projeto de computacao 1
*/

#include "config.h"
#include "base.h"

//
// PRE CARREGAMENTO DAS FUNCOES
//

void Carrega_Teclas_de_Acao(Objeto* jogador);
SDL_Texture* Cria_Texto(SDL_Renderer* renderer, char* texto, TTF_Font* fonte, SDL_Color cor_do_texto);
void Texto_em_Tela_Nome_do_Personagem(SDL_Renderer* renderer, SDL_Event event);
FILE* DATA_Carrega_Save_Game();
void DATA_Salva_Informacoes_Basicas(FILE* save_game);
void DATA_Carrega_Informacoes(Status* mago, Status* arqueiro, Ranking* ranking);


// ***************************************************************************************************

//
// TECLAS DE MOVIMENTACAO
//

// TECLAS DE ACAO DE UM JOGADOR
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
			jogador->movimento.ataque = keystates[SDL_SCANCODE_Q];
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

// ***************************************************************************************************

//
// TEXTO
//

SDL_Texture* Cria_Texto(SDL_Renderer* renderer, char* texto, TTF_Font* fonte, SDL_Color cor_do_texto)
{
	SDL_Surface* Loadind_Surf = NULL;

	Loadind_Surf = TTF_RenderText_Solid (fonte,
		texto,
		cor_do_texto);

	SDL_Texture* texto_em_tela = NULL;

	texto_em_tela = SDL_CreateTextureFromSurface (renderer,
		Loadind_Surf);

	SDL_FreeSurface (Loadind_Surf);

	return texto_em_tela;
}

//ESCREVE NOME DO JOGADOR EM TELA NA SELECAO DE PERSONAGENS
void Texto_em_Tela_Nome_do_Personagem(SDL_Renderer* renderer, SDL_Event event)
{

}

// ***************************************************************************************************

//
// SAVE GAME
//

// CARREGA SAVE GAME
FILE* DATA_Carrega_Save_Game()
{
	FILE* save_game;
	char* nome_do_arquivo = "data/data.dat";

	if ((save_game = fopen(nome_do_arquivo, "r+b")) == NULL)
	{
		printf("Criando um novo arquivo\n");
		if ((save_game = fopen(nome_do_arquivo, "w+b")) == NULL)
			printf("Arquivo nao pode ser criado\n");
		else
		{
			printf("Arquivo criado com sucesso\n");
			DATA_Salva_Informacoes_Basicas(save_game);
		}
		
	}
	else
		printf("Arquivo carregado com sucesso\n");
	return save_game;
}

// SALVA INFORMACOES BASICAS DO SAVE GAME
void DATA_Salva_Informacoes_Basicas(FILE* save_game)
{
	Status mago, arqueiro;

	// STATUS BASICOS DO MAGO
	mago.forca = 5;
	mago.destreza = 0;
	mago.inteligencia = 15;
	mago.constituicao = 7;
	mago.lvl = 1;
	mago.dano = 0;
	mago.HP_Max = 500 + mago.constituicao*10 + mago.lvl*5;
	mago.HP = mago.HP_Max;
	mago.MP_Max = 100 + mago.inteligencia*5 + mago.lvl*2;
	mago.MP = mago.MP_Max;
	mago.ataque = 50 + mago.inteligencia*5;
	mago.defesa = mago.constituicao;
	mago.morte = 0;

	// STATUS BASICOS DO ARQUEIRO
	arqueiro.forca = 12;
	arqueiro.destreza = 15;
	arqueiro.inteligencia = 0;
	arqueiro.constituicao = 10;
	arqueiro.lvl = 1;
	arqueiro.exp = 0;
	arqueiro.next_lvl = 1000;
	arqueiro.dano = 0;
	arqueiro.HP_Max = 600 + arqueiro.constituicao*10 + arqueiro.lvl*5;
	arqueiro.HP = arqueiro.HP_Max;
	arqueiro.MP_Max = 5 + arqueiro.destreza/2;
	arqueiro.MP = arqueiro.MP_Max;
	arqueiro.ataque = 50 + arqueiro.destreza*3;
	arqueiro.defesa = arqueiro.constituicao;
	arqueiro.morte = 0;

	// ********************************************************************

	// RANKING

	Ranking ranking;

	ranking.rkn[0].nome = "Joaozinho\0";
	ranking.rkn[0].pontuacao = 100.000;
	ranking.rkn[1].nome = "Joaozinho\0";
	ranking.rkn[1].pontuacao = 90.000;
	ranking.rkn[2].nome = "Joaozinho\0";
	ranking.rkn[2].pontuacao = 80.000;
	ranking.rkn[3].nome = "Joaozinho\0";
	ranking.rkn[3].pontuacao = 70.000;
	ranking.rkn[4].nome = "Joaozinho\0";
	ranking.rkn[4].pontuacao = 60.000;
	ranking.rkn[5].nome = "Joaozinho\0";
	ranking.rkn[5].pontuacao = 50.000;
	ranking.rkn[6].nome = "Joaozinho\0";
	ranking.rkn[6].pontuacao = 40.000;
	ranking.rkn[7].nome = "Joaozinho\0";
	ranking.rkn[7].pontuacao = 30.000;
	ranking.rkn[8].nome = "Joaozinho\0";
	ranking.rkn[8].pontuacao = 20.000;
	ranking.rkn[9].nome = "Joaozinho\0";
	ranking.rkn[9].pontuacao = 10.000;

	// TECLAS DE MOVIMENTACAO DOS JOGADORES
	/*
		EM BREVE
	*/

	// GRAVANDO INFORMACOES NO ARQUIVO
	rewind(save_game);

	fwrite(&mago, sizeof(Status), 1, save_game);
	fwrite(&arqueiro, sizeof(Status), 1, save_game);
	fwrite(&ranking, sizeof(Ranking), 1, save_game);
	//fwrite(&teclas_jogador1, sizeof(Teclas_de_Acao), 1, save_game);
	//fwrite(&teclas_jogador2, sizeof(Teclas_de_Acao), 1, save_game);
}

// CARREGA DADOS DO SAVE GAME
void DATA_Carrega_Informacoes(Status* mago, Status* arqueiro, Ranking* ranking)
{
	rewind(Save_Game);

	fread(mago, sizeof(Status), 1, Save_Game);
	fread(arqueiro, sizeof(Status), 1, Save_Game);
	fread(ranking, sizeof(Ranking), 1, Save_Game);
	//fread(teclas_jogador1, sizeof(Teclas_de_Acao), 1, Save_Game);
	//fread(teclas_jogador2, sizeof(Teclas_de_Acao), 1, Save_Game);
}

// ***************************************************************************************************

// FIM
