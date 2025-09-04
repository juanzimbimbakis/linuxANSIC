#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "funciones.h"
#include "definiciones.h"

int inDevolverNumeroAleatorio(int desde, int hasta)
{
    int inNumeroAleatorio = 0;
    inNumeroAleatorio = (rand() % (hasta - desde + 1)) + desde;
    return inNumeroAleatorio;
}


int inDevolverNumeroAleatorioNoRepetitivo(int desde, int hasta)
{

    int numeroAleatorio = 0;
    int repetido = TRUE;
    FILE *archivo;


    numeroAleatorio = inDevolverNumeroAleatorio(desde, hasta);


    repetido = validarRepetido(numeroAleatorio);



    while (repetido == TRUE)
    {
        numeroAleatorio = inDevolverNumeroAleatorio(desde, hasta);
        repetido = validarRepetido(numeroAleatorio);
    }


    /* Si llegamos a este punto, el numero no es repetido */
    
    archivo = fopen("numeros.txt", "a");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo\n");
        return -1; /* Esto porque fopen() devuelve un puntero con la direcc del archivo
                        , entonces si archivo == NULL es porque no existe 
                        o hubo un error al abrirlo */
    }

    fprintf(archivo, "%d\n", numeroAleatorio); /* copiamos el nuevo numero 
                                                NO REPETITIVO en el archivo de 
                                                numeros repetidos */
    fclose(archivo);

    return numeroAleatorio;

}


/* Funcion para verificar si el numero está o no en el archivo: */
/*  Return FALSE si no es repetido, return TRUE si está repetido */
int validarRepetido(int numero)
{
    int numeroLeido;
    FILE *archivo;

    
    archivo = fopen("numeros.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return FALSE; /*  Esto porque --> no repetido si no se puede abrir el archivo */
    }


    while (fscanf(archivo, "%d", &numeroLeido) != EOF) 
    {
        if (numeroLeido == numero) {
            printf("El numero %d ya está en el archivo.\n", numero);
            fclose(archivo);
            return TRUE; /* Repetido */
        }    
    }


    fclose(archivo);
    return FALSE; /* No repetido */
}
