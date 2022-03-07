#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int h;   
    int i, j, k;

    scanf("%d", &h);

    for(i = 1; i <= h; ++i)
    {
        for(j = 0; j < h - i; ++j)
        {
            putchar(' ');
        }

        for(k = 1; k < 2 * i; ++k)
        {
            putchar('*');
        }
        
        putchar('\n');
    }

    return EXIT_SUCCESS;
}

/*EOF*/
