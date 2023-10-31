#include <stddef.h>

#define SIZE 10
#define TRUE 1
#define FALSE 0

typedef struct Block {
    size_t size;
    struct Block* next;
} Block;

void *myMalloc(size_t size);
void myFree(void *ptr);
void initializeHeap();
