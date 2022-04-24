#include <stdio.h>
#include <stdlib.h>
#define N 4

void print_matrix(int *, int);
void init_matrix(int *, int, int);


int main(void)
{
    int matrix[N * N] = {1};   // To handle N = 1
    int i;

    for(i = 0; i <= (N - 2); ++i)
    {
        init_matrix(matrix, N, i);
    }

    print_matrix(matrix, N);

    return EXIT_SUCCESS;
}


void print_matrix(int * matrix, int dim)
{
    int i, j;

    for(i = 0; i < dim; ++i)
    {
        for(j = 0; j < dim; ++j)
        {
            printf("%2d ", matrix[(i * dim) + j]);
        }

        puts("");
    }
}

void init_matrix
(int * matrix, int dim, int st_pt)
{
    int i, j;
    int value = 1;

    // Initialize sup row
    for(i = st_pt, j = st_pt; j < dim - st_pt; ++j)
    {
        matrix[(i * dim) + j] = value++;
    }

    // Initialize right column without first element
    for(i += 1, j -= 1; i < dim - st_pt; ++i)
    {
        matrix[(i * dim) + j] = value++;
    }

    // Initialize inf row without last element
    for(i -= 1, j -= 1; j >= st_pt; --j)
    {
        matrix[(i * dim) + j] = value++;
    }

    // Initialize left column without first and last element
    for(i -= 1, j += 1; i > st_pt; --i)
    {
        matrix[(i * dim) + j] = value++;
    }
}


/* EOF */

