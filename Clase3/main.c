#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "archivos.h"
#include "global.h"


typedef struct
{
    char nombre[30];
    int id;
} Producto;

void escribirProducto(void) /* Pasamos void porque no recibe parametros */
{
    Producto producto;
    char szBuffer[50];
    int continuar = 1;
    int i = 0;
    producto.id = 0; /* Inicializamos el ID del producto */
    /* Abrimos el archivo en modo write , si no existe lo crea */

    if(!abrirArchivo("productos.txt", "w")) /* Si le pasamos "w" borra y vuelve a escribir, si le pasamos "a" lo agrega */
    {
        printf("Error al abrir el archivo para escritura.\n");
        return;
    }

    while(continuar)
    {

        printf("Ingrese nombre del producto: ");
        scanf("%s", producto.nombre);

        for(i = 0; i < 10; i++)
        {
            producto.id = producto.id + 1; /*  Incrementamos el ID del producto */

            sprintf(szBuffer, "%s-%02d", producto.nombre, producto.id);
            /* Escribimos la linea en el buffer y se lo pasamos al escribirArchivo para que lo escriba ahi2 */
            if(!escribirArchivo(szBuffer))
            {
                printf("Error al escribir archivo.\n");
            }

        }

        printf("Desea escribir otro producto? (1: Si, 0: No): ");
        scanf("%d", &continuar);

    }

    cerrarArchivo(); /*  SIEMPRE tenemos que cerrar los archivos */

}


void leerProducto(void) /* x2 */
{
    char szBuffer[50];

    if(!abrirArchivo("productos.txt", "r"))
    {
        printf("Error al abrir el archivo para lectura.\n");
        return;
    }

    while (!feof(archivo))
    {
        /* El feof lo usamos para verificar si llegamos al final del archivo */
        if(leerArchivo(szBuffer, sizeof(szBuffer)) == TRUE)
        {
            printf("%s\n", szBuffer);
        }
    }

    cerrarArchivo(); /* x2 */
}

int main(int argc, char *argv[])
{


    escribirProducto();
    printf("\n----------------------------\n");
    leerProducto();
    printf("\n----------------------------\n");
    printf("Fin del programa.\n");


    /*
    # comentamos

CC = gcc
FLAGS = -Wall -std=gnu89 -pedantic-errors -pthread -O3 -I./

all: clean programaTp

programaTp : Main.c archivos.h global.h
	$(CC) $(FLAGS) -o programaTp Main.c archivos.c global.c


clean:
	rm -f *o programaTp
	

    */


    return 0;
}


