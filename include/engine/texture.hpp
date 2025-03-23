#ifndef TEXTURE
#define TEXTURE

#include <SDL3/SDL.h>
#include <iostream>

using namespace std;

class texture {
    private:
        struct textureData {
            SDL_Surface *surface;
            SDL_Texture *texture;
        };

        textureData data;

    public:
        texture(SDL_Renderer *render, const char *file) {
            data.surface = SDL_LoadBMP(file);
            data.texture = SDL_CreateTextureFromSurface(render, data.surface);
            SDL_DestroySurface(data.surface);
        }

        SDL_Texture* get() {
            return data.texture;
        }
};

#endif