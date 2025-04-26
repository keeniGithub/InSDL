#ifndef APP
#define APP

#include <string>
#include <iostream>
#include <map>
#include <functional>
#include <vector>
#include <direct.h>

#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <rect.hpp>
#include <frect.hpp>

using namespace std;

class app {
    private:
        struct keyBindStruct {
            SDL_Scancode key;
            function<void()> func;
        };

        struct mouseBindStruct {
            Uint8 button;
            function<void()> func;
        };

        struct mouseMotionBindStruct {
            function<void(int, int)> func;
        };

        struct colorStruct {
            Uint8 r = 0;
            Uint8 g = 0;
            Uint8 b = 0;
        };

        struct windowStruct {
            int width;
            int height;
            string name;
        };

        bool renderMode;
        
        void createWindow(int width, int height, string name){
            SDL_Init(SDL_INIT_VIDEO);
            window.width = width;
            window.height = height;
            window.name = name;

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
        }

        char buffer[1024];
        char* pathname = getcwd(buffer, 1024);

    public:
        SDL_Window *Window;
        SDL_Surface *Surface;
        SDL_Renderer *Render;
        bool quit = false;
        vector<keyBindStruct> keyBindings;
        vector<mouseBindStruct> mouseBindings;
        vector<mouseMotionBindStruct> mouseMotionBindings;
        colorStruct color;
        windowStruct window;
        string font = string(buffer);

        void init(int width, int height, string name, bool render = false, string fontpath = "") {
            createWindow(width, height, name);
            if (!fontpath.empty()) font = fontpath;

            if (!render) {
                renderMode = false;
                Surface = SDL_GetWindowSurface(Window);
                SDL_FillSurfaceRect(Surface, NULL, SDL_MapSurfaceRGB(Surface, 0, 0, 0));
            } else {
                renderMode = true;
                Render = SDL_CreateRenderer(Window, NULL);
                TTF_Init();
            }
        }

        void fill(Uint8 r = -1, Uint8 g = -1, Uint8 b = -1) {
            if (r == -1) r = color.r;
            else color.r = r;
            if (g == -1) g = color.g;
            else color.g = g;
            if (b == -1) b = color.b;
            else color.b = b;

            if (!renderMode) SDL_FillSurfaceRect(Surface, NULL, SDL_MapSurfaceRGB(Surface, r, g, b));
            else {
                SDL_SetRenderDrawColor(Render, r, g, b, 255);
                SDL_RenderClear(Render);
            }
        }

        void update() {
            if (renderMode) SDL_RenderPresent(Render);
            else SDL_UpdateWindowSurface(Window);
        }
        
        void setIcon(texture icon) {
            SDL_Surface *iconSurface = icon.get().surface;
            SDL_SetWindowIcon(Window, iconSurface);
        }

        void setFont(string fontpath){
            font = fontpath;
        }

        void change(int width, int height, string name) {
            if ((width < 0 && width != -1) || (height < 0 && height != -1)) {
                throw "Размер окна не может быть меньше 0";
                return;
            }
        
            window.width = width;
            window.height = height;
            SDL_SetWindowSize(Window, width, height);

            if (!name.empty()) {
                SDL_SetWindowTitle(Window, name.c_str());
                window.name = name;
            }
        }

        template<typename Func>
        void bindKey(SDL_Scancode key, Func func) {
            keyBindings.push_back({ key, func });
        }

        template<typename Func>
        void bindMouseButton(Uint8 button, Func func) {
            mouseBindings.push_back({ button, func });
        }

        template<typename Func>
        void bindMouseMotion(Func func) {
            mouseMotionBindings.push_back({ func });
        }

        void exit() {
            if (renderMode) {
                SDL_DestroyRenderer(Render); 
                TTF_Quit();
            }
            SDL_DestroyWindow(Window);
            SDL_Quit();
        }
};

#endif