#include <stddef.h>

#define HEAP_SIZE 65536

static unsigned char heap[HEAP_SIZE];
static size_t heap_used = 0;

void *kmalloc(size_t size) {

    if (size == 0 || size > HEAP_SIZE - heap_used)
        return NULL;

    void *ptr = &heap[heap_used];

    heap_used += size;

    return ptr;
}