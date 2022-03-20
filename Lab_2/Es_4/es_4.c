#include <stdio.h>
#include <stdlib.h>
#define N 10
#define TRUE 1
#define FALSE 0

int main()
{
    int i, j;
    int v[N];
    int monotonous = TRUE;
    int decreasing = TRUE;

    i = 0;
    j = 0;

    while(monotonous && i < N)
    {
        scanf("%d", &v[i]);

        if(j == 0)
        {
            ++j;
        }
        else if(j == 1)
        {
            if(v[i - 1] < (v[i]))
            {
                decreasing = FALSE;
                ++j;
            }
            else if(v[i - 1] > (v[i]))
            {
                decreasing = TRUE;
                ++j;
            }
            else
            {
                j = 1;
            }
        }
        else
        {
            if(v[i - 1] < (v[i]))
            {
                if(decreasing)
                {
                    monotonous = FALSE;
                }

                decreasing = FALSE;
            }
            else if(v[i - 1] > (v[i]))
            {
                if(!decreasing)
                {
                    monotonous = FALSE;
                }

                decreasing = TRUE;
            }
        }

        i++;
    }

    if(monotonous)
    {
        puts("La serie e' monotona");
    }
    else
    {
        puts("La serie non e' monotona");
    }

    return EXIT_SUCCESS;
}

/* EOF */
