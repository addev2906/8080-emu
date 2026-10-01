#include "8080.hpp"
#include <cstdint>
#include <stdio.h>
#include <iostream>
#include <sys/types.h>

int Disassemble8080::Disassemble(unsigned char* byte,int pc){
    int opbytes = 1;
    unsigned char* opcode = &byte[pc];
    printf ("%04x ", pc);
    switch(*opcode){
        case 0x00: printf("NOP"); break;
        case 0x01: printf("LXI B #$%02X%02X",opcode[2],opcode[1]);opbytes=3;break;
        case 0x02: printf("STAX B");break;
        case 0x03: printf("INX B");break;
        case 0x04: printf("INR B");break;
        case 0x05: printf("DCR B");break;
        case 0x06: printf("MVI B #$%02X",opcode[1]);opbytes=2;break;
        case 0x07: printf("RLC");break;
        case 0x08: printf("NOP");break;
        case 0x09: printf("DAD B");break;
        case 0x0a: printf("LDAX B");break;
        case 0x0b: printf("DCX B");break;
        case 0x0c: printf("INR C");break;
        case 0x0d: printf("DCR C");break;
        case 0x0e: printf("MVI C #$%02X",opcode[1]);opbytes=2;break;
        case 0x0f: printf("RRC");break;
        case 0x10: printf("NOP");break;
        case 0x11: printf("LXI D #$%02X%02X",opcode[2],opcode[1]);opbytes=3;break;
        case 0x12: printf("STAX D");break;
        case 0x13: printf("INX D");break;
        case 0x14: printf("INR D");break;
        case 0x15: printf("DCR D");break;
        case 0x16: printf("MVI D #$%02X",opcode[1]);opbytes=2;break;
        case 0x17: printf("RAL");break;
        case 0x18: printf("NOP");break;
        case 0x19: printf("DAD D");break;
        case 0x1a: printf("LDAX D");break;
        case 0x1b: printf("DCX D");break;
        case 0x1c: printf("INR E");break;
        case 0x1d: printf("DCR E");break;
        case 0x1e: printf("MVI E #$%02X",opcode[1]);opbytes=2;break;
        case 0x1f: printf("RAR");break;
        case 0x20: printf("NOP");break;
        case 0x21: printf("LXI H #$%02X%02X",opcode[2],opcode[1]);opbytes=3;break;
        case 0x22: printf("SHLD $%02X%02X",opcode[2],opcode[1]);opbytes=3;break;
        case 0x23: printf("INX H");break;
        case 0x24: printf("INR H");break;
        case 0x25: printf("DCR H");break;
        case 0x26: printf("MVI H #$%02X",opcode[1]);opbytes=2;break;
        case 0x27: printf("DAA");break;
        case 0x28: printf("NOP");break;
        case 0x29: printf("DAD H");break;
        case 0x2a: printf("LHLD $%02X%02X",opcode[2],opcode[1]);opbytes=3;break;
        case 0x2b: printf("DCX H");break;
        case 0x2c: printf("INR L");break;
        case 0x2d: printf("DCR L");break;
        case 0x2e: printf("MVI L #$%02X",opcode[1]);opbytes=2;break;
        case 0x2f: printf("CMA");break;
        case 0x30: printf("NOP");break;
        case 0x31: printf("LXI SP #$%02X%02X",opcode[2],opcode[1]);opbytes=3;break;
        case 0x32: printf("STA $%02X%02X",opcode[2],opcode[1]);opbytes=3;break;
        case 0x33: printf("INX SP");break;
        case 0x34: printf("INR M");break;
        case 0x35: printf("DCR M");break;
        case 0x36: printf("MVI M #$%02X",opcode[1]);opbytes=2;break;
        case 0x37: printf("STC");break;
        case 0x38: printf("NOP");break;
        case 0x39: printf("DAD SP");break;
        case 0x3a: printf("LDA $%02X%02X",opcode[2],opcode[1]);opbytes=3;break;
        case 0x3b: printf("DCX SP");break;
        case 0x3c: printf("INR A");break;
        case 0x3d: printf("DCR A");break;
        case 0x3e: printf("MVI A #$%02X",opcode[1]);opbytes=2;break;
        case 0x3f: printf("CMC");break;
        case 0x40: printf("MOV B,B");break;
        case 0x41: printf("MOV B,C");break;
        case 0x42: printf("MOV B,D");break;
        case 0x43: printf("MOV B,E");break;
        case 0x44: printf("MOV B,H");break;
        case 0x45: printf("MOV B,L");break;
        case 0x46: printf("MOV B,M");break;
        case 0x47: printf("MOV B,A");break;
        case 0x48: printf("MOV C,B");break;
        case 0x49: printf("MOV C,C");break;
        case 0x4a: printf("MOV C,D");break;
        case 0x4b: printf("MOV C,E");break;
        case 0x4c: printf("MOV C,H");break;
        case 0x4d: printf("MOV C,L");break;
        case 0x4e: printf("MOV C,M");break;
        case 0x4f: printf("MOV C,A");break;
        case 0x50: printf("MOV D,B");break;
        case 0x51: printf("MOV D,C");break;
        case 0x52: printf("MOV D,D");break;
        case 0x53: printf("MOV D,E");break;
        case 0x54: printf("MOV D,H");break;
        case 0x55: printf("MOV D,L");break;
        case 0x56: printf("MOV D,M");break;
        case 0x57: printf("MOV D,A");break;
        case 0x58: printf("MOV E,B");break;
        case 0x59: printf("MOV E,C");break;
        case 0x5a: printf("MOV E,D");break;
        case 0x5b: printf("MOV E,E");break;
        case 0x5c: printf("MOV E,H");break;
        case 0x5d: printf("MOV E,L");break;
        case 0x5e: printf("MOV E,M");break;
        case 0x5f: printf("MOV E,A");break;
        case 0x60: printf("MOV H,B");break;
        case 0x61: printf("MOV H,C");break;
        case 0x62: printf("MOV H,D");break;
        case 0x63: printf("MOV H,E");break;
        case 0x64: printf("MOV H,H");break;
        case 0x65: printf("MOV H,L");break;
        case 0x66: printf("MOV H,M");break;
        case 0x67: printf("MOV H,A");break;
        case 0x68: printf("MOV L,B");break;
        case 0x69: printf("MOV L,C");break;
        case 0x6a: printf("MOV L,D");break;
        case 0x6b: printf("MOV L,E");break;
        case 0x6c: printf("MOV L,H");break;
        case 0x6d: printf("MOV L,L");break;
        case 0x6e: printf("MOV L,M");break;
        case 0x6f: printf("MOV L,A");break;
        case 0x70: printf("MOV M,B");break;
        case 0x71: printf("MOV M,C");break;
        case 0x72: printf("MOV M,D");break;
        case 0x73: printf("MOV M,E");break;
        case 0x74: printf("MOV M,H");break;
        case 0x75: printf("MOV M,L");break;
        case 0x76: printf("HLT");break;
        case 0x77: printf("MOV M,A");break;
        case 0x78: printf("MOV A,B");break;
        case 0x79: printf("MOV A,C");break;
        case 0x7a: printf("MOV A,D");break;
        case 0x7b: printf("MOV A,E");break;
        case 0x7c: printf("MOV A,H");break;
        case 0x7d: printf("MOV A,L");break;
        case 0x7e: printf("MOV A,M");break;
        case 0x7f: printf("MOV A,A");break;
        case 0x80: printf("ADD B");break;
        case 0x81: printf("ADD C");break;
        case 0x82: printf("ADD D");break;
        case 0x83: printf("ADD E");break;
        case 0x84: printf("ADD H");break;
        case 0x85: printf("ADD L");break;
        case 0x86: printf("ADD M");break;
        case 0x87: printf("ADD A");break;
        case 0x88: printf("ADC B");break;
        case 0x89: printf("ADC C");break;
        case 0x8a: printf("ADC D");break;
        case 0x8b: printf("ADC E");break;
        case 0x8c: printf("ADC H");break;
        case 0x8d: printf("ADC L");break;
        case 0x8e: printf("ADC M");break;
        case 0x8f: printf("ADC A");break;
        case 0x90: printf("SUB B");break;
        case 0x91: printf("SUB C");break;
        case 0x92: printf("SUB D");break;
        case 0x93: printf("SUB E");break;
        case 0x94: printf("SUB H");break;
        case 0x95: printf("SUB L");break;
        case 0x96: printf("SUB M");break;
        case 0x97: printf("SUB A");break;
        case 0x98: printf("SBB B");break;
        case 0x99: printf("SBB C");break;
        case 0x9a: printf("SBB D");break;
        case 0x9b: printf("SBB E");break;
        case 0x9c: printf("SBB H");break;
        case 0x9d: printf("SBB L");break;
        case 0x9e: printf("SBB M");break;
        case 0x9f: printf("SBB A");break;
        case 0xa0: printf("ANA B");break;
        case 0xa1: printf("ANA C");break;
        case 0xa2: printf("ANA D");break;
        case 0xa3: printf("ANA E");break;
        case 0xa4: printf("ANA H");break;
        case 0xa5: printf("ANA L");break;
        case 0xa6: printf("ANA M");break;
        case 0xa7: printf("ANA A");break;
        case 0xa8: printf("XRA B");break;
        case 0xa9: printf("XRA C");break;
        case 0xaa: printf("XRA D");break;
        case 0xab: printf("XRA E");break;
        case 0xac: printf("XRA H");break;
        case 0xad: printf("XRA L");break;
        case 0xae: printf("XRA M");break;
        case 0xaf: printf("XRA A");break;
        case 0xb0: printf("ORA B");break;
        case 0xb1: printf("ORA C");break;
        case 0xb2: printf("ORA D");break;
        case 0xb3: printf("ORA E");break;
        case 0xb4: printf("ORA H");break;
        case 0xb5: printf("ORA L");break;
        case 0xb6: printf("ORA M");break;
        case 0xb7: printf("ORA A");break;
        case 0xb8: printf("CMP B");break;
        case 0xb9: printf("CMP C");break;
        case 0xba: printf("CMP D");break;
        case 0xbb: printf("CMP E");break;
        case 0xbc: printf("CMP H");break;
        case 0xbd: printf("CMP L");break;
        case 0xbe: printf("CMP M");break;
        case 0xbf: printf("CMP A");break;
        case 0xc0: printf("RNZ");break;
        case 0xc1: printf("POP B");break;
        case 0xc2: printf("JNZ $%02X%02X",opcode[2],opcode[1]);opbytes=3;break;
        case 0xc3: printf("JMP $%02X%02X",opcode[2],opcode[1]);opbytes=3;break;
        case 0xc4: printf("CNZ $%02X%02X",opcode[2],opcode[1]);opbytes=3;break;
        case 0xc5: printf("PUSH B");break;
        case 0xc6: printf("ADI #$%02X",opcode[1]);opbytes=2;break;
        case 0xc7: printf("RST0");break;
        case 0xc8: printf("RZ");break;
        case 0xc9: printf("RET");break;
        case 0xca: printf("JZ $%02X%02X",opcode[2],opcode[1]);opbytes=3;break;
        case 0xcb: printf("JMP $%02X%02X",opcode[2],opcode[1]);opbytes=3;break; // undocumented dup
        case 0xcc: printf("CZ $%02X%02X",opcode[2],opcode[1]);opbytes=3;break;
        case 0xcd: printf("CALL $%02X%02X",opcode[2],opcode[1]);opbytes=3;break;
        case 0xce: printf("ACI #$%02X",opcode[1]);opbytes=2;break;
        case 0xcf: printf("RST1");break;
        case 0xd0: printf("RNC");break;
        case 0xd1: printf("POP D");break;
        case 0xd2: printf("JNC $%02X%02X",opcode[2],opcode[1]);opbytes=3;break;
        case 0xd3: printf("OUT #$%02X",opcode[1]);opbytes=2;break;
        case 0xd4: printf("CNC $%02X%02X",opcode[2],opcode[1]);opbytes=3;break;
        case 0xd5: printf("PUSH D");break;
        case 0xd6: printf("SUI #$%02X",opcode[1]);opbytes=2;break;
        case 0xd7: printf("RST2");break;
        case 0xd8: printf("RC");break;
        case 0xd9: printf("RET");break; // undocumented dup
        case 0xda: printf("JC $%02X%02X",opcode[2],opcode[1]);opbytes=3;break;
        case 0xdb: printf("IN #$%02X",opcode[1]);opbytes=2;break;
        case 0xdc: printf("CC $%02X%02X",opcode[2],opcode[1]);opbytes=3;break;
        case 0xdd: printf("CALL $%02X%02X",opcode[2],opcode[1]);opbytes=3;break; // undocumented dup
        case 0xde: printf("SBI #$%02X",opcode[1]);opbytes=2;break;
        case 0xdf: printf("RST3");break;
        case 0xe0: printf("RPO");break;
        case 0xe1: printf("POP H");break;
        case 0xe2: printf("JPO $%02X%02X",opcode[2],opcode[1]);opbytes=3;break;
        case 0xe3: printf("XTHL");break;
        case 0xe4: printf("CPO $%02X%02X",opcode[2],opcode[1]);opbytes=3;break;
        case 0xe5: printf("PUSH H");break;
        case 0xe6: printf("ANI #$%02X",opcode[1]);opbytes=2;break;
        case 0xe7: printf("RST4");break;
        case 0xe8: printf("RPE");break;
        case 0xe9: printf("PCHL");break;
        case 0xea: printf("JPE $%02X%02X",opcode[2],opcode[1]);opbytes=3;break;
        case 0xeb: printf("XCHG");break;
        case 0xec: printf("CPE $%02X%02X",opcode[2],opcode[1]);opbytes=3;break;
        case 0xed: printf("CALL $%02X%02X",opcode[2],opcode[1]);opbytes=3;break; // undocumented dup
        case 0xee: printf("XRI #$%02X",opcode[1]);opbytes=2;break;
        case 0xef: printf("RST5");break;
        case 0xf0: printf("RP");break;
        case 0xf1: printf("POP PSW");break;
        case 0xf2: printf("JP $%02X%02X",opcode[2],opcode[1]);opbytes=3;break;
        case 0xf3: printf("DI");break;
        case 0xf4: printf("CP $%02X%02X",opcode[2],opcode[1]);opbytes=3;break;
        case 0xf5: printf("PUSH PSW");break;
        case 0xf6: printf("ORI #$%02X",opcode[1]);opbytes=2;break;
        case 0xf7: printf("RST6");break;
        case 0xf8: printf("RM");break;
        case 0xf9: printf("SPHL");break;
        case 0xfa: printf("JM $%02X%02X",opcode[2],opcode[1]);opbytes=3;break;
        case 0xfb: printf("EI");break;
        case 0xfc: printf("CM $%02X%02X",opcode[2],opcode[1]);opbytes=3;break;
        case 0xfd: printf("CALL $%02X%02X",opcode[2],opcode[1]);opbytes=3;break; // undocumented dup
        case 0xfe: printf("CPI #$%02X",opcode[1]);opbytes=2;break;
        case 0xff: printf("RST7");break;

    }
    printf("\n");

    return opbytes;
}

