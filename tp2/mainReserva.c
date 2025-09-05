#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semaforo.h"
#include "unistd.h"
#include "global.h"
#include "archivos.h"

void reservarVuelos(void)
{
    char szBuffer[100];
    static int contador = 0;
    char nuevoNombre[20];

    if(!abrirArchivo("lote.dat", "r"))
    {
        printf("Error al abrir archivo lote.dat para lectura. \n");
        return;
    }

    while(leerArchivo(szBuffer, sizeof(szBuffer)) == TRUE)
    {
        printf("%s", szBuffer);
    }

    printf("\n");
    cerrarArchivo();

    sprintf(nuevoNombre, "lote_%03d.dat", contador);
    if(rename("lote.dat", nuevoNombre) == 0)
    {
        printf("\nLote procesado. Renombrado a %s\n", nuevoNombre);
        contador = contador + 1;
    } else
    {
        printf("\nError al renombrar lote.dat\n");
    }

}


int main(int argc, char *argv[])
{
    int id_semaforo;
    id_semaforo =  creoSemaforo();

    while(1)
    {
        esperaSemaforo(id_semaforo);

        reservarVuelos();

        levantaSemaforo(id_semaforo);
        usleep(INTERVALO_PARTIDA*1000);

    }



    return 0;
}

