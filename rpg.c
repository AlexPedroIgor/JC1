// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

/*
	RPG

	FUNCOES DE STATUS DOS JOGADORES E INIMIGOS

	Jogo de desenvolvido para projeto de computacao 1
*/

// BIBLIOTECAS INTERNAS
#include "rpg.h"
#include "base.h"

// ***********************************************************************************************

//
// VARIAVEIS GLOBAIS
//

int carregado = 0;

// ***********************************************************************************************

//
// PRE CARREGAMENTO DAS FUNCOES
//

void carrega_HUD(SDL_Renderer* renderer, Jogadores* jogadores);
void Definir_status_iniciais(Jogadores* jogadores);
void Atualiza_Status_Geral(Jogadores* jogadores);
void Manter_status(Jogadores* jogadores);
void Tomar_dano(Inimigos* inimigo, Status* inimigo_status, Jogadores* jogadores, int jogador_proximo);
void Define_Status_Inimigo(Status* status, int tipo);

// **********************************************************************************************

//
// STATUS DO JOGADOR
//

//HUD
void carrega_HUD(SDL_Renderer* renderer, Jogadores* jogadores)
{
	//Base da HUD
	SDL_Surface* Loading_Surf = NULL;

	SDL_Texture* gHUD = NULL	;

	Loading_Surf = IMG_Load("arte/menu/HUD.png"); 

	gHUD = SDL_CreateTextureFromSurface(renderer, Loading_Surf);

	SDL_FreeSurface(Loading_Surf);

	SDL_Rect hud;

		hud.x = 0;
		hud.y = 0;
		hud.w = 298;
		hud.h = 82;

	//HP
	SDL_Texture* gHP = NULL	;

	Loading_Surf = IMG_Load("arte/menu/HP.png"); 

	gHP = SDL_CreateTextureFromSurface(renderer, Loading_Surf);

	SDL_FreeSurface(Loading_Surf);
	SDL_Rect hp;

		hp.x = hud.x+51;
		hp.y = hud.y+34;
		hp.w = jogadores->jogador[0].status.HP*226/jogadores->jogador[0].status.HP_Max;
		hp.h = 11;

	//MP
	SDL_Texture* gMP = NULL	;

	Loading_Surf = IMG_Load("arte/menu/MP.png"); 

	gMP = SDL_CreateTextureFromSurface(renderer, Loading_Surf);

	SDL_FreeSurface(Loading_Surf);
	SDL_Rect mp;
		
		mp.x = hud.x+181;
		mp.y = hud.y+58;
		mp.w = jogadores->jogador[0].status.MP*106/jogadores->jogador[0].status.MP_Max;
		mp.h = 11;


	SDL_RenderCopy(renderer, gHUD, NULL, &hud);
	SDL_RenderCopy(renderer, gHP, NULL, &hp);
	SDL_RenderCopy(renderer, gMP, NULL, &mp);

	//hud multiplayer
	if (jogadores->quantidade == 2)	
	{

		//Base da HUD
		SDL_Surface* Loading_Surf = NULL;

		SDL_Texture* gHUD2 = NULL	;

		Loading_Surf = IMG_Load("arte/menu/HUD.png"); 

		gHUD2 = SDL_CreateTextureFromSurface(renderer, Loading_Surf);

		SDL_FreeSurface(Loading_Surf);

		SDL_Rect hud2;

			hud2.x = 500;
			hud2.y = 0;
			hud2.w = 298;
			hud2.h = 82;

		//HP
		SDL_Texture* gHP2 = NULL	;

		Loading_Surf = IMG_Load("arte/menu/HP.png"); 

		gHP2 = SDL_CreateTextureFromSurface(renderer, Loading_Surf);

		SDL_FreeSurface(Loading_Surf);
		SDL_Rect hp2;

			hp2.x = hud2.x+51;
			hp2.y = hud2.y+34;
			hp2.w = jogadores->jogador[1].status.HP*226/jogadores->jogador[1].status.HP;
			hp2.h = 11;

		//MP
		SDL_Texture* gMP2 = NULL	;

		Loading_Surf = IMG_Load("arte/menu/MP.png"); 

		gMP2 = SDL_CreateTextureFromSurface(renderer, Loading_Surf);

		SDL_FreeSurface(Loading_Surf);
		SDL_Rect mp2;
			
			mp2.x = hud2.x+181;
			mp2.y = hud2.y+58;
			mp2.w = jogadores->jogador[1].status.MP*106/jogadores->jogador[1].status.MP_Max;
			mp2.h = 11;

			


		SDL_RenderCopy(renderer, gHUD2, NULL, &hud2);
		SDL_RenderCopy(renderer, gHP2, NULL, &hp2);
		SDL_RenderCopy(renderer, gMP2, NULL, &mp2);
	}
}

//Status
void Definir_status_iniciais(Jogadores* jogadores)
{
	Status mago, arqueiro;
	Ranking ranking;

	DATA_Carrega_Informacoes(&mago, &arqueiro, &ranking);

	switch(jogadores->jogador[0].inf.tipo)
	{
		case MAGO:
			jogadores->jogador[0].status = mago;
			break;

		case 2:
			jogadores->jogador[0].status = arqueiro;
			break;		
	}

	if(jogadores->quantidade == 2)
	{
		switch(jogadores->jogador[1].inf.tipo)
		{
			case MAGO:
				jogadores->jogador[1].status = mago;
				break;

			case 2:
				jogadores->jogador[1].status = arqueiro;
				break;	
		}
	}
}

