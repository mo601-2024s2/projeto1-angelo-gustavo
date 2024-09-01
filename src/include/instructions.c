#include <stdio.h>
#include <stdlib.h>
#include "instructions.h"


// Support functions
int32_t sign_extend(int32_t value, int bit_width) {
    // Calculate the sign bit position
    int32_t sign_bit = 1 << (bit_width - 1);

    // If the sign bit is set, extend the sign
    if (value & sign_bit) {
        value |= ~((1 << bit_width) - 1);  // Set the upper bits to 1
    } else {
        value &= (1 << bit_width) - 1;  // Clear the upper bits
    }
    return value;
}

// Vetor de resgistradores tal que é possível obter seu noma ABI a partir 
const char* registers[] = {
    "zero",  // x0
    "ra",    // x1
    "sp",    // x2
    "gp",    // x3
    "tp",    // x4
    "t0",    // x5
    "t1",    // x6
    "t2",    // x7
    "s0",    // x8
    "s1",    // x9
    "a0",    // x10
    "a1",    // x11
    "a2",    // x12
    "a3",    // x13
    "a4",    // x14
    "a5",    // x15
    "a6",    // x16
    "a7",    // x17
    "s2",    // x18
    "s3",    // x19
    "s4",    // x20
    "s5",    // x21
    "s6",    // x22
    "s7",    // x23
    "s8",    // x24
    "s9",    // x25
    "s10",   // x26
    "s11",   // x27
    "t3",    // x28
    "t4",    // x29
    "t5",    // x30
    "t6"     // x31
};


// Instructions to simulate
void lui(CPU* cpu, Log* log, int rd, int imm) {
    sprintf(log->disassembledInstruction, "lui     %s,%d", registers[rd], imm);

    uint32_t val = imm << 12;

    setReg(cpu, rd, val);
}

void auipc(CPU* cpu, Log* log, int rd, int imm) {
    sprintf(log->disassembledInstruction, "auipc   %s,%d", registers[rd], imm);

    uint32_t val = cpu->pc + (imm << 12);

    setReg(cpu, rd, val);
}

void addi(CPU* cpu, Log* log, int rd, int rs1, int imm) {
    sprintf(log->disassembledInstruction, "addi    %s,%s,%d", registers[rd], registers[rs1], imm);

    int32_t val = (int) getReg(cpu, rs1) + (int) (imm);

    setReg(cpu, rd, val);
}

void slti(CPU* cpu, Log* log, int rd, int rs1, int imm) {
    sprintf(log->disassembledInstruction, "slti    %s,%s,%d", registers[rd], registers[rs1], imm);

    uint32_t val = (int) getReg(cpu, rs1) < (int) (imm);

    setReg(cpu, rd, val);
}

void sltiu(CPU* cpu, Log* log, int rd, int rs1, int imm) {
    sprintf(log->disassembledInstruction, "sltiu   %s,%s,%d", registers[rd], registers[rs1], imm);

    uint32_t val = (uint32_t) getReg(cpu, rs1) < (uint32_t) (imm);

    setReg(cpu, rd, val);
}

void xori(CPU* cpu, Log* log, int rd, int rs1, int imm) {
    sprintf(log->disassembledInstruction, "xori    %s,%s,%d", registers[rd], registers[rs1], imm);

    uint32_t val = (int) getReg(cpu, rs1) ^ (int) (imm);

    setReg(cpu, rd, val);
}

void ori(CPU* cpu, Log* log, int rd, int rs1, int imm) {
    sprintf(log->disassembledInstruction, "ori     %s,%s,%d", registers[rd], registers[rs1], imm);

    uint32_t val = (int) getReg(cpu, rs1) | (int) (imm);

    setReg(cpu, rd, val);
}

void andi(CPU* cpu, Log* log, int rd, int rs1, int imm) {
    sprintf(log->disassembledInstruction, "andi    %s,%s,%d", registers[rd], registers[rs1], imm);

    uint32_t val = (int) getReg(cpu, rs1) & (int) (imm);

    setReg(cpu, rd, val);
}

