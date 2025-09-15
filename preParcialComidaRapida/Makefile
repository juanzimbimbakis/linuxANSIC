# comentamos

CC = gcc
FLAGS = -Wall -std=gnu89 -pedantic-errors -pthread -O3 -I./

all: clean  pTuComida pSistema

pTuComida : mainTuComida.c global.h archivos.h clave.h semaforo.h
	$(CC) $(FLAGS) -o pTuComida mainTuComida.c global.c archivos.c clave.c semaforo.c

pSistema : mainSistema.c global.h archivos.h clave.h semaforo.h
	$(CC) $(FLAGS) -o pSistema mainSistema.c global.c archivos.c clave.c semaforo.c



clean:
	rm -f *o  pTuComida pSistema
	
