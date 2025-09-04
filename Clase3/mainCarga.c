#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semaforo.h"
#include "unistd.h"
#include "global.h"
#include "archivos.h"

typedef struct
{
    int id_vuelo;
    char destino[50];
    char nombre[50];
} Vuelo;


void cargarVuelos(void)
{
    char szBuffer[100];
    Vuelo vuelo;
    int continuar = 1;
    int i;
    vuelo.id_vuelo = 1000;

    if(!abrirArchivo("lote.dat", "w"))
    {
        printf("Error al abrir el archivo para escritura.\n");
        return;
    }

    while (continuar)
        {

            printf("Bienvenido! Vamos a cargar un lote\n");

            for(i = 0; i < 2; i++)
            {
                printf("\nIngrese destino del vuelo: ");
                scanf("%s", vuelo.destino);

                printf("\nIngrese nombre del pasajero: ");
                scanf("%s", vuelo.nombre);
                
                sprintf(szBuffer, "%d %s %s", vuelo.id_vuelo, vuelo.destino, vuelo.nombre);

                if(!escribirArchivo(szBuffer))
                {
                    printf("Error al cargar vuelo.\n");
                }

                vuelo.id_vuelo = vuelo.id_vuelo + 1;
            }

            cerrarArchivo();

            printf("Desea ingresar otro lote? (1: Si, 0: No): ");
            scanf("%d", &continuar);

            if(continuar == 0)
            {
                vuelo.id_vuelo = 1000;
            } else if(continuar == 1)
            {
                if(!abrirArchivo("lote.dat", "w"))
                {
                    printf("Error al abrir el archivo para escritura.\n");
                    return;
                }
            } else 
            {
                printf("Opcion invalida. Saliendo.\n");
                continuar = 0;
            }

        }

}

int main(int argc,char *argv[])
{

    int id_semaforo;

    id_semaforo =  creoSemaforo();

    inicioSemaforo(id_semaforo, VERDE);

    while (1)
    {

        esperaSemaforo(id_semaforo);

        cargarVuelos();

        levantaSemaforo(id_semaforo);
        usleep(10*1000);
    }




    return 0;
}

