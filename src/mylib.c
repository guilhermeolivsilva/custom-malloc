#include "mylib.h"

char buffer[SIZE];

char* __my_heap_start = buffer;
char* __my_heap_end = buffer + SIZE;

void *my_malloc(size_t size) {
    return buffer;
}


void my_free(void *ptr) {

}