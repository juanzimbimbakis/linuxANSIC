# comentamos

CC = gcc
FLAGS = -Wall -std=gnu89 -pedantic-errors -pthread -O3 -I./

all: clean  pEquipo pPanel

pEquipo : mainEquipo.c global.h archivos.h clave.h semaforo.h funciones.h
	$(CC) $(FLAGS) -o pEquipo mainEquipo.c global.c archivos.c clave.c semaforo.c funciones.c

pPanel : mainPanel.c global.h archivos.h clave.h semaforo.h funciones.h
	$(CC) $(FLAGS) -o pPanel mainPanel.c global.c archivos.c clave.c semaforo.c funciones.c



clean:
	rm -f *o  pEquipo pPanel
	