void slli(CPU* cpu, Log* log, int rd, int rs1, int shamt) {
    sprintf(log->disassembledInstruction, "slli    %s,%s,%d", registers[rd], registers[rs1], shamt);

    uint32_t val = (int) getReg(cpu, rs1) << (shamt);

    setReg(cpu, rd, val);
}

void srli(CPU* cpu, Log* log, int rd, int rs1, int shamt) {
    sprintf(log->disassembledInstruction, "srli    %s,%s,%d", registers[rd], registers[rs1], shamt);

    // aparentemente pra o shift direito ser lógico tem q ser unsigned
    uint32_t val = (uint32_t) getReg(cpu, rs1) >> (shamt);

    setReg(cpu, rd, val);
}

void srai(CPU* cpu, Log* log, int rd, int rs1, int shamt) {
    sprintf(log->disassembledInstruction, "srai    %s,%s,%d", registers[rd], registers[rs1], shamt);

    uint32_t val = (int) getReg(cpu, rs1) >> (shamt);

    setReg(cpu, rd, val);
}

void add(CPU* cpu, Log* log, int rd, int rs1, int rs2) {
    sprintf(log->disassembledInstruction, "add     %s,%s,%s", registers[rd], registers[rs1], registers[rs2]);

    uint32_t val = (int) getReg(cpu, rs1) + (int) getReg(cpu, rs2);

    setReg(cpu, rd, val);
}

void sub(CPU* cpu, Log* log, int rd, int rs1, int rs2){
    sprintf(log->disassembledInstruction, "sub     %s,%s,%s", registers[rd], registers[rs1], registers[rs2]);

    uint32_t val = (int) getReg(cpu, rs1) - (int) getReg(cpu, rs2);

    setReg(cpu, rd, val);
}

void sll(CPU* cpu, Log* log, int rd, int rs1, int rs2) {
    sprintf(log->disassembledInstruction, "sll     %s,%s,%s", registers[rd], registers[rs1], registers[rs2]);

    uint32_t val = (int) getReg(cpu, rs1) << (int) getReg(cpu, rs2);

    setReg(cpu, rd, val);
}

void slt(CPU* cpu, Log* log, int rd, int rs1, int rs2) {
    sprintf(log->disassembledInstruction, "slt     %s,%s,%s", registers[rd], registers[rs1], registers[rs2]);

    uint32_t val = (int) getReg(cpu, rs1) < (int) getReg(cpu, rs2);

    setReg(cpu, rd, val);
}

void sltu(CPU* cpu, Log* log, int rd, int rs1, int rs2) {
    sprintf(log->disassembledInstruction, "sltu    %s,%s,%s", registers[rd], registers[rs1], registers[rs2]);

    uint32_t val = (uint32_t) getReg(cpu, rs1) < (uint32_t) getReg(cpu, rs2);

    setReg(cpu, rd, val);
}

void xorOp(CPU* cpu, Log* log, int rd, int rs1, int rs2) {
    sprintf(log->disassembledInstruction, "xor     %s,%s,%s", registers[rd], registers[rs1], registers[rs2]);

    uint32_t val = (int) getReg(cpu, rs1) ^ (int) getReg(cpu, rs2);

    setReg(cpu, rd, val);
}

void srl(CPU* cpu, Log* log, int rd, int rs1, int rs2) {
    sprintf(log->disassembledInstruction, "srl     %s,%s,%s", registers[rd], registers[rs1], registers[rs2]);

    uint32_t val = (uint32_t) getReg(cpu, rs1) >> (uint32_t) getReg(cpu, rs2);

    setReg(cpu, rd, val);
}

void sra(CPU* cpu, Log* log, int rd, int rs1, int rs2) {
    sprintf(log->disassembledInstruction, "sra     %s,%s,%s", registers[rd], registers[rs1], registers[rs2]);

    uint32_t val = (int) getReg(cpu, rs1) >> (int) getReg(cpu, rs2);

    setReg(cpu, rd, val);
}

void orOp(CPU* cpu, Log* log, int rd, int rs1, int rs2) {
    sprintf(log->disassembledInstruction, "or      %s,%s,%s", registers[rd], registers[rs1], registers[rs2]);

    uint32_t val = (int) getReg(cpu, rs1) | (int) getReg(cpu, rs2);

    setReg(cpu, rd, val);
}

