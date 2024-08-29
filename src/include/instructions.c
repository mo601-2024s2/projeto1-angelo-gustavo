#include <stdio.h>
#include <stdlib.h>
#include "instructions.h"

void lui(CPU* cpu, Log* log, int rd, int imm) {
    sprintf(log->disassembledInstruction, "lui %d,%d", rd, imm);

    uint32_t val = imm << 12;

    setReg(cpu, rd, val);
}

void auipc(CPU* cpu, Log* log, int rd, int imm) {
    sprintf(log->disassembledInstruction, "auipc %d,%d", rd, imm);

    uint32_t val = cpu->pc + (imm << 12);

    setReg(cpu, rd, val);
}

void addi(CPU* cpu, Log* log, int rd, int rs1, int imm) {
    sprintf(log->disassembledInstruction, "addi %d,%d,%d", rd, rs1, imm);

    uint32_t val = (int) getReg(cpu, rs1) + (int) (imm);

    setReg(cpu, rd, val);
}

void slti(CPU* cpu, Log* log, int rd, int rs1, int imm) {
    sprintf(log->disassembledInstruction, "slti %d,%d,%d", rd, rs1, imm);

    uint32_t val = (int) getReg(cpu, rs1) < (int) (imm);

    setReg(cpu, rd, val);
}

void sltiu(CPU* cpu, Log* log, int rd, int rs1, int imm) {
    sprintf(log->disassembledInstruction, "sltiu %d,%d,%d", rd, rs1, imm);

    uint32_t val = (uint32_t) getReg(cpu, rs1) < (uint32_t) (imm);

    setReg(cpu, rd, val);
}

void xori(CPU* cpu, Log* log, int rd, int rs1, int imm) {
    sprintf(log->disassembledInstruction, "xori %d,%d,%d", rd, rs1, imm);

    uint32_t val = (int) getReg(cpu, rs1) ^ (int) (imm);

    setReg(cpu, rd, val);
}

void ori(CPU* cpu, Log* log, int rd, int rs1, int imm) {
    sprintf(log->disassembledInstruction, "ori %d,%d,%d", rd, rs1, imm);

    uint32_t val = (int) getReg(cpu, rs1) | (int) (imm);

    setReg(cpu, rd, val);
}

void andi(CPU* cpu, Log* log, int rd, int rs1, int imm) {
    sprintf(log->disassembledInstruction, "andi %d,%d,%d", rd, rs1, imm);

    uint32_t val = (int) getReg(cpu, rs1) & (int) (imm);

    setReg(cpu, rd, val);
}

void slli(CPU* cpu, Log* log, int rd, int rs1, int shamt) {
    sprintf(log->disassembledInstruction, "slli %d,%d,%d", rd, rs1, shamt);

    uint32_t val = (int) getReg(cpu, rs1) << (shamt);

    setReg(cpu, rd, val);
}

void srli(CPU* cpu, Log* log, int rd, int rs1, int shamt) {
    sprintf(log->disassembledInstruction, "srli %d,%d,%d", rd, rs1, shamt);

    // aparentemente pra o shift direito ser lógico tem q ser unsigned
    uint32_t val = (uint32_t) getReg(cpu, rs1) >> (shamt);

    setReg(cpu, rd, val);
}

void srai(CPU* cpu, Log* log, int rd, int rs1, int shamt) {
    sprintf(log->disassembledInstruction, "srai %d,%d,%d", rd, rs1, shamt);

    uint32_t val = (int) getReg(cpu, rs1) >> (shamt);

    setReg(cpu, rd, val);
}

void add(CPU* cpu, Log* log, int rd, int rs1, int rs2) {
    sprintf(log->disassembledInstruction, "add %d,%d,%d", rd, rs1, rs2);

    uint32_t val = (int) getReg(cpu, rs1) + (int) getReg(cpu, rs2);

    setReg(cpu, rd, val);
}

void sub(CPU* cpu, Log* log, int rd, int rs1, int rs2){
    sprintf(log->disassembledInstruction, "sub %d,%d,%d", rd, rs1, rs2);

    uint32_t val = (int) getReg(cpu, rs1) - (int) getReg(cpu, rs2);

    setReg(cpu, rd, val);
}

