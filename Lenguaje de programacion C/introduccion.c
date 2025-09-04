#include "stdio.h"


int celsiusPasador(int fahrenheit)
{
    return (fahrenheit - 32) * 5 / 9;
}

int main()
{

    /*
    int fahrenheit, celsius, piso, techo, paso;

    piso = 0;
    techo = 300;
    paso = 20;

    printf("\nHola, Mundo\n");
    printf("---------------------------\n---------------------------\n\n");
    fahrenheit = piso;

    while (fahrenheit <= techo)
    {
        celsius = celsiusPasador(fahrenheit);

        printf("%6d\t%d\n", fahrenheit, celsius);
        fahrenheit = fahrenheit + paso;
    }

    printf("\nO...\n");

    for(fahrenheit = 0; fahrenheit <= 300; fahrenheit = fahrenheit + 20)
    {
        celsius = celsiusPasador(fahrenheit);
        printf("%6d\t%d\n", fahrenheit, celsius);
    }

    printf("\nO...\n");

    for(fahrenheit= 300; fahrenheit >= 0; fahrenheit = fahrenheit - 20)
    {
        celsius = celsiusPasador(fahrenheit);
        printf("%6d\t%d\n", fahrenheit, celsius);
    }
    */

   int x;
   x = 0;

   while (x < 10)
   {
        printf("%d\n", x);
        ++x;
   }
   /* tar -cvzf ./tpclase3_Pepe_Rodriguez.tar ./tpclase3 */
   /* para descomprimir: tar -xvzf ./tpclase3_Pepe_Rodriguez.tar */

    return 0;
}