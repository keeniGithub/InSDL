#ifndef APP
#define APP

#include <string>
#include <iostream>
#include <SDL3/SDL.h>

using namespace std;

class app {
    public:
        SDL_Window *myWindow;
        SDL_Surface *myWindowSurface;
        bool quit = false;

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

            myWindow = SDL_CreateWindow(
                name.c_str(),
                width,
                height,
                0
            );
            myWindowSurface = SDL_GetWindowSurface(myWindow);
            SDL_FillSurfaceRect(myWindowSurface, NULL, SDL_MapRGB(myWindowSurface->format, 0, 0, 0));
        }

        void update(Uint8 r, Uint8 g, Uint8 b) {
            SDL_FillSurfaceRect(myWindowSurface, NULL, SDL_MapRGB(myWindowSurface->format, r, g, b));
            SDL_UpdateWindowSurface(myWindow);
        }

        void destroy() {
            SDL_DestroyWindow(myWindow);
            SDL_Quit();
        }

        void fill(SDL_Rect *rect, Uint8 r, Uint8 g, Uint8 b) {
            SDL_FillSurfaceRect(myWindowSurface, rect, SDL_MapRGB(myWindowSurface->format, r, g, b));
        }
        
        void change(int width, int height, string name) {
            if ((width < 0 && width != -1) || (height < 0 && height != -1)) {
                throw "Размер окна не может быть меньше 0";
                return;
            }
        
            SDL_SetWindowSize(myWindow, width, height);
            if (!name.empty()) SDL_SetWindowTitle(myWindow, name.c_str());
        }
};

#endif