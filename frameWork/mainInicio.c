#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semaforo.h"
#include "unistd.h"
#include "global.h"
#include "archivos.h"


int main(int argc, char *argv[])
{

    int id_semaforo;

    id_semaforo = creoSemaforo();

    inicioSemaforo(id_semaforo, VERDE);

    while (1)
    {

        esperaSemaforo(id_semaforo);

        printf("Hola desde inicio\n");

        levantaSemaforo(id_semaforo);

        usleep(500 * 1000);

    }


    return 0;
}

