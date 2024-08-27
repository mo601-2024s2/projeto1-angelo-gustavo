#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libelf.h>
#include <fcntl.h>
#include <gelf.h>
#include <unistd.h>
#include <sysexits.h>
#include <err.h>
#include <vis.h>
#include "reader.h"

void read_elf(char* elf_file) {
    int i, fd;
    Elf *e;
    GElf_Ehdr ehdr;
    char *id;
    // // size_t n;
    // GElf_Shdr shdr;
    // Elf_Scn *scn = NULL;
    // Elf_Data *data = NULL;

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

    if (gelf_getehdr (e, &ehdr ) == NULL ) {
        errx(EX_SOFTWARE, "getehdr() failed: %s.", elf_errmsg (-1));
    }

    if ((i = gelf_getclass(e)) == ELFCLASSNONE) {
        errx(EX_SOFTWARE, "getclass() failed: %s.", elf_errmsg (-1));
    }

    printf("%s: %d - bit ELF object\n", elf_file, i == ELFCLASS32 ? 32 : 64);

    if ((id = elf_getident(e, NULL)) == NULL) {
        errx(EX_SOFTWARE , "getident() failed: %s.", elf_errmsg ( -1));
    }

    printf("%3s e_ident [0..%1d] %7s", " ", EI_ABIVERSION, "\n");
    // while ((scn = elf_nextscn(e, scn)) != NULL) {
    //     gelf_getshdr(scn, &shdr);
    //     char *section_name = elf_strptr(e, elf_ndxscn(scn), shdr.sh_name);

    //     // Look for the .text section where instructions are usually stored
    //     if (strcmp(section_name, ".text") == 0) {
    //         data = elf_getdata(scn, data);
    //         if (data == NULL || data->d_buf == NULL) {
    //             fprintf(stderr, "Failed to read .text section\n");
    //             exit(EXIT_FAILURE);
    //         }

    //         // Print the instructions in hex
    //         for (size_t i = 0; i < data->d_size; i += 4) {
    //             uint32_t instruction = *(uint32_t *)((uint8_t *)data->d_buf + i);
    //             printf("%08x\n", instruction);
    //         }
    //     }
    // }

    // elf_end(e);
    // close(fd);
}