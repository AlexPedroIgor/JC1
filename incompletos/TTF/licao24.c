#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "base.h"


int main()
{
	FILE* save_game;
	char* nome_arquivo = "data.dat";

	Status status_escrito1, status_escrito2, status_lido1, status_lido2;

	if ((save_game = fopen(nome_arquivo, "r+b")) == NULL)
	{
		printf("Criando novo arquivo\n");
		if ((save_game = fopen(nome_arquivo, "w+b")) == NULL)
			printf("Arquivo nao pode ser criado\n");
	}
	if (save_game != NULL)
		printf("Arquivo aberto com sucesso\n");

	scanf("%f", &status_escrito1.HP_Max);
	scanf("%f", &status_escrito1.MP_Max);
	scanf("%f", &status_escrito2.HP_Max);
	scanf("%f", &status_escrito2.MP_Max);

	fwrite(&status_escrito1, sizeof(Status), 1, save_game);
	fwrite(&status_escrito2, sizeof(Status), 1, save_game);

	rewind(save_game);

	fread(&status_lido2, sizeof(Status), 1, save_game);
	fread(&status_lido1, sizeof(Status), 1, save_game);

	printf("%f\n", status_lido1.HP_Max);
	printf("%f\n", status_lido1.MP_Max);
	printf("%f\n", status_lido2.HP_Max);
	printf("%f\n", status_lido2.MP_Max);


	fclose(save_game);
	return 0;
}