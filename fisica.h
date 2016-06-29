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
int Colisao_Entre_Jogadores(Jogador* jogador1, Jogador* jogador2);
int Colisao_Entre_Jogador_Inimigo(Jogador* jogador, Inimigo* inimigo);
int Colisao_Impacto_Jogador(Jogador* jogador, Objeto* objeto);
int Colisao_Impacto_Inimigo(Inimigo* inimigo, Objeto* objeto);
int Distancia(Objeto* objeto1, Objeto* objeto2);
int Distancia(Objeto* objeto1, Objeto* objeto2);
Objeto Converte_Jogador_Objeto(Jogador* Jogador);
Objeto Converte_Inimigo_Objeto(Inimigo* inimigo);

#endif

// fim
