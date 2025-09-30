# comentamos

CC = gcc
FLAGS = -Wall -std=gnu89 -pedantic-errors -pthread -O3 -I./

all: clean  pPienso pJugador

pPienso : mainPienso.c global.h archivos.h clave.h semaforo.h funciones.h memoria.h
	$(CC) $(FLAGS) -o pPienso mainPienso.c global.c archivos.c clave.c semaforo.c funciones.c memoria.c

pJugador : mainJugador.c global.h archivos.h clave.h semaforo.h funciones.h memoria.h
	$(CC) $(FLAGS) -o pJugador mainJugador.c global.c archivos.c clave.c semaforo.c funciones.c memoria.c



clean:
	rm -f *o  pPienso pJugador
	
