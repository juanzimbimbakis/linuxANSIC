#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semaforo.h"
#include "unistd.h"
#include "global.h"
#include "archivos.h"

void procesarMedicamentos(char *parametro)
{
    char szBuffer[20];
    int totalMedicamentos = 0;
    int totalPastillasRealizadas = 0;

    printf("\n----------\n");
    if(*parametro == 'a')
    {
        if(!abrirArchivo("sistemaA.dat", "r"))
        {
            printf("Error al abrir sistemaA.dat");
        }

        while(leerArchivo(szBuffer, sizeof(szBuffer)) == TRUE)
        {
            if(sscanf(szBuffer, "%d %d", &totalMedicamentos, &totalPastillasRealizadas) == 2)
            {
                printf("Total medicamentos procesados por Sistema A: %d\n", totalMedicamentos);
                printf("Total pastillas procesadas por Sistema A: %d\n", totalPastillasRealizadas);
            }
        }

        cerrarArchivo();

    }
    if(*parametro == 'b')
    {
        if(!abrirArchivo("sistemaB.dat", "r"))
        {
            printf("Error al abrir sistemaB.dat");
        }

        while(leerArchivo(szBuffer, sizeof(szBuffer)) == TRUE)
        {
            if(sscanf(szBuffer, "%d %d", &totalMedicamentos, &totalPastillasRealizadas) == 2)
            {
                printf("Total medicamentos procesados por Sistema B: %d\n", totalMedicamentos);
                printf("Total pastillas procesadas por Sistema B: %d\n", totalPastillasRealizadas);
            }
        }

        cerrarArchivo();

    }
    if(*parametro == 'c')
    {
        if(!abrirArchivo("sistemaC.dat", "r"))
        {
            printf("Error al abrir sistemaC.dat");
        }

        while(leerArchivo(szBuffer, sizeof(szBuffer)) == TRUE)
        {
            if(sscanf(szBuffer, "%d %d", &totalMedicamentos, &totalPastillasRealizadas) == 2)
            {
                printf("Total medicamentos procesados por Sistema C: %d\n", totalMedicamentos);
                printf("Total pastillas procesadas por Sistema C: %d\n", totalPastillasRealizadas);
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
        printf("Error! No se han pasado correctamente la cantidad de parametros");
        return 1;
    }

    parametro = argv[1];


    if(*parametro != 'a' && *parametro != 'b' && *parametro != 'c')
    {
        printf("Error! Parametro incorrecto. Tiene que ser 'a', 'b', ó 'c'\n");
        return 1;
    }

    id_semaforo = creoSemaforo();

    while (1)
    {
        esperaSemaforo(id_semaforo);


        procesarMedicamentos(parametro);


        levantaSemaforo(id_semaforo);

        usleep(500 * 1000);
    }


    return 0;
}

