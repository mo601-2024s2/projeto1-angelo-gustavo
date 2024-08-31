#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <elf.h>
#include "include/cpu.h"
#include "include/reader.h"



int main(int argc, char *argv[]) {
    // Tells how many instructions the program has.
    long int size = 0;
    unsigned int* instruction_memory = malloc(4096*sizeof(unsigned int *));


    if(argc == 2) {
        printf("Programa %s", argv[1]);

        read_elf(argv[1], &size, instruction_memory);

        printf("\n%ld\n\n", size);

        runProgram(instruction_memory, size);
    } else {
        printf("Número de argumentos incorreto, por favor insira somente 1 path de programa para ser executado.\n");
    }

    return 0;
}