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
    int cantidadAutos;
} EstructuraVia;

void insertarAuto(EstructuraVia *memoria, int n)
{
    int i;
    int j = 0;
    int minimo = 0;
    
    minimo = memoria[0].cantidadAutos;

        for(i = 0; i < n; i++)
        {
            if(memoria[i].cantidadAutos < minimo)
            {
                minimo = memoria[i].cantidadAutos;
                j = i;
            }
        }

        memoria[j].cantidadAutos = memoria[j].cantidadAutos + 1;

        printf("\nInsertamos en el peaje/via numero %d un nuevo auto\n", j+1);
}


int main(int argc, char *argv[])
{

    int id_semaforo;
    int id_memoria;
    EstructuraVia *memoria = NULL;
    int n = 0;
    int aleatorio = 0;
    int duracion = 15; /*  Tiempo que queremos ejecutar el programa */
    time_t empezamos = time(NULL); /*  Nos devuelve segundos en teoria */
    



    if(argc != 2)
    {
        fprintf(stderr, "\nError! cantidad de parametros mal pasados\n");
        return 1;
    }

    n = atoi(argv[1]);
    if(n < 1)
    {
        fprintf(stderr, "\nError! Parametro tiene que ser mayor a 0\n");
        return 1;
    }

    srand(time(NULL));


    memoria = (EstructuraVia*)creo_memoria(sizeof(EstructuraVia) * n, &id_memoria, 33);

    id_semaforo = creoSemaforo();

    while (time(NULL) - empezamos < duracion)
    {
        esperaSemaforo(id_semaforo);

        insertarAuto(memoria, n);
        

        levantaSemaforo(id_semaforo);

        aleatorio = devolverNumeroAleatorio(400, 600);

        usleep(aleatorio * 1000);


    }

    shmdt((char *)memoria);
    shmctl(id_memoria, IPC_RMID, (struct shmid_ds *)NULL);

    printf("\n Ha terminado el programa\n");


    return 0;
}

