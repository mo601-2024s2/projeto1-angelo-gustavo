#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <elf.h>
#include "include/reader.h"



int main() {

    read_elf("../test/000.main.riscv");


    return 0;
}