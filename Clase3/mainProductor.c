#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semaforo.h"
#include "unistd.h"
#include "global.h"

int main(int argc,char *argv[])
{
    char cadena[200]; /* Un array lo suficientemente grande como para guardar la línea más larga del fichero */
    int numero_producto=0, numero_partida=0;

    FILE *productor;

    int id_semaforo;

    id_semaforo =  creoSemaforo();

    inicioSemaforo(id_semaforo, VERDE);

    while (1)
    {

        esperaSemaforo(id_semaforo);

        printf("\nHOLA\n");

        levantaSemaforo(id_semaforo);
        usleep(10*1000);
    }




    return 0;
}

