#include "SpaceInvadersMachine.hpp"
#include <cstdint>

uint8_t SpaceInvadersMachine::ReadPort(uint8_t port) {
    switch (port) {
        case 0: return 0x0E;
        case 1: return port1;
        case 2: return port2;
        case 3: return (shift_register >> (8 - shift_offset)) & 0xFF;
        default: return 0x00;
    }
}
void SpaceInvadersMachine::KeyDown(int key) {
    switch (key) {
        case COIN:     port1 |= 0x01; break;
        case P1_START: port1 |= 0x04; break;
        case P1_FIRE:  port1 |= 0x10; break;
        case P1_LEFT:  port1 |= 0x20; break;
        case P1_RIGHT: port1 |= 0x40; break;
    }
}

void SpaceInvadersMachine::KeyUp(int key) {
    switch (key) {
        case COIN:     port1 &= ~0x01; break;
        case P1_START: port1 &= ~0x04; break;
        case P1_FIRE:  port1 &= ~0x10; break;
        case P1_LEFT:  port1 &= ~0x20; break;
        case P1_RIGHT: port1 &= ~0x40; break;
    }
}
void SpaceInvadersMachine::WritePort(uint8_t port,int value){
    switch(port){
        case 2:
            shift_offset = value & 0x07;
            break;
        case 4:
            shift_register = (shift_register >> 8) | ((uint16_t)(value & 0xFF) << 8);
            break;
        default:break;
    }
}
