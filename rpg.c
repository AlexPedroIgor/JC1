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

void carrega_HUD(SDL_Renderer* renderer, Jogadores* jogadores);

// ****************************************************************************

//HUD
void carrega_HUD(SDL_Renderer* renderer, Jogadores* jogadores)
{
//hp e mp pra teste

jogadores->jogador[0].status.HP_Max = 1000;
jogadores->jogador[0].status.MP_Max = 500;
jogadores->jogador[0].status.HP = 500;
jogadores->jogador[0].status.MP = 380;

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
	hp.w = jogadores->jogador[0].status.HP = 500*226/jogadores->jogador[0].status.MP_Max;
	hp.h = 11;

//MP
SDL_Texture* gMP = NULL	;

Loading_Surf = IMG_Load("arte/menu/MP.png"); 

gMP = SDL_CreateTextureFromSurface(renderer, Loading_Surf);

SDL_FreeSurface(Loading_Surf);
SDL_Rect mp;

	mp.x = hud.x+181;
	mp.y = hud.y+58;
	mp.w = jogadores->jogador[0].status.atk_cooldown*106/10;
	mp.h = 11;


SDL_RenderCopy(renderer, gHUD, NULL, &hud);
SDL_RenderCopy(renderer, gHP, NULL, &hp);
SDL_RenderCopy(renderer, gMP, NULL, &mp);
//int quantidade = 2;
if (jogadores->quantidade == 2)	//mudar para quantidade dejogadores mais tarde
{
//hp e mp pra teste

jogadores->jogador[1].status.HP_Max = 800;
jogadores->jogador[1].status.MP_Max = 700;
jogadores->jogador[1].status.HP = 600;
jogadores->jogador[1].status.MP = 120;

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
	mp2.y = hud2	.y+58;
	mp2.w = jogadores->jogador[1].status.MP*106/jogadores->jogador[1].status.MP_Max;
	mp2.h = 11;


SDL_RenderCopy(renderer, gHUD2, NULL, &hud2);
SDL_RenderCopy(renderer, gHP2, NULL, &hp2);
SDL_RenderCopy(renderer, gMP2, NULL, &mp2);
}

}
// FIM
