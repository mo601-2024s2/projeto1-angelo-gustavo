#include "cpu.h"
#include "log.h"
#include "instructions.h"
#include <stdio.h>
#include <stdlib.h>


CPU* createCPU() {
    CPU* cpu = malloc(sizeof(CPU));

    if (cpu == NULL) {
        printf("Unable to allocate memory for CPU");
        exit(0);
    }

    cpu->memory = createMemory();

    cpu->pc = 0;
    cpu->regs[0] = 0;

    return cpu;
}

void setReg(CPU* cpu, int pos, uint32_t val) {
    if (pos != 0)
        cpu->regs[pos] = val;
}

uint32_t getReg(CPU* cpu, int pos) {
    return cpu->regs[pos];
}

void freeCPU(CPU* cpu) {
    freeMemory(cpu->memory);
    free(cpu);
}

void runProgram(uint32_t program[], int programSize) {
    CPU* cpu = createCPU();

    while (cpu->pc / 4 < programSize) {
        runInstruction(program[cpu->pc / 4], cpu);
        cpu->pc += 4;
    }

    freeCPU(cpu);
}


void runInstruction(uint32_t instruction, CPU* cpu) {
    Log* log = createLog();

    log->instruction = instruction;
    log->pc = cpu->pc;
    
    int rd = (instruction >> 7) && 0b11111;
    int rs1 = (instruction >> 15) && 0b11111;
    int rs2 = (instruction >> 19) && 0b11111;

    log->rs1 = getByte(cpu->memory, getReg(cpu, rs1));
    log->rs2 = getByte(cpu->memory, getReg(cpu, rs2));

    int opcode = instruction && 0x7F;
    int funct3 = (instruction >> 12) && 0x7;
    int funct7 = (instruction >> 25) && 0x7F;

    switch (opcode) {
        case 0x37: // 01101 11 - lui
            lui(cpu, log, rd, (instruction >> 12) && 0xFFFFF);
            break;
        case 0x17: // 00101 11 - auipc
            auipc(cpu, log, rd, (instruction >> 12) && 0xFFFFF);
            break;
        case 0x13: // 00100 11 - addi, slti, xori, ori, andi, alli, srli, srai
            switch (funct3) {
                case 0X0: // 000 - addi
                    break;
                case 0X2: // 010 - slti
                    break;
                case 0X3: // 011 - sltiu
                    break;
                case 0X4: // 100 - xori
                    break;
                case 0X6: // 110 - ori
                    break;
                case 0X7: // 111 - andi
                    break;
                case 0X1: // 001 - slli
                    break;
                case 0X5: // 101 - srli, srai
                    int effectiveFunct7 = (instruction >> 27) && 0x1F;
                    switch (effectiveFunct7) {
                        case 0x0: // 00000 - srli
                            break;
                        case 0x8: // 01000 - srai
                            break;
                    }
                    break;
            }
            break;
        case 0x33: // 01100 11 - add, sub, sll, slt, sltu, xor, srl, sra, or, and, mul, mulh, mulhsu, mulhu, div, divu, rem, remu
            switch (funct3) {
                case 0X0: // 000 - add, sub, mul
                    switch (funct7) {
                        case 0x0: // 00000 00 - add
                            break;
                        case 0x1: // 00000 01 - mul
                            break;
                        case 0x20: // 01000 00 - sub
                            break;
                    }
                    break;
                case 0X1: // 001 - sll, mulh
                    switch (funct7) {
                        case 0x0: // 00000 00 - sll
                            break;
                        case 0x1: // 00000 01 - mulh
                            break;
                    }
                    break;
                case 0X2: // 010 - slt, mulhsu
                    switch (funct7) {
                        case 0x0: // 00000 00 - slt
                            break;
                        case 0x1: // 00000 01 - mul
                            break;
                    }
                    break;
                case 0X3: // 011 - sltu, mulhu
                    switch (funct7) {
                        case 0x0: // 00000 00 - sltu
                            break;
                        case 0x1: // 00000 01 - mulhu
                            break;
                    }
                    break;
                case 0X4: // 100 - xor, div
                    switch (funct7) {
                        case 0x0: // 00000 00 - xor
                            break;
                        case 0x1: // 00000 01 - div
                            break;
                    }
                    break;
                case 0X5: // 101 - srl, sra, divu
                    switch (funct7) {
                        case 0x0: // 00000 00 - srl
                            break;
                        case 0x1: // 00000 01 - divu
                            break;
                        case 0x20: // 01000 00 - sra
                            break;
                    }
                    break;
                case 0x6: // 110 - or, rem
                    switch (funct7) {
                        case 0x0: // 00000 00 - or
                            break;
                        case 0x1: // 00000 01 - rem
                            break;
                    }
                    break;
                case 0X7: // 111 - and, remu
                    switch (funct7) {
                        case 0x0: // 00000 00 - and
                            break;
                        case 0x1: // 00000 01 - remu
                            break;
                    }
                    break;
            }
            break;
        case 0xF: // 00011 11 - fence, fence.i
            switch (funct3) {
                case 0x0: // 000 - fence
                    break;
                case 0x1: // 001 - fence.i
                    break;
            }
            break;
        case 0x73: // 11100 11  - csrrw, csrrs, csrrc, csrrwi, csrrsi, csrrci, ecall, ebreak, uret, sret, mret, wfi, sfence.vma, 
            switch (funct3) {
                case 0x0: // 000 - ecall, ebreak, uret, sret, mret, wfi, sfence.vma
                    int f = (instruction >> 20) && 0x1F;
                    switch (funct7) {
                        case 0x0: // 00000 00 - ecall, ebreak, uret
                            switch (f) {
                                case 0x0: // 00000 - ecall
                                    break;
                                case 0x1: // 00001 - ebreak
                                    break;
                                case 0x2: // 00010 - uret
                                    break;
                            }
                            break;
                        case 0x8: // 00010 00 - sret, wfi
                            switch (f) {
                                case 0x2: // 00010 - sret
                                    break;
                                case 0x5: // 00101 - wfi
                                    wfi(cpu, log);
                                    break;
                            }
                            break;
                        case 0x18: // 00110 00 - mret
                            break;
                        case 0x9: // 00010 01 - sfence.vma
                            sfenceVma(cpu, log, rs1, rs2);
                            break;
                    }
                case 0x1: // 001 - csrrw
                    break;
                case 0x2: // 010 - csrrs
                    break;
                case 0x3: // 011 - csrrc
                    break;
                case 0x5: // 101 - csrrwi
                    break;
                case 0x6: // 110 - csrrsi
                    break;
                case 0x7: // 111 - csrrci
                    break;
            }
            break;
        case 0x3: // 00000 11 - lb, lh, lw, lbu, lhu
            int offset = (instruction >> 20) && 0b111111111111;
            switch (funct3) {
                case 0x0: // 000 - lb
                    lb(cpu, log, rd, rs1, offset);
                    break;
                case 0x1: // 001 - lh
                    lh(cpu, log, rd, rs1, offset);
                    break;
                case 0x2: // 010 - lw
                    lw(cpu, log, rd, rs1, offset);
                    break;
                case 0x4: // 100 - lbu
                    lbu(cpu, log, rd, rs1, offset);
                    break;
                case 0x5: // 101 - lhu
                    lhu(cpu, log, rd, rs1, offset);
                    break;
            }
            break;
        case 0x23: // 01000 11 - sb, sh, sw
            switch (funct3) {
                case 0x0: // 000 - sb
                    break;
                case 0x1: // 001 - sh
                    break;
                case 0x2: // 010 - sw
                    break;
            }
            break;
        case 0x6F: // 11011 11 - jal
            break;
        case 0x67: // 11001 11 - jalr
            break;
        case 0x63: // 11000 11 - beq, bne, blt, bge, bltu, bgeu
            int offset = ((instruction >> 8) && 0b1111);    // 4:1
            offset = (offset << 6) + ((instruction >> 25) && 0b111111); // 5:10
            offset = (offset << 1) + ((instruction >> 7) && 0b1);       // 11
            offset = (offset << 1) + ((instruction >> 31) && 0b1);      // 12
            switch (funct3) {
                case 0x0: // 000 - beq
                    beq(cpu, log, rs1, rs2, offset);
                    break;
                case 0x1: // 001 - bne
                    bne(cpu, log, rs1, rs2, offset);
                    break;
                case 0x4: // 100 - blt
                    blt(cpu, log, rs1, rs2, offset);
                    break;
                case 0x5: // 101 - bge
                    bge(cpu, log, rs1, rs2, offset);
                    break;
                case 0x6: // 110 - bltu
                    bltu(cpu, log, rs1, rs2, offset);
                    break;
                case 0x7: // 111 - bgeu
                    bgeu(cpu, log, rs1, rs2, offset);
                    break;
            }
            break;
    }

    log->rd = getByte(cpu->memory, getReg(cpu, rd));

    printLog(log);
    freeLog(log);
}