void sll(CPU* cpu, Log* log, int rd, int rs1, int rs2) {
    sprintf(log->disassembledInstruction, "sll %d,%d,%d", rd, rs1, rs2);

    uint32_t val = (int) getReg(cpu, rs1) << (int) getReg(cpu, rs2);

    setReg(cpu, rd, val);
}

void slt(CPU* cpu, Log* log, int rd, int rs1, int rs2) {
    sprintf(log->disassembledInstruction, "slt %d,%d,%d", rd, rs1, rs2);

    uint32_t val = (int) getReg(cpu, rs1) < (int) getReg(cpu, rs2);

    setReg(cpu, rd, val);
}

void sltu(CPU* cpu, Log* log, int rd, int rs1, int rs2) {
    sprintf(log->disassembledInstruction, "sltu %d,%d,%d", rd, rs1, rs2);

    uint32_t val = (uint32_t) getReg(cpu, rs1) < (uint32_t) getReg(cpu, rs2);

    setReg(cpu, rd, val);
}

void xorOp(CPU* cpu, Log* log, int rd, int rs1, int rs2) {
    sprintf(log->disassembledInstruction, "xor %d,%d,%d", rd, rs1, rs2);

    uint32_t val = (int) getReg(cpu, rs1) ^ (int) getReg(cpu, rs2);

    setReg(cpu, rd, val);
}

void srl(CPU* cpu, Log* log, int rd, int rs1, int rs2) {
    sprintf(log->disassembledInstruction, "srl %d,%d,%d", rd, rs1, rs2);

    uint32_t val = (uint32_t) getReg(cpu, rs1) >> (uint32_t) getReg(cpu, rs2);

    setReg(cpu, rd, val);
}

void sra(CPU* cpu, Log* log, int rd, int rs1, int rs2) {
    sprintf(log->disassembledInstruction, "sra %d,%d,%d", rd, rs1, rs2);

    uint32_t val = (int) getReg(cpu, rs1) >> (int) getReg(cpu, rs2);

    setReg(cpu, rd, val);
}

void orOp(CPU* cpu, Log* log, int rd, int rs1, int rs2) {
    sprintf(log->disassembledInstruction, "or %d,%d,%d", rd, rs1, rs2);

    uint32_t val = (int) getReg(cpu, rs1) | (int) getReg(cpu, rs2);

    setReg(cpu, rd, val);
}

void andOp(CPU* cpu, Log* log, int rd, int rs1, int rs2) {
    sprintf(log->disassembledInstruction, "and %d,%d,%d", rd, rs1, rs2);

    uint32_t val = (int) getReg(cpu, rs1) & (int) getReg(cpu, rs2);

    setReg(cpu, rd, val);
}

// Pra gente n faz nada pq n temos multicore
void fence(CPU* cpu, Log* log, int pred, int succ) {
    sprintf(log->disassembledInstruction, "fence %d,%d", pred, succ);
    return;
}
void fenceI(CPU* cpu, Log* log) {
    sprintf(log->disassembledInstruction, "fence.i");
    return;
}

// Ao que tudo indica precisa de um outro registrador especial na CPU pra todas as instruções de csr
void csrrw(CPU* cpu, Log* log, int rd, int rs1, int csr) {
    sprintf(log->disassembledInstruction, "csrrw %d,%d,%d", rd, rs1, csr);

    uint32_t val = (int) csr;

    setReg(cpu, rd, val);
    cpu->csr = rs1;
}

void csrrs(CPU* cpu, Log* log, int rd, int rs1, int csr) {
    sprintf(log->disassembledInstruction, "csrrs %d,%d,%d", rd, rs1, csr);

    uint32_t val = (int) csr;
    setReg(cpu, rd, val);

    val = val | (int) getReg(cpu, rs1);

    cpu->csr = val;
}

void csrrc(CPU* cpu, Log* log, int rd, int rs1, int csr) {
    sprintf(log->disassembledInstruction, "csrrc %d,%d,%d", rd, rs1, csr);

    uint32_t val = (int) csr;
    setReg(cpu, rd, val);

    val = val | ~(int) getReg(cpu, rs1);

    cpu->csr = val;
}

