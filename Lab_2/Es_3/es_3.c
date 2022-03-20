#include <stdio.h>
#include <stdlib.h>
#define N 5

int main(void)
{
    int v1[N] = {0}, v2[N] = {0};
    int n;
    size_t i, j;

    i = 0;
    j = 0;

    while(i < N && j < N)
    {
        scanf("%d", &n);

        if(n >= 0)
        {
            if((n % 3) == 0)
            {
                v1[i] = n;
                ++i;
            }
        }
        else
        {
            if((n % 3) != 0 && (n % 2) == -1)
            {
                v2[i] = n;
                ++j;
            }
        }
    }


    puts("Vettore 1:");
    for(i = 0; i < N; ++i)
    {
        printf("%d\n", v1[i]);
    }

    puts("Vettore 2:");
    for(i = 0; i < N; ++i)
    {
        printf("%d\n", v2[i]);
    }

    return EXIT_SUCCESS;
}

/* EOF */