void andOp(CPU* cpu, Log* log, int rd, int rs1, int rs2) {
    sprintf(log->disassembledInstruction, "and     %s,%s,%s", registers[rd], registers[rs1], registers[rs2]);

    uint32_t val = (int) getReg(cpu, rs1) & (int) getReg(cpu, rs2);

    setReg(cpu, rd, val);
}

// Pra gente n faz nada pq n temos multicore
void fence(CPU* cpu, Log* log, int pred, int succ) {
    sprintf(log->disassembledInstruction, "fence   %d,%d", pred, succ);
    return;
}
void fenceI(CPU* cpu, Log* log) {
    sprintf(log->disassembledInstruction, "fence.i ");
    return;
}

// Ao que tudo indica precisa de um outro registrador especial na CPU pra todas as instruções de csr
void csrrw(CPU* cpu, Log* log, int rd, int rs1, int csr) {
    sprintf(log->disassembledInstruction, "csrrw   %s,%s,csr", registers[rd], registers[rs1]);

    uint32_t val = (int) csr;

    setReg(cpu, rd, val);
    cpu->csr = rs1;
}

void csrrs(CPU* cpu, Log* log, int rd, int rs1, int csr) {
    sprintf(log->disassembledInstruction, "csrrs   %s,%s,csr", registers[rd], registers[rs1]);

    uint32_t val = (int) csr;
    setReg(cpu, rd, val);

    val = val | (int) getReg(cpu, rs1);

    cpu->csr = val;
}

void csrrc(CPU* cpu, Log* log, int rd, int rs1, int csr) {
    sprintf(log->disassembledInstruction, "csrrc   %s,%s,csr", registers[rd], registers[rs1]);

    uint32_t val = (int) csr;
    setReg(cpu, rd, val);

    val = val | ~(int) getReg(cpu, rs1);

    cpu->csr = val;
}

void csrrwi(CPU* cpu, Log* log, int rd, int uimm, int csr) {
    sprintf(log->disassembledInstruction, "csrrwi  %s,%d,csr", registers[rd], uimm);

    uint32_t val = (int) csr;
    setReg(cpu, rd, val);

    val = (uint32_t) uimm;

    cpu->csr = val;
}

void csrrsi(CPU* cpu, Log* log, int rd, int uimm, int csr) {
    sprintf(log->disassembledInstruction, "csrrsi  %s,%d,csr", registers[rd], uimm);

    uint32_t val = (int) csr;
    setReg(cpu, rd, val);

    val = val | (uint32_t) uimm;

    cpu->csr = val;
}
void csrrci(CPU* cpu, Log* log, int rd, int uimm, int csr) {
    sprintf(log->disassembledInstruction, "csrrci  %s,%d,csr", registers[rd], uimm);

    uint32_t val = (int) csr;
    setReg(cpu, rd, val);

    val = val | (uint32_t) uimm;

    cpu->csr = val;
}

void ecall(CPU* cpu, Log* log) {
    sprintf(log->disassembledInstruction, "ecall   ");

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
    sprintf(log->disassembledInstruction, "wfi     ");
}
void sfenceVma(CPU* cpu, Log* log, int rs1, int rs2) {
    sprintf(log->disassembledInstruction, "sfence.vma %s %s", registers[rs1], registers[rs2]);
}

