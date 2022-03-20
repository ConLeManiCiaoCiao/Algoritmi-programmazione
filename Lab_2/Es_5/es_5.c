#include <stdio.h>
#include <stdlib.h>
#define N 10


int main(void)
{
    int v[N];
    int positions[N];
    int value;
    int i, dim_p, dim_v;


    puts("Inserisci i valori del vettore:");
    value = 1;

    /* Inizializzo value ad 1 per entrare nel ciclo che termina */
    /* appena inserisco un valore negativo */

    for(i = 0, dim_v = 0; i < N && value > 0; ++i)
    {
        scanf("%d", &value);

        /* Se il valore e' valido lo salvo nel vettore e incremento */
        /* la variabile dim_v che contiene la dimensione effettiva */
        /* ( Potrei non riempire tutto il vettore) */

        if(value > 0)
        {
            v[i] = value;
            ++dim_v;
        }
    }

    do
    {
        puts("Inserisci il valore da cercare nel vettore:");
        scanf("%d", &value);

        /* Itero lungo il vettore v e se value corrisponde */
        /* all'i-esimo elemento allora lo salvo nel vettore positions */
        /* incrementando dim_p che poi conterrà il numero di posizioni */

        if(value > 0)
        {
            for(i = 0, dim_p = 0; i < dim_v; ++i)
            {
                if(v[i] == value)
                {
                    positions[dim_p] = i + 1;
                    ++dim_p;
                }
            }

            puts("Stampa le posizioni salvate nel vettore:");

            for(i = 0; i < dim_p; ++i)
            {
                printf("%d\n", positions[i]);
            }
        }
        
    } while(value > 0);


    return EXIT_SUCCESS;
}

/* EOF */
