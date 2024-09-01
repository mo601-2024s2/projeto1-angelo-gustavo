#include "log.h"
#include <stdlib.h>
#include <stdio.h>

Log* createLog() {
    Log* log = malloc(sizeof(Log));

    if (log == NULL) {
        printf("Not enough memory to allocate log");
        exit(0);
    }

    return log;
}

void printLog(Log* log, int rd, int rs1, int rs2, FILE* file) {
    printf("%s [%X] - PC=0x%X x%02d=%X x%02d=%X x%02d=%X\n", log->disassembledInstruction, log->instruction, log->pc, rs1, log->rs1, rs2, log->rs2, rd, log->rd);
    fprintf(file, "%s [%X] - PC=0x%X x%02d=%X x%02d=%X x%02d=%X\n", log->disassembledInstruction, log->instruction, log->pc, rs1, log->rs1, rs2, log->rs2, rd, log->rd);
}

void freeLog(Log* log) {
    free(log);
}