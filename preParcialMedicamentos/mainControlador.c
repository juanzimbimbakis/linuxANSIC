#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semaforo.h"
#include "unistd.h"
#include "global.h"
#include "archivos.h"
#include "time.h"
#include "funciones.h"

typedef struct mainControlador
{
    int tipoMedicamento;
    int colorPastilla;
    int cantidad;
} Medicamento;

int calcularCantidad(Medicamento *arrayMedicamento, int contador)
{
    int i = 0;
    int cantidad = 0;

    for(i = 0; i < contador; i++)
    {
        cantidad = cantidad + arrayMedicamento[i].cantidad;
    }

    return cantidad;
}

void escribir(Medicamento *medicamento, Medicamento *arrayMedicamento, int contador)
{
    char szBuffer[20];
    int cantidadTotal = 0;

    if(medicamento->cantidad == 5)
    {
        if(!abrirArchivo("sistemaA.dat", "w"))
        {
            printf("Error al abrir archivo\n");
        }

        cantidadTotal = calcularCantidad(arrayMedicamento, contador);
        /*  totalidad de medicamentos y pastillas realizadas */
        sprintf(szBuffer, "%d %d", contador, cantidadTotal);

        if(!escribirArchivo(szBuffer))
        {
            printf("Error al escribir medicamento 5\n");
        }

        cerrarArchivo();
    }
    if(medicamento->cantidad == 10)
    {
        if(!abrirArchivo("sistemaB.dat", "w"))
        {
            printf("Error al abrir archivo\n");
        }

        cantidadTotal = calcularCantidad(arrayMedicamento, contador);
        /*  totalidad de medicamentos y pastillas realizadas */
        sprintf(szBuffer, "%d %d", contador, cantidadTotal);

        if(!escribirArchivo(szBuffer))
        {
            printf("Error al escribir medicamento 10\n");
        }

        cerrarArchivo();
    }
    if(medicamento->cantidad == 20)
    {
        if(!abrirArchivo("sistemaC.dat", "w"))
        {
            printf("Error al abrir archivo\n");
        }

        cantidadTotal = calcularCantidad(arrayMedicamento, contador);
        /*  totalidad de medicamentos y pastillas realizadas */
        sprintf(szBuffer, "%d %d", contador, cantidadTotal);

        if(!escribirArchivo(szBuffer))
        {
            printf("Error al escribir medicamento 20\n");
        }

        cerrarArchivo();
    }

}



void realizarMedicamentos(Medicamento *medicamento, Medicamento *arrayMedicamentos5, Medicamento *arrayMedicamentos10, Medicamento *arrayMedicamentos20, int *contador5, int *contador10, int *contador20)
{
    int continuar = 1;

    /*
            (siendo 1 Rojo, 2 Amarillo, 3 Fucsia).
    */

    printf("Bienvenido al sistema Tu Medicamento!\n");

    while (continuar)
    {
        
        medicamento->tipoMedicamento = devolverNumeroAleatorio(1, 3);
        medicamento->colorPastilla = devolverNumeroAleatorio(1, 3);

        printf("Tipo medicamento aleatorio: %d\n", medicamento->tipoMedicamento);
        printf("Color pastilla aleatoria: %d\n", medicamento->colorPastilla);

        printf("Ingrese la cantidad de pastillas a realizar (5, 10, 20): ");
        scanf("%d", &medicamento->cantidad);

        while(medicamento->cantidad != 5 && medicamento->cantidad != 10 && medicamento->cantidad != 20)
        {
            printf("\nError! Ingrese correctamente la cantidad (5, 10, 20): ");
            scanf("%d", &medicamento->cantidad);
        }

        if(medicamento->cantidad == 5)
        {
            arrayMedicamentos5[*contador5] = *medicamento;
            (*contador5) ++;
            escribir(medicamento, arrayMedicamentos5, *contador5);
        }

        if(medicamento->cantidad == 10)
        {
            arrayMedicamentos10[*contador10] = *medicamento;
            (*contador10) ++;
            escribir(medicamento, arrayMedicamentos10, *contador10);
        }

        if(medicamento->cantidad == 20)
        {
            arrayMedicamentos20[*contador20] = *medicamento;
            (*contador20) ++;
            escribir(medicamento, arrayMedicamentos20, *contador20);
        }

        printf("Desea realizar otro medicamento? (SI: 1, NO: 0): ");
        scanf("%d", &continuar);

        while(continuar != 1 && continuar != 0)
        {
            printf("ERROR! Desea realizar otro medicamento? (SI: 1, NO: 0): ");
            scanf("%d", &continuar);
        }

    }
}


int main(int argc, char *argv[])
{

    int id_semaforo;
    Medicamento medicamento;

    Medicamento arrayMedicamentos5[30] = {0};
    Medicamento arrayMedicamentos10[30] = {0};
    Medicamento arrayMedicamentos20[30] = {0};

    int contador5 = 0;
    int contador10 = 0;
    int contador20 = 0;

    medicamento.cantidad = 0;
    medicamento.colorPastilla = 0;
    medicamento.tipoMedicamento = 0;

    srand(time(NULL));



    id_semaforo = creoSemaforo();

    inicioSemaforo(id_semaforo, VERDE);

    while (1)
    {

        esperaSemaforo(id_semaforo);

        realizarMedicamentos(&medicamento, arrayMedicamentos5, arrayMedicamentos10, arrayMedicamentos20, &contador5, &contador10, &contador20);

        levantaSemaforo(id_semaforo);

        usleep(500 * 1000);

    }


    return 0;
}

