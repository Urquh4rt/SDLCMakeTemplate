#include <SDL.h> 
#include <SDL_image.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef EMSCRIPTEN
#include <emscripten.h>
void mainLoop();
#else
#endif

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Surface* surface;

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_VIDEO);
	int imgFlags = IMG_INIT_PNG;
	IMG_Init(imgFlags);
    SDL_CreateWindowAndRenderer(512, 512, 0, &window, &renderer);
    //surface = SDL_CreateRGBSurface(0, 512, 512, 32, 0, 0, 0, 0);
    surface = IMG_Load("map.png");
    if (surface == NULL) {
        surface = SDL_CreateRGBSurface(0, 512, 512, 32, 0, 0, 0, 0);
        Uint8* pixels = (Uint8*) surface->pixels;
        for (int i = 0; i < 1048576; i++) {
            char randomByte = 150 % 255;
            pixels[i] = randomByte;
        }
    }
    SDL_Texture* screenTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, screenTexture, NULL, NULL);
    SDL_RenderPresent(renderer);

#ifdef EMSCRIPTEN
	emscripten_set_main_loop(mainLoop, 0, 1);
}
void mainLoop() {
#else
	while (true)
#endif
	{
        //Uint8* pixels = (Uint8*) surface->pixels;

        //for (int i = 0; i < 1048576; i++) {
        //    char randomByte = rand() % 255;
        //    pixels[i] = randomByte;
        //}

        //if (SDL_MUSTLOCK(surface)) SDL_UnlockSurface(surface);

        //SDL_Texture* screenTexture = SDL_CreateTextureFromSurface(renderer, surface);

        //SDL_RenderClear(renderer);
        //SDL_RenderCopy(renderer, screenTexture, NULL, NULL);
        //SDL_RenderPresent(renderer);

        //SDL_DestroyTexture(screenTexture);
	}
}