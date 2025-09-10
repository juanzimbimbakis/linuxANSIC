#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semaforo.h"
#include "unistd.h"
#include "global.h"
#include "archivos.h"

typedef struct
{
    int cantidadEfectivo;
    int totalEfectivo;
    int cantidadCheque;
    int totalCheque;
} EstructuraTesorero;

void actualizarEstadisticasTesorero(char *szBuffer, EstructuraTesorero *tesorero)
{
    int monto;
    int medioPago;
    monto = 0;
    medioPago = 0;

    sscanf(szBuffer, "%d %d", &monto, &medioPago);
    printf("Monto: %d - MedioPago: %d\n", monto, medioPago);
    printf("DEBUG -> szBuffer leido: '%s'\n", szBuffer);


    if(medioPago == 0)
    {
        tesorero->totalCheque = tesorero->totalCheque + monto;
        tesorero->cantidadCheque = tesorero->cantidadCheque + 1;
    } else if (medioPago == 1)
    {
        tesorero->totalEfectivo = tesorero->totalEfectivo + monto;
        tesorero->cantidadEfectivo = tesorero->cantidadEfectivo + 1;
    }
}

void mostrarEstadisticas(EstructuraTesorero *tesorero1, EstructuraTesorero *tesorero2, EstructuraTesorero *tesorero3, EstructuraTesorero *tesoreroTotal)
{
    printf("\n Ultima actualizacion de los depositos. \n");
    printf("Depositos Cajero 1: \n");
    printf("Cantidad Depositos efectivo: %d \n", tesorero1->cantidadEfectivo);
    printf("Total Depositos efectivo: $%d \n", tesorero1->totalEfectivo);
    printf("Cantidad Depositos cheque: %d \n", tesorero1->cantidadCheque);
    printf("Total Depositos cheque: $%d \n", tesorero1->totalCheque);

    printf("\nDepositos Cajero 2: \n");
    printf("Cantidad Depositos efectivo: %d \n", tesorero2->cantidadEfectivo);
    printf("Total Depositos efectivo: $%d \n", tesorero2->totalEfectivo);
    printf("Cantidad Depositos cheque: %d \n", tesorero2->cantidadCheque);
    printf("Total Depositos cheque: $%d \n", tesorero2->totalCheque);

    printf("\nDepositos Cajero 3: \n");
    printf("Cantidad Depositos efectivo: %d \n", tesorero3->cantidadEfectivo);
    printf("Total Depositos efectivo: $%d \n", tesorero3->totalEfectivo);
    printf("Cantidad Depositos cheque: %d \n", tesorero3->cantidadCheque);
    printf("Total Depositos cheque: $%d \n", tesorero3->totalCheque);

    printf("\nDepositos Totales: \n");
    printf("Cantidad Depositos efectivo: %d \n", tesoreroTotal->cantidadEfectivo);
    printf("Total Depositos efectivo: $%d \n", tesoreroTotal->totalEfectivo);
    printf("Cantidad Depositos cheque: %d \n", tesoreroTotal->cantidadCheque);
    printf("Total Depositos cheque: $%d \n", tesoreroTotal->totalCheque);
}





