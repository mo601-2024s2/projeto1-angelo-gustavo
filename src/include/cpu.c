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
    cpu->csr = 0;

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

int32_t imm_sig_extension(int imm) {
    if (imm & 0x800) {  // Check if the sign bit (bit 11) is set
        imm |= 0xFFFFF000;  // Set the upper 20 bits to 1 for negative numbers
    }

    return imm;
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
    
    int rd = (instruction >> 7) & 0b11111;
    int rs1 = (instruction >> 15) & 0b11111;
    int rs2 = (instruction >> 19) & 0b11111;

    log->rs1 = getReg(cpu, rs1);
    // printf("%d\n", rs2);
    log->rs2 = getReg(cpu, rs2);

    int opcode = instruction & 0x7F;
    int funct3 = (instruction >> 12) & 0x7;
    int funct7 = (instruction >> 25) & 0x7F;

    int offset;

    switch (opcode) {
        case 0x37: // 01101 11 - lui
            lui(cpu, log, rd, (instruction >> 12) & 0xFFFFF);
            break;
        case 0x17: // 00101 11 - auipc
            auipc(cpu, log, rd, (instruction >> 12) & 0xFFFFF);
            break;
        case 0x13: // 00100 11 - addi, slti, xori, ori, andi, alli, srli, srai
            switch (funct3) {
                case 0X0: // 000 - addi
                    addi(cpu, log, rd, rs1, imm_sig_extension(instruction >> 20));
                    break;
                case 0X2: // 010 - slti
                    slti(cpu, log, rd, rs1, imm_sig_extension(instruction >> 20));
                    break;
                case 0X3: // 011 - sltiu
                    sltiu(cpu, log, rd, rs1, imm_sig_extension(instruction >> 20));
                    break;
                case 0X4: // 100 - xori
                    xori(cpu, log, rd, rs1, imm_sig_extension(instruction >> 20));
                    break;
                case 0X6: // 110 - ori
                    ori(cpu, log, rd, rs1, imm_sig_extension(instruction >> 20));
                    break;
                case 0X7: // 111 - andi
                    andi(cpu, log, rd, rs1, imm_sig_extension(instruction >> 20));
                    break;
                case 0X1: // 001 - slli
                    slli(cpu, log, rd, rs1, imm_sig_extension(instruction >> 20));
                    break;
                case 0X5: // 101 - srli, srai
                    int effectiveFunct7 = (instruction >> 27) && 0x1F;
                    switch (effectiveFunct7) {
                        case 0x0: // 00000 - srli
                            srli(cpu, log, rd, rs1, imm_sig_extension(instruction >> 20));
                            break;
                        case 0x8: // 01000 - srai
                            srai(cpu, log, rd, rs1, imm_sig_extension(instruction >> 20));
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
                            add(cpu, log, rd, rs1, rs2);
                            break;
                        case 0x1: // 00000 01 - mul
                            mul(cpu, log, rd, rs1, rs2);
                            break;
                        case 0x20: // 01000 00 - sub
                            sub(cpu, log, rd, rs1, rs2);
                            break;
                    }
                    break;
                case 0X1: // 001 - sll, mulh
                    switch (funct7) {
                        case 0x0: // 00000 00 - sll
                            sll(cpu, log, rd, rs1, rs2);
                            break;
                        case 0x1: // 00000 01 - mulh
                            mulh(cpu, log, rd, rs1, rs2);
                            break;
                    }
                    break;
                case 0X2: // 010 - slt, mulhsu
                    switch (funct7) {
                        case 0x0: // 00000 00 - slt
                            slt(cpu, log, rd, rs1, rs2);
                            break;
                        case 0x1: // 00000 01 - mulhsu
                            mulhsu(cpu, log, rd, rs1, rs2);
                            break;
                    }
                    break;
                case 0X3: // 011 - sltu, mulhu
                    switch (funct7) {
                        case 0x0: // 00000 00 - sltu
                            sltu(cpu, log, rd, rs1, rs2);
                            break;
                        case 0x1: // 00000 01 - mulhu
                            mulhu(cpu, log, rd, rs1, rs2);
                            break;
                    }
                    break;
                case 0X4: // 100 - xor, div
                    switch (funct7) {
                        case 0x0: // 00000 00 - xor
                            xorOp(cpu, log, rd, rs1, rs2);
                            break;
                        case 0x1: // 00000 01 - div
                            opDiv(cpu, log, rd, rs1, rs2);
                            break;
                    }
                    break;
                case 0X5: // 101 - srl, sra, divu
                    switch (funct7) {
                        case 0x0: // 00000 00 - srl
                            srl(cpu, log, rd, rs1, rs2);
                            break;
                        case 0x1: // 00000 01 - divu
                            divu(cpu, log, rd, rs1, rs2);
                            break;
                        case 0x20: // 01000 00 - sra
                            sra(cpu, log, rd, rs1, rs2);
                            break;
                    }
                    break;
                case 0x6: // 110 - or, rem
                    switch (funct7) {
                        case 0x0: // 00000 00 - or
                            orOp(cpu, log, rd, rs1, rs2);
                            break;
                        case 0x1: // 00000 01 - rem
                            rem(cpu, log, rd, rs1, rs2);
                            break;
                    }
                    break;
                case 0X7: // 111 - and, remu
                    switch (funct7) {
                        case 0x0: // 00000 00 - and
                            andOp(cpu, log, rd, rs1, rs2);
                            break;
                        case 0x1: // 00000 01 - remu
                            remu(cpu, log, rd, rs1, rs2);
                            break;
                    }
                    break;
            }
            break;
        case 0xF: // 00011 11 - fence, fence.i
            switch (funct3) {
                case 0x0: // 000 - fence
                    // acho q dá pra deixar só assim mesmo pq a instrução é inútil
                    break;
                case 0x1: // 001 - fence.i
                    // read comment above
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
                                    ecall(cpu, log);
                                    break;
                                case 0x1: // 00001 - ebreak
                                    ebreak(cpu, log);
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
                    csrrw(cpu, log, rd, rs1, cpu->csr);
                    break;
                case 0x2: // 010 - csrrs
                    csrrs(cpu, log, rd, rs1, cpu->csr);
                    break;
                case 0x3: // 011 - csrrc
                    csrrc(cpu, log, rd, rs1, cpu->csr);
                    break;
                case 0x5: // 101 - csrrwi
                    csrrwi(cpu, log, rd, rs1, cpu->csr);
                    break;
                case 0x6: // 110 - csrrsi
                    csrrsi(cpu, log, rd, rs1, cpu->csr);
                    break;
                case 0x7: // 111 - csrrci
                    csrrci(cpu, log, rd, rs1, cpu->csr);
                    break;
            }
            break;
        case 0x3: // 00000 11 - lb, lh, lw, lbu, lhu
            offset = (instruction >> 20) && 0b111111111111;
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
            offset = (instruction >> 25);                                   // 11:5
            offset = (offset << 7) + (instruction >> 7) && 0b11111;         // 4:0
            switch (funct3) {
                case 0x0: // 000 - sb
                    sb(cpu, log, rs1, rs2, offset);
                    break;
                case 0x1: // 001 - sh
                    sh(cpu, log, rs1, rs2, offset);
                    break;
                case 0x2: // 010 - sw
                    sw(cpu, log, rs1, rs2, offset);
                    break;
            }
            break;
        case 0x6F: // 11011 11 - jal
            offset = instruction >> 31;                                     // 20
            offset = (offset << 1) + ((instruction >> 15) & 0b11111);       // 12:19
            offset = (offset << 5) + ((instruction >> 20) & 0b1);           // 11
            offset = (offset << 1) + ((instruction >> 21) & 0b1111111111);  // 1:10
            offset = offset << 1;                                           // 0
            jal(cpu, log, rd, offset);
            break;
        case 0x67: // 11001 11 - jalr
            offset = instruction >> 20;                                     // 0:11
            jalr(cpu, log, rd, rs1, offset);
            break;
        case 0x63: // 11000 11 - beq, bne, blt, bge, bltu, bgeu
            offset = (instruction >> 31);                                   // 12
            offset = (offset << 1) + ((instruction >> 7) & 0b1);            // 11
            offset = (offset << 1) + ((instruction >> 25) & 0b111111);      // 5:10
            offset = (offset << 6) + ((instruction >> 8) & 0b1111);         // 1:4
            offset = offset << 1;                                           // 0
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

    log->rd = getReg(cpu, rd);

    printLog(log);
    freeLog(log);
}