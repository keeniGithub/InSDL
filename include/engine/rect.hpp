#ifndef RECT
#define RECT

#include <SDL3/SDL.h>
#include <iostream>

using namespace std;

/**
 * @brief Класс для создания нового rect`a в SDL
 * @param x pos x
 * @param y pos y
 * @param w width
 * @param h height
**/
class rect {
    public:
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

        int getX(){ return data.rect.x; }
        int getY(){ return data.rect.y; }
        int getWidth(){ return data.rect.w; }
        int getHeight(){ return data.rect.h; }

        SDL_Rect get() const {
            return data.rect;
        }

        friend ostream& operator<<(ostream& os, rect& r) {
            os << "Rect(x: " << r.data.rect.x << ", y: " << r.data.rect.y 
               << ", w: " << r.data.rect.w << ", h: " << r.data.rect.h << ")";
            return os;
        }
    
    private:
        struct rectData {
            SDL_Rect rect;
        };

        rectData data;
};

#endif