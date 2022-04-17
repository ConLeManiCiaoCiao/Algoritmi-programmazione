#include <stdio.h>
#include <stdlib.h>
#define N 4

void print_matrix(const int [N][N], int, int);
void init_matrix(int [N][N], int, int);


int main(void)
{
    int matrix[N][N];
    int i;

    for(i = 0; i < (N - 2); ++i)
    {
        init_matrix(matrix, N - i, i);
    }

    print_matrix(matrix, N, N);

    return EXIT_SUCCESS;
}


void print_matrix
(const int matrix[N][N], int r, int c)
{
    int i, j;

    for(i = 0; i < r; ++i)
    {
        for(j = 0; j < c; ++j)
        {
            printf("%2d ", matrix[i][j]);
        }
        puts("");
    }
}

void init_matrix
(int matrix[N][N], int dim, int st_pt)
{
    int i, j;
    int value = 1;

    // Print sup row
    for(i = st_pt, j = st_pt; j < dim; ++j)
    {
        matrix[i][j] = value++;
    }

    // Print right column without first element
    for(i += 1, j -= 1; i < dim; ++i)
    {
        matrix[i][j] = value++;
    }

    // Print inf row without last element
    for(i -= 1, j -= 1; j >= st_pt; --j)
    {
        matrix[i][j] = value++;
    }

    // Print left column without first and last element
    for(i -= 1, j += 1; i > st_pt; --i)
    {
        matrix[i][j] = value++;
    }
}

/* EOF */
