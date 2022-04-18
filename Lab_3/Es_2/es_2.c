#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define STR_SIZE 202
#define SEQ_SIZE 5

static char * insert_marker(char *, const char *, size_t);

int main(void)
{
    char dna[STR_SIZE] = "ACAGTAGATCCTCCCCGCGCATCCTATTTATTAAGTTAATTCTACAGCAATACGATCATATGCGGATCCGCAGTGGCCGGTAGACACACGTCTACCCCGC";
    char seq[SEQ_SIZE] = "CCCC";
    size_t indexes[STR_SIZE];

    size_t dna_size, seq_size, id_size;
    size_t i, j;
    int ct_occ;

    // puts("Inserisci la sequenza di DNA:");
    // gets(dna);
    dna_size = strlen(dna);

    // puts("Inserisci la sequenza da cercare:");
    // gets(pattern);
    seq_size = strlen(seq);

    ct_occ = 0;
    id_size = 0;

    for(i = 0; i < dna_size; ++i)
    {
        for(j = 0; j < seq_size && dna[i + j] == seq[j]; ++j);

        if(j == seq_size)
        {
            indexes[id_size] = i + id_size;
            ++id_size;
            ++ct_occ;
        }
    }

    for(i = 0; i < id_size; ++i)
    {
        insert_marker(dna, "*", indexes[i] + i);
        insert_marker(dna, "*", indexes[i] + SEQ_SIZE + i);
    }

    printf("Il numero di occorenze della sequenza %s e' %d\n", 
            seq, ct_occ);
    puts(dna);
    
    return EXIT_SUCCESS;
}


char * insert_marker
(char * s1, const char * marker, size_t index)
{
    size_t len = strlen(s1);

    if (len < index)
    {
        index = len;
    }

    for (size_t i = 0; i < len - index; i++ )
    {
        s1[len - i] = s1[len - i - 1];
    }

    s1[index] = marker[0];
    s1[len + 1] = '\0';

    return s1;
}

/* EOF */

