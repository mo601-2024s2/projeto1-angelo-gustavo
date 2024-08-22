#include "memory.h"
#include <stdlib.h>


Mem* createMemory() {
    Mem* mem = (Mem*) malloc(sizeof(Mem));
    
    if (mem == NULL) {
        printf("No memory available for allocating MEM");
        exit(0);
    }

    return mem;
}

void insertByte(Mem* mem, int pos, uint8_t byte) {
    mem->mem[pos] = byte;
}

uint8_t getByte(Mem* mem, int pos) {
    return mem->mem[pos];
}

void freeMemory(Mem* mem) {
    free(mem);
}