void Atualiza_Status_Geral(Jogadores* jogadores)
{
	switch(jogadores->jogador[0].inf.tipo)
	{
		case MAGO:
			jogadores->jogador[0].status.HP_Max = 500 + jogadores->jogador[0].status.constituicao*10 + jogadores->jogador[0].status.lvl*5;
			jogadores->jogador[0].status.MP_Max = 100 + jogadores->jogador[0].status.inteligencia*5 + jogadores->jogador[0].status.lvl*2;
			jogadores->jogador[0].status.HP = jogadores->jogador[0].status.HP_Max;
			jogadores->jogador[0].status.ataque = 50 + jogadores->jogador[0].status.inteligencia*5;
			jogadores->jogador[0].status.defesa = jogadores->jogador[0].status.constituicao;
			break;

		case ARQUEIRO:
			jogadores->jogador[0].status.HP_Max = 600 + jogadores->jogador[0].status.constituicao*10 + jogadores->jogador[0].status.lvl*5;
			jogadores->jogador[0].status.MP_Max = 5 + jogadores->jogador[0].status.destreza/2;
			jogadores->jogador[0].status.HP = jogadores->jogador[0].status.HP_Max;
			jogadores->jogador[0].status.ataque = 50 + jogadores->jogador[0].status.destreza*3;
			jogadores->jogador[0].status.defesa = jogadores->jogador[0].status.constituicao;
			break;		
	}

	if(jogadores->quantidade == 2)
	{
		switch(jogadores->jogador[1].inf.tipo)
		{
			case MAGO:
				jogadores->jogador[1].status.HP_Max = 500 + jogadores->jogador[1].status.constituicao*10 + jogadores->jogador[0].status.lvl*5;
				jogadores->jogador[1].status.MP_Max = 100 + jogadores->jogador[1].status.inteligencia*5 + jogadores->jogador[0].status.lvl*2;
				jogadores->jogador[1].status.HP = jogadores->jogador[1].status.HP_Max;
				jogadores->jogador[1].status.ataque = 50 + jogadores->jogador[1].status.inteligencia*5;
				jogadores->jogador[1].status.defesa = jogadores->jogador[1].status.constituicao;
				break;

			case ARQUEIRO:
				jogadores->jogador[1].status.HP_Max = 600 + jogadores->jogador[1].status.constituicao*10 + jogadores->jogador[0].status.lvl*5;
				jogadores->jogador[1].status.MP_Max = 5 + jogadores->jogador[1].status.destreza/2;
				jogadores->jogador[1].status.HP = jogadores->jogador[1].status.HP_Max;
				jogadores->jogador[1].status.ataque = 50 + jogadores->jogador[1].status.destreza*3;
				jogadores->jogador[1].status.defesa = jogadores->jogador[1].status.constituicao;
				break;		
		}
	}
}

void Manter_status(Jogadores* jogadores)
{
	jogadores->jogador[0].status.HP -= jogadores->jogador[0].status.dano;
	jogadores->jogador[0].status.dano = 0;

	if (jogadores->quantidade == 2)
	{
		jogadores->jogador[0].status.HP -= jogadores->jogador[0].status.dano;
		jogadores->jogador[0].status.dano = 0;
	}
}

void Tomar_dano(Inimigos* inimigo, Status* inimigo_status, Jogadores* jogadores, int jogador_proximo)
{
	jogador_proximo--;

	jogadores->jogador[jogador_proximo].status.dano -= (inimigo_status->ataque - jogadores->jogador[jogador_proximo].status.defesa);

	if(jogadores->jogador[jogador_proximo].status.dano >= jogadores->jogador[jogador_proximo].status.HP_Max)
	{
		//printf("MORRI\n");
		jogadores->jogador[jogador_proximo].status.HP = 0;
		jogadores->jogador[jogador_proximo].status.morte = VERDADEIRO;
	}
}

// ********************************************************************************************

//
// STATUS DOS INIMIGOS
//

// CARREGA
void Define_Status_Inimigo(Status* status, int tipo)
{
	switch (tipo)
	{
		case 1:
			status->lvl = 1;
			status->forca = 2;
			status->destreza = 7;
			status->inteligencia = 3;
			status->constituicao = 5;
			status->ataque = 1 + status->forca*2;
			status->defesa = status->constituicao;
			status->HP_Max = 200 + status->constituicao*9 + status->lvl*3;
			status->MP_Max = 50 + status->inteligencia*4 + status->lvl*2;
			status->HP = status->HP_Max;
			status->MP = status->MP_Max;
			status->morte = FALSO;
			status->atk_cooldown = 0;
			status->delay_ataque = 1;
			break;

		case 2:
			status->lvl = 1;
			status->forca = 10;
			status->destreza = 7;
			status->inteligencia = 3;
			status->constituicao = 5;
			status->ataque = 3 + status->forca*2;
			status->defesa = status->constituicao;
			status->HP_Max = 200 + status->constituicao*9 + status->lvl*3;
			status->MP_Max = 50 + status->inteligencia*4 + status->lvl*2;
			status->HP = status->HP_Max;
			status->MP = status->MP_Max;
			status->morte = FALSO;
			status->atk_cooldown = 0;
			status->delay_ataque = 1;
			break;

		case 3:
			status->lvl = 1;
			status->forca = 10;
			status->destreza = 7;
			status->inteligencia = 3;
			status->constituicao = 5;
			status->ataque = 3 + status->forca*2;
			status->defesa = status->constituicao;
			status->HP_Max = 200 + status->constituicao*9 + status->lvl*3;
			status->MP_Max = 50 + status->inteligencia*4 + status->lvl*2;
			status->HP = status->HP_Max;
			status->MP = status->MP_Max;
			status->morte = FALSO;
			status->atk_cooldown = 0;
			status->delay_ataque = 1;
			break;
	}
}

// FIM