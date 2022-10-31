#include <SDL.h> 
#include <SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include "MainLoop.h"

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Surface* surface;

void init()
{
    SDL_Init(SDL_INIT_VIDEO);
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
    }
    SDL_CreateWindowAndRenderer(512, 512, 0, &window, &renderer);
    //surface = SDL_CreateRGBSurface(0, 512, 512, 32, 0, 0, 0, 0);
    surface = IMG_Load("assets/map.png");
    if (surface == NULL) {
        printf("Unable to load image %s! SDL_image Error: %s\n", "assets/map.png", IMG_GetError());
        surface = SDL_CreateRGBSurface(0, 512, 512, 32, 0, 0, 0, 0);
        Uint8* pixels = (Uint8*)surface->pixels;
        for (int i = 0; i < 1048576; i++) {
            char randomByte = 150 % 255;
            pixels[i] = randomByte;
        }
    } 
	SDL_Texture* screenTexture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, screenTexture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

void mainLoop() {

    Uint8* pixels = (Uint8*)surface->pixels;
    for (int i = 0; i < 1048576; i++) {
        char randomByte = rand() % 255;
        pixels[i] = randomByte;
    }
    SDL_Texture* screenTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, screenTexture, NULL, NULL);
    SDL_RenderPresent(renderer);
}