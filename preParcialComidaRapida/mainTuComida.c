#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semaforo.h"
#include "unistd.h"
#include "global.h"
#include "archivos.h"

typedef struct 
{
    char tipoMenu;
    int postre;
    int precioFinal;
} Pedido;

typedef struct
{
    int acumulado;
    int contador;
    Pedido arrayPedidos[15];
} TotalPedidos;

void acumularPedidos(TotalPedidos *totalPedidos, Pedido *pedido)
{
    
    totalPedidos->arrayPedidos[totalPedidos->contador] = *pedido;
    totalPedidos->contador ++;
    totalPedidos->acumulado = totalPedidos->acumulado + pedido->precioFinal;

}

void escribir(Pedido *pedido, TotalPedidos *totalPedidos)
{
    char szBuffer[20];
    if(pedido->tipoMenu == 'a')
    {
        if(!abrirArchivo("sistemaA.dat", "w"))
        {
            printf("Error al abrir archivo\n");
        }

        sprintf(szBuffer, "%d %d", totalPedidos->contador, totalPedidos->acumulado);

        if(!escribirArchivo(szBuffer))
        {
            printf("Error al escribir menu\n");
        }
        cerrarArchivo();

    } 
    if(pedido->tipoMenu == 'b')
    {
        if(!abrirArchivo("sistemaB.dat", "w"))
        {
            printf("Error al abrir archivo\n");
        }

        sprintf(szBuffer, "%d %d", totalPedidos->contador, totalPedidos->acumulado);

        if(!escribirArchivo(szBuffer))
        {
            printf("Error al escribir menu\n");
        }
        cerrarArchivo();

    } 
    if(pedido->tipoMenu == 'c')
    {
        if(!abrirArchivo("sistemaC.dat", "w"))
        {
            printf("Error al abrir archivo\n");
        }

        sprintf(szBuffer, "%d %d", totalPedidos->contador, totalPedidos->acumulado);

        if(!escribirArchivo(szBuffer))
        {
            printf("Error al escribir menu\n");
        }
        cerrarArchivo();

    } 
    
}


void cargarPedidos(Pedido *pedido, TotalPedidos *totalPedidosA, TotalPedidos *totalPedidosB, TotalPedidos *totalPedidosC)
{
    int continuar = 1;

    

    printf("Bienvenido a comida palermo hollywood !\n");


    while (continuar)
    {

        printf("Ingrese menu a comprar ('a', 'b', 'c'): ");
        scanf(" %c", &pedido->tipoMenu);

        printf("\nQuiere sumar poster? (+ $200) (1: sí, 0: no): ");
        scanf("%d", &pedido->postre);

        if(pedido->tipoMenu == 'a')
        {
            pedido->precioFinal = 1000;
            

            if(pedido->postre == 1)
            {
                pedido->precioFinal = pedido->precioFinal + 200;
            }

            
            acumularPedidos(totalPedidosA, pedido);
            escribir(pedido, totalPedidosA);

        } else if(pedido->tipoMenu == 'b')
        {
            pedido->precioFinal = 2000;
            

            if(pedido->postre == 1)
            {
                pedido->precioFinal = pedido->precioFinal + 200;
            }

            
            acumularPedidos(totalPedidosB, pedido);
            escribir(pedido, totalPedidosB);

        } else if(pedido->tipoMenu == 'c')
        {
            pedido->precioFinal = 3000;
            

            if(pedido->postre == 1)
            {
                pedido->precioFinal = pedido->precioFinal + 200;
            }

            acumularPedidos(totalPedidosC, pedido);
            escribir(pedido, totalPedidosC);

        }

        

        

        



        printf("\nDesea comprar otro menu? (si: 1, no: 0): ");
        scanf("%d", &continuar);


    }


}


int main(int argc, char *argv[])
{
    int id_semaforo;

    Pedido pedido;
    TotalPedidos totalPedidosA;
    TotalPedidos totalPedidosB;
    TotalPedidos totalPedidosC;
    pedido.postre = 0;
    pedido.precioFinal = 0;
    pedido.tipoMenu = '\0';

    totalPedidosA.acumulado = 0;
    totalPedidosA.arrayPedidos[0];
    totalPedidosA.contador = 0;

    totalPedidosB.acumulado = 0;
    totalPedidosB.arrayPedidos[0];
    totalPedidosB.contador = 0;

    totalPedidosC.acumulado = 0;
    totalPedidosC.arrayPedidos[0];
    totalPedidosC.contador = 0;


    id_semaforo =  creoSemaforo();

    inicioSemaforo(id_semaforo, VERDE);

    while(1)
    {
        esperaSemaforo(id_semaforo);

        cargarPedidos(&pedido, &totalPedidosA, &totalPedidosB, &totalPedidosC);

        levantaSemaforo(id_semaforo);

        usleep(500*1000);
        
    }
    


    return 0;
}

