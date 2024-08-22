/*
    Log created for each instruction. Stores:

    - Current PC address (hex)
    - Instruction (hex)
    - rd value after instruction (hex)
    - rs1 value before instruction (hex)
    - rs2 value before instruction (hex)
    - Disassembled instruction
*/

#include <stdint.h>

typedef struct {
    uint32_t pc;
    uint32_t instruction;
    uint32_t rd;
    uint32_t rs1;
    uint32_t rs2;
    char* disassembledInstruction;
} Log;

Log* createLog();
void printLog(Log* log);
void freeLog(Log* log);