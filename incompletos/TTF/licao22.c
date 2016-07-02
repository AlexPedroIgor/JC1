#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
	// Inicializa o SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	// Inicializa o leitor de fontes
	TTF_Init();

	// Cria o ponteiro da janela
	SDL_Window* window = NULL;

	// Cria a janela em tela
	window = SDL_CreateWindow("Teste",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		640, 480, 0);

	// Cria o ponteiro do render
	SDL_Renderer* renderer = NULL;

	// Carrega o render em tela
	renderer = SDL_CreateRenderer(window, -1, 0);

	// Cria o ponteiro da fonte
	TTF_Font* fonte = NULL;

	// Define uma cor pra fonte - Branco
	SDL_Color cor_do_texto = {255,255,255};

	// Carrega fonte na memoria
	fonte = TTF_OpenFont("OpenSans-Regular.ttf", 28);

	// Cria uma surface para escrever uma mensagem
	SDL_Surface* mensagem = NULL;

	// Cria uma textura para desenhar o texto em tela
	SDL_Texture* mensagem_em_tela = NULL;

	// Define um rect para tamanho e posicao do texto em tela
	SDL_Rect tamanho_posicao;
	tamanho_posicao.x = 30;
	tamanho_posicao.y = 225;
	tamanho_posicao.w = 300;
	tamanho_posicao.h = 30;

	// Variavel do loop
	int rodando = 1;

	// Eventos
	SDL_Event event;

	// Variavel para fazer o timer
	Uint32 start = 0;

	// Marca o tempo inicial
	start = SDL_GetTicks();

	// String para guardar o valor do tempo
	char tempo[22];

	// Variavel para auxiliar na hora de transformar o tempo numa string
	int n;

	// Loop
	while (rodando)
	{
		// Evento para fechar a janela
		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				rodando = 0;
		}

		// Transforma o tempo numa string para printar em tela
		n = sprintf(tempo, "Tempo: %d", SDL_GetTicks() - start);

		// Escreve a string na surface 
		mensagem = TTF_RenderText_Solid(fonte, tempo, cor_do_texto);

		// Converte o texto da surface em textura para mandar pro render
		mensagem_em_tela = SDL_CreateTextureFromSurface(renderer, mensagem);

		// Limpa a memoria da surface
		SDL_FreeSurface (mensagem);

		// Limpa tela
		SDL_RenderClear(renderer);

		// Carrega o texto em tela
		SDL_RenderCopy(renderer, mensagem_em_tela, NULL, &tamanho_posicao);

		// Atualiza a tela
		SDL_RenderPresent(renderer);
	}

	// Limpa textura da memoria
	SDL_DestroyTexture(mensagem_em_tela);

	// Fecha a fonte
	TTF_CloseFont(fonte);

	// Destroi o render
	SDL_DestroyRenderer(renderer);

	// Destriu a imagem
	SDL_DestroyWindow(window);

	// Finaliza o TTF
	TTF_Quit();

	// Finaliza o SDL
	SDL_Quit();
}