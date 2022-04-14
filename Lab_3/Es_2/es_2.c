#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#define STR_SIZE 101
#define SEQ_SIZE 5

void print_dna(const char *, const int *, int);
void init_array(int *, int, int);

int main(void)
{
    char dna[STR_SIZE] = "ACAGTAGATCCTCCCCGCGCATCCTATTTATTAAGTTAATTCTACAGCAATACGATCATATGCGGATCCGCAGTGGCCGGTAGACACACGTCTACCCCGC";
    char pattern[SEQ_SIZE] = "ACAG";
    int indexes[STR_SIZE];

    int dna_len, pattern_len;
    int i, j;
    int ct_occ;

    init_array(indexes, STR_SIZE, -1);

    // puts("Inserisci la sequenza di DNA:");
    // gets(dna);
    dna_len = strlen(dna);

    // puts("Inserisci la sequenza da cercare:");
    // gets(pattern);
    pattern_len = strlen(pattern);

    ct_occ = 0;

    for(i = 0; i < dna_len; ++i)
    {
        for(j = 0; j < pattern_len && dna[i + j] == pattern[j]; ++j);

        if(j == pattern_len)
        {
            indexes[i] = i;
            indexes[i + pattern_len] = i + pattern_len;
            ++ct_occ;
        }
    }

    printf("Il numero di occorenze della sottostringa %s e' %d\n", 
            pattern, ct_occ);
    
    print_dna(dna, indexes, dna_len);

    return EXIT_SUCCESS;
}


void print_dna(const char * dna, const int * indexes, int len)
{
    int i;

    for(i = 0; i < len; ++i)
    {
        if(i == indexes[i])
        {
            putchar('*');
        }
        
        putchar(dna[i]);
    }

    // If needed print the last marker for the sequence
    if(i == indexes[i])
    {
        putchar('*');
    }

    puts("");
}


void init_array(int * v, int dim, int value)
{
    int i;

    for(i = 0; i < dim; ++i)
    {
        v[i] = value;
    }
}


/* EOF */
