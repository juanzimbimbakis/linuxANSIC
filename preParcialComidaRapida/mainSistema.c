#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semaforo.h"
#include "unistd.h"
#include "global.h"
#include "archivos.h"


void procesarPedidos(char *parametro)
{
    char szBuffer[20];
    int contador = 0;
    int total = 0;


    if(*parametro == 'a')
    {
        if(!abrirArchivo("sistemaA.dat", "r"))
        {
            printf("Error al abrir sistemaA.dat\n");
        }

        while(leerArchivo(szBuffer, sizeof(szBuffer)) == TRUE)
        {
            if(sscanf(szBuffer, "%d %d", &contador, &total) == 2)
            {
                printf("Cantidad de Menu A: %d\n", contador);
                printf("Total por pedidos de Menu A: %d\n", total);
            }
        }

        cerrarArchivo();
    }
    if(*parametro == 'b')
    {
        if(!abrirArchivo("sistemaB.dat", "r"))
        {
            printf("Error al abrir sistemaB.dat\n");
        }

        while(leerArchivo(szBuffer, sizeof(szBuffer)) == TRUE)
        {
            if(sscanf(szBuffer, "%d %d", &contador, &total) == 2)
            {
                printf("Cantidad de Menu B: %d\n", contador);
                printf("Total por pedidos de Menu B: %d\n", total);
            }
        }

        cerrarArchivo();
    }
    if(*parametro == 'c')
    {
        if(!abrirArchivo("sistemaC.dat", "r"))
        {
            printf("Error al abrir sistemaC.dat\n");
        }

        while(leerArchivo(szBuffer, sizeof(szBuffer)) == TRUE)
        {
            if(sscanf(szBuffer, "%d %d", &contador, &total) == 2)
            {
                printf("Cantidad de Menu C: %d\n", contador);
                printf("Total por pedidos de Menu C: %d\n", total);
            }
        }

        cerrarArchivo();
    }

}

int main(int argc, char *argv[])
{
    int id_semaforo;
    char *parametro;
    if(argc != 2)
    {
        printf("Error! No se han pasado correctamnete los parametros\n");
        return 1;
    }

    parametro = argv[1];

    if(*parametro != 'a' && *parametro != 'b' && *parametro != 'c')
    {
        printf("Error! Hay que pasar por parametyro 'a', 'b' o 'c'\n");
        return 1;
    }

    id_semaforo =  creoSemaforo();


    while(1)
    {

        esperaSemaforo(id_semaforo);

        procesarPedidos(parametro);

        levantaSemaforo(id_semaforo);

        usleep(500*1000);
    }



    return 0;
}

