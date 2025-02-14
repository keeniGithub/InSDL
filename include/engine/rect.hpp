#ifndef RECT
#define RECT

#include <SDL3/SDL.h>
#include <iostream>

using namespace std;

/**
 * @brief Класс для создания нового rect`a в SDL
*/
class rect {
    public:
        rect(int x = 0, int y = 0, int width = 0, int height = 0) {
            data.rect.x = x;
            data.rect.y = y;
            data.rect.w = width;
            data.rect.h = height;
        }
        
        void setRect(int x, int y, int width, int height) {
            data.rect.x = x;
            data.rect.y = y;
            data.rect.w = width;
            data.rect.h = height;
        }

        void setPosition(int x, int y) {
            data.rect.x = x;
            data.rect.y = y;
        }

        void setSize(int width, int height) {
            data.rect.w = width;
            data.rect.h = height;
        }

        void setX(int x){ data.rect.x = x; }
        void setY(int y){ data.rect.y = y; }
        void setW(int width){ data.rect.w = width; }
        void setH(int height){ data.rect.h = height; }

        int getX(){ return data.rect.x; }
        int getY(){ return data.rect.y; }
        int getWidth(){ return data.rect.w; }
        int getHeight(){ return data.rect.h; }

        SDL_Rect get() const {
            return data.rect;
        }

        friend ostream& operator<<(ostream& os, const rect& r) {
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