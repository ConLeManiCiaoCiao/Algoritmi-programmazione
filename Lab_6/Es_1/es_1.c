#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void input_array(int * , size_t);
void print_array(const int * , size_t);
double calc_avg(const int * , size_t);
int find_max(const int * , size_t);
void print_pos(const int * , size_t, int);


int main(void)
{
    int * v = NULL;
    size_t dim = 0;
    int max;

    puts("Inserisci la dimensione del vettore:");
    scanf("%lu", &dim);

    v = malloc(dim * sizeof(int));

    if(v == NULL)
    {
        fprintf(stderr, "Errore nell'allocazione del vettore...\n");
        return EXIT_FAILURE;
    }

    input_array(v, dim);
    print_array(v, dim);

    printf("La media dei valori e': %.2f\n",
           calc_avg(v, dim));

    max = find_max(v, dim);
    printf("Il massimo e': %d\n\n", max);
    print_pos(v, dim, max);

    free(v);

    return EXIT_SUCCESS;
}


void input_array(int *  v, size_t dim)
{
    size_t i;

    puts("Inserisci il vettore:");

    for(i = 0; i < dim; ++i)
    {
        scanf("%d", &v[i]);
    }
}

void print_array(const int *  v, size_t dim)
{
    size_t i;

    puts("Il vettore inserito e':");

    for(i = 0; i < dim; ++i)
    {
        printf("[%d]\n", v[i]);
    }

    puts("");
}

double calc_avg(const int *  v, size_t dim)
{
    size_t i;
    double avg = 0;

    for(i = 0; i < dim; ++i)
    {
        avg += v[i];
    }

    return avg / dim;
}

int find_max(const int *  v, size_t dim)
{
    size_t i;

    int max = v[0];

    for(i = 1; i < dim; ++i)
    {
        if(max < v[i])
        {
            max = v[i];
        }
    }

    return max;
}

void print_pos(const int * v, size_t dim, int value)
{
    size_t i;

    printf("L'elemento %d compare nelle seguenti posizioni:\n",
            value);

    for(i = 0; i < dim; ++i)
    {
        if(v[i] == value)
        {
            printf("%lu\n", i + 1);
        }
    }
}


/* EOF */

