#include <stdio.h>
#include "mylib.h"


int main() {
    extern char buffer[SIZE];
    int* teste = (int*) my_malloc(sizeof(int));
    *teste = 10;

    printf("teste: %d\n", *teste);
    printf("buffer: %d\n", *buffer);

    return 0;
}