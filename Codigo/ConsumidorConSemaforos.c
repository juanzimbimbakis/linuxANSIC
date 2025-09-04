#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semaforo.h"
#include "unistd.h"

int main(int argc,char *argv[])
{
	char cadena[LARGO]; /* Un array lo suficientemente grande como para guardar la l�nea m�s larga del fichero */
	int cant_producto=0;
	FILE *consumidor; 
	
	int id_semaforo;
	id_semaforo =  creo_semaforo();
	
	while(1)
	{
		espera_semaforo(id_semaforo);
			/*
			consumidor = fopen("producto.txt", "r");
			if (consumidor!=NULL)
			{
				printf("\nCONSUMIMOS\n");
				while (!feof(consumidor))
				{
					fscanf(consumidor,"%s",cadena);
					printf("%s\n", cadena);
					usleep(INTERVALO_PRODUCTO*1000);
					cant_producto++;
				}
				fclose(consumidor);
				if(cant_producto>0)
				{
					printf("\nBORRAMOS\n");
					remove("producto.txt");
					cant_producto=0;
				}
			}
			else
				perror ("Error al abrir producto.txt");

			printf("\nESPERAMOS\n");
				*/
					printf("\nCONSUMIDOR\n");
		levanta_semaforo(id_semaforo);
		usleep(INTERVALO_PARTIDA*1000);
	};
	return 0;
}
