#include <stdio.h>
#include "mylib.h"


int main()
{
    int* teste_int_1 = malloc(sizeof(int));
    int* teste_int_2 = malloc(sizeof(int));
    int* teste_int_3 = NULL;
    double* teste_double_1 = NULL;

    printf("teste_int_1 @ %p\n", teste_int_1);
    printf("teste_int_2 @ %p\n", teste_int_2);
    printf("teste_int_3 @ %p\n", teste_int_3);
    printf("teste_double_1 @ %p\n\n", teste_double_1);

    free(teste_int_1);
    printf("Freed teste_int_1.\n\n");

    printf("teste_int_1 @ %p\n", teste_int_1);
    printf("teste_int_2 @ %p\n", teste_int_2);
    printf("teste_int_3 @ %p\n", teste_int_3);
    printf("teste_double_1 @ %p\n\n", teste_double_1);

    teste_int_3 = malloc(sizeof(int));
    printf("Allocated memory for teste_int_3.\n\n");

    printf("teste_int_1 @ %p\n", teste_int_1);
    printf("teste_int_2 @ %p\n", teste_int_2);
    printf("teste_int_3 @ %p\n", teste_int_3);
    printf("teste_double_1 @ %p\n\n", teste_double_1);

    free(teste_int_2);
    free(teste_int_3);
    printf("Freed teste_int_2 and teste_int_3.\n\n");

    printf("teste_int_1 @ %p\n", teste_int_1);
    printf("teste_int_2 @ %p\n", teste_int_2);
    printf("teste_int_3 @ %p\n", teste_int_3);
    printf("teste_double_1 @ %p\n\n", teste_double_1);

    teste_double_1 = malloc(sizeof(double));
    printf("Allocated memory for teste_double_1.\n\n");

    printf("teste_int_1 @ %p\n", teste_int_1);
    printf("teste_int_2 @ %p\n", teste_int_2);
    printf("teste_int_3 @ %p\n", teste_int_3);
    printf("teste_double_1 @ %p\n\n", teste_double_1);

    return 0;
}
