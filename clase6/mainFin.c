#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semaforo.h"
#include "unistd.h"
#include "global.h"
#include "archivos.h"
#include "time.h"
#include "funciones.h"
#include "memoria.h"
#include "clave.h"
#include "sys/ipc.h"
#include "sys/shm.h"

typedef struct
{
    int numero;
    char letra;
} dato;


int main(int argc, char *argv[])
{

    int id_semaforo;
    int id_memoria;
    dato *memoria = NULL;
    int i;

    memoria = (dato*)creo_memoria(sizeof(dato)*10, &id_memoria, 33);

    id_semaforo = creoSemaforo();

    while (1)
    {
        esperaSemaforo(id_semaforo);

        printf("Leemos la memoria\n");

        for(i = 0; i < 10; i++)
        {
            printf("Leido %d %c\n", memoria[i].numero, memoria[i].letra);
            
        }
        printf("Dejamos de leer la memoria\n");


        levantaSemaforo(id_semaforo);

        sleep(15);


    }

    shmdt((char *)memoria);
    shmctl(id_memoria, IPC_RMID, (struct shmid_ds *)NULL);


    return 0;
}

