# Makefile do jogo ##
# Bibliotecas: SDL 2.0, SDL_image 2.0, SDL_mixer 2.0 ##

## O comando make cria o executavel ##
## O comando make clean limpa os arquivos .o ##
## O comando make mrproper apaga o executavel ##

############################### Makefile ###############################

all: meujogo
meujogo: main.o menu.o jogo.o som.o config.o
		# Compilando os objetos
		gcc -o meujogo som.o jogo.o menu.o config.o main.o -lSDL2 -lSDL2_image -lSDL2_mixer 2>log/meujogo.gccmessages
#------> Execucao dos arquivos
som.o: som.c main.h som.h
		gcc -o som.o -c som.c -Wall -lSDL2 -lSDL2_image -lSDL2_mixer 2>log/som.gccmessages
#
jogo.o: jogo.c main.h som.h config.h
		gcc -o jogo.o -c jogo.c -Wall -lSDL2 -lSDL2_image -lSDL2_mixer 2>log/jogo.gccmessages
#
menu.o: menu.c som.h main.h config.h
		gcc -o menu.o -c menu.c -Wall -lSDL2 -lSDL2_image -lSDL2_mixer 2>log/menu.gccmessages
#
config.o: config.c main.h
		gcc -o config.o -c config.c -Wall -lSDL2 -lSDL2_image -lSDL2_mixer 2>log/config.gccmessages
#
main.o: main.c main.h menu.h jogo.h config.h
		gcc -o main.o -c main.c -Wall -lSDL2 -lSDL2_image -lSDL2_mixer 2>log/main.gccmessages
#
clean:
		rm -rf *.o
#
mrproper: clean
		rm -rf meujogo