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
            string path;
        };

        textureData data;

    public:
        texture(SDL_Renderer *render, string file) {
            data.surface = SDL_LoadBMP(file.c_str());
            data.texture = SDL_CreateTextureFromSurface(render, data.surface);
            data.path = file;
        }

        void destroy() {
            SDL_DestroySurface(data.surface);
            SDL_DestroyTexture(data.texture);
        }

        textureData get() {
            return data;
        }

        friend ostream& operator<<(ostream& os, const texture& t) {
            os << "Texture(path: " << t.data.path << ")";
            return os;
        }
};

#endif