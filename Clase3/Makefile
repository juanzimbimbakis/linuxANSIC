# comentamos

CC = gcc
FLAGS = -Wall -std=gnu89 -pedantic-errors -pthread -O3 -I./

all: clean  programaMainCarga programaMainReserva

programaMainCarga : mainCarga.c clave.h semaforo.h global.h archivos.h
	$(CC) $(FLAGS) -o programaMainCarga mainCarga.c clave.c semaforo.c global.c archivos.c

programaMainReserva : mainReserva.c clave.h semaforo.h global.h archivos.h
	$(CC) $(FLAGS) -o programaMainReserva mainReserva.c clave.c semaforo.c global.c archivos.c



clean:
	rm -f *o  programaMainCarga programaMainReserva
	
