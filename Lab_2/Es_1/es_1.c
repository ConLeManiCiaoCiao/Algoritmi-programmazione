#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MIN 0
#define MAX 100

/*  To clear keyboard buffer */
static void clean_buf() 
{
    int ch;
    while (((ch = getchar()) != '\n') && (ch != EOF)); 
}


int main(void)
{
    int n;
    int start = MIN, end = MAX;
    int mid = -1;
    char ans;

    printf("Inserisci un numero compreso tra %d e %d\n", start, end);

    do
    {
        scanf("%d", &n);
        clean_buf();

        if(n < start || n > end)
        {
            printf("Errore, il numero dev'essere compreso tra %d e %d!\n",
                    start, end);
        }
    } while(n < start || n > end);


    while(start <= end)
    {
        mid = (start + end) / 2;
        
        printf("Il numero e' maggiore o uguale di %d? (y/n)\n", mid);
        scanf("%c", &ans);
        clean_buf();

        if(tolower(ans) == 'y')
        {
            start = mid + 1;
        }
        else if(tolower(ans) == 'n')
        {
            end = mid - 1;
        }
        else
        {
            puts("Opzione non valida!");
        }
    }

    printf("Il numero scelto e' %d (just for debug, n = %d)\n", mid, n);

    return EXIT_SUCCESS;
}

/* EOF */