void csrrwi(CPU* cpu, Log* log, int rd, int uimm, int csr) {
    sprintf(log->disassembledInstruction, "csrrwi %d,%d,%d", rd, uimm, csr);

    uint32_t val = (int) csr;
    setReg(cpu, rd, val);

    val = (uint32_t) uimm;

    cpu->csr = val;
}

void csrrsi(CPU* cpu, Log* log, int rd, int uimm, int csr) {
    sprintf(log->disassembledInstruction, "csrrsi %d,%d,%d", rd, uimm, csr);

    uint32_t val = (int) csr;
    setReg(cpu, rd, val);

    val = val | (uint32_t) uimm;

    cpu->csr = val;
}
void csrrci(CPU* cpu, Log* log, int rd, int uimm, int csr) {
    sprintf(log->disassembledInstruction, "csrrci %d,%d,%d", rd, uimm, csr);

    uint32_t val = (int) csr;
    setReg(cpu, rd, val);

    val = val | (uint32_t) uimm;

    cpu->csr = val;
}

void ecall(CPU* cpu, Log* log) {
    sprintf(log->disassembledInstruction, "ecall");

    // ecall handler
    // atualizar conforme necessário, pq senão é vai ter muita coisa inútil e demorado de fazer
    int a0 = getReg(cpu, 10);
    
    switch (a0)
    {
    case 1:
        printf("ECALL: Print integer: %d\n", a0);
        break;
    
    default:
        break;
    }
}

void ebreak(CPU* cpu, Log* log) {
    printf("EBREAK: Breakpoint encountered!\n");
    // Simulate stopping execution (e.g., invoke a debugger or exit the program)
    exit(EXIT_FAILURE);
}
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

    val = val || ((val << 24) & 0b10000000000000000000000000000000); // Sign extend
    val = val & 0b11111111111111111111111101111111;

    setReg(cpu, rd, val);
}
void lh(CPU* cpu, Log* log, int rd, int rs1, int offset) {
    sprintf(log->disassembledInstruction, "lh %d,%d(%d)", rd, offset, rs1);
    
    int address = (int) getReg(cpu, rs1) + offset;
    uint32_t val = (uint32_t) getByte(cpu->memory, address);
    val = (val << 8) + (uint32_t) getByte(cpu->memory, address + 1);

    val = val || ((val << 16) & 0b10000000000000000000000000000000); // Sign extend
    val = val & 0b11111111111111110111111111111111;

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

void sb(CPU* cpu, Log* log, int rs1, int rs2, int offset) {
    sprintf(log->disassembledInstruction, "sb %d,%d(%d)", rs2, offset, rs1);

    int address = (int) getReg(cpu, rs1) + offset;
    uint8_t val = (uint8_t) getReg(cpu, rs2) & 0b11111111;
    
    insertByte(cpu->memory, address, val);
}
void sh(CPU* cpu, Log* log, int rs1, int rs2, int offset) {
    sprintf(log->disassembledInstruction, "sh %d,%d(%d)", rs2, offset, rs1);

    int address = (int) getReg(cpu, rs1) + offset;
    uint32_t reg = getReg(cpu, rs2);
    uint8_t valL = (uint8_t) reg & 0b11111111;
    uint8_t valH = (uint8_t) (reg >> 8) & 0b11111111;
    
    insertByte(cpu->memory, address, valH);
    insertByte(cpu->memory, address + 1, valL);
}

void sw(CPU* cpu, Log* log, int rs1, int rs2, int offset) {
    sprintf(log->disassembledInstruction, "sw %d,%d(%d)", rs2, offset, rs1);

    int address = (int) getReg(cpu, rs1) + offset;
    uint32_t reg = getReg(cpu, rs2);
    uint8_t valL = (uint8_t) reg & 0b11111111;
    uint8_t valLH = (uint8_t) (reg >> 8) & 0b11111111;
    uint8_t valHL = (uint8_t) (reg >> 16) & 0b11111111;
    uint8_t valH = (uint8_t) (reg >> 24) & 0b11111111;

    insertByte(cpu->memory, address, valH);
    insertByte(cpu->memory, address + 1, valHL);
    insertByte(cpu->memory, address + 2, valLH);
    insertByte(cpu->memory, address + 3, valL);
}

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