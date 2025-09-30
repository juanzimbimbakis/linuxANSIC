# comentamos

CC = gcc
FLAGS = -Wall -std=gnu89 -pedantic-errors -pthread -O3 -I./

all: clean  pP pA

pP : mainPeaje.c global.h archivos.h clave.h semaforo.h funciones.h memoria.h
	$(CC) $(FLAGS) -o pP mainPeaje.c global.c archivos.c clave.c semaforo.c funciones.c memoria.c

pA : mainAuto.c global.h archivos.h clave.h semaforo.h funciones.h memoria.h
	$(CC) $(FLAGS) -o pA mainAuto.c global.c archivos.c clave.c semaforo.c funciones.c memoria.c



clean:
	rm -f *o  pP pA
	
