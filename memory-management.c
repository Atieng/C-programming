//Iimport necessary headers
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

#define PAGE_SIZE 4096

typedef struct Block {
    size_t offset;
    size_t size;
    int free;
    struct Block *next;
} Block;

void *memory = NULL;
Block *head = NULL;

// Initialize memory manager
int init_alloc() {
    memory = mmap(NULL, PAGE_SIZE, PROT_READ | PROT_WRITE,
                  MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    if (memory == MAP_FAILED) return -1;

    // One big free block
    head = (Block *)malloc(sizeof(Block));
    head->offset = 0;
    head->size = PAGE_SIZE;
    head->free = 1;
    head->next = NULL;

    return 0;
}

// Cleanup
int cleanup() {
    if (munmap(memory, PAGE_SIZE) != 0) return -1;

    // free metadata
    Block *curr = head;
    while (curr) {
        Block *temp = curr;
        curr = curr->next;
        free(temp);
    }

    head = NULL;
    return 0;
}

// Split block
void split(Block *block, size_t size) {
    Block *newBlock = (Block *)malloc(sizeof(Block));

    newBlock->offset = block->offset + size;
    newBlock->size = block->size - size;
    newBlock->free = 1;
    newBlock->next = block->next;

    block->size = size;
    block->next = newBlock;
}

// Allocate memory
char *alloc(int size) {
    if (size % 8 != 0) return NULL;

    Block *curr = head;

    while (curr) {
        if (curr->free && curr->size >= size) {

            if (curr->size > size) {
                split(curr, size);
            }

            curr->free = 0;
            return (char *)memory + curr->offset;
        }
        curr = curr->next;
    }

    return NULL; // no space
}

// Merge adjacent free blocks
void merge() {
    Block *curr = head;

    while (curr && curr->next) {
        if (curr->free && curr->next->free) {
            Block *temp = curr->next;

            curr->size += temp->size;
            curr->next = temp->next;

            free(temp);
        } else {
            curr = curr->next;
        }
    }
}

// Deallocate memory
void dealloc(char *ptr) {
    if (!ptr) return;

    size_t offset = ptr - (char *)memory;

    Block *curr = head;

    while (curr) {
        if (curr->offset == offset) {
            curr->free = 1;
            merge();
            return;
        }
        curr = curr->next;
    }
}