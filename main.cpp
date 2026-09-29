#include "8080.hpp"
#include <fstream>
#include <iostream>
using namespace std;

int main(int argc,char* argv[]){
    ifstream file(argv[1],ios::binary | ios::ate);
    unsigned char* buffer;
    if(!file.is_open()){
        cout<<"Error opening file"<<"\n";
        return 0;
    }
    streampos size = file.tellg();
    buffer = new unsigned char[size];

    file.seekg(0);
    file.read(reinterpret_cast<char*>(buffer),size);
    file.close();

    Disassemble8080 disasm;
    State8080 state;
    for(int i=0;i<size;i++){
        state.memory[i] = buffer[i];
    }
    state.pc = 0;
    int pc =0;
    while(state.pc<size){
        // state.pc+= disasm.Disassemble(state.memory,state.pc);
        state.Emulate8080();
    }
    // int pc = 0;
    // while(pc<size){
    //     pc +=disasm.Disassemble(buffer, pc);
    // }
    delete[] buffer;
    return 0;
}
