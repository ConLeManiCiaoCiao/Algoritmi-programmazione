#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STR_SIZE 202
#define SEQ_SIZE 5

char * insert_marker(char *, const char *, size_t);

int main(void)
{
    char dna[STR_SIZE] = "ACAGTAGATCCTCCCCGCGCATCCTATTTATTAAGTTAATTCTACAGCAATACGATCATATGCGGATCCGCAGTGGCCGGTAGACACACGTCTACCCCGC";
    char seq[SEQ_SIZE] = "CCGC";

    size_t dna_size, seq_size;
    size_t i, j;
    size_t ct_occ;

    dna_size = strlen(dna);
    seq_size = strlen(seq);

    ct_occ = 0;

    for(i = 0; i < dna_size; i += 1 + ct_occ)
    {
        for(j = 0; j < seq_size && dna[i + j + ct_occ] == seq[j]; ++j);

        if(j == seq_size)
        {
            insert_marker(dna, "*", i + ct_occ);
            insert_marker(dna, "*", i + ct_occ + SEQ_SIZE);
            ++ct_occ;
        }
    }

    printf("Il numero di occorenze della sequenza %s e' %lu\n", 
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

