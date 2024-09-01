/*
    Log created for each instruction. Stores:

    - Current PC address (hex)
    - Instruction (hex)
    - rd value after instruction (hex)
    - rs1 value before instruction (hex)
    - rs2 value before instruction (hex)
    - Disassembled instruction
*/
#ifndef LOG_H
#define LOG_H

#include <stdint.h>
#include <stdio.h>
#define MAX_INST_SIZE 64

typedef struct {
    uint32_t pc;
    uint32_t instruction;
    uint32_t rd;
    uint32_t rs1;
    uint32_t rs2;
    char disassembledInstruction[MAX_INST_SIZE];
} Log;

Log* createLog();
void printLog(Log* log, FILE* file);
void freeLog(Log* log);

#endif