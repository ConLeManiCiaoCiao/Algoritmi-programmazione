#include <stdio.h>
#include <stdlib.h>
#define MIN 0
#define MAX 100

enum rval {ERROR = -1, SUCCESS = 1};
typedef enum {FALSE, TRUE} bool_t;

typedef struct num_list_t
{
    int num;
    struct num_list_t * next;
} num_list_t;


int insert_tail(num_list_t **, int);
void print_list(num_list_t *);
bool_t is_prime(int);
void new_primes_list(num_list_t *, num_list_t **);
void free_list(num_list_t *);


int main(void)
{
    num_list_t * nums = NULL;
    num_list_t * primes = NULL;

    int n;

    printf("Inserisci dei numeri compresi tra %d e %d, inserisci -1 per fermarti\n", 
            MIN, MAX);

    do
    {
        scanf("%d", &n);
        if(n == -1)
        {
            puts("Inserimento interrotto");
        }
        else if(n < -1 || n > MAX)
        {
            printf("Errore, il numero dev'essere compreso tra %d e %d\n", 
                    MIN, MAX);
        }
        else if(insert_tail(&nums, n))
        {
            puts("Elemento inserito");
        }
        else
        {
            puts("Errore nell'inserimento");
        }

    } while(n != -1);

    new_primes_list(nums, &primes);
    
    puts("La lista contenente i numeri primi inseriti nella prima:");
    print_list(primes);
    free_list(nums);
    free_list(primes);
        
    return EXIT_SUCCESS;
}

int insert_tail(num_list_t ** t, int new_num)
{
    num_list_t * p, * q;
    
    p = malloc(sizeof(num_list_t));

    if(p == NULL)
    {
        return ERROR;
    }

    p->num = new_num;
    p->next = NULL;

    if(* t == NULL)
    {
        * t = p;
    }
    else
    {
        q = * t;

        while(q->next != NULL)
        {
            q = q->next;
        }

        q->next = p;
    }

    return SUCCESS;
}


void print_list(num_list_t * head)
{
    num_list_t * curr = head;

    while(curr != NULL)
    {
        printf("%d\n", curr->num);
        curr = curr->next;
    }
}

bool_t is_prime(int n)
{
    int i;

    if(n <= 3)
    {
        return n > 1;
    }
    
    if((n % 2) == 0 || (n % 3) == 0)
    {
        return FALSE;
    }

    for(i = 5; (i * i) <= n; i += 6)
    {
        if((n % i) == 0 || (n % (i + 2)) == 0)
        {
            return FALSE;
        }
    }

    return TRUE;
}


void new_primes_list(num_list_t * nums, num_list_t ** primes)
{
    num_list_t * curr = nums;

    while(curr != NULL)
    {
        if(is_prime(curr->num))
        {
            insert_tail(primes, curr->num);
        }
        curr = curr->next;
    }
}

void free_list(num_list_t * head)
{
    num_list_t * tmp;

    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

/* EOF */

