#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semaforo.h"
#include "unistd.h"
#include "global.h"
#include "archivos.h"


typedef struct 
{
    int id_vuelo;
    char destino[50];
    int cantidad_pasajeros;
} EstructuraVuelo;

void actualizarEstadisticas(char *szBuffer, EstructuraVuelo *estructuraVuelo, int *cantidadVuelos)
{
    int id;
    int i;
    char destino[50];
    char nombre[50];

    /* Primero vamos a "desarmar" la linwa que recibimos del szBuffer */
    sscanf(szBuffer, "%d %s %[^\n]", &id, destino, nombre);


    /* Ahora buscamos si el vuelo ya existe en el array con los vuelos */
    for(i = 0; i < *cantidadVuelos; i++)
    {
        if(estructuraVuelo[i].id_vuelo == id)
        {
            estructuraVuelo[i].cantidad_pasajeros = estructuraVuelo[i].cantidad_pasajeros + 1;
            return;
        }
    }

    /* Si no encontramso el id, creamos un nuevo vuelo en el array */

    estructuraVuelo[*cantidadVuelos].id_vuelo = id;
    strcpy(estructuraVuelo[*cantidadVuelos].destino, destino);
    estructuraVuelo[*cantidadVuelos].cantidad_pasajeros = 1; /* porque seria el primer pasajero */
    (*cantidadVuelos) = (*cantidadVuelos) + 1; /* dejamos guardado que hay un vuelo mas */




}


void mostrarEstadisticas(EstructuraVuelo *estructuraVuelo, int *cantidadVuelos)
{
    /* Aca tranquilamente podriamos recibir solo int cantidadVuelos y no la direccion (&) de la variable, lo hacemos para practicar nomas */
    int i;

    printf("\n Estadisticas de vuelos procesados. \n");
    printf("ID Vuelo        Destino        Cantidad Pasajeros \n");

    for(i = 0; i < *cantidadVuelos; i++)
    {
        printf("%i        %s        %i \n", estructuraVuelo[i].id_vuelo, estructuraVuelo[i].destino, estructuraVuelo[i].cantidad_pasajeros);
    }
}




void reservarVuelos(void)
{
    char szBuffer[100];
    static int contador = 0;
    char nuevoNombre[20];
    EstructuraVuelo estructuraVuelo[15];
    int cantidadVuelos = 0;

    if(!abrirArchivo("lote.dat", "r"))
    {
        printf("Error al abrir archivo lote.dat para lectura. \n");
        return;
    }

    while(leerArchivo(szBuffer, sizeof(szBuffer)) == TRUE)
    {
        actualizarEstadisticas(szBuffer, estructuraVuelo, &cantidadVuelos);
        printf("%s", szBuffer);
    }

    printf("\n");
    cerrarArchivo();

    

    sprintf(nuevoNombre, "lote_%03d.dat", contador);
    if(rename("lote.dat", nuevoNombre) == 0)
    {
        printf("\nLote procesado. Renombrado a %s\n", nuevoNombre);
        contador = contador + 1;
    } else
    {
        printf("\nError al renombrar lote.dat\n");
    }


    mostrarEstadisticas(estructuraVuelo, &cantidadVuelos);
    printf("\n");

}


int main(int argc, char *argv[])
{
    int id_semaforo;
    id_semaforo =  creoSemaforo();

    while(1)
    {
        esperaSemaforo(id_semaforo);

        reservarVuelos();

        levantaSemaforo(id_semaforo);
        usleep(INTERVALO_PARTIDA*1000);

    }



    return 0;
}