void State8080::UnimplementedFunction(){
    printf("Unimplemented opcode 0x%02X at pc=0x%04X\n", memory[pc], pc);
    std::cout<<"Unimplemented function encountered."<<"\n";
    exit(1);
}

uint8_t* State8080::Register(int code){
    switch(code){
        case 0: return &b;break;
        case 1: return &c;break;
        case 2: return &d;break;
        case 3: return &e;break;
        case 4: return &h;break;
        case 5: return &l;break;
        case 6: return &memory[(h<<8) | l];break;
        case 7: return &a;break;
    }
    return nullptr;
}

void State8080::printState(){
    printf("b : 0x%02X\tcarry : %X\n", (uint8_t)b, (uint8_t)f.cy);
    printf("c : 0x%02X\taux   : %X\n", (uint8_t)c, (uint8_t)f.ac);
    printf("d : 0x%02X\tsign  : %X\n", (uint8_t)d, (uint8_t)f.s);
    printf("e : 0x%02X\tparity: %X\n", (uint8_t)e, (uint8_t)f.p);
    printf("h : 0x%02X\tzero  : %X\n", (uint8_t)h, (uint8_t)f.z);
    printf("l : 0x%02X\n", (uint8_t)l);
    printf("a : 0x%02X\n", (uint8_t)a);
    printf("pc : 0x%04X\n", (uint16_t)pc);
    printf("msp1 : 0x%02X\n", (uint8_t)memory[sp]);
    printf("msp2 : 0x%02X\n\n", (uint8_t)memory[sp+1]);

}

