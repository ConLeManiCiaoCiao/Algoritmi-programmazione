#include <stdio.h>
#include <stdlib.h>
#define N 10
#define TRUE 1
#define FALSE 0

void input(float * , FILE * , size_t);
int is_r1_valid(float * , float , size_t);
int is_r2_valid(float * , size_t);


int main(void)
{
    FILE * fp;
    float values[N];
    float cl;

    fp = fopen("esperimenti.txt", "r");

    if(fp == NULL)
    {
        fprintf(stderr,"Errore nell'apertura del file\n");
        exit(EXIT_FAILURE);
    }

    while(!feof(fp))
    {
        input(values, fp, N);
        fscanf(fp, "%f", &cl);

        if(!is_r1_valid(values, cl, N))
        {
            puts("Serie scartata (R1)");
        }
        else if(!is_r2_valid(values, N))
        {
            puts("Serie scartata (R2)");
        }
        else
        {
            puts("Serie accettata");
        }
    }

    fclose(fp);

    return EXIT_SUCCESS;
}


void input(float  *values, FILE * fp, size_t dim)
{
    size_t i;

    for(i = 0; i < dim; ++i)
    {
        fscanf(fp, "%f", &values[i]);
    }
}

int is_r1_valid(float * values, float cl, size_t dim)
{
    float avg = 0;
    size_t i;
    int is_valid = TRUE;

    for(i = 0; i < dim; ++i)
    {
        avg += values[i];
    }

    avg /= dim;

    for(i = 0; i < dim && is_valid; ++i)
    {
        if(values[i] > (avg + (3 * cl)) || values[i] < (avg - (3 * cl)))
        {
            is_valid = FALSE;
        }
    }

    return is_valid;
}

int is_r2_valid(float * values, size_t dim)
{
    int is_valid = TRUE;
    size_t i;

    for(i = 0; i < (dim - 4) && is_valid; ++i)
    {
        if(values[i] < values[i + 1] && values[i + 1] < values[i + 2]
           && values[i + 2] < values[i + 3])
        {
            is_valid = FALSE;
        }
        else if(values[i] > values[i + 1] && values[i + 1] > values[i + 2]
                && values[i + 2] > values[i + 3])
        {
            is_valid = FALSE;
        }
    }

    return is_valid;
}

/* EOF */
