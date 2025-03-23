#ifndef TEXT
#define TEXT

#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <iostream>

using namespace std;

class text {
    private:
        struct textData {
            SDL_Surface *surface;
            SDL_Texture *texture;
            TTF_Font* font;
            SDL_Color color = {255, 255, 255, 255};
            string text;
            string path;
        };

        textData data;
        SDL_Renderer *Render;

    public:
        text(SDL_Renderer *render, const string& text, string file, Uint8 r = 255, Uint8 g = 255, Uint8 b = 255) {
            data.color = {r, g, b, 255};
            data.font = TTF_OpenFont(file.c_str(), 128);
            data.surface = TTF_RenderText_Solid(data.font, text.c_str(), text.length(), data.color);
            data.texture = SDL_CreateTextureFromSurface(render, data.surface);
            Render = render;
            data.text = text;
            data.path = file;
        }

        void destroy() {
            SDL_DestroySurface(data.surface);
            SDL_DestroyTexture(data.texture);
        }

        void setText(const string& newText) {
            destroy();

            data.surface = TTF_RenderText_Solid(data.font, newText.c_str(), newText.length(), data.color);
            data.texture = SDL_CreateTextureFromSurface(Render, data.surface);
        }
        
        void setColor(Uint8 r = -1, Uint8 g = -1, Uint8 b = -1) {
            destroy();

            if (r == -1) r = data.color.r;
            else data.color.r = r;
            if (g == -1) g = data.color.g;
            else data.color.g = g;
            if (b == -1) b = data.color.b;
            else data.color.b = b;

            data.color = {r, g, b, 255};
            data.surface = TTF_RenderText_Solid(data.font, data.text.c_str(), data.text.length(), data.color);
            data.texture = SDL_CreateTextureFromSurface(Render, data.surface);
        }

        textData get() {
            return data;
        }

        friend ostream& operator<<(ostream& os, const text& t) {
            os << "Text(text: \"" << t.data.text << "\", path: " << t.data.path 
               << ", r: " << static_cast<int>(t.data.color.r) 
               << ", g: " << static_cast<int>(t.data.color.g) 
               << ", b: " << static_cast<int>(t.data.color.b) << ")";
            return os;
        }
};

#endif