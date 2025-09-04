#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "archivos.h"
#include "global.h"

void escribirTexto(void)
{
    char szBuffer[50];

    if(!abrirArchivo("textoMain4.txt", "w"))
    {
        printf("Error al abrir el archivo textoMain4.txt para escritura.\n");
        return;
    }

    printf("Ingrese un texto para textoMain4.txt: ");
    fgets(szBuffer, sizeof(szBuffer), stdin);
    szBuffer[strcspn(szBuffer, "\n")] = 0; /* Elimina el salto de linea al final del string */

    if(!escribirArchivo(szBuffer))
    {
        printf("Error al escribir en el archivo textoMain3.txt.\n");
    }

    cerrarArchivo();


}


int main(int argc, char *argv[])
{
    printf("------------\n");
    escribirTexto();
    printf("------------\n");
    printf("Fin de escritura.\n");



    return 0;
}
