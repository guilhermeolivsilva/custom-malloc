#include <stdio.h>
#include "mylib.h"


int main()
{
    extern char heap[MEM_SIZE];
    
    printf("heap starts @ \t%p\n", heap);
    printf("heap ends @ \t%p\n", heap + MEM_SIZE);
    printf("available memory: %d\n\n", getAvailableMemory());
    printf("----------------------------\n");

    int* teste_int_1 = myMalloc(sizeof(int));
    int* teste_int_2 = myMalloc(sizeof(int));
    int* teste_int_3 = NULL;
    double* teste_double_1 = NULL;

    printf("teste_int_1 @ %p\n", teste_int_1);
    printf("teste_int_2 @ %p\n", teste_int_2);
    printf("teste_int_3 @ %p\n", teste_int_3);
    printf("teste_double_1 @ %p\n", teste_double_1);
    printf("available memory: %d\n\n", getAvailableMemory());

    myFree(teste_int_1);
    printf("Freed teste_int_1.\n");
    printf("available memory: %d\n\n", getAvailableMemory());

    printf("teste_int_1 @ %p\n", teste_int_1);
    printf("teste_int_2 @ %p\n", teste_int_2);
    printf("teste_int_3 @ %p\n", teste_int_3);
    printf("teste_double_1 @ %p\n", teste_double_1);
    printf("available memory: %d\n\n", getAvailableMemory());

    teste_int_3 = myMalloc(sizeof(int));
    printf("Allocated memory for teste_int_3.\n\n");

    printf("teste_int_1 @ %p\n", teste_int_1);
    printf("teste_int_2 @ %p\n", teste_int_2);
    printf("teste_int_3 @ %p\n", teste_int_3);
    printf("teste_double_1 @ %p\n", teste_double_1);
    printf("available memory: %d\n\n", getAvailableMemory());

    myFree(teste_int_2);
    myFree(teste_int_3);
    printf("Freed teste_int_2 and teste_int_3.\n\n");

    printf("teste_int_1 @ %p\n", teste_int_1);
    printf("teste_int_2 @ %p\n", teste_int_2);
    printf("teste_int_3 @ %p\n", teste_int_3);
    printf("teste_double_1 @ %p\n", teste_double_1);
    printf("available memory: %d\n\n", getAvailableMemory());

    teste_double_1 = myMalloc(sizeof(double));
    printf("Allocated memory for teste_double_1.\n\n");

    printf("teste_int_1 @ %p\n", teste_int_1);
    printf("teste_int_2 @ %p\n", teste_int_2);
    printf("teste_int_3 @ %p\n", teste_int_3);
    printf("teste_double_1 @ %p\n", teste_double_1);
    printf("available memory: %d\n\n", getAvailableMemory());

    return 0;
}
