#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a, b;
    float avg;

    scanf("%d %d", &a, &b);

    avg = ((float)a + (float)b) / 2;

    printf("La media di (%d, %d) e' %.2f\n", a, b, avg);

    return EXIT_SUCCESS;
}

/*EOF*/
