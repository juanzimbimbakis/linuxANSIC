# comentamos

CC = gcc
FLAGS = -Wall -std=gnu89 -pedantic-errors -pthread -O3 -I./

all: clean  p1 p2

p1 : mainInicio.c global.h archivos.h clave.h semaforo.h funciones.h memoria.h
	$(CC) $(FLAGS) -o p1 mainInicio.c global.c archivos.c clave.c semaforo.c funciones.c memoria.c

p2 : mainFin.c global.h archivos.h clave.h semaforo.h funciones.h memoria.h
	$(CC) $(FLAGS) -o p2 mainFin.c global.c archivos.c clave.c semaforo.c funciones.c memoria.c



clean:
	rm -f *o  p1 p2
	
