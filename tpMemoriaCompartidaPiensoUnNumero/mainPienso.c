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
    char nombreJugdor[30];
    int numeroPensado;
    int estadoAcierto;
    int contador;
} Juego;


int main(int argc, char *argv[])
{

    int id_semaforo;
    int id_memoria;
    Juego *memoria = NULL;
    int localPiensoUnNumero;
    localPiensoUnNumero = 0;

    srand(time(NULL));

    /*  Generamos del 1 al 99 un aleatorio */
    localPiensoUnNumero = devolverNumeroAleatorio(1, 10);

    memoria = (Juego*)creo_memoria(sizeof(Juego), &id_memoria, 33);

    memset(memoria, 0, sizeof(Juego));
    memoria->contador = 1;

    

    id_semaforo = creoSemaforo();

    inicioSemaforo(id_semaforo, VERDE);

    while (1)
    {

        esperaSemaforo(id_semaforo);

        printf("\n local: %d -- pensado: %d\n", localPiensoUnNumero, memoria->numeroPensado);

        if(memoria->numeroPensado != 0 && memoria->estadoAcierto == 0)
        {
            if(memoria->numeroPensado == localPiensoUnNumero)
            {
                memoria->estadoAcierto = 1;
                printf("\nNombre del ganador: %s\n", memoria->nombreJugdor);
                levantaSemaforo(id_semaforo);
                break;

            } else
            {
                memoria->numeroPensado = 0;
                memoria->estadoAcierto = 0;
            }
        }


        levantaSemaforo(id_semaforo);

        sleep(1);

    }

    


    return 0;
}

