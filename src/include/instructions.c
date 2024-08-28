#include <stdio.h>
#include "instructions.h"

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

void wfi(CPU* cpu, Log* log) {
    sprintf(log->disassembledInstruction, "wfi");
}
void sfenceVma(CPU* cpu, Log* log, int rs1, int rs2) {
    sprintf(log->disassembledInstruction, "sfence.vma %d %d", rs1, rs2);
}

void lb(CPU* cpu, Log* log, int rd, int rs1, int offset) {
    sprintf(log->disassembledInstruction, "lb %d,%d(%d)", rd, offset, rs1);

    int address = (int) getReg(cpu, rs1) + offset;
    uint32_t val = (uint32_t) getByte(cpu->memory, address);

    val = val || ((val << 24) && 0b10000000000000000000000000000000); // Sign extend
    val = val && 0b11111111111111111111111101111111;

    setReg(cpu, rd, val);
}
void lh(CPU* cpu, Log* log, int rd, int rs1, int offset) {
    sprintf(log->disassembledInstruction, "lh %d,%d(%d)", rd, offset, rs1);
    
    int address = (int) getReg(cpu, rs1) + offset;
    uint32_t val = (uint32_t) getByte(cpu->memory, address);
    val = (val << 8) + (uint32_t) getByte(cpu->memory, address + 1);

    val = val || ((val << 16) && 0b10000000000000000000000000000000); // Sign extend
    val = val && 0b11111111111111110111111111111111;

    setReg(cpu, rd, val);
}
void lw(CPU* cpu, Log* log, int rd, int rs1, int offset) {
    sprintf(log->disassembledInstruction, "lw %d,%d(%d)", rd, offset, rs1);
    
    int address = (int) getReg(cpu, rs1) + offset;
    uint32_t val = (uint32_t) getByte(cpu->memory, address);
    val = (val << 8) + (uint32_t) getByte(cpu->memory, address + 1);
    val = (val << 8) + (uint32_t) getByte(cpu->memory, address + 2);
    val = (val << 8) + (uint32_t) getByte(cpu->memory, address + 3);

    setReg(cpu, rd, val);
}
void lbu(CPU* cpu, Log* log, int rd, int rs1, int offset) {
    sprintf(log->disassembledInstruction, "lbu %d,%d(%d)", rd, offset, rs1);
    
    int address = (int) getReg(cpu, rs1) + offset;
    uint32_t val = (uint32_t) getByte(cpu->memory, address);

    setReg(cpu, rd, val);
}
void lhu(CPU* cpu, Log* log, int rd, int rs1, int offset) {
    sprintf(log->disassembledInstruction, "lhu %d,%d(%d)", rd, offset, rs1);
    
    int address = (int) getReg(cpu, rs1) + offset;
    uint32_t val = (uint32_t) getByte(cpu->memory, address);
    val = (val << 8) + (uint32_t) getByte(cpu->memory, address + 1);

    setReg(cpu, rd, val);
}
void sb(CPU* cpu, Log* log, int rs1, int rs2, int offset);
void sh(CPU* cpu, Log* log, int rs1, int rs2, int offset);
void sw(CPU* cpu, Log* log, int rs1, int rs2, int offset);
void jal(CPU* cpu, Log* log, int rd, int offset);
void jalr(CPU* cpu, Log* log, int rd, int rs1, int offset);

void setBranchLog(Log* log, char instName[], int rs1, int rs2, int offset) {
    sprintf(log->disassembledInstruction, "%s x%d x%d %d", instName, rs1, rs2, offset);
}
void beq(CPU* cpu, Log* log, int rs1, int rs2, int offset) {
    setBranchLog(log, "beq", rs1, rs2, offset);
    if ((int) getReg(cpu, rs1) == (int) getReg(cpu, rs2))
        cpu->pc += offset - 4;
}
void bne(CPU* cpu, Log* log, int rs1, int rs2, int offset) {
    setBranchLog(log, "bne", rs1, rs2, offset);
    if ((int) getReg(cpu, rs1) != (int) getReg(cpu, rs2))
        cpu->pc += offset - 4;
}
void blt(CPU* cpu, Log* log, int rs1, int rs2, int offset) {
    setBranchLog(log, "blt", rs1, rs2, offset);
    if ((int) getReg(cpu, rs1) < (int) getReg(cpu, rs2))
        cpu->pc += offset - 4;
}
void bge(CPU* cpu, Log* log, int rs1, int rs2, int offset) {
    setBranchLog(log, "bge", rs1, rs2, offset);
    if ((int) getReg(cpu, rs1) >= (int) getReg(cpu, rs2))
        cpu->pc += offset - 4;
}
void bltu(CPU* cpu, Log* log, int rs1, int rs2, int offset) {
    setBranchLog(log, "bltu", rs1, rs2, offset);
    if (getReg(cpu, rs1) < getReg(cpu, rs2))
        cpu->pc += offset - 4;
}
void bgeu(CPU* cpu, Log* log, int rs1, int rs2, int offset) {
    setBranchLog(log, "bgeu", rs1, rs2, offset);
    if (getReg(cpu, rs1) >= getReg(cpu, rs2))
        cpu->pc += offset - 4;
}

// RV32M

void mul(CPU* cpu, Log* log, int rd, int rs1, int rs2);
void mulh(CPU* cpu, Log* log, int rd, int rs1, int rs2);
void mulhsu(CPU* cpu, Log* log, int rd, int rs1, int rs2);
void mulhu(CPU* cpu, Log* log, int rd, int rs1, int rs2);
void opDiv(CPU* cpu, Log* log, int rd, int rs1, int rs2);
void divu(CPU* cpu, Log* log, int rd, int rs1, int rs2);
void rem(CPU* cpu, Log* log, int rd, int rs1, int rs2);
void remu(CPU* cpu, Log* log, int rd, int rs1, int rs2);