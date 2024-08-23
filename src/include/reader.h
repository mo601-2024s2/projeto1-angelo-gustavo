/*
    Responsible for reading the elf file and transforming it into binary
*/
#ifndef READER_H
#define READER_H

/***
 * Function responsible to read an elf file and return it as a binary vector.
 */
void read_elf(char* elf_file);

/***
 * Function responsible to read a hex file and return it as a hex vector.
 */
void read_hex(char* hex_file);

#endif