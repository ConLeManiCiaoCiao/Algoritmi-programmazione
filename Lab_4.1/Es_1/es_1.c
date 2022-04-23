#include <stdio.h>
#include <stdlib.h>
#define N 10lu
#define TRUE 1
#define FALSE 0

void print_matrix(const int *, size_t);
int * init_matrix(size_t);
int sum_elements(const int *, size_t);
int trace(const int *, size_t);
int * matrix_sum(int * , int *, size_t);
int * matrix_prod(int * , int *, size_t);
size_t get_dim(size_t);
int is_equal(int, int);
int matrix_cmp(int *, int *, size_t);


int main(void)
{
    size_t dim;
    int * matrix_a, * matrix_b;

    dim = get_dim(N);

    puts("Inserisci la prima matrice:");
    matrix_a = init_matrix(dim);

    puts("Inserisci la seconda matrice:");
    matrix_b = init_matrix(dim);

    if(matrix_a != NULL && matrix_b != NULL)
    {
        int a = sum_elements(matrix_a, dim);
        int b = sum_elements(matrix_b, dim);

        if(is_equal(a, b))
        {
            puts("La somma degli elementi delle 2 matrici e' uguale");
        }
        else
        {
            puts("La somma degli elementi delle 2 matrici NON e' uguale");
        }

        if(matrix_cmp(matrix_a, matrix_b, dim))
        {
            puts("Le 2 matrici sono uguali");
        }
        else
        {
            puts("Le 2 matrici sono diverse");
        }


        printf("La somma della diagonale principale delle 2 matrici e': %d %d\n",
                trace(matrix_a, dim), trace(matrix_b, dim));

        puts("La somma delle 2 matrici e':");
                print_matrix(matrix_sum(matrix_a, matrix_b, dim), dim);

        puts("Il prodotto delle 2 matrici e':");
                print_matrix(matrix_prod(matrix_a, matrix_b, dim), dim);

    }

    return EXIT_SUCCESS;
}


void print_matrix(const int * matrix, size_t dim)
{
    size_t i, j;
    
    for(i = 0; i < dim; ++i)
    {
        for(j = 0; j < dim; ++j)
        {
            printf("%d ", matrix[(i * dim) + j]);
        }

        puts("");
    }
}

int * init_matrix(size_t dim)
{
    int * matrix = malloc(sizeof(int) * dim * dim);
    size_t i, j;

    puts("Inserisci la matrice:");

    if(matrix == NULL)
    {
        fprintf(stderr, "Errore nell'allocazione della matrice...\n");
        return matrix;
    }

    for(i = 0; i < dim; ++i)
    {
        for(j = 0; j < dim; ++j)
        {
            scanf("%2d", &matrix[(i * dim) + j]);
        }
    }

    return matrix;
}

int sum_elements(const int * matrix, size_t dim)
{
    size_t i, j;
    int sum = 0;

    for(i = 0; i < dim; ++i)
    {
        for(j = 0; j < dim; ++j)
        {
            sum += matrix[(i * dim) + j];
        }
    }

    return sum;
}

int trace(const int * matrix, size_t dim)
{
    size_t i, j;
    int diag = 0;

    for(i = 0; i < dim; ++i)
    {
        for(j = 0; j < dim; ++j)
        {
            if(i == j)
            {
                diag += matrix[(dim * i) + j];
            }
        }
    }

    return diag;
}

int * matrix_sum
(int * matrix_a, int * matrix_b, size_t dim)
{
    int * sum = malloc(sizeof(int) * dim * dim);

    if(sum == NULL)
    {
        fprintf(stderr, "Errore nell'allocazione della matrice somma\n");
    }
    else
    {
        size_t i, j;

        for(i = 0; i < dim; ++i)
        {
            for(j = 0; j < dim; ++j)
            {
                sum[(dim * i) + j] = 
                matrix_a[(dim * i) + j] + matrix_b[(dim * i) + j];
            }
        }
    }

    return sum;
}


int * matrix_prod
(int * matrix_a, int * matrix_b, size_t dim)
{
    int * m_prod = calloc(sizeof(int), dim * dim);

    if(m_prod == NULL)
    {
        fprintf(stderr, "Errore nell'allocazione dinamica.\n");
    }
    else
    {
        size_t i, j, k;

        for(i = 0; i < dim; ++i)
        {
            for(j = 0; j < dim; ++j)
            {
                for(k = 0; k < dim; ++k)
                {
                    m_prod[(i * dim) + j] +=
                    matrix_a[(i * dim) + k] * matrix_b[(k * dim) + j];
                }
            }
        }
    }

    return m_prod;
}

size_t get_dim(size_t sup)
{
    size_t dim;

    printf("Inserisci la dimensione della matrice compresa tra 1 e %lu:\n",
            sup);

    do
    {
        scanf("%lu", &dim);
        if(dim == 0 || dim > 10)
        {
            printf("Errore, la dimensione dev'essere compresa tra 1 e %lu\n", 
                    N);
        }
    } while (dim == 0 || dim > 10);

    return dim;
}

int is_equal(int a, int b)
{
    return a == b;
}

int matrix_cmp(int * a, int * b, size_t dim)
{
    size_t i, j;
    int equal = TRUE;

    for(i = 0; i < dim; ++i)
    {
        for(j = 0; j < dim; ++j)
        {
            if(a[(i * dim) + j] != b[(i * dim) + j])
            {
                equal = FALSE;
                break;
            }
        }
    }

    return equal;
}


/* EOF */

