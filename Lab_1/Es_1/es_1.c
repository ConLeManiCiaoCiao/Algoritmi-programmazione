#include <stdio.h>
#include <stdlib.h>
#define K 10

int main(void)
{
    int a, b, c, d;     /* Coefficients */
    int A, B;           /* Variables for generic Ax = B equation */
    float x;            /* Unknown variable */

    scanf("%d %d %d %d", &a, &b, &c, &d);

    A = a + (b * c);
    B = -d * K;
    
    if(A != 0)
    {
        x = (float)(B) / (float)(A);
        printf("Risultato: %f\n", x);
    }
    else if(B == 0)
    {
        printf("Risultato: indeterminata\n");
    }
    else
    {
        printf("Risultato: impossibile\n");
    }

    return EXIT_SUCCESS; 
}

/* EOF*/
