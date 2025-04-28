#ifndef RECT
#define RECT

#include <SDL3/SDL.h>
#include <iostream>

using namespace std;

class rect {
    private:
        struct rectData {
            SDL_Rect rect;
        };

        struct colorStruct {
            Uint8 r = 0;
            Uint8 g = 0;
            Uint8 b = 0;
        };

        rectData data;

    public:
        colorStruct color;

        rect(int x = 0, int y = 0, int w = 0, int h = 0) {
            data.rect.x = x;
            data.rect.y = y;
            data.rect.w = w;
            data.rect.h = h;
        }
        
        void setRect(int x, int y, int w, int h) {
            data.rect.x = x;
            data.rect.y = y;
            data.rect.w = w;
            data.rect.h = h;
        }

        void setPosition(int x, int y) {
            data.rect.x = x;
            data.rect.y = y;
        }

        void setSize(int w, int h) {
            data.rect.w = w;
            data.rect.h = h;
        }

        void setX(int x){ data.rect.x = x; }
        void setY(int y){ data.rect.y = y; }
        void setWidth(int w){ data.rect.w = w; }
        void setHeight(int h){ data.rect.h = h; }

        void addX(int x){ data.rect.x += x; }
        void addY(int y){ data.rect.y += y; }
        void addWidth(int w){ data.rect.w += w; }
        void addHeight(int h){ data.rect.h += h; }

        void subX(int x){ data.rect.x -= x; }
        void subY(int y){ data.rect.y -= y; }
        void subWidth(int w){ data.rect.w -= w; }
        void subHeight(int h){ data.rect.h -= h; }

        int getX(){ return data.rect.x; }
        int getY(){ return data.rect.y; }
        int getWidth(){ return data.rect.w; }
        int getHeight(){ return data.rect.h; }

        SDL_Rect get() {
            return data.rect;
        }

        void fill(SDL_Surface *surface, Uint8 r = -1, Uint8 g = -1, Uint8 b = -1) {
            if (r == -1) r = color.r;
            else color.r = r;
            if (g == -1) g = color.g;
            else color.g = g;
            if (b == -1) b = color.b;
            else color.b = b;
            SDL_FillSurfaceRect(surface, &data.rect, SDL_MapSurfaceRGB(surface, r, g, b));
        }

        void update(SDL_Surface *surface) {
            SDL_FillSurfaceRect(surface, &data.rect, SDL_MapSurfaceRGB(surface, color.r, color.g, color.b));
        }

        bool onTouch(rect& otrect) {
            if (data.rect.x < otrect.data.rect.x + otrect.data.rect.w &&
                data.rect.x + data.rect.w > otrect.data.rect.x &&
                data.rect.y < otrect.data.rect.y + otrect.data.rect.h &&
                data.rect.y + data.rect.h > otrect.data.rect.y) {
                return true;
            }
            return false;
        }

        bool onHover() {
            float mouseX, mouseY;
            SDL_GetMouseState(&mouseX, &mouseY);

            if (mouseX >= data.rect.x && mouseX <= data.rect.x + data.rect.w &&
                mouseY >= data.rect.y && mouseY <= data.rect.y + data.rect.h) {
                return true;
            }
            return false;
        }
        
        friend ostream& operator<<(ostream& os, rect& r) {
            os << "Rect(x: " << r.data.rect.x << ", y: " << r.data.rect.y 
               << ", w: " << r.data.rect.w << ", h: " << r.data.rect.h 
               << ", r: " << static_cast<int>(r.color.r) 
               << ", g: " << static_cast<int>(r.color.g) 
               << ", b: " << static_cast<int>(r.color.b) 
               << ")";
            return os;
        }
};

#endif