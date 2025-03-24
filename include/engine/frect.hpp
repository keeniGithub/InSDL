#ifndef FRECT
#define FRECT

#include <SDL3/SDL.h>
#include <iostream>
#include <texture.hpp>
#include <text.hpp>

using namespace std;

class frect {
    private:
        struct frectData {
            SDL_FRect frect;
        };

        struct colorStruct {
            Uint8 r = 0;
            Uint8 g = 0;
            Uint8 b = 0;
            Uint8 alpha = 255;
        };

        frectData data;

    public:
        colorStruct color;

        frect(int x = 0, int y = 0, int w = 0, int h = 0) {
            data.frect.x = x;
            data.frect.y = y;
            data.frect.w = w;
            data.frect.h = h;
        }
        
        void setFrect(int x, int y, int w, int h) {
            data.frect.x = x;
            data.frect.y = y;
            data.frect.w = w;
            data.frect.h = h;
        }

        void setPosition(int x, int y) {
            data.frect.x = x;
            data.frect.y = y;
        }

        void setSize(int w, int h) {
            data.frect.w = w;
            data.frect.h = h;
        }

        void setX(int x){ data.frect.x = x; }
        void setY(int y){ data.frect.y = y; }
        void setWidth(int w){ data.frect.w = w; }
        void setHeight(int h){ data.frect.h = h; }

        void addX(int x){ data.frect.x += x; }
        void addY(int y){ data.frect.y += y; }
        void addWidth(int w){ data.frect.w += w; }
        void addHeight(int h){ data.frect.h += h; }

        void subX(int x){ data.frect.x -= x; }
        void subY(int y){ data.frect.y -= y; }
        void subWidth(int w){ data.frect.w -= w; }
        void subHeight(int h){ data.frect.h -= h; }

        int getX(){ return data.frect.x; }
        int getY(){ return data.frect.y; }
        int getWidth(){ return data.frect.w; }
        int getHeight(){ return data.frect.h; }

        SDL_FRect get() {
            return data.frect;
        }

        void fill(SDL_Renderer *render, Uint8 r = -1, Uint8 g = -1, Uint8 b = -1, Uint8 alpha = -1) {
            if (r == -1) r = color.r;
            else color.r = r;
            if (g == -1) g = color.g;
            else color.g = g;
            if (b == -1) b = color.b;
            else color.b = b;
            if (alpha == -1) alpha = color.alpha;
            else color.alpha = alpha;
            
            SDL_SetRenderDrawColor(render, r, g, b, alpha);
            SDL_RenderFillRect(render, &data.frect);
        }

        void fillTexture(SDL_Renderer *render, texture *texture){
            SDL_RenderTexture(render, texture->get().texture, NULL, &data.frect);
        }

        void fillText(SDL_Renderer *render, text *text){
            SDL_RenderTexture(render, text->get().texture, NULL, &data.frect);
        }

        bool onTouch(frect& otfrect) {
            if (data.frect.x < otfrect.data.frect.x + otfrect.data.frect.w &&
                data.frect.x + data.frect.w > otfrect.data.frect.x &&
                data.frect.y < otfrect.data.frect.y + otfrect.data.frect.h &&
                data.frect.y + data.frect.h > otfrect.data.frect.y) {
                return true;
            }
            return false;
        }

        bool onHover() {
            float mouseX, mouseY;
            SDL_GetMouseState(&mouseX, &mouseY);

            if (mouseX >= data.frect.x && mouseX <= data.frect.x + data.frect.w &&
                mouseY >= data.frect.y && mouseY <= data.frect.y + data.frect.h) {
                return true;
            }
            return false;
        }

        friend ostream& operator<<(ostream& os, frect& r) {
            os << "FRect(x: " << r.data.frect.x << ", y: " << r.data.frect.y 
               << ", w: " << r.data.frect.w << ", h: " << r.data.frect.h 
               << ", r: " << static_cast<int>(r.color.r) 
               << ", g: " << static_cast<int>(r.color.g) 
               << ", b: " << static_cast<int>(r.color.b) 
               << ", alpha: " << static_cast<int>(r.color.alpha) << ")";
            return os;
        }
};

#endif