#pragma once
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>
#include <cstdint>

class Platform{
public:
    Platform(const char *windowName,int windowWidth, int windowHeight,int textureWidth, int textureHeight);
    ~Platform();

    void Update(void const* buffer, int pitch);
    bool processInput(uint8_t* keys);

private:
    SDL_Window* window{};
    SDL_Renderer* renderer{};
    SDL_Texture* texture{};
};
