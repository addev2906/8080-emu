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
    int pc = 0;
    while(pc<size){
        pc += disasm.Disassemble(buffer,pc);
    }

    return 0;
}