uint8_t Parity(uint8_t res){
    res ^= res >> 4;
    res ^= res >> 2;
    res ^= res >> 1;

    return !(res&1);
}

void State8080::SubLevel(){
    unsigned char* opcode = &memory[pc];
    int dst = (*opcode >> 3) & 0x07;
    int src = *opcode & 0x07;
    uint8_t& reg = *Register(dst);
    switch(*opcode & 0xC7){
        case 0x04: //INR
            reg++;
            if(reg==0) f.z=1;
            else f.z=0;
            f.s = reg >> 7;
            f.p = Parity(reg);
            break;
        case 0x05: //DCR
            reg--;
            if(reg==0) f.z=1;
            else f.z=0;
            f.s = reg >> 7u;
            f.p = Parity(reg);
            //ac not configured yet
            break;
        case 0x06: //MVI
            reg = memory[pc+1];
            pc++;
            break;
    }
    if((*opcode & 0xC0) == 0x40){
        *Register(dst) = *Register(src);
        return;
    }
}

void State8080::Emulate8080(){
    unsigned char* opcode = &memory[pc];
    printf("%04X : %02X \n",pc,*opcode);
    int check = *opcode & 0xc7;
    int movcheck = (*opcode & 0xC0);
    if(*opcode==0x76){
        printf("Program Halted.");
        exit(0);
    }
    if(check == 0x05 || check == 0x04 || check == 0x06 || movcheck == 0x40){
        SubLevel();
    }
    else{
    switch(*opcode){
        case 0x00: break;
        case 0x01:
            b = memory[pc+2];
            c = memory[pc+1];
            pc = pc+2;
            break;
        case 0x20:
            break;
        default:
            UnimplementedFunction();
            break;
        // case 0x02: printf("STAX B");break;
        case 0x03: //INX B
            c++;
            if(c==0) b++;
            break;
        // case 0x07: printf("RLC");break;
        // case 0x08: printf("NOP");break;
        case 0x09:{
            uint32_t bc = (b<<8) | c;
            uint32_t hl = (h<<8) | l;
            uint32_t res = bc+hl;
            h = res>>8u & 0xFF;
            l = res & 0xFF;
            f.cy = (res >0xFFFF);
            break;
        }
        // case 0x0a: printf("LDAX B");break;
        // case 0x0b: printf("DCX B");break;
        case 0x0f:
            printState();
            f.cy = a & 0x01;
            a = (a >> 1) | (f.cy << 7);
            printState();
            break;
        // case 0x10: printf("NOP");break;
        case 0x11: //LXI D
            d = memory[pc+2];
            e = memory[pc+1];
            pc+=2;
            break;
        // case 0x12: printf("STAX D");break;
        case 0x13:
            e++;
            if(e==0) d++;
            break;
        // case 0x17: printf("RAL");break;
        // case 0x18: printf("NOP");break;
        case 0x19:{
            uint32_t de = (d<<8) | e;
            uint32_t hl = (h<<8) | l;

            uint32_t res = de+hl;
            h = res>>8u & 0xFF;
            l = res & 0xFF;
            f.cy = (res >0xFFFF);
            break;
        }
        case 0x1a: //LDAX D
            a = memory[((d<<8) | e)];
            break;
        // case 0x1b: printf("DCX D");break;
        // case 0x1f: printf("RAR");break;
        // case 0x20: printf("NOP");break;
        case 0x21: //LXI H
            h = memory[pc+2];
            l = memory[pc+1];
            pc+=2;
            break;
        // case 0x22: printf("SHLD $%02X%02X",opcode[2],opcode[1]);opbytes=3;break;
        case 0x23:
            l++;
            if(l==0) h++;
            break;
        // case 0x27: printf("DAA");break;
        // case 0x28: printf("NOP");break;
        case 0x29:{
            uint32_t hl = (h<<8) | l;
            uint32_t res = hl+hl;
            h = res>>8u & 0xFF;
            l = res & 0xFF;
            f.cy = (res >0xFFFF);
            break;
        }
        // case 0x2a: printf("LHLD $%02X%02X",opcode[2],opcode[1]);opbytes=3;break;
        // case 0x2b: printf("DCX H");break;
        // case 0x2f: printf("CMA");break;
        // case 0x30: printf("NOP");break;
        case 0x31: //"LXI SP #$%02X%02X"
            sp = ((memory[pc+2] << 8u) | (memory[pc+1]));
            pc+=2;
            break;
        case 0x32:
            memory[((memory[pc+2]<<8) | memory[pc+1])] = a;
            pc+=2;
            break;
        case 0x33: //INX SP
            sp++;
            break;
        // case 0x37: printf("STC");break;
        // case 0x38: printf("NOP");break;
        case 0x39:{
            uint32_t hl = (h<<8) | l;
            uint32_t res = hl+(uint32_t)sp;
            h = (res >> 8) & 0xFF;
            l = res & 0xFF;
            f.cy = (res >0xFFFF);
            break;
        }
        case 0x3a:
            a = memory[memory[pc+2]<<8 | memory[pc+1]];
            pc+=2;
            break;
        // case 0x3b: printf("DCX SP");break;
        // case 0x3f: printf("CMC");break;
        // case 0x80: printf("ADD B");break;
        // case 0x81: printf("ADD C");break;
        // case 0x82: printf("ADD D");break;
        // case 0x83: printf("ADD E");break;
        // case 0x84: printf("ADD H");break;
        // case 0x85: printf("ADD L");break;
        // case 0x86: printf("ADD M");break;
        // case 0x87: printf("ADD A");break;
        // case 0x88: printf("ADC B");break;
        // case 0x89: printf("ADC C");break;
        // case 0x8a: printf("ADC D");break;
        // case 0x8b: printf("ADC E");break;
        // case 0x8c: printf("ADC H");break;
        // case 0x8d: printf("ADC L");break;
        // case 0x8e: printf("ADC M");break;
        // case 0x8f: printf("ADC A");break;
        // case 0x90: printf("SUB B");break;
        // case 0x91: printf("SUB C");break;
        // case 0x92: printf("SUB D");break;
        // case 0x93: printf("SUB E");break;
        // case 0x94: printf("SUB H");break;
        // case 0x95: printf("SUB L");break;
        // case 0x96: printf("SUB M");break;
        // case 0x97: printf("SUB A");break;
        // case 0x98: printf("SBB B");break;
        // case 0x99: printf("SBB C");break;
        // case 0x9a: printf("SBB D");break;
        // case 0x9b: printf("SBB E");break;
        // case 0x9c: printf("SBB H");break;
        // case 0x9d: printf("SBB L");break;
        // case 0x9e: printf("SBB M");break;
        // case 0x9f: printf("SBB A");break;
        // case 0xa0: printf("ANA B");break;
        // case 0xa1: printf("ANA C");break;
        // case 0xa2: printf("ANA D");break;
        // case 0xa3: printf("ANA E");break;
        // case 0xa4: printf("ANA H");break;
        // case 0xa5: printf("ANA L");break;
        // case 0xa6: printf("ANA M");break;
        case 0xa7:
            f.cy = 0;
            f.z = (a==0);
            f.p = Parity(a);
            f.s = a>>7;
            break;
        // case 0xa8: printf("XRA B");break;
        // case 0xa9: printf("XRA C");break;
        // case 0xaa: printf("XRA D");break;
        // case 0xab: printf("XRA E");break;
        // case 0xac: printf("XRA H");break;
        // case 0xad: printf("XRA L");break;
        // case 0xae: printf("XRA M");break;
        case 0xaf:
            a=0;
            f.cy = 0;
            f.z = (a==0);
            f.p = Parity(a);
            f.s = a>>7;
            break;
        // case 0xb0: printf("ORA B");break;
        // case 0xb1: printf("ORA C");break;
        // case 0xb2: printf("ORA D");break;
        // case 0xb3: printf("ORA E");break;
        // case 0xb4: printf("ORA H");break;
        // case 0xb5: printf("ORA L");break;
        // case 0xb6: printf("ORA M");break;
        // case 0xb7: printf("ORA A");break;
        // case 0xb8: printf("CMP B");break;
        // case 0xb9: printf("CMP C");break;
        // case 0xba: printf("CMP D");break;
        // case 0xbb: printf("CMP E");break;
        // case 0xbc: printf("CMP H");break;
        // case 0xbd: printf("CMP L");break;
        // case 0xbe: printf("CMP M");break;
        // case 0xbf: printf("CMP A");break;
        // case 0xc0: printf("RNZ");break;
        case 0xc1:
            c = memory[sp];
            b = memory[sp+1];
            sp+=2;
            break;
        case 0xc2:
            printState();
            printf("0x%02X",memory[pc+2]);
            printf("0x%02X",memory[pc+1]);
            if(!f.z) {
                pc= ((memory[pc+2]<<8) | memory[pc+1]);
                printState();
                return;
            }
            pc+=2;
            printState();
            break;
        case 0xc3:
            pc = (memory[pc+2] << 8) | (memory[pc+1]);
            return;
        // case 0xc4: printf("CNZ $%02X%02X",opcode[2],opcode[1]);opbytes=3;break;
        case 0xc5:
            memory[sp-1] = b;
            memory[sp-2] = c;
            sp-=2;
            break;
        case 0xc6:{
            uint16_t res = (uint16_t)a + (uint16_t)memory[pc+1];
            a = res;
            f.cy = (res>0xFF);
            f.s = a>>7;
            f.z = (a==0);
            f.p = Parity(a);
            pc++;
            break;
        }
        // case 0xc7: printf("RST0");break;
        // case 0xc8: printf("RZ");break;
        case 0xc9: //RET
            printState();
            pc = memory[sp+1]<<8 | memory[sp];
            sp+=2;
            printState();
            return;

        // case 0xca: printf("JZ $%02X%02X",opcode[2],opcode[1]);opbytes=3;break;
        // case 0xcb: printf("JMP $%02X%02X",opcode[2],opcode[1]);opbytes=3;break; // undocumented dup
        // case 0xcc: printf("CZ $%02X%02X",opcode[2],opcode[1]);opbytes=3;break;
        case 0xcd:{ //CALL
            uint16_t ret = pc+3;
            memory[sp-1] = (ret >> 8) & 0xFF;
            memory[sp-2] = ret & 0xFF;
            sp-=2;
            pc = ((memory[pc+2] << 8) | memory[pc+1]);
            // printf("Opcode: %X \n",memory[pc]);
            return;
        }
        // case 0xce: printf("ACI #$%02X",opcode[1]);opbytes=2;break;
        // case 0xcf: printf("RST1");break;
        // case 0xd0: printf("RNC");break;
        case 0xd1:
            e = memory[sp];
            d = memory[sp+1];
            sp+=2;
            break;
        // case 0xd2: printf("JNC $%02X%02X",opcode[2],opcode[1]);opbytes=3;break;
        case 0xd3: //To be implemented
            // io->WritePort(memory[pc+1], a);
            pc++;
            break;
        // case 0xd4: printf("CNC $%02X%02X",opcode[2],opcode[1]);opbytes=3;break;
        case 0xd5:
            memory[sp-1] = d;
            memory[sp-2] = e;
            sp-=2;
            break;
        // case 0xd6: printf("SUI #$%02X",opcode[1]);opbytes=2;break;
        // case 0xd7: printf("RST2");break;
        // case 0xd8: printf("RC");break;
        // case 0xd9: printf("RET");break; // undocumented dup
        // case 0xda: printf("JC $%02X%02X",opcode[2],opcode[1]);opbytes=3;break;
        case 0xdb:
            // a = io->ReadPort(memory[pc+1]);
            pc++;
            break;
        // case 0xdc: printf("CC $%02X%02X",opcode[2],opcode[1]);opbytes=3;break;
        // case 0xdd: printf("CALL $%02X%02X",opcode[2],opcode[1]);opbytes=3;break; // undocumented dup
        // case 0xde: printf("SBI #$%02X",opcode[1]);opbytes=2;break;
        // case 0xdf: printf("RST3");break;
        // case 0xe0: printf("RPO");break;
        case 0xe1:
            l = memory[sp];
            h = memory[sp+1];
            sp+=2;
            break;
        // case 0xe2: printf("JPO $%02X%02X",opcode[2],opcode[1]);opbytes=3;break;
        // case 0xe3: printf("XTHL");break;
        // case 0xe4: printf("CPO $%02X%02X",opcode[2],opcode[1]);opbytes=3;break;
        case 0xe5:
            memory[sp-1] = h;
            memory[sp-2] = l;
            sp-=2;
            break;
        case 0xe6:
            a = a & memory[pc+1];
            f.z = (a==0);
            f.cy = 0;
            f.p = Parity(a);
            f.s = a>>7;
            pc++;
            break;
        // case 0xe7: printf("RST4");break;
        // case 0xe8: printf("RPE");break;
        // case 0xe9: printf("PCHL");break;
        // case 0xea: printf("JPE $%02X%02X",opcode[2],opcode[1]);opbytes=3;break;
        case 0xeb:{
            uint8_t temp = d;
            d=h;
            h=temp;
            temp = e;
            e=l;
            l=temp;
            break;
        }
        // case 0xec: printf("CPE $%02X%02X",opcode[2],opcode[1]);opbytes=3;break;
        // case 0xed: printf("CALL $%02X%02X",opcode[2],opcode[1]);opbytes=3;break; // undocumented dup
        // case 0xee: printf("XRI #$%02X",opcode[1]);opbytes=2;break;
        // case 0xef: printf("RST5");break;
        // case 0xf0: printf("RP");break;
        case 0xf1: { // POP PSW
            uint8_t psw = memory[sp];
            a = memory[sp+1];
            sp += 2;
            f.s  = (psw >> 7) & 0x01;
            f.z  = (psw >> 6) & 0x01;
            f.ac = (psw >> 4) & 0x01;
            f.p  = (psw >> 2) & 0x01;
            f.cy = psw & 0x01;
            break;
        }
        // case 0xf2: printf("JP $%02X%02X",opcode[2],opcode[1]);opbytes=3;break;
        // case 0xf3: printf("DI");break;
        // case 0xf4: printf("CP $%02X%02X",opcode[2],opcode[1]);opbytes=3;break;
        case 0xf5: { // PUSH PSW
            memory[sp - 1] = a;
            uint8_t psw = (f.s << 7)|(f.z << 6)|(0 << 5)|(f.ac << 4)| (0 << 3)|(f.p << 2)|(1 << 1)|(f.cy);
            memory[sp - 2] = psw;
            sp -= 2;
            break;
        }
        // case 0xf6: printf("ORI #$%02X",opcode[1]);opbytes=2;break;
        // case 0xf7: printf("RST6");break;
        // case 0xf8: printf("RM");break;
        // case 0xf9: printf("SPHL");break;
        // case 0xfa: printf("JM $%02X%02X",opcode[2],opcode[1]);opbytes=3;break;
        case 0xfb:
            ei = 1;
            break;
        // case 0xfc: printf("CM $%02X%02X",opcode[2],opcode[1]);opbytes=3;break;
        // case 0xfd: printf("CALL $%02X%02X",opcode[2],opcode[1]);opbytes=3;break; // undocumented dup
        case 0xfe:{//CPI
            uint8_t calc = a-memory[pc+1];
            f.s = calc >>7;
            f.p = Parity(calc);
            f.z = (calc==0);
            f.cy = (a<memory[pc+1]);
            break;
        }
        // case 0xff: printf("RST7");break;
    }
    }

    pc++;
    return;
}
