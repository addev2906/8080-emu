#include "headers/Platform.hpp"
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>
#include <cstdint>

Platform::Platform(const char *windowName,int windowWidth, int windowHeight,int textureWidth, int textureHeight){

    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow(windowName,windowWidth, windowHeight,0);
    renderer = SDL_CreateRenderer(window, NULL);
    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888 , SDL_TEXTUREACCESS_STREAMING, textureWidth, textureHeight);
    SDL_SetTextureScaleMode(texture, SDL_SCALEMODE_NEAREST);
}
Platform::~Platform() {
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
void Platform::Update(void const* buffer, int pitch){
    SDL_UpdateTexture(texture, NULL, buffer,pitch);
   	SDL_RenderClear(renderer);
	SDL_RenderTexture(renderer, texture, nullptr, nullptr);
	SDL_RenderPresent(renderer);
}
