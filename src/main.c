#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <elf.h>
#include "include/cpu.h"
#include "include/reader.h"



int main() {
    // Tells how many instructions the program has.
    long int size = 0;
    unsigned int* instruction_memory = malloc(4096*sizeof(unsigned int *));

    read_elf("../test/000.main.riscv", &size, instruction_memory);

    printf("%ld", size);

    printf("\n%08x\n", instruction_memory[13]);

    runProgram(instruction_memory, size);

    return 0;
}