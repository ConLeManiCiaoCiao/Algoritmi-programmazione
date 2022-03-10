#include <stdio.h>
#include <stdlib.h>
#define N 4

int main(void)
{
    int v[N];
    int min, max;
    int diff_max;
    size_t i;

    for(i = 0; i < N; ++i)
    {
        scanf("%d", &v[i]);
        if(v[i] < 0 || v[i] > 999)
        {
            printf("Errore, il numero %d e' fuori dall'intervallo [0, 1000)\n", v[i]);
            v[i] = 0;
        }
    }

    min = v[0];
    max = v[0];

    for(i = 0; i < N; ++i)
    {
        if(v[i] > max)
        {
            max = v[i];
        }
        
        if(v[i] < min)
        {
            min = v[i];
        }
    }

    diff_max = max - min;

    printf("La differenza massima e': %d\n", diff_max);

    return EXIT_SUCCESS;
}

/* EOF*/
