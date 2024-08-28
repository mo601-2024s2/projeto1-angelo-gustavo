/*
    Implementations of specific instructions
*/

#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include <stdint.h>
#include "log.h"
#include "cpu.h"

// RV32I

void lui(CPU* cpu, Log* log, int rd, int imm);
void auipc(CPU* cpu, Log* log, int rd, int imm);
void addi(CPU* cpu, Log* log, int rd, int rs1, int imm);
void slti(CPU* cpu, Log* log, int rd, int rs1, int imm);
void sltiu(CPU* cpu, Log* log, int rd, int rs1, int imm);
void xori(CPU* cpu, Log* log, int rd, int rs1, int imm);
void ori(CPU* cpu, Log* log, int rd, int rs1, int imm);
void andi(CPU* cpu, Log* log, int rd, int rs1, int imm);
void slli(CPU* cpu, Log* log, int rd, int rs1, int shamt);
void srli(CPU* cpu, Log* log, int rd, int rs1, int shamt);
void srai(CPU* cpu, Log* log, int rd, int rs1, int shamt);
void add(CPU* cpu, Log* log, int rd, int rs1, int rs2);
void sub(CPU* cpu, Log* log, int rd, int rs1, int rs2);
void sll(CPU* cpu, Log* log, int rd, int rs1, int rs2);
void slt(CPU* cpu, Log* log, int rd, int rs1, int rs2);
void sltu(CPU* cpu, Log* log, int rd, int rs1, int rs2);
void xorOp(CPU* cpu, Log* log, int rd, int rs1, int rs2);
void srl(CPU* cpu, Log* log, int rd, int rs1, int rs2);
void sra(CPU* cpu, Log* log, int rd, int rs1, int rs2);
void orOp(CPU* cpu, Log* log, int rd, int rs1, int rs2);
void andOp(CPU* cpu, Log* log, int rd, int rs1, int rs2);
void fence(CPU* cpu, Log* log, int pred, int succ);
void fenceI(CPU* cpu, Log* log);
void csrrw(CPU* cpu, Log* log, int rd, int rs1, int csr);
void csrrs(CPU* cpu, Log* log, int rd, int rs1, int csr);
void csrrc(CPU* cpu, Log* log, int rd, int rs1, int csr);
void csrrwi(CPU* cpu, Log* log, int rd, int uimm, int csr);
void csrrsi(CPU* cpu, Log* log, int rd, int uimm, int csr);
void csrrci(CPU* cpu, Log* log, int rd, int uimm, int csr);
void ecall(CPU* cpu, Log* log);
void ebreak(CPU* cpu, Log* log);
void uret(CPU* cpu, Log* log);
void sret(CPU* cpu, Log* log);
void mret(CPU* cpu, Log* log);
void wfi(CPU* cpu, Log* log);
void sfenceVma(CPU* cpu, Log* log, int rs1, int rs2);
void lb(CPU* cpu, Log* log, int rd, int rs1, int offset);
void lh(CPU* cpu, Log* log, int rd, int rs1, int offset);
void lw(CPU* cpu, Log* log, int rd, int rs1, int offset);
void lbu(CPU* cpu, Log* log, int rd, int rs1, int offset);
void lhu(CPU* cpu, Log* log, int rd, int rs1, int offset);
void sb(CPU* cpu, Log* log, int rs1, int rs2, int offset);
void sh(CPU* cpu, Log* log, int rs1, int rs2, int offset);
void sw(CPU* cpu, Log* log, int rs1, int rs2, int offset);
void jal(CPU* cpu, Log* log, int rd, int offset);
void jalr(CPU* cpu, Log* log, int rd, int rs1, int offset);
void beq(CPU* cpu, Log* log, int rs1, int rs2, int offset);
void bne(CPU* cpu, Log* log, int rs1, int rs2, int offset);
void blt(CPU* cpu, Log* log, int rs1, int rs2, int offset);
void bge(CPU* cpu, Log* log, int rs1, int rs2, int offset);
void bltu(CPU* cpu, Log* log, int rs1, int rs2, int offset);
void bgeu(CPU* cpu, Log* log, int rs1, int rs2, int offset);

// RV32M

void mul(CPU* cpu, Log* log, int rd, int rs1, int rs2);
void mulh(CPU* cpu, Log* log, int rd, int rs1, int rs2);
void mulhsu(CPU* cpu, Log* log, int rd, int rs1, int rs2);
void mulhu(CPU* cpu, Log* log, int rd, int rs1, int rs2);
void opDiv(CPU* cpu, Log* log, int rd, int rs1, int rs2);
void divu(CPU* cpu, Log* log, int rd, int rs1, int rs2);
void rem(CPU* cpu, Log* log, int rd, int rs1, int rs2);
void remu(CPU* cpu, Log* log, int rd, int rs1, int rs2);

#endif