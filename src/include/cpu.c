#include "cpu.h"
#include "log.h"
#include <stdio.h>
#include <stdlib.h>


CPU* createCPU() {
    CPU* cpu = malloc(sizeof(CPU));

    if (cpu == NULL) {
        printf("Unable to allocate memory for CPU");
        exit(0);
    }

    cpu->memory = createMemory();

    return cpu;
}

void freeCPU(CPU* cpu) {
    freeMemory(cpu->memory);
    free(cpu);
}

void runProgram(uint32_t program[], int programSize) {
    CPU* cpu = createCPU();
    cpu->pc = 0;

    while (cpu->pc < programSize) {
        runInstruction(program[cpu->pc], cpu);
        cpu->pc++;
    }

    freeCPU(cpu);
}


void runInstruction(uint32_t instruction, CPU* cpu) {
    
}