#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semaforo.h"
#include "unistd.h"
#include "global.h"
#include "archivos.h"
#include "time.h"
#include "funciones.h"

int mostrarResultados(void)
{
    char szBuffer1[10];
    char szBuffer2[10];
    int numeroIngresado1 = 0;
    int golesAFavor1 = 0;

    int maximoGoles = 0;

    int numeroAleatorio1 = 0;
    int numeroIngresado2 = 0;
    int golesAFavor2 = 0;
    
    int numeroAleatorio2 = 0;

    memset(szBuffer1, 0, sizeof(szBuffer1));
    memset(szBuffer2, 0, sizeof(szBuffer2));


    if(!abrirArchivo("equipo1.dat", "r"))
    {
        printf("Error al abrir equipo1.dat para lectura\n");
    }

    /*   numeroIngresado, *golesAFavor, maximoGoles, numeroAleatorio */

    while(leerArchivo(szBuffer1, sizeof(szBuffer1)) == TRUE)
    {
        sscanf(szBuffer1, "%d %d %d %d", &numeroIngresado1, &golesAFavor1, &maximoGoles, &numeroAleatorio1);

    }

    cerrarArchivo();

    if(!abrirArchivo("equipo2.dat", "r"))
    {
        printf("Error al abrir equipo2.dat para lectura\n");
    }

    /*   numeroIngresado, *golesAFavor, maximoGoles, numeroAleatorio */

    while(leerArchivo(szBuffer2, sizeof(szBuffer2)) == TRUE)
    {
        sscanf(szBuffer2, "%d %d %d %d", &numeroIngresado2, &golesAFavor2, &maximoGoles, &numeroAleatorio2);

    }

    cerrarArchivo();

    printf("\n--------------------------\n");
    printf("Actualizacion equipo 1:\n");

    printf("Numero aleatorio 1: %d\n", numeroAleatorio1);
    printf("Numero ingresado 1: %d\n", numeroIngresado1);
    printf("Goles a favor 1: %d\n", golesAFavor1);


    printf("\n--------------------------\n");
    printf("Actualizacion equipo 2:\n");

    printf("\nNumero aleatorio 2: %d\n", numeroAleatorio2);
    printf("Numero ingresado 2: %d\n", numeroIngresado2);
    printf("Goles a favor 2: %d\n", golesAFavor2);
    
    if(golesAFavor1 == maximoGoles && golesAFavor2 != maximoGoles)
    {
        printf("\n--- TENEMOS GANADOR ---\n");
        printf("Ha ganado el equipo 1!!!!\n");

        printf("Resultado del partido:\n");
        printf("%d a %d para equipo 1\n", golesAFavor1, golesAFavor2);
        return 1;
    }

    if(golesAFavor2 == maximoGoles && golesAFavor1 != maximoGoles)
    {
        printf("\n--- TENEMOS GANADOR ---\n");
        printf("Ha ganado el equipo 2!!!!\n");

        printf("Resultado del partido:\n");
        printf("%d a %d para equipo 2\n", golesAFavor2, golesAFavor1);
        return 1;
    }

    if(golesAFavor1 == maximoGoles && golesAFavor2 == maximoGoles)
    {
        printf("\n--- TENEMOS UN EMPATE ---\n");

        printf("Resultado del partido:\n");
        printf("Igualdad de %d a %d\n", golesAFavor2, golesAFavor1);
        return 1;
    }

    return 0;

}


int main(int argc, char *argv[])
{

    int id_semaforo;

    id_semaforo = creoSemaforo();

    while (1)
    {
        esperaSemaforo(id_semaforo);

        if(mostrarResultados() == 1)
        {
            break;
        }

        levantaSemaforo(id_semaforo);

        usleep(500 * 1000);
    }


    return 0;
}

