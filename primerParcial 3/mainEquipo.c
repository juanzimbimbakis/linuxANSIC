#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semaforo.h"
#include "unistd.h"
#include "global.h"
#include "archivos.h"
#include "time.h"
#include "funciones.h"

void escribir(int equipo, int numeroIngresado, int *golesAFavor, int maximoGoles, int numeroAleatorio)
{

    char szBuffer[10];
    memset(szBuffer, 0, sizeof(szBuffer));

    if(equipo == 1)
    {
        if(!abrirArchivo("equipo1.dat", "w"))
        {
            printf("Error al abrir equipo1.dat\n");
        }

        sprintf(szBuffer, "%d %d %d %d", numeroIngresado, *golesAFavor, maximoGoles, numeroAleatorio);

        if(!escribirArchivo(szBuffer))
        {
            printf("Error al escribir equipo1.dat\n");
        }

        cerrarArchivo();

    }


    if(equipo == 2)
    {
        if(!abrirArchivo("equipo2.dat", "w"))
        {
            printf("Error al abrir equipo2.dat\n");
        }

        sprintf(szBuffer, "%d %d %d %d", numeroIngresado, *golesAFavor, maximoGoles, numeroAleatorio);

        if(!escribirArchivo(szBuffer))
        {
            printf("Error al escribir equipo1.dat\n");
        }

        cerrarArchivo();

    }


}

void jugarPartido(int equipo, int maximoGoles,int *golesAFavor)
{
    char szBuffer[10];
    int numeroIngresado = 0;
    int numeroAleatorio = 0;

    memset(szBuffer, 0, sizeof(szBuffer));

    printf("Equipo %d.\n", equipo);
    
    printf("Ingrese un numero del 1 al 3: ");
    scanf("%d", &numeroIngresado);
    while(numeroIngresado < 1 || numeroIngresado > 3)
    {
        printf("Error! Ingrese un numero del 1 al 3: ");
        scanf("%d", &numeroIngresado);
    }

    numeroAleatorio = devolverNumeroAleatorio(1, 3);


    /*  int equipo, int numeroIngresado, int *golesAFavor, int maximoGoles, int numeroAleatorio */
    if(numeroIngresado == numeroAleatorio)
    {
        (*golesAFavor) = (*golesAFavor) + 1;
    } 

    escribir(equipo, numeroIngresado, golesAFavor, maximoGoles, numeroAleatorio);

}


int main(int argc, char *argv[])
{

    int id_semaforo;
    int golesAFavor = 0;
    int equipo = 0;
    int maximoGoles = 0;

    if(argc != 3)
    {
        printf("Error! Cantidad de parametros incorrecta\n");
        return 1;
    }

    equipo = atoi(argv[1]);
    maximoGoles = atoi(argv[2]);

    if(equipo != 1 && equipo != 2)
    {
        printf("Error! Debe pasar por parametro 1 o 2 !!!\n");
        return 1;
    }

    if(maximoGoles <= 0 || maximoGoles > 3)
    {
        printf("Error! El maximo de goles es 3 y tiene que ser mayor a 0!\n");
        return 1;
    }

    id_semaforo = creoSemaforo();
    
    srand(time(NULL));

    if(equipo == 1)
    {
        inicioSemaforo(id_semaforo, VERDE);
    }


    while (1)
    {

        esperaSemaforo(id_semaforo);

        jugarPartido(equipo, maximoGoles, &golesAFavor);

        levantaSemaforo(id_semaforo);

        usleep(500 * 1000);

    }


    return 0;
}

