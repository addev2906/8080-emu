#include "8080.hpp"
// #include "SpaceInvadersMachine.hpp"
#include "Platform.hpp"
#include <cstdint>
#include <fstream>
#include <iostream>
#include <SDL3/SDL.h>
#include <chrono>
#include <thread>

#define SCALE 2
#define WINDOW_WIDTH (224*SCALE)
#define WINDOW_HEIGHT (256*SCALE)

#define TEXTURE_WIDTH 224
#define TEXTURE_HEIGHT 256

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
    // SpaceInvadersMachine machine;
    uint32_t pixels[224*256];
    // state.io = &machine;
    Platform platform("Invaders",WINDOW_WIDTH, WINDOW_HEIGHT,TEXTURE_WIDTH,TEXTURE_HEIGHT);
    for(int i=0;i<size;i++){
        state.memory[i] = buffer[i];
    }
    delete[] buffer;
    state.pc = 0;

    bool quit = false;
    SDL_Event event;
    while (!quit) {
        // 1. Get start time (ensure no older 'frame_start' variable exists above this!)
        auto frame_start = std::chrono::steady_clock::now();

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }

        for (int i = 0; i < 8333; i++) {
            state.Emulate8080();
        }
        for(int i=0;i<7168;i++){
            uint8_t byte = state.memory[0x2400 + i];

            for(int bit=0;bit<8;bit++){
                int native_x = (i%32)*8+bit;
                int natiye_y = i/32;

                int sdl_x = natiye_y;
                int sdly_y = 255-native_x;
                int pixel_index = sdly_y*224+sdl_x;

                uint8_t is_pixel_on = (byte >> bit) & 0x01;
                pixels[pixel_index] = is_pixel_on ? 0xFFFFFFFF : 0x000000FF;
            }
        }
        platform.Update(pixels, 224 * sizeof(uint32_t));

        // 2. Get end time
        auto frame_end = std::chrono::steady_clock::now();

        // 3. Calculate difference
        auto time_taken = std::chrono::duration_cast<chrono::microseconds>(frame_end - frame_start);

        // 4. Sleep if we are too fast (16666 microseconds = 60Hz)
        std::chrono::microseconds target_time(16666);
        if (time_taken < target_time) {
            std::this_thread::sleep_for(target_time - time_taken);
        }
    }


    return 0;
}
