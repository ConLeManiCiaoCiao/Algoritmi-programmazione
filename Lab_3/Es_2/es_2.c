#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define STR_SIZE 200
#define SEQ_SIZE 5

static char *insert_string (char *, const char *, size_t);

int main(void)
{
    char dna[STR_SIZE] = "ACAGTAGATCCTCCCCGCGCATCCTATTTATTAAGTTAATTCTACAGCAATACGATCATATGCGGATCCGCAGTGGCCGGTAGACACACGTCTACCCCGC";
    char seq[SEQ_SIZE] = "ACAG";
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
    
    for(i = 0, id_size = 0; i < dna_size; ++i)
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
        insert_string(dna, "*", indexes[i] + i);
        insert_string(dna, "*", indexes[i] + SEQ_SIZE + i);
    }

    printf("Il numero di occorenze della sequenza %s e' %d\n", 
            seq, ct_occ);
    puts(dna);
    
    return EXIT_SUCCESS;
}


char * insert_string
(char * s1, const char *marker, size_t pos)
{
    size_t len_s1 = strlen(s1);

    if (len_s1 < pos)
    {
        pos = len_s1;
    }

    for ( size_t i = 0; i < len_s1 - pos; i++ )
    {
        s1[len_s1 - i] = s1[len_s1 - i - 1];
    }

    s1[pos] = marker[0];
    s1[len_s1 + 1] = '\0';

    return s1;
}

/* EOF */


