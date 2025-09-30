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

void imprimirPantalla(EstructuraVia *memoria, int n)
{
    int i;

    printf("\n---------  Mostramos cantidad de autos por peaje/via ---------\n");
    for(i = 0; i < n; i++)
    {

        printf("\nCantidad de autos en el peaje/via %d: %d", i+1, memoria[i].cantidadAutos);

    }
    printf("\n------------------\n");
}

void anotarLimpiezas(int *contador)
{
    char szBuffer[10];
    memset(szBuffer, 0, sizeof(szBuffer));


    if(!abrirArchivo("limpiezas.dat", "w"))
    {
        printf("\nError al abrir limpiezas.dat");
    }

    sprintf(szBuffer, "%d", *contador);

    if(!escribirArchivo(szBuffer))
    {
        printf("\nError al escribir limpiezas.dat");
    }

    cerrarArchivo();
}

void atenderPeajes(EstructuraVia *memoria, int n, int *i, int *contador)
{
    if(memoria[(*i)].cantidadAutos > 10)
    {
        (*contador) = (*contador) + 1;

        anotarLimpiezas(contador);

        memoria[(*i)].cantidadAutos = 0;
        printf("\n Se dejó pasar todos los autos en la via %d\n", (*i)+1);
    } else
    {
        if((*i) + 1 == n && memoria[(*i)].cantidadAutos > 0)
        {
            memoria[(*i)].cantidadAutos = memoria[(*i)].cantidadAutos - 1;
            printf("\nRestando un auto al peaje %d\n", (*i)+1);
            ((*i)) = 0;
        } else if (memoria[(*i)].cantidadAutos > 0)
        {
            memoria[(*i)].cantidadAutos = memoria[(*i)].cantidadAutos - 1;
            printf("\nRestando un auto al peaje %d\n", (*i)+1);
            (*i)++; 
        }
    }
}





int main(int argc, char *argv[])
{

    int id_semaforo;
    int id_memoria;
    int i;
    EstructuraVia *memoria = NULL;
    int duracion = 15; /*  Tiempo que queremos ejecutar el programa */
    time_t empezamos = time(NULL); /*  Nos devuelve segundos en teoria */
    int n = 0;
    int aleatorio = 0;
    int contador = 0;
    

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



    i = 0;


    memoria = (EstructuraVia*)creo_memoria(sizeof(EstructuraVia) * n, &id_memoria, 33);
    memset(memoria, 0, sizeof(EstructuraVia) * n);

    srand(time(NULL));


    id_semaforo = creoSemaforo();

    inicioSemaforo(id_semaforo, VERDE);

    while (time(NULL) - empezamos < duracion)
    {

        esperaSemaforo(id_semaforo);


        /*  Y aca atendemos los peajes  */
        atenderPeajes(memoria, n, &i, &contador);

        /*  Imprimimos en pantalla: */
        imprimirPantalla(memoria, n);


        levantaSemaforo(id_semaforo);

        aleatorio = devolverNumeroAleatorio(100, 5000);

        usleep(aleatorio * 1000);

    }

    printf("\n Ha terminado el programa\n");


    return 0;
}

