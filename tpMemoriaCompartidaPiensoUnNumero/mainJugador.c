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

    


    memoria = (Juego*)creo_memoria(sizeof(Juego), &id_memoria, 33);

    id_semaforo = creoSemaforo();

    printf("\nBienvenido a Pienso un numero.");
    printf("\nRealizamos esto con memoria compartida...");
    printf("\nIngrese su nombre: ");
    scanf(" %[^\n]", memoria->nombreJugdor);

    while (1)
    {
        esperaSemaforo(id_semaforo);

        printf("\n local: %d -- pensado: %d\n", localPiensoUnNumero, memoria->numeroPensado);

        if(memoria->numeroPensado == 0 && memoria->estadoAcierto == 0)
        {
            /*  Generamos del 1 al 99 un aleatorio */
            localPiensoUnNumero = devolverNumeroAleatorio(1, 10);

            memoria->numeroPensado = localPiensoUnNumero;
            memoria->contador = memoria->contador + 1;
        }

        if(memoria->numeroPensado != 0 && memoria->estadoAcierto == 1)
        {
            printf("\nFelicitaciones!! Ha ganado :)");
            printf("\nCantidad de intentos: %d\n", memoria->contador);
            break;
        }


        levantaSemaforo(id_semaforo);

        sleep(1);


    }

    shmdt((char *)memoria);
    shmctl(id_memoria, IPC_RMID, (struct shmid_ds *)NULL);


    return 0;
}

