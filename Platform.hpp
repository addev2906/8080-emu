#pragma once
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>

class Platform{
public:
    Platform(const char *windowName,int windowWidth, int windowHeight,int textureWidth, int textureHeight);
    ~Platform();

    void Update(void const* buffer, int pitch);

private:
    SDL_Window* window{};
    SDL_Renderer* renderer{};
    SDL_Texture* texture{};
};
