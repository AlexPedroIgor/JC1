// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

/*
	RPG

	FUNCOES DE STATUS DOS JOGADORES E INIMIGOS

	Jogo de desenvolvido para projeto de computacao 1
*/


#include "rpg.h"

//
// PRE CARREGAMENTO DAS FUNCOES
//

void carrega_HUD(SDL_Renderer* renderer);

// ****************************************************************************

//HUD
void carrega_HUD(SDL_Renderer* renderer)
{
//hp e mp pra teste
Status jogador;
jogador.HP_Max = 1000;
jogador.MP_Max = 500;
jogador.HP = 500;
jogador.MP = 380;

//Base da HUD
SDL_Surface* Loading_Surf = NULL;

SDL_Texture* gHUD = NULL	;

Loading_Surf = IMG_Load("arte/HUD/HUD.png"); 

gHUD = SDL_CreateTextureFromSurface(renderer, Loading_Surf);

SDL_FreeSurface(Loading_Surf);

SDL_Rect hud;

	hud.x = 0;
	hud.y = 0;
	hud.w = 298;
	hud.h = 82;

//HP
SDL_Texture* gHP = NULL	;

Loading_Surf = IMG_Load("arte/HUD/HP.png"); 

gHP = SDL_CreateTextureFromSurface(renderer, Loading_Surf);

SDL_FreeSurface(Loading_Surf);
SDL_Rect hp;

	hp.x = hud.x+51;
	hp.y = hud.y+34;
	hp.w = jogador.HP*226/jogador.HP_Max;;
	hp.h = 11;

//MP
SDL_Texture* gMP = NULL	;

Loading_Surf = IMG_Load("arte/HUD/MP.png"); 

gMP = SDL_CreateTextureFromSurface(renderer, Loading_Surf);

SDL_FreeSurface(Loading_Surf);
SDL_Rect mp;

	mp.x = 181;
	mp.y = 58;
	mp.w = jogador.MP*106/jogador.MP_Max;
	mp.h = 11;


SDL_RenderCopy(renderer, gHUD, NULL, &hud);
SDL_RenderCopy(renderer, gHP, NULL, &hp);
SDL_RenderCopy(renderer, gMP, NULL, &mp);

}
// FIM
