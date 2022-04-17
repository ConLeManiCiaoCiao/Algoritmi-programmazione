#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

int is_prime(int);

int main(void)
{
    int n;
    int tmp;
    int r_trunc_prime;

    do
    {
        scanf("%d", &n);
        
        if(n < 0)
        {
            if(n != -1)
            {
                puts("Il numero inserito dev'essere positivo");
            }
        }
        else
        {
            r_trunc_prime = TRUE;

            for(tmp = n; tmp != 0 && r_trunc_prime; tmp /= 10)
            {
                if(!is_prime(tmp))
                {
                    r_trunc_prime = FALSE;
                }
            }

            if(r_trunc_prime)
            {
                puts("NUMERO VALIDO");
            }
            else
            {
                puts("NUMERO NON VALIDO");
            }
        }

    } while (n != -1);
    

    return EXIT_SUCCESS;
}


int is_prime(int n)
{
    int is_prime = TRUE;
    int i;

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

    return is_prime;
}

/* EOF */
