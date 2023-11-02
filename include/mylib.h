#include <stddef.h>

#define MEM_SIZE 72
#define TRUE 1
#define FALSE 0

typedef struct Block {
    size_t size;
    char isFree;
    struct Block* next;
} Block;

void *myMalloc(size_t size);
void myFree(void *ptr);
int getAvailableMemory();
