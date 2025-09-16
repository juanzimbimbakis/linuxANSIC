# comentamos

CC = gcc
FLAGS = -Wall -std=gnu89 -pedantic-errors -pthread -O3 -I./

all: clean  pInicio pFin

pInicio : mainInicio.c global.h archivos.h clave.h semaforo.h funciones.h
	$(CC) $(FLAGS) -o pInicio mainInicio.c global.c archivos.c clave.c semaforo.c funciones.c

pFin : mainFin.c global.h archivos.h clave.h semaforo.h funciones.h
	$(CC) $(FLAGS) -o pFin mainFin.c global.c archivos.c clave.c semaforo.c funciones.c



clean:
	rm -f *o  pInicio pFin
	
