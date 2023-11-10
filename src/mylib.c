#include "mylib.h"

#define MEM_SIZE 72
#define TRUE 1
#define FALSE 0

typedef struct Block
{
    size_t size;
    char isFree;
    struct Block* next;
} Block;

static char heap[MEM_SIZE];

void *malloc(size_t size)
{
    static int heapHasBeenInitialized = FALSE;

    if(size + sizeof(Block) > MEM_SIZE || size <= 0) {
        return NULL;
    }

    Block* heap_start = (Block*) heap;

    if(!heapHasBeenInitialized) {
        heap_start->size = MEM_SIZE - sizeof(Block);
        heap_start->next = NULL;
        heap_start->isFree = TRUE;
        heapHasBeenInitialized = TRUE;
    }

    Block* current = heap_start;

    while(current) {
        if(current->size >= size && current->isFree) {
            if(current->size > size + sizeof(Block)) {
                Block* new_block = (Block*) ((char*) current + sizeof(Block) + size);
                new_block->size = current->size - size - sizeof(Block);
                new_block->next = current->next;
                new_block->isFree = TRUE;
                current->next = new_block;
            }

            current->size = size;
            current->isFree = FALSE;

            return (char*) current + sizeof(Block);
        }

        current = current->next;
    }

    return NULL;
}


void free(void* ptr)
{
    if (ptr == NULL) {
        return;
    }

    Block* block = (Block*)((char*)ptr - sizeof(Block));
    block->isFree = TRUE;
    ptr = NULL;

    Block* current = (Block*) heap;
    Block* prev = NULL;

    // Coalesce memory
    while(current) {
        if(current->isFree && current->next && current->next->isFree) {
            current->size += sizeof(Block) + current->next->size;
            current->next = current->next->next;
        }

        prev = current;
        current = current->next;
    }
}

