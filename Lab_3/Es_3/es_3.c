#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 128
#define TRUE 1
#define FALSE 0

int main(void)
{
    char s[N];
    size_t i, len;
    int ct_alpha = 0;
    int ct_upper = 0;
    int ct_space = 0;
    int ct_digit = 0;
    int ct_words = 0;
    int is_word = FALSE;

    gets(s);
    len = strlen(s);

    for(i = 0; i < len; ++i)
    {
        if(isalpha(s[i]))
        {
            ++ct_alpha;
        }
        if(isupper(s[i]))
        {
            ++ct_upper;
        }
        if(isspace(s[i]))
        {
            is_word = FALSE;
            ++ct_space;
        }
        else if(!is_word && isalpha(s[i]))
        {
            is_word = TRUE;
            ++ct_words;
        }
        if(isdigit(s[i]))
        {
            ++ct_digit;
        }
    }

    printf("Numero di caratteri introdotti: %lu\n", len);
    printf("Numero di caratteri alfabetici: %d\n", ct_alpha);
    printf("Numero di caratteri maiuscoli: %d\n", ct_upper);
    printf("Numero di cifre decimali: %d\n", ct_digit);
    printf("Numero di caratteri di spaziatura: %d\n", ct_space);
    printf("Numero di parole: %d\n", ct_words);

    return EXIT_SUCCESS;
}

/* EOF */
