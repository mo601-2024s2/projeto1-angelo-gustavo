#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libelf.h>
#include <fcntl.h>
#include <gelf.h>
#include <unistd.h>
#include <sysexits.h>
#include <err.h>
#include <bsd/vis.h>
#include "reader.h"

void read_elf(char* elf_file, long int* size, unsigned int* instruction_memory) {
    int i, fd;
    Elf *e;
    GElf_Ehdr ehdr;
    char *id;
    GElf_Shdr shdr;
    Elf_Scn *scn = NULL;
    Elf_Data *data = NULL;
    size_t shstrndx;

    if (elf_version(EV_CURRENT) == EV_NONE) {
        fprintf(stderr, "ELF library initialization failed: %s\n", elf_errmsg(-1));
        exit(EXIT_FAILURE);
    }

    if ((fd = open(elf_file, O_RDONLY, 0)) < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    if ((e = elf_begin(fd, ELF_C_READ, NULL)) == NULL) {
        fprintf(stderr, "elf_begin() failed: %s.\n", elf_errmsg(-1));
        exit(EXIT_FAILURE);
    }

    if (elf_kind(e) != ELF_K_ELF) {
        fprintf(stderr, "%s is not an ELF object.\n", elf_file);
        exit(EXIT_FAILURE);
    }

    if (gelf_getehdr (e, &ehdr) == NULL) {
        errx(EX_SOFTWARE, "getehdr() failed: %s.", elf_errmsg (-1));
    }

    if (elf_getshdrstrndx(e, &shstrndx) != 0) {
        fprintf(stderr, "elf_getshdrstrndx failed: %s\n", elf_errmsg(-1));
    }

    if ((i = gelf_getclass(e)) == ELFCLASSNONE) {
        errx(EX_SOFTWARE, "getclass() failed: %s.", elf_errmsg (-1));
    }

    if ((id = elf_getident(e, NULL)) == NULL) {
        errx(EX_SOFTWARE , "getident() failed: %s.", elf_errmsg ( -1));
    }

    while ((scn = elf_nextscn(e, scn)) != NULL) {
        if(!gelf_getshdr(scn, &shdr)) {
            fprintf(stderr, "gelf_getshdr failed: %s\n", elf_errmsg(-1));
            elf_end(e);
            close(fd);
        }
        char *section_name = elf_strptr(e, shstrndx, shdr.sh_name);

        // Look for the .text section where instructions are usually stored
        if (strcmp(section_name, ".text") == 0) {
            printf("Found .text section at offset 0x%jx with size 0x%jx\n", (uintmax_t)shdr.sh_offset, (uintmax_t)shdr.sh_size);

            // Get the data from .text section
            data = elf_getdata(scn, NULL);
            if (data == NULL || data->d_buf == NULL) {
                fprintf(stderr, "Failed to read .text section\n");
                exit(EXIT_FAILURE);
            }
            printf("Data in .text section (grouped 4 bytes at a time):\n");
            // Each "word" is an instruction
            for (size_t i = 0; i < data->d_size; i += 4) {
                // Handle cases where the remaining data is less than 4 bytes
                unsigned int word = 0;
                memcpy(&word, ((unsigned char *)data->d_buf) + i, (data->d_size - i) >= 4 ? 4 : (data->d_size - i));
                printf("%08x ", word);
                printf("\n");

                instruction_memory[*size] = word;

                *size+=1;
            }
            break;
        }
    }
    elf_end(e);
    close(fd);
}