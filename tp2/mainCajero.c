#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semaforo.h"
#include "unistd.h"
#include "global.h"
#include "archivos.h"

typedef struct
{
    int monto;
    int medioPago;
} Deposito;

void cargarDepositos(int *numeroCajero)
{
    char szBuffer[100];
    char nombreArchivo[20];
    int continuar = 1;
    int i;
    int n;
    Deposito deposito;
    deposito.monto = 0;
    deposito.medioPago = 0;


    /* Armamos el nombre con el numero de cajero */
    sprintf(nombreArchivo, "cajero%d.dat", *numeroCajero);

    if(!abrirArchivo(nombreArchivo, "a"))
    {
        printf("Error al abrir el archivo para escritura.\n");
        return;
    }

    while(continuar)
    {

        printf("Bievenido al Banco TP2 de Laboratorio 3!\n");
        printf("Ingrese el numero de depositos a realizar (minimo 1, maximo 20): ");
        scanf("%d", &n);

        while (n < 1 || n > 20)
        {
            printf("Error! Ingrese un numero valido entre 1 y 20: ");
            scanf("%d", &n);
        }


        for(i = 0; i < n; i++)
        {
            printf("\n Ingrese el monto del deposito: ");
            scanf("%d", &deposito.monto);
            while(deposito.monto <= 0)
            {
                printf("Error! Ingrese un monto valido mayor a 0: ");
                scanf("%d", &deposito.monto);
            }

            printf("\n Ingrese el medio de pago (0: Cheque, 1: Efectivo): ");
            scanf("%d", &deposito.medioPago);
            while(deposito.medioPago < 0 || deposito.medioPago > 1)
            {
                printf("Error! Ingrese un medio de pago valido (0: Cheque, 1: Efectivo): ");
                scanf("%d", &deposito.medioPago);
            }

            sprintf(szBuffer, "%d %d\n", deposito.monto, deposito.medioPago);

            if(!escribirArchivo(szBuffer))
            {
                printf("Error al escribir archivo.\n");
            }

        }

        cerrarArchivo();

        printf("Desea realizar otro deposito? (1: Si, 0: No): ");
        scanf("%d", &continuar);
        while (continuar < 0 || continuar > 1)
        {
            printf("Error! Ingrese un valor valido (1: Si, 0: No): ");
            scanf("%d", &continuar);
        }

        if(continuar == 1)
        {
            if(!abrirArchivo(nombreArchivo, "a"))
            {
                printf("Error al abrir el archivo para escritura.\n");
                return;
            }
        }


    }

}


int main(int argc, char *argv[])
{

    int numeroCajero;
    int idSemaforo;

    if(argc != 2)
    {
        printf("Error! Tiene que enviar un parametro del numero de cajero.\n");
        return 1;
    } 

    numeroCajero = atoi(argv[1]);

    if(numeroCajero < 1 || numeroCajero > 3)
    {
        printf("Error! El numero de cajero tiene que ser entre 1 y 3. Ejecute nuevamente el programa con los parametros correctos\n");
        return 1;
    }


    idSemaforo = creoSemaforo();

    inicioSemaforo(idSemaforo, VERDE);

    while(1)
    {
        esperaSemaforo(idSemaforo);

        cargarDepositos(&numeroCajero);

        levantaSemaforo(idSemaforo);
        usleep(2000*1000);
    }
    

    


    return 0;
}
