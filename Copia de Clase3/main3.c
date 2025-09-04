#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "archivos.h"
#include "global.h"


void escribirTexto(void)
{
    char szBuffer[50];

    if(!abrirArchivo("textoMain3.txt", "w"))
    {
        printf("Error al abrir el archivo textoMain3.txt para escritura.\n");
        return;
    }

    printf("Ingrese un texto para textoMain3.txt: ");
    fgets(szBuffer, sizeof(szBuffer), stdin);
    szBuffer[strcspn(szBuffer, "\n")] = 0; /* Elimina el salto de linea al final del string */

    if(!escribirArchivo(szBuffer))
    {
        printf("Error al escribir en el archivo textoMain3.txt.\n");
    }

    cerrarArchivo();


}

void leerTexto(void)
{
    char szBuffer[50];

    if(!abrirArchivo("textoMain3.txt", "r"))
    {
        printf("Error al abrir archivo textoMain3.txt para lectura. \n");
        return;
    }

    /*
    while(!feof(archivo))
    {
        if(leerArchivo(szBuffer) == TRUE)
        {
            printf("%s\n", szBuffer);
        }

    }
    */
    while(leerArchivo(szBuffer) == TRUE)
    {
        printf("%s\n", szBuffer);
    }

   

    cerrarArchivo();

}


int main(int argc, char *argv[])
{

    printf("-------------------------\n");
    escribirTexto();
    printf("-------------------------\n");
    leerTexto();
    printf("\nFin del programa\n");
    

    return 0;
}
