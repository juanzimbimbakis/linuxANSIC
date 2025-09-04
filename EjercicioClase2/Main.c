#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "funciones.h"
#include "definiciones.h"
#include "time.h"
#include "unistd.h"


int main(int argc, char *argv[])
{

    int inNumeroAleatorio = 0;
    int desde = DESDE;
    int hasta = HASTA;

    srand(time(NULL));

    if(argc == 4)
    {
        desde = atoi(argv[1]);
        hasta = atoi(argv[2]);

    
        printf("El tercer parametro y cuarto del Array es: %s\n", argv[3]);
        printf("El desde es: %d\n", desde);
        printf("El hasta es: %d\n", hasta);
    }

    /*
    inNumeroAleatorio = inDevolverNumeroAleatorio(DESDE, HASTA);
    */

    inNumeroAleatorio = inDevolverNumeroAleatorioNoRepetitivo(desde, hasta);
    

    printf("El numero aleatorio es: %d\n", inNumeroAleatorio);
    
    

    return 0;
}
