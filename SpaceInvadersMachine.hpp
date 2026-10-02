#pragma once
#include "io_device.hpp"
#include <cstdint>

class SpaceInvadersMachine : public IODevice{
public:
    uint8_t port1{0x08};
    uint8_t port2{0x00};
    uint16_t shift_register{};
    uint8_t shift_offset{};

    uint8_t ReadPort(uint8_t port) override;
    void WritePort(uint8_t port, int value) override;

    void KeyDown(int key);
    void KeyUp(int key);
};

enum{COIN, P1_START, P1_LEFT, P1_RIGHT, P1_FIRE};
