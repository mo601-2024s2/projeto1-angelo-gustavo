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

void printLog(Log* log, FILE* file) {
    printf("%s [%X] - PC:0x%X rs1:0x%X rs2:0x%X rd:0x%X\n", log->disassembledInstruction, log->instruction, log->pc, log->rs1, log->rs2, log->rd);
    fprintf(file, "%s [%X] - PC:0x%X rs1:0x%X rs2:0x%X rd:0x%X\n", log->disassembledInstruction, log->instruction, log->pc, log->rs1, log->rs2, log->rd);
}

void freeLog(Log* log) {
    free(log);
}