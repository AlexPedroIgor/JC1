// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

#ifndef FISICA_H
#define FISICA_H

#include "main.h"
#include "inimigo.h"

// Funcoes de colisao
int Colisao_Circular(Objeto* objeto1, Objeto* objeto2);
int Colisao_Retangular(Objeto* Objeto1, Objeto* Objeto2);
int Colisao_Perimetro(Objeto* objeto1, Objeto* objeto2);
int Colisao_LimiteDeTela(Objeto* objeto);
int Colisao_Jogador_LimiteDeTela(Jogador* jogador);
int Colisao_Inimigo_LimiteDeTela(Inimigo* inimigo);
int Colisao_Entre_Jogadores(Jogador* jogador1, Jogador* jogador2);
int Colisao_Entre_Jogador_Inimigo(Jogador* jogador, Inimigo* inimigo);
int Colisao_Impacto_Jogador(Jogador* jogador, Objeto* objeto);
int Colisao_Entre_Inimigo_Jogador(Inimigo* inimigo, Jogador* jogador);
int Colisao_Entre_Inimigos(Inimigo* inimigo1, Inimigo* inimigo2);
int Colisao_Impacto_Inimigo(Inimigo* inimigo, Objeto* objeto);
int* Distancia(Objeto* objeto1, Objeto* objeto2);
int* Distancia_Inimigo_Jogador(Inimigo* inimigo, Jogador* jogador);
Objeto Converte_Jogador_Objeto(Jogador* Jogador);
Objeto Converte_Inimigo_Objeto(Inimigo* inimigo);
void Teste_de_Colisao_Jogador(Jogador* jogador, Vetor_de_Inimigos* vetor_de_inimigos);
Objeto Cria_Tiro(Jogador* jogador);
void CarregaTiro(SDL_Renderer* renderer, Objeto* tiro, Jogador* jogador);
Vetor_de_Tiros Cria_Vetor_de_Tiros();
void Adiciona_Tiro_ao_Vetor(SDL_Renderer* renderer, Vetor_de_Tiros* vetor_de_tiros, Jogador* jogador);
void Renderiza_Tiros(SDL_Renderer* renderer, Vetor_de_Tiros* vetor_de_tiros);

#endif

// fim
