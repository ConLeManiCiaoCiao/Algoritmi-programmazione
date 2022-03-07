#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int h;   
    int i, j;

    scanf("%d", &h);

    for(i = 0; i < h; ++i)
    {
        for(j = 0; j < h + i; ++j)
        {
            if((h - j - 1) > i)
            {
                putchar(' ');
            }
            else
            {
                putchar('*');
            }
        }
        
        putchar('\n');
    }

    return EXIT_SUCCESS;
}

/* EOF*/