void procesarDepositos(void)
{
    char szBuffer[100];
    char nuevoNombre[20];
    EstructuraTesorero tesorero1;
    EstructuraTesorero tesorero2;
    EstructuraTesorero tesorero3;
    EstructuraTesorero tesoreroTotal;
    int monto;
    int medioPago;
    monto = 0;
    medioPago = 0;
    tesoreroTotal.cantidadCheque = 0;
    tesoreroTotal.totalCheque = 0;
    tesoreroTotal.cantidadEfectivo = 0;
    tesoreroTotal.totalEfectivo = 0;
    tesorero1.cantidadCheque = 0;
    tesorero1.totalCheque = 0;
    tesorero1.cantidadEfectivo = 0;
    tesorero1.totalEfectivo = 0;
    tesorero2.cantidadCheque = 0;
    tesorero2.totalCheque = 0;
    tesorero2.cantidadEfectivo = 0;
    tesorero2.totalEfectivo = 0;
    tesorero3.cantidadCheque = 0;
    tesorero3.totalCheque = 0;
    tesorero3.cantidadEfectivo = 0;
    tesorero3.totalEfectivo = 0;


    /*
    Tambien puedo hacerlo cuando lo declaro, por ejemplo si es un aaray
    EstructuraTesorero tesorero1[10] = {0};
    EstructuraTesorero tesorero2[10] = {0};
    EstructuraTesorero tesorero3[10] = {0};
    */


    if(abrirArchivo("cajero1.dat", "r") == TRUE)
    {
        printf("Procesando archivo cajero1.dat\n");
        while(leerArchivo(szBuffer, sizeof(szBuffer)) == TRUE)
        {
            if (sscanf(szBuffer, "%d %d", &monto, &medioPago) == 2)
            {
                actualizarEstadisticasTesorero(szBuffer, &tesorero1);
            }

        }
        tesoreroTotal.cantidadEfectivo = tesoreroTotal.cantidadEfectivo + tesorero1.cantidadEfectivo;
        tesoreroTotal.totalEfectivo = tesoreroTotal.totalEfectivo + tesorero1.totalEfectivo;
        tesoreroTotal.cantidadCheque = tesoreroTotal.cantidadCheque + tesorero1.cantidadCheque;
        tesoreroTotal.totalCheque = tesoreroTotal.totalCheque + tesorero1.totalCheque;
        cerrarArchivo();
    } 
    if (abrirArchivo("cajero2.dat", "r") == TRUE) 
    {
        printf("Procesando archivo cajero2.dat\n");
        while(leerArchivo(szBuffer, sizeof(szBuffer)) == TRUE)
        {
            if (sscanf(szBuffer, "%d %d", &monto, &medioPago) == 2)
            {
                actualizarEstadisticasTesorero(szBuffer, &tesorero2);
            }
        }
        cerrarArchivo();
        tesoreroTotal.cantidadEfectivo = tesoreroTotal.cantidadEfectivo + tesorero2.cantidadEfectivo;
        tesoreroTotal.totalEfectivo = tesoreroTotal.totalEfectivo + tesorero2.totalEfectivo;
        tesoreroTotal.cantidadCheque = tesoreroTotal.cantidadCheque + tesorero2.cantidadCheque;
        tesoreroTotal.totalCheque = tesoreroTotal.totalCheque + tesorero2.totalCheque;
    }
    if (abrirArchivo("cajero3.dat", "r") == TRUE)
    {
        printf("Procesando archivo cajero3.dat\n");
        while(leerArchivo(szBuffer, sizeof(szBuffer)) == TRUE)
        {
            if (sscanf(szBuffer, "%d %d", &monto, &medioPago) == 2)
            {
                actualizarEstadisticasTesorero(szBuffer, &tesorero3);
            }
        }
        cerrarArchivo();
        tesoreroTotal.cantidadEfectivo = tesoreroTotal.cantidadEfectivo + tesorero3.cantidadEfectivo;
        tesoreroTotal.totalEfectivo = tesoreroTotal.totalEfectivo + tesorero3.totalEfectivo;
        tesoreroTotal.cantidadCheque = tesoreroTotal.cantidadCheque + tesorero3.cantidadCheque;
        tesoreroTotal.totalCheque = tesoreroTotal.totalCheque + tesorero3.totalCheque;
    } 

    mostrarEstadisticas(&tesorero1, &tesorero2, &tesorero3, &tesoreroTotal);




    
}


int main(int argc, char *argv[])
{

    int idSemaforo;

    idSemaforo = creoSemaforo();

    while(1)
    {
        esperaSemaforo(idSemaforo);

        printf("Tesorero ejecutando...\n");
        procesarDepositos();

        levantaSemaforo(idSemaforo);
        usleep(500*1000);
    }


    return 0;
}
