#include <stdio.h>
#include <stdlib.h>
#define ROWS 5
#define COLUMNS 5
#define LEN_SEQ 3
#define VALUE 0

void read_matrix(int [ROWS][COLUMNS], int , int , FILE *);
void print_matrix(const int [ROWS][COLUMNS], int, int);


int main(void)
{
    int matrix [ROWS][COLUMNS];

    int i, j;
    int ct_seq;
    FILE * fp;

    fp = fopen("matrice.txt", "r");

    if(fp == NULL)
    {
        fprintf(stderr, "Errore nell'apertura del file\n");
        return EXIT_FAILURE;
    }

    read_matrix(matrix, ROWS, COLUMNS, fp);

    puts("La matrice letta da file e':");
    print_matrix(matrix, ROWS, COLUMNS);

    for(i = 0; i < ROWS; ++i) {
        ct_seq = 0;
        for(j = 0; j < COLUMNS; ++j) {
            if(matrix[i][j] == VALUE) {
                ++ct_seq;
            }
            else { 
                if(ct_seq >= LEN_SEQ) {
                    printf("La sequenza di %d compare nella riga %d\n", VALUE, i + 1);
                }
            ct_seq = 0;
            }
        }
        if(ct_seq >= LEN_SEQ) {
                printf("La sequenza di %d compare nella riga %d\n", VALUE, i + 1);
        }
    }

    for(j = 0; j < COLUMNS; ++j) {
        ct_seq = 0;
        for(i = 0; i < ROWS; ++i) {
            if(matrix[i][j] == VALUE) {
                ++ct_seq;
            }
            else { 
                if(ct_seq >= LEN_SEQ) {
                    printf("La sequenza di %d compare nella colonna %d\n", VALUE, j + 1);
                }
            ct_seq = 0;
            }
        }
        if(ct_seq >= LEN_SEQ) {
                printf("La sequenza di %d compare nella colonna %d\n", VALUE, j + 1);
        }
    }

    return EXIT_SUCCESS;
}


void read_matrix
(int matrix[ROWS][COLUMNS], int r, int c, FILE * fp)
{
    int i, j;

    for(i = 0; i < r; ++i)
    {
        for(j = 0; j < c; ++j)
        {
            fscanf(fp, "%d", &matrix[i][j]);
        }
        fgetc(fp);
    }
}

void print_matrix
(const int matrix[ROWS][COLUMNS], int r, int c)
{
    int i, j;

    for(i = 0; i < r; ++i)
    {
        for(j = 0; j < c; ++j)
        {
            printf("%d ", matrix[i][j]);
        }
        puts("");
    }
}

/* EOF */
