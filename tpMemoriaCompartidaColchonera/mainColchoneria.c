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

#define LARGO_NOMBRE 25

typedef struct
{
    int codigo;
    char cantidad;
    char nombre[LARGO_NOMBRE];
} Descripcion;

void actualizarStock(Descripcion *memoria)
{
    int i;

    for(i = 0; i < 5; i++)
    {
        if(memoria[i].cantidad < 10)
        {
            memoria[i].cantidad = memoria[i].cantidad + 1;
            printf("\nSe ha sumado una unidad de stock al colchon %s\n", memoria[i].nombre);
        }
    }
}

void mostrarStock(Descripcion *memoria)
{
    int i;

    printf("\n----- Mostramos stock actual -----");

    for(i = 0; i < 5; i++)
    {

        printf("\nStock de %s: %d\n", memoria[i].nombre, memoria[i].cantidad);

    }

    printf("\n---------");

}


void setRegistros(Descripcion *memoria)
{

    int i;

    for(i = 0; i < 5; i++)
    {
        memoria[i].codigo = i + 1;
        memoria[i].cantidad = 10;
    }

    strcpy(memoria[1].nombre, "SUAVESTAR");
    strcpy(memoria[2].nombre, "CANNON");
    strcpy(memoria[3].nombre, "SIMMONS");
    strcpy(memoria[4].nombre, "BELMO");
    strcpy(memoria[0].nombre, "PIERO");
}


int main(int argc, char *argv[])
{

    int id_semaforo;
    int id_memoria;
    Descripcion *memoria = NULL;

    memoria = (Descripcion*)creo_memoria(sizeof(Descripcion) * 5, &id_memoria, 33);
    memset(memoria, 0, sizeof(Descripcion) * 5);


    /*  Seteamos los registros de nuestra estructura */
    setRegistros(memoria);
    

    srand(time(NULL));

    id_semaforo = creoSemaforo();

    inicioSemaforo(id_semaforo, VERDE);

    while (1)
    {

        esperaSemaforo(id_semaforo);


        /*  Primero mostramos */
        mostrarStock(memoria);

        /*  Ahora actualizamos */
        actualizarStock(memoria);
        

        levantaSemaforo(id_semaforo);

        usleep(500 * 1000);

    }

    


    return 0;
}

