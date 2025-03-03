#ifndef APP
#define APP

#include <string>
#include <iostream>
#include <map>
#include <functional>
#include <vector>

#include <SDL3/SDL.h>
#include <rect.hpp>

using namespace std;

class app {
    private:
        struct bindStruct {
            SDL_Scancode key;
            function<void()> func;
        };

        struct colorStruct {
            Uint8 r = 0;
            Uint8 g = 0;
            Uint8 b = 0;
        };
        
    public:
        SDL_Window *Window;
        SDL_Surface *Surface;
        bool quit = false;
        vector<bindStruct> keyBindings;
        colorStruct color;

        void init(int width, int height, string name) {
            SDL_Init(SDL_INIT_VIDEO);

            if (width < 0 || height < 0)
            {
                throw "Размер окна не может быть меньше 0";
            }
            else if (name.empty())
            {
                throw "Окно должно иметь название";
            }

            Window = SDL_CreateWindow(
                name.c_str(),
                width,
                height,
                0
            );
            
            Surface = SDL_GetWindowSurface(Window);
            SDL_FillSurfaceRect(Surface, NULL, SDL_MapSurfaceRGB(Surface, 0, 0, 0));
        }

        void fill(Uint8 r = -1, Uint8 g = -1, Uint8 b = -1) {
            if (r == -1) r = color.r;
            else color.r = r;
            if (g == -1) g = color.g;
            else color.g = g;
            if (b == -1) b = color.b;
            else color.b = b;
            SDL_FillSurfaceRect(Surface, NULL, SDL_MapSurfaceRGB(Surface, r, g, b));
        }

        void update() {
            SDL_UpdateWindowSurface(Window);
        }
        
        void destroy() {
            SDL_DestroyWindow(Window);
            SDL_Quit();
        }
        
        void change(int width, int height, string name) {
            if ((width < 0 && width != -1) || (height < 0 && height != -1)) {
                throw "Размер окна не может быть меньше 0";
                return;
            }
        
            SDL_SetWindowSize(Window, width, height);
            if (!name.empty())
                SDL_SetWindowTitle(Window, name.c_str());
        }

        template<typename Func>
        void bindKey(SDL_Scancode key, Func func) {
            keyBindings.push_back({ key, func });
        }
};

#endif