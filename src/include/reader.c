#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <elf.h>
#include "reader.h"


void bin(unsigned n)
{
    long long i, j;

    for(i=0;i<sizeof(int);i++) {
        char byte = ((char*)&n)[i];
        for (j=8; j>=0; j--) {
            char bit = (byte >> j) & 1;
            printf("%hhd", bit);
        }
        printf(" ");
    }
}


void read_elf(char* elf_file) {
    Elf32_Ehdr header;

    FILE* file = fopen(elf_file, "rb");

    unsigned int buffer[100];


    if(file) {
        fread(&header, sizeof(header), 1, file);

        if(memcmp(header.e_ident, ELFMAG, SELFMAG) == 0) {
            fread(buffer,sizeof(buffer),1,file);
            for(int i = 0; i < 100; i++) {
                bin(buffer[i]);
                printf("\n");
            }
        } else {
            printf("tristeza\n");
        }

        fclose(file);
    } else {
        printf("AAAAAAAAAAAAAAAA\n");
    }
}