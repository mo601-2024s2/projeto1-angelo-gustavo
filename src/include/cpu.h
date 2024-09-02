/*
    Responsible for reading, interpreting and executing instructions
*/
#ifndef CPU_H
#define CPU_H

#include <stdint.h>
#include <stdio.h>
#include "memory.h"

typedef struct {
    uint32_t regs[32];
    uint32_t pc;
    uint32_t csr;
    Mem* memory;
} CPU;

CPU* createCPU();
void setReg(CPU* cpu, int pos, uint32_t val);
uint32_t getReg(CPU* cpu, int pos);
void freeCPU(CPU* cpu);
void runProgram(uint32_t program[], int programSize, char* logfile);
void runInstruction(uint32_t instruction, CPU* cpu, FILE* file);

#endif