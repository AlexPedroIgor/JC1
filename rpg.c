// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

/*
	RPG

	FUNCOES DE STATUS DOS JOGADORES E INIMIGOS

	Jogo de desenvolvido para projeto de computacao 1
*/


#include "rpg.h"
#include "base.h"

//
// PRE CARREGAMENTO DAS FUNCOES
//
int carregado = 0;

void carrega_HUD(SDL_Renderer* renderer, Jogadores* jogadores);
void Definir_status_iniciais(Jogadores* jogadores);
void Manter_status(Jogadores* jogadores);
void Tomar_dano(Inimigos* inimigo, Jogadores* jogadores);
void Carrega_inimigo_status(Inimigos* inimigo);

// ****************************************************************************

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

	switch(jogadores->jogador[0].inf.tipo)
	{
		case 1:
		jogadores->jogador[0].status.destreza = 0;
		jogadores->jogador[0].status.inteligencia = 15;
		jogadores->jogador[0].status.constituicao = 7;
		jogadores->jogador[0].status.lvl = 1;
		jogadores->jogador[0].status.dano = 0;

		break;

		case 2:
		jogadores->jogador[0].status.destreza = 15;
		jogadores->jogador[0].status.inteligencia = 0;
		jogadores->jogador[0].status.constituicao = 10;
		jogadores->jogador[0].status.lvl = 1;
		jogadores->jogador[0].status.dano = 0;

		break;		
	}
	if(jogadores->quantidade == 2)
	{
	switch(jogadores->jogador[1].inf.tipo)
	{
		case 1:
		jogadores->jogador[1].status.destreza = 0;
		jogadores->jogador[1].status.inteligencia = 15;
		jogadores->jogador[1].status.constituicao = 7;
		jogadores->jogador[1].status.lvl = 1;
		jogadores->jogador[1].status.dano = 0;

		break;

		case 2:
		jogadores->jogador[1].status.destreza = 15;
		jogadores->jogador[1].status.inteligencia = 0;
		jogadores->jogador[1].status.constituicao = 10;
		jogadores->jogador[1].status.lvl = 1;
		jogadores->jogador[1].status.dano = 0;

		break;
	}
	}
}
 void Manter_status(Jogadores* jogadores)
{
	

	switch(jogadores->jogador[0].inf.tipo)
	{
		case 1:
		jogadores->jogador[0].status.HP_Max = 500 + jogadores->jogador[0].status.constituicao*10 + jogadores->jogador[0].status.lvl*5;
		jogadores->jogador[0].status.MP_Max = 100 + jogadores->jogador[0].status.inteligencia*5 + jogadores->jogador[0].status.lvl*2;
		printf("HP MAX : %d \n", jogadores->jogador[0].status.HP_Max);
		printf("HP : %d \n", jogadores->jogador[0].status.HP);
		jogadores->jogador[0].status.HP = jogadores->jogador[0].status.HP_Max-jogadores->jogador[0].status.dano;
		jogadores->jogador[0].status.ataque = 50 + jogadores->jogador[0].status.inteligencia*5;
		jogadores->jogador[0].status.defesa = jogadores->jogador[0].status.constituicao;
		break;
		case 2:
		jogadores->jogador[0].status.HP_Max = 600 + jogadores->jogador[0].status.constituicao*10 + jogadores->jogador[0].status.lvl*5;
		jogadores->jogador[0].status.MP_Max = 5 + jogadores->jogador[0].status.destreza/2;
		jogadores->jogador[0].status.HP = jogadores->jogador[0].status.HP_Max-jogadores->jogador[0].status.dano;
		jogadores->jogador[0].status.ataque = 50 + jogadores->jogador[0].status.destreza*3;
		jogadores->jogador[0].status.defesa = jogadores->jogador[0].status.constituicao;
		break;		
	}
	if(jogadores->quantidade == 2)
	{
	switch(jogadores->jogador[1].inf.tipo)
	{
		case 1:
		jogadores->jogador[1].status.HP_Max = 500 + jogadores->jogador[1].status.constituicao*10 + jogadores->jogador[0].status.lvl*5;
		jogadores->jogador[1].status.MP_Max = 100 + jogadores->jogador[1].status.inteligencia*5 + jogadores->jogador[0].status.lvl*2;
		jogadores->jogador[1].status.HP = jogadores->jogador[1].status.HP_Max-jogadores->jogador[1].status.dano;
		jogadores->jogador[1].status.ataque = 50 + jogadores->jogador[1].status.inteligencia*5;
		jogadores->jogador[1].status.defesa = jogadores->jogador[1].status.constituicao;
		break;
		case 2:
		jogadores->jogador[1].status.HP_Max = 600 + jogadores->jogador[1].status.constituicao*10 + jogadores->jogador[0].status.lvl*5;
		jogadores->jogador[1].status.MP_Max = 5 + jogadores->jogador[1].status.destreza/2;
		jogadores->jogador[1].status.HP = jogadores->jogador[1].status.HP_Max-jogadores->jogador[1].status.dano;
		jogadores->jogador[1].status.ataque = 50 + jogadores->jogador[1].status.destreza*3;
		jogadores->jogador[1].status.defesa = jogadores->jogador[1].status.constituicao;
		break;		
	}
	}
}

void Tomar_dano(Inimigos* inimigo, Jogadores* jogadores)
{
	Carrega_inimigo_status(inimigo);

	printf("%d\n", inimigo->inimigo[0].status.ataque);

	if(inimigo->inimigo[0].status.ataque * 4 < jogadores->jogador[0].status.defesa)
		jogadores->jogador[0].status.dano = jogadores->jogador[0].status.dano +1 ; 
	else
		jogadores->jogador[0].status.dano += (inimigo->inimigo[0].status.ataque *4 -jogadores->jogador[0].status.defesa);
	if(jogadores->jogador[0].status.dano >= jogadores->jogador[0].status.HP_Max)
	{
		printf("MORRI\n");
		jogadores->jogador[0].status.HP = 0;
		jogadores->jogador[0].status.morte = 1;
	}
}
// FIM
void Carrega_inimigo_status(Inimigos* inimigo)
{
	inimigo->inimigo[0].status.ataque = 3;
}
