/*
    Responsible for reading, interpreting and executing instructions
*/
#include <stdint.h>
#include "memory.h"

typedef struct {
    uint32_t regs[32];
    uint32_t pc;
    Mem* memory;
} CPU;

CPU* createCPU();
void freeCPU(CPU* cpu);
void runProgram(uint32_t program[], int programSize);
void runInstruction(uint32_t instruction, CPU* cpu);