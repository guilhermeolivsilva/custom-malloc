#include "mylib.h"

char heap[MEM_SIZE];

void *myMalloc(size_t size) {
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


void myFree(void *ptr) {

}