void lb(CPU* cpu, Log* log, int rd, int rs1, int offset) {
    sprintf(log->disassembledInstruction, "lb      %s,%d(%s)", registers[rd], offset, registers[rs1]);

    int address = (int) getReg(cpu, rs1) + offset;
    uint32_t val = (uint32_t) getByte(cpu->memory, address);

    val = val || ((val << 24) & 0b10000000000000000000000000000000); // Sign extend
    val = val & 0b11111111111111111111111101111111;

    setReg(cpu, rd, val);
}
void lh(CPU* cpu, Log* log, int rd, int rs1, int offset) {
    sprintf(log->disassembledInstruction, "lh      %s,%d(%s)", registers[rd], offset, registers[rs1]);
    
    int address = (int) getReg(cpu, rs1) + offset;
    uint32_t val = (uint32_t) getByte(cpu->memory, address);
    val = (val << 8) + (uint32_t) getByte(cpu->memory, address + 1);

    val = val || ((val << 16) & 0b10000000000000000000000000000000); // Sign extend
    val = val & 0b11111111111111110111111111111111;

    setReg(cpu, rd, val);
}
void lw(CPU* cpu, Log* log, int rd, int rs1, int offset) {
    sprintf(log->disassembledInstruction, "lw      %s,%d(%s)", registers[rd], offset, registers[rs1]);
    
    int address = (int) getReg(cpu, rs1) + offset;
    uint32_t val = (uint32_t) getByte(cpu->memory, address);
    val = (val << 8) + (uint32_t) getByte(cpu->memory, address + 1);
    val = (val << 8) + (uint32_t) getByte(cpu->memory, address + 2);
    val = (val << 8) + (uint32_t) getByte(cpu->memory, address + 3);

    setReg(cpu, rd, val);
}
void lbu(CPU* cpu, Log* log, int rd, int rs1, int offset) {
    sprintf(log->disassembledInstruction, "lbu     %s,%d(%s)", registers[rd], offset, registers[rs1]);
    
    int address = (int) getReg(cpu, rs1) + offset;
    uint32_t val = (uint32_t) getByte(cpu->memory, address);

    setReg(cpu, rd, val);
}
void lhu(CPU* cpu, Log* log, int rd, int rs1, int offset) {
    sprintf(log->disassembledInstruction, "lhu     %s,%d(%s)", registers[rd], offset, registers[rs1]);
    
    int address = (int) getReg(cpu, rs1) + offset;
    uint32_t val = (uint32_t) getByte(cpu->memory, address);
    val = (val << 8) + (uint32_t) getByte(cpu->memory, address + 1);

    setReg(cpu, rd, val);
}

void sb(CPU* cpu, Log* log, int rs1, int rs2, int offset) {
    sprintf(log->disassembledInstruction, "sb      %s,%d(%s)", registers[rs2], offset, registers[rs1]);

    int address = (int) getReg(cpu, rs1) + offset;
    uint8_t val = (uint8_t) getReg(cpu, rs2) & 0b11111111;
    
    insertByte(cpu->memory, address, val);
}
void sh(CPU* cpu, Log* log, int rs1, int rs2, int offset) {
    sprintf(log->disassembledInstruction, "sh      %s,%d(%s)", registers[rs2], offset, registers[rs1]);

    int address = (int) getReg(cpu, rs1) + offset;
    uint32_t reg = getReg(cpu, rs2);
    uint8_t valL = (uint8_t) reg & 0b11111111;
    uint8_t valH = (uint8_t) (reg >> 8) & 0b11111111;
    
    insertByte(cpu->memory, address, valH);
    insertByte(cpu->memory, address + 1, valL);
}

