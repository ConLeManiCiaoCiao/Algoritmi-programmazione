#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define STR_SIZE 128
#define KEY_SIZE 4

size_t input_key(int * , size_t);
void encrypt(char * , int * , size_t);

void clear_buffer(void);

int main(void)
{
    char s[STR_SIZE];
    int key[KEY_SIZE];
    size_t key_dim;
    int mode;

    puts("1 per criptare, 2 per decriptare");

    do
    {
        scanf("%d", &mode);
        clear_buffer();

        if(mode != 1 && mode != 2)
        {
            puts("Opzione non valida!");
            puts("1 per criptare, 2 per decriptare");
        }
    } while (mode != 1 && mode != 2);
    
    puts("Inserisci la frase:");
    gets(s);
    
    puts("Inserisci la chiave:");
    key_dim = input_key(key, KEY_SIZE);

    if(mode == 1)
    {
        encrypt(s, key, KEY_SIZE);
        printf("La frase criptata e': %s\n", s);
    }
    else if(mode == 2)
    {
        printf("La frase decriptata e': %s\n", s);
    }


    return EXIT_SUCCESS;
}

void encrypt(char * string, int * key, size_t key_size)
{
    size_t len = strlen(string);

    for(size_t i = 0, j = 0; i < len; ++i, ++j)
    {
        if(j == key_size)
        {
            j = 0;
        }

        string[i] += key[j];
    }
}

size_t input_key(int * key, size_t dim)
{
    size_t i;
    size_t n_read = 0;

    for(i = 0; i < dim; ++i)
    {
        scanf("%d", &key[i]);
        ++n_read;
    }

    return n_read;
}

void clear_buffer()
{
    int ch;
    while (((ch = getchar()) != '\n') && (ch != EOF)); 
}

/* EOF */
