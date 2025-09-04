# comentamos

CC = gcc
FLAGS = -Wall -std=gnu89 -pedantic-errors -pthread -O3 -I./

all: clean  progMain4 progMain5

progMain4 : main4.c global.h archivos.h
	$(CC) $(FLAGS) -o progMain4 main4.c global.c archivos.c

progMain5 : main5.c global.h archivos.h
	$(CC) $(FLAGS) -o progMain5 main5.c global.c archivos.c



clean:
	rm -f *o  progMain4 progMain5
	
