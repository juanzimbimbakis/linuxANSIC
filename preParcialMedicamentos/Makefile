# comentamos

CC = gcc
FLAGS = -Wall -std=gnu89 -pedantic-errors -pthread -O3 -I./

all: clean  pControlador pSistema

pControlador : mainControlador.c global.h archivos.h clave.h semaforo.h funciones.h
	$(CC) $(FLAGS) -o pControlador mainControlador.c global.c archivos.c clave.c semaforo.c funciones.c

pSistema : mainSistema.c global.h archivos.h clave.h semaforo.h funciones.h
	$(CC) $(FLAGS) -o pSistema mainSistema.c global.c archivos.c clave.c semaforo.c funciones.c



clean:
	rm -f *o  pControlador pSistema
	