void sw(CPU* cpu, Log* log, int rs1, int rs2, int offset) {
    sprintf(log->disassembledInstruction, "sw      %s,%d(%s)", registers[rs2], offset, registers[rs1]);

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

void jal(CPU* cpu, Log* log, int rd, int offset) {
    sprintf(log->disassembledInstruction, "jal     %s,%d", registers[rd], offset);

    setReg(cpu, rd, cpu->pc + 4);
    cpu->pc += offset - 4;
}
void jalr(CPU* cpu, Log* log, int rd, int rs1, int offset) {
    sprintf(log->disassembledInstruction, "jalr    %s,%s,%d", registers[rd], registers[rs1], offset);

    int t = cpu->pc + 4;
    cpu->pc = (getReg(cpu, rs1) + offset) & ~1;
    cpu->pc -= 4;
    setReg(cpu, rd, t);
}

void setBranchLog(Log* log, char instName[], int rs1, int rs2, int offset) {
    sprintf(log->disassembledInstruction, "%s %s %s %d", instName, registers[rs1], registers[rs2], offset);
}
void beq(CPU* cpu, Log* log, int rs1, int rs2, int offset) {
    setBranchLog(log, "beq    ", rs1, rs2, offset);
    if ((int) getReg(cpu, rs1) == (int) getReg(cpu, rs2))
        cpu->pc += offset - 4;
}
void bne(CPU* cpu, Log* log, int rs1, int rs2, int offset) {
    setBranchLog(log, "bne    ", rs1, rs2, offset);
    if ((int) getReg(cpu, rs1) != (int) getReg(cpu, rs2))
        cpu->pc += offset - 4;
}
void blt(CPU* cpu, Log* log, int rs1, int rs2, int offset) {
    setBranchLog(log, "blt    ", rs1, rs2, offset);
    if ((int) getReg(cpu, rs1) < (int) getReg(cpu, rs2))
        cpu->pc += offset - 4;
}
void bge(CPU* cpu, Log* log, int rs1, int rs2, int offset) {
    setBranchLog(log, "bge    ", rs1, rs2, offset);
    if ((int) getReg(cpu, rs1) >= (int) getReg(cpu, rs2))
        cpu->pc += offset - 4;
}
void bltu(CPU* cpu, Log* log, int rs1, int rs2, int offset) {
    setBranchLog(log, "bltu   ", rs1, rs2, offset);
    if (getReg(cpu, rs1) < getReg(cpu, rs2))
        cpu->pc += offset - 4;
}
void bgeu(CPU* cpu, Log* log, int rs1, int rs2, int offset) {
    setBranchLog(log, "bgeu   ", rs1, rs2, offset);
    if (getReg(cpu, rs1) >= getReg(cpu, rs2))
        cpu->pc += offset - 4;
}

// RV32M

void set3RLog(Log* log, char instName[], int rd, int rs1, int rs2) {
    sprintf(log->disassembledInstruction, "%s %s,%s,%s", instName, registers[rd], registers[rs1], registers[rs2]);
}
void mul(CPU* cpu, Log* log, int rd, int rs1, int rs2) {
    set3RLog(log, "mul    ", rd, rs1, rs2);

    setReg(cpu, rd, (int) getReg(cpu, rs1) * (int) getReg(cpu, rs2));
}
void mulh(CPU* cpu, Log* log, int rd, int rs1, int rs2) {
    set3RLog(log, "mulh   ", rd, rs1, rs2);

    setReg(cpu, rd, ((int) getReg(cpu, rs1) * (long) getReg(cpu, rs2)) >> 32);
}
void mulhsu(CPU* cpu, Log* log, int rd, int rs1, int rs2) {
    set3RLog(log, "mulhsu ", rd, rs1, rs2);

    setReg(cpu, rd, ((int) getReg(cpu, rs1) * (long) getReg(cpu, rs2)) >> 32);
}
void mulhu(CPU* cpu, Log* log, int rd, int rs1, int rs2) {
    set3RLog(log, "mulhu  ", rd, rs1, rs2);

    setReg(cpu, rd, (getReg(cpu, rs1) * (long) getReg(cpu, rs2)) >> 32);
}
void opDiv(CPU* cpu, Log* log, int rd, int rs1, int rs2) {
    set3RLog(log, "div    ", rd, rs1, rs2);

    setReg(cpu, rd, (int) getReg(cpu, rs1) / (int) getReg(cpu, rs2));
}
void divu(CPU* cpu, Log* log, int rd, int rs1, int rs2) {
    set3RLog(log, "divu   ", rd, rs1, rs2);

    setReg(cpu, rd, getReg(cpu, rs1) / getReg(cpu, rs2));
}
void rem(CPU* cpu, Log* log, int rd, int rs1, int rs2) {
    set3RLog(log, "rem    ", rd, rs1, rs2);

    setReg(cpu, rd, (int) getReg(cpu, rs1) % (int) getReg(cpu, rs2));
}
void remu(CPU* cpu, Log* log, int rd, int rs1, int rs2) {
    set3RLog(log, "remu   ", rd, rs1, rs2);

    setReg(cpu, rd, getReg(cpu, rs1) % getReg(cpu, rs2));
}