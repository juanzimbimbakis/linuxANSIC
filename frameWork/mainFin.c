#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semaforo.h"
#include "unistd.h"
#include "global.h"
#include "archivos.h"
#include "time.h"
#include "funciones.h"


int main(int argc, char *argv[])
{

    int id_semaforo;

    id_semaforo = creoSemaforo();

    while (1)
    {
        esperaSemaforo(id_semaforo);

        printf("Chau desde fin\n");

        levantaSemaforo(id_semaforo);

        usleep(500 * 1000);
    }


    return 0;
}

