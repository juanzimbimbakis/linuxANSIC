#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semaforo.h"
#include "unistd.h"
#include "global.h"


int main(int argc, char *argv[])
{
    char cadena[200]; /* Un array lo suficientemente grande como para guardar la línea más larga del fichero */

    int id_semaforo;
    id_semaforo =  creoSemaforo();

    while(1)
    {
        esperaSemaforo(id_semaforo);

        printf("\nCHAU\n");

        levantaSemaforo(id_semaforo);
        usleep(INTERVALO_PARTIDA*1000);

    }



    return 0;
}

