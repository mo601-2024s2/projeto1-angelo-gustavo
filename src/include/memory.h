/*
    Responsible for memory operations
*/

#define DRAM_SIZE 6242880

#include <stdint.h>


typedef struct {
    uint8_t mem[DRAM_SIZE];
} Mem;


Mem* createMemory();
void insertByte(Mem* mem, int pos, uint8_t byte);
uint8_t getByte(Mem* mem, int pos);
void freeMemory(Mem* mem);