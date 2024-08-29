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

void printLog(Log* log) {
    printf("%s [%X/n] - PC:0x%X/n rs1:0x%X/n rs2:0x%X/n rd:0x%X/n\n", log->disassembledInstruction, log->instruction, log->pc, log->rs1, log->rs2, log->rd);
}

void freeLog(Log* log) {
    free(log);
}