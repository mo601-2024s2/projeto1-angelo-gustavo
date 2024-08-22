/*
    Implementations of specific instructions
*/

#include <stdint.h>

typedef struct CPU;

// RV32I

void lui(CPU* cpu, int rd, int imm);
void auipc(CPU* cpu, int rd, int imm);
void addi(CPU* cpu, int rd, int rs1, int imm);
void slti(CPU* cpu, int rd, int rs1, int imm);
void sltiu(CPU* cpu, int rd, int rs1, int imm);
void xori(CPU* cpu, int rd, int rs1, int imm);
void ori(CPU* cpu, int rd, int rs1, int imm);
void andi(CPU* cpu, int rd, int rs1, int imm);
void slli(CPU* cpu, int rd, int rs1, int shamt);
void srli(CPU* cpu, int rd, int rs1, int shamt);
void srai(CPU* cpu, int rd, int rs1, int shamt);
void add(CPU* cpu, int rd, int rs1, int rs2);
void sub(CPU* cpu, int rd, int rs1, int rs2);
void sll(CPU* cpu, int rd, int rs1, int rs2);
void slt(CPU* cpu, int rd, int rs1, int rs2);
void sltu(CPU* cpu, int rd, int rs1, int rs2);
void xorOp(CPU* cpu, int rd, int rs1, int rs2);
void srl(CPU* cpu, int rd, int rs1, int rs2);
void sra(CPU* cpu, int rd, int rs1, int rs2);
void orOp(CPU* cpu, int rd, int rs1, int rs2);
void andOp(CPU* cpu, int rd, int rs1, int rs2);
void fence(CPU* cpu, int pred, int succ);
void fenceI(CPU* cpu);
void csrrw(CPU* cpu, int rd, int rs1, int csr);
void csrrs(CPU* cpu, int rd, int rs1, int csr);
void csrrc(CPU* cpu, int rd, int rs1, int csr);
void csrrwi(CPU* cpu, int rd, int uimm, int csr);
void csrrsi(CPU* cpu, int rd, int uimm, int csr);
void csrrci(CPU* cpu, int rd, int uimm, int csr);
void ecall(CPU* cpu);
void ebreak(CPU* cpu);
void uret(CPU* cpu);
void sret(CPU* cpu);
void mret(CPU* cpu);
void wfi(CPU* cpu);
void sfenceVma(CPU* cpu, int rs1, int rs2);
void lb(CPU* cpu, int rd, int rs1, int offset);
void lh(CPU* cpu, int rd, int rs1, int offset);
void lw(CPU* cpu, int rd, int rs1, int offset);
void lbu(CPU* cpu, int rd, int rs1, int offset);
void lhu(CPU* cpu, int rd, int rs1, int offset);
void sb(CPU* cpu, int rs1, int rs2, int offset);
void sh(CPU* cpu, int rs1, int rs2, int offset);
void sw(CPU* cpu, int rs1, int rs2, int offset);
void jal(CPU* cpu, int rd, int offset);
void jalr(CPU* cpu, int rd, int rs1, int offset);
void beq(CPU* cpu, int rs1, int rs2, int offset);
void bne(CPU* cpu, int rs1, int rs2, int offset);
void blt(CPU* cpu, int rs1, int rs2, int offset);
void bge(CPU* cpu, int rs1, int rs2, int offset);
void bltu(CPU* cpu, int rs1, int rs2, int offset);
void bgeu(CPU* cpu, int rs1, int rs2, int offset);

// RV32M

void mul(CPU* cpu, int rd, int rs1, int rs2);
void mulh(CPU* cpu, int rd, int rs1, int rs2);
void mulhsu(CPU* cpu, int rd, int rs1, int rs2);
void mulhu(CPU* cpu, int rd, int rs1, int rs2);
void div(CPU* cpu, int rd, int rs1, int rs2);
void divu(CPU* cpu, int rd, int rs1, int rs2);
void rem(CPU* cpu, int rd, int rs1, int rs2);
void remu(CPU* cpu, int rd, int rs1, int rs2);