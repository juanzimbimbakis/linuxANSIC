#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "archivos.h"
#include "global.h"


void leerTexto(void)
{
    char szBuffer[50];

    if(!abrirArchivo("textoMain4.txt", "r"))
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
    printf("------------\n");
    leerTexto();
    printf("------------\n");
    printf("Fin de lectura.\n");



    return 0;
}
