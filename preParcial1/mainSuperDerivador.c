#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semaforo.h"
#include "unistd.h"
#include "global.h"
#include "archivos.h"

typedef struct
{
    char descripcion[100];
    int precio;
} EstructuraPedido;

void recibirPedidos(void)
{
    char szBuffer[100];
    int continuar = 1;
    EstructuraPedido pedido;
    EstructuraPedido pedidos[100];
    int cantidadPedidos = 0;

    printf("Bienvenido! Vamos a recibir pedidos\n");
    

    while (continuar)
    {
        printf("\nIngrese descripcion del producto: ");
        scanf(" %[^\n]", pedido.descripcion);

        printf("\nIngrese precio del producto: ");
        scanf("%d", &pedido.precio);

        printf("\nIngrese la cantidad de unidades del pedido: ");
        scanf("%d", &cantidadPedidos);

        sprintf(szBuffer, "%d %d %s", cantidadPedidos, pedido.precio, pedido.descripcion);

        if(cantidadPedidos > 0 && cantidadPedidos <= 5)
        {
            if(abrirArchivo("cajero1.dat", "w") == FALSE)
            {
                printf("Error al abrir el archivo para escritura.\n");
                return;
            } else{

                if(!escribirArchivo(szBuffer))
                {
                    printf("Error al cargar pedido.\n");
                }

            }
            

            cerrarArchivo();
        }
        if(cantidadPedidos > 5 && cantidadPedidos <= 10)
        {
            if(abrirArchivo("cajero2.dat", "w") == FALSE)
            {
                printf("Error al abrir el archivo para escritura.\n");
                return;
            }else
            {
                if(!escribirArchivo(szBuffer))
                {
                    printf("Error al cargar pedido.\n");
                }
            }
            cerrarArchivo();

        }
        if(cantidadPedidos > 11)
        {
            if(abrirArchivo("cajero3.dat", "w") == FALSE)
            {
                printf("Error al abrir el archivo para escritura.\n");
                return;
            }else
            {
                if(!escribirArchivo(szBuffer))
                {
                    printf("Error al cargar pedido.\n");
                }
            }
            cerrarArchivo();
        }

        printf("Desea ingresar otro pedido? (1: Si, 0: No): ");
        scanf("%d", &continuar);
        cantidadPedidos = 0;




    }
}


int main(int argc, char *argv[])
{

    int id_semaforo;

    id_semaforo =  creoSemaforo();

    inicioSemaforo(id_semaforo, VERDE);


    while(1)
    {
        esperaSemaforo(id_semaforo);


        recibirPedidos();

        levantaSemaforo(id_semaforo);

        usleep(50*1000);
    }



    return 0;
}

