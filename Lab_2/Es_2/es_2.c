#include <stdio.h>
#include <stdlib.h>
#define N 5

int main(void)
{
    int v[N];
    int i;
    int somma;
    float avg;
    int max;

    for(i = 0; i < N; ++i)
    {
        scanf("%d", &v[i]);
    }

    for(i = 0; i < N; ++i)
    {
        printf("[%2d] : %d\n", i + 1, v[i]);
    }

    somma = 0;

    for(i = 0; i < N; ++i)
    {
        somma += v[i];
    }

    avg = (float) (somma) / (float)(N);
    printf("Media dei valori del vettore: %.2f\n", avg);

    max = v[0];

    for(i = 1; i < N; ++i)
    {
        if(v[i] > max)
        {
            max = v[i];
        }
    }

    printf("Il valore massimo e': %d e compare nelle seguenti posizioni:\n", max);

    for(i = 0; i < N; ++i)
    {
        if(v[i] == max)
        {
            printf("%2d\n", i + 1);
        }
    }

    return EXIT_SUCCESS;
}

/* EOF */
