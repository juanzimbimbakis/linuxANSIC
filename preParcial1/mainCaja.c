#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semaforo.h"
#include "unistd.h"
#include "global.h"
#include "archivos.h"

int calcularTotal(int cantidadPedidos, int monto)
{
    return cantidadPedidos * monto;
}

void procesarPedido(int *numeroCaja)
{
    char szBuffer[100];
    int cantidadPedidos;
    int monto;
    char descripcion[100];
    int total;
    cantidadPedidos = 0;
    monto = 0;
    total = 0;

    printf("Llegamos a procesar pedido --------------------\n");


    if((*numeroCaja) == 1)
    {
        if(!abrirArchivo("cajero1.dat", "r"))
        {
            printf("Cajero 1 no tiene pedidos \n");
            return;
        }
        

        while(leerArchivo(szBuffer, sizeof(szBuffer)) == TRUE)
        {

            if (sscanf(szBuffer, "%d %d %[^\n]", &cantidadPedidos, &monto, descripcion) == 3)
            {

                total = calcularTotal(cantidadPedidos, monto);
                printf("Caja 1 - Pedido procesado: %d unidades de %s a $%d cada una. Total: $%d\n", cantidadPedidos, descripcion, monto, total);

            }

        
        }
        cerrarArchivo();
        if(abrirArchivo("cajero1.dat", "w") == TRUE)
        {
            cerrarArchivo();
        }
        
    }
    if((*numeroCaja) == 2)
    {
        if(!abrirArchivo("cajero2.dat", "r"))
        {
            printf("Cajero 2 no tiene pedidos \n");
            return;
        }

        while(leerArchivo(szBuffer, sizeof(szBuffer)) == TRUE)
        {
            if (sscanf(szBuffer, "%d %d %[^\n]", &cantidadPedidos, &monto, descripcion) == 3)
            {
                total = calcularTotal(cantidadPedidos, monto);
                printf("Caja 2 - Pedido procesado: %d unidades de %s a $%d cada una. Total: $%d\n", cantidadPedidos, descripcion, monto, total);
            }
        }
        cerrarArchivo();
        if(abrirArchivo("cajero2.dat", "w") == TRUE)
        {
            cerrarArchivo();
        }
    }
    if((*numeroCaja) == 3)
    {
        if(!abrirArchivo("cajero3.dat", "r"))
        {
            printf("Cajero 3 no tiene pedidos \n");
            return;
        }

        while(leerArchivo(szBuffer, sizeof(szBuffer)) == TRUE)
        {
            if (sscanf(szBuffer, "%d %d %[^\n]", &cantidadPedidos, &monto, descripcion) == 3)
            {
                total = calcularTotal(cantidadPedidos, monto);
                printf("Caja 3 - Pedido procesado: %d unidades de %s a $%d cada una. Total: $%d\n", cantidadPedidos, descripcion, monto, total);
            }
        }
        cerrarArchivo();
        if(abrirArchivo("cajero3.dat", "w") == TRUE)
        {
            cerrarArchivo();
        }
    }
}


int main(int argc, char *argv[])
{
    int numeroCaja;
    int id_semaforo;
    numeroCaja = 0;

    if(argc != 2)
    {
        printf("Error! Tiene que enviar un parametro del numero de caja.\n");
        return 1;
    }
    numeroCaja = atoi(argv[1]);

    if(numeroCaja < 1 || numeroCaja > 3)
    {
        printf("Error! El numero de caja tiene que ser entre 1 y 3. Ejecute nuevamente el programa con los parametros correctos\n");
        return 1;
    }

    id_semaforo =  creoSemaforo();


    while(1)
    {
        esperaSemaforo(id_semaforo);


        procesarPedido(&numeroCaja);

        levantaSemaforo(id_semaforo);

        usleep(100*1000);
    }



    return 0;
}

