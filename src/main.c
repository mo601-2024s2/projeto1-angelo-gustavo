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
    char logfile[32];
    int len;


    if(argc == 2) {
        printf("Programa %s\n", argv[1]);

        strcpy(logfile, argv[1]);

        len = strlen(logfile);

        // logfile[len-1] = ' ';
        logfile[len-2] = '\0';
        logfile[len-3] = 'g';
        logfile[len-4] = 'o';
        logfile[len-5] = 'l';

        read_elf(argv[1], &size, instruction_memory);

        printf("\nNúmero de instruções do programa: %ld\n\n", size);
        printf("Log de execução em: %s\n\n", logfile);

        runProgram(instruction_memory, size, logfile);
    } else {
        printf("Número de argumentos incorreto, por favor insira somente 1 path de programa para ser executado.\n");
    }

    return 0;
}