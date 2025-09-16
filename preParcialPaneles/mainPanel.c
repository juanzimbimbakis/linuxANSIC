#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semaforo.h"
#include "unistd.h"
#include "global.h"
#include "archivos.h"


void accionPanel(int parametro)
{
    char szBuffer[50];

    if(parametro == 1)
    {
        if(!abrirArchivo("panel1.dat", "r"))
        {
            printf("Error al abrir archivo panel1.dat para lectura\n");
        }

        while(leerArchivo(szBuffer, sizeof(szBuffer)) == TRUE)
        {
            printf("%s", szBuffer);
        }

        cerrarArchivo();

        if(!abrirArchivo("panel1.dat", "w"))
        {
            printf("Error al abrir archivo panel1.dat para borrar\n");
        }

        cerrarArchivo();

    }

    if(parametro == 2)
    {
        if(!abrirArchivo("panel2.dat", "r"))
        {
            printf("Error al abrir archivo panel2.dat para lectura\n");
        }

        while(leerArchivo(szBuffer, sizeof(szBuffer)) == TRUE)
        {
            printf("%s", szBuffer);
        }

        cerrarArchivo();

        if(!abrirArchivo("panel2.dat", "w"))
        {
            printf("Error al abrir archivo panel2.dat para borrar\n");
        }

        cerrarArchivo();

    }

    if(parametro == 3)
    {
        if(!abrirArchivo("panel3.dat", "r"))
        {
            printf("Error al abrir archivo panel3.dat para lectura\n");
        }

        while(leerArchivo(szBuffer, sizeof(szBuffer)) == TRUE)
        {
            printf("%s", szBuffer);
        }

        cerrarArchivo();

        if(!abrirArchivo("panel3.dat", "w"))
        {
            printf("Error al abrir archivo panel3.dat para borrar\n");
        }

        cerrarArchivo();

    }

}


int main(int argc, char *argv[])
{

    int id_semaforo;
    int parametro;

    if(argc != 2)
    {
        printf("Error! No se recibió el segundo parametro\n");
        return 1;
    }

    parametro = atoi(argv[1]);
    while(parametro != 1 && parametro != 2 && parametro != 3)
    {
        printf("Error! El parametro es 1, 2 o 3! \n");
        return 1;
    }

    id_semaforo = creoSemaforo();

    while (1)
    {
        esperaSemaforo(id_semaforo);

        accionPanel(parametro);

        levantaSemaforo(id_semaforo);

        usleep(100 * 1000);
    }


    return 0;
}

