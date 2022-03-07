#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int h;   
    int i,j;

    scanf("%d", &h);

    for(i = 1; i <= h; ++i)
    {
        for(j = 0; j < i; ++j)
        {
            putchar('*');
        }
        putchar('\n');
    }

    return EXIT_SUCCESS;
}

/* EOF*/
