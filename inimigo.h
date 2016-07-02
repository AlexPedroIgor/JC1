// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

#ifndef INIMIGO_H
#define INIMIGO_H

// BIBLIOTECAS INTERNAS
#include "main.h"
#include "bse.h"
#include "rpg.h"
#include "fisica.h"
#include "colisao.h"

// ***************************************************************************************

//
// FUNCOES
//

Inimigo Carrega_Inimigo(SDL_Renderer* renderer, int numero);
Vetor_de_Inimigos Cria_Vetor_de_inimigos(SDL_Renderer* renderer, int quantidade, int tipo);
void Adiciona_inimigos(SDL_Renderer* renderer,Vetor_de_Inimigos* vetor_de_inimigos, int quantidade, int tipo, int portal, Fase* fase);
void Remove_Inimigos_Mortos(SDL_Renderer* renderer, Vetor_de_Inimigos* vetor_de_inimigos);
void Posiciona_Inimigo(SDL_Renderer* renderer, Inimigo* inimigo, int portal, Fase* fase);
void Posiciona_Vetor_de_Inimigos(SDL_Renderer* renderer, Vetor_de_Inimigos* vetor_de_inimigos, int portal, Fase* fase);
void Movimenta_Inimigo(Inimigo* inimigo);
void IA_de_Movimentacao(Inimigo* inimigo, Jogador* jogador1, Jogador* jogador2);
void Movimentacao_dos_Inimigos(Vetor_de_Inimigos* vetor_de_inimigos, Jogador* jogador1, Jogador* jogador2);
void Atualiza_Inimigos_em_Tela(SDL_Renderer* renderer, Vetor_de_Inimigos* vetor_de_inimigos);
void Atacar_inimigo(Inimigo* inimigo);

// ********************************************************************************************

#endif

// FIM
