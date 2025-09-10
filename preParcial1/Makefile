# comentamos

CC = gcc
FLAGS = -Wall -std=gnu89 -pedantic-errors -pthread -O3 -I./

all: clean  pDerivador pCaja

pDerivador : mainSuperDerivador.c global.h archivos.h clave.h semaforo.h
	$(CC) $(FLAGS) -o pDerivador mainSuperDerivador.c global.c archivos.c clave.c semaforo.c

pCaja : mainCaja.c global.h archivos.h clave.h semaforo.h
	$(CC) $(FLAGS) -o pCaja mainCaja.c global.c archivos.c clave.c semaforo.c



clean:
	rm -f *o  pCaja pDerivador
	
