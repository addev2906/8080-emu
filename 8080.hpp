#include <cstdint>
class Disassemble8080{
public:
    int Disassemble(unsigned char* byte,int pc);
};

struct Flags {
    uint8_t z  : 1;
    uint8_t s  : 1;
    uint8_t p  : 1;
    uint8_t cy : 1;
    uint8_t ac : 1;
    uint8_t pad : 3;
};

class State8080{
public:
    Flags f;
    uint8_t a{},b{},c{},d{},e{},h{},l{};
    uint16_t sp;
    uint16_t pc;
    uint8_t ie;
    uint8_t memory[0xFFFF+1];
    uint8_t* Register(int code);
    void Emulate8080();
    void SubLevel();
    void printState();
    void UnimplementedFunction();
};
