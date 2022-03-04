#include <stdio.h>
#include <stdlib.h>
#define BASE_PRICE 100
#define ADDS_ON 40
#define DISCOUNT 20
#define N_MONTHS 12

int main(void)
{
    int price, features, months, years;

    scanf("%d %d", &features, &years);

    months = years * N_MONTHS;
    price = BASE_PRICE + (features * ADDS_ON) - (DISCOUNT * months);

    printf("%d euro\n", price);

    return EXIT_SUCCESS;
}

/* EOF */
