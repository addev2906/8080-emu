#pragma once
#include <cstdint>
class IODevice{
public:
    virtual uint8_t ReadPort(uint8_t port)=0;
    virtual void WritePort(uint8_t port,int value)=0;
    ~IODevice() = default;
};
