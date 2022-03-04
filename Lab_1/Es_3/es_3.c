#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

int main(void)
{
    int n;
    int i;
    int is_prime = TRUE;

    scanf("%d", &n);
 
    if(n <= 3)
    {
        is_prime = n > 1;
    }
    else if((n % 2) == 0 || (n % 3) == 0)
    {
        is_prime = FALSE;
    }

    if(is_prime)
    {
        for(i = 5; (i * i) <= n; i += 6)
        {
            if((n % i) == 0 || (n % (i + 2)) == 0)
            {
                is_prime = FALSE;
            }
        }
    }

    if(is_prime)
    {
        printf("%d e' un numero primo.\n", n);
    }
    else
    {
        printf("%d non e' un numero primo.\n", n);
    }


    return EXIT_SUCCESS;
}

/* EOF*/
