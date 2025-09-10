# comentamos

CC = gcc
FLAGS = -Wall -std=gnu89 -pedantic-errors -pthread -O3 -I./

all: clean  pCajero pTesorero

pCajero : mainCajero.c global.h archivos.h clave.h semaforo.h
	$(CC) $(FLAGS) -o pCajero mainCajero.c global.c archivos.c clave.c semaforo.c

pTesorero : mainTesorero.c global.h archivos.h clave.h semaforo.h
	$(CC) $(FLAGS) -o pTesorero mainTesorero.c global.c archivos.c clave.c semaforo.c



clean:
	rm -f *o  pCajero pTesorero
	
