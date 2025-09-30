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

void vender(Descripcion *memoria)
{
    int codigo = 0;
    int cantidad = 0;


    printf("\nVamos a vender...\n");
    printf("\nIngrese codigo de colchon a vender (1 a 5): ");
    scanf("%d", &codigo);
    while(codigo < 1 || codigo > 5)
    {
        printf("\nError! Ingrese codigo de colchon a vender (1 a 5): ");
        scanf("%d", &codigo);
    }

    printf("\nIngrese cantidad a restar del colchon de codigo %d (1 a 5): ", codigo);
    scanf("%d", &cantidad);
    while(cantidad < 1 || cantidad > 5)
    {
        printf("\nError! Ingrese cantidad de colchon a vender (1 a 5): ");
        scanf("%d", &codigo);
    }

    while (((memoria[codigo - 1].cantidad) - cantidad) < 0)
    {
        printf("\nError en la operacion! Stock insuficiente");
        printf("\nIngrese cantidad a restar del colchon de codigo %d (1 a 5): ", codigo);
        scanf("%d", &cantidad);

    }
    
    (memoria[codigo - 1].cantidad) = (memoria[codigo - 1].cantidad) - cantidad;
    printf("\nSe ha restado correctamente %d unidades al colchon %d\n", cantidad, codigo);



}


int main(int argc, char *argv[])
{

    int id_semaforo;
    int id_memoria;
    Descripcion *memoria = NULL;

    memoria = (Descripcion*)creo_memoria(sizeof(Descripcion) * 5, &id_memoria, 33);
    


    id_semaforo = creoSemaforo();

    while (1)
    {
        esperaSemaforo(id_semaforo);


        vender(memoria);
        


        levantaSemaforo(id_semaforo);

        usleep(600 * 1000);


    }

    shmdt((char *)memoria);
    shmctl(id_memoria, IPC_RMID, (struct shmid_ds *)NULL);


    return 0;
}

