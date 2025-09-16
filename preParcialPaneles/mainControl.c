#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semaforo.h"
#include "unistd.h"
#include "global.h"
#include "archivos.h"

typedef struct mainControl
{
    int numeroPanel;
    char mensaje[50];
} Panel;

void escribir(char *szBuffer, int panelElegido)
{
    if(panelElegido == 1)
    {
        if(!abrirArchivo("panel1.dat", "w"))
        {
            printf("Error al abrir panel1.dat\n");
        }

        if(!escribirArchivo(szBuffer))
        {
            printf("Error al escribir panel1.dat");
        }

        cerrarArchivo();
    }

    if(panelElegido == 2)
    {
        if(!abrirArchivo("panel2.dat", "w"))
        {
            printf("Error al abrir panel2.dat\n");
        }

        if(!escribirArchivo(szBuffer))
        {
            printf("Error al escribir panel2.dat");
        }

        cerrarArchivo();
    }

    if(panelElegido == 3)
    {
        if(!abrirArchivo("panel3.dat", "w"))
        {
            printf("Error al abrir panel3.dat\n");
        }

        if(!escribirArchivo(szBuffer))
        {
            printf("Error al escribir panel3.dat");
        }

        cerrarArchivo();
    }
}

void generar(Panel *panel1, Panel *panel2, Panel *panel3)
{
    int p = 0;
    int opcion = 0;
    char szBuffer[50];
    

    printf("\nIngrese opcion (Leer panel: 1, Escribir panel: 2): ");
    scanf("%d", &opcion);
    getchar();
    while(opcion != 1 && opcion != 2)
    {
        printf("\nError! Ingrese opcion correcta (Leer panel: 1, Escribir panel: 2):");
        scanf("%d", &opcion);
        getchar();
    }

    printf("\nIngrese numero de panel para interactuar (1, 2 , 3): ");
    scanf("%d", &p);
    getchar();
    while(opcion != 1 && opcion != 2 && opcion != 3)
    {
        printf("\nError! Ingrese numero de panel para interactuar (1, 2 , 3):");
        scanf("%d", &p);
        getchar();
    }

    if(p == 1)
    {
        if(opcion == 2)
        {
            printf("\nIngrese mensaje: ");
            fgets(szBuffer, sizeof(szBuffer), stdin);
            szBuffer[strcspn(szBuffer, "\n")] = 0; /* Elimina el salto de linea al final del string */

            strcpy(panel1->mensaje, szBuffer);
                    
            escribir(szBuffer, p);
        
        }

        if(opcion == 1)
        {
            strcpy(szBuffer, panel1->mensaje);

            escribir(szBuffer, p);
        }
    }

    if(p == 2)
    {
        if(opcion == 2)
        {
            printf("\nIngrese mensaje: ");
            fgets(szBuffer, sizeof(szBuffer), stdin);
            szBuffer[strcspn(szBuffer, "\n")] = 0; /* Elimina el salto de linea al final del string */

            
            strcpy(panel2->mensaje, szBuffer);
                    
            escribir(szBuffer, p);
            
        }

        if(opcion == 1)
        {
            strcpy(szBuffer, panel2->mensaje);

            escribir(szBuffer, p);
        }
    }

    if(p == 3)
    {
        if(opcion == 2)
        {
            printf("\nIngrese mensaje: ");
            fgets(szBuffer, sizeof(szBuffer), stdin);
            szBuffer[strcspn(szBuffer, "\n")] = 0; /* Elimina el salto de linea al final del string */

            strcpy(panel3->mensaje, szBuffer);
                    
            escribir(szBuffer, p);
            
        }

        if(opcion == 1)
        {
            strcpy(szBuffer, panel3->mensaje);

            escribir(szBuffer, p);
        }
    }


}



int main(int argc, char *argv[])
{
    Panel panel1;
    Panel panel2;
    Panel panel3;
    int id_semaforo;

    memset(&panel1, 0, sizeof(panel1));
    memset(&panel2, 0, sizeof(panel2));
    memset(&panel3, 0, sizeof(panel3));

    panel1.numeroPanel = 1;
    strcpy(panel1.mensaje, "default");

    panel2.numeroPanel = 2;
    strcpy(panel2.mensaje, "default");

    panel3.numeroPanel = 3;
    strcpy(panel3.mensaje, "default");


    id_semaforo = creoSemaforo();

    inicioSemaforo(id_semaforo, VERDE);

    while (1)
    {

        esperaSemaforo(id_semaforo);

        generar(&panel1, &panel2, &panel3);

        levantaSemaforo(id_semaforo);

        usleep(100 * 1000);

    }


    return 0;
}

