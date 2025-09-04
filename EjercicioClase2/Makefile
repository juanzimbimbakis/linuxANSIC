# comentamos

CC = gcc
FLAGS = -Wall -std=gnu89 -pedantic-errors -pthread -O3 -I./

all: clean programa1

programa1 : Main.c funciones.h definiciones.h
	$(CC) $(FLAGS) -o programa1 Main.c funciones.c


clean:
	rm -f *o programa1
