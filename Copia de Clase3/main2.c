#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "clave.h"


int main(int argc, char *argv[])
{

    int clave;

    clave = creoClave();

    printf("La clave es: %d\n", clave);




    return 0;
}

