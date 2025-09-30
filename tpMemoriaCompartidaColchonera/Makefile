# comentamos

CC = gcc
FLAGS = -Wall -std=gnu89 -pedantic-errors -pthread -O3 -I./

all: clean  pColchoneria pVendedor

pColchoneria : mainColchoneria.c global.h archivos.h clave.h semaforo.h funciones.h memoria.h
	$(CC) $(FLAGS) -o pColchoneria mainColchoneria.c global.c archivos.c clave.c semaforo.c funciones.c memoria.c

pVendedor : mainVendedor.c global.h archivos.h clave.h semaforo.h funciones.h memoria.h
	$(CC) $(FLAGS) -o pVendedor mainVendedor.c global.c archivos.c clave.c semaforo.c funciones.c memoria.c



clean:
	rm -f *o  pColchoneria pVendedor
	
