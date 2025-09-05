# comentamos

CC = gcc
FLAGS = -Wall -std=gnu89 -pedantic-errors -pthread -O3 -I./

all: clean  pCarga pReserva

pCarga : mainCarga.c global.h archivos.h clave.h semaforo.h
	$(CC) $(FLAGS) -o pCarga mainCarga.c global.c archivos.c clave.c semaforo.c

pReserva : mainReserva.c global.h archivos.h clave.h semaforo.h
	$(CC) $(FLAGS) -o pReserva mainReserva.c global.c archivos.c clave.c semaforo.c



clean:
	rm -f *o  pCarga pReserva
	
