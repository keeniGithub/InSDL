#ifndef EVENT
#define EVENT

#include <app.hpp>
#include <functional>

using namespace std;

void exitEvent(app& app) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            app.quit = true;
        }
    }
}

void handleEvent(app& app) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            app.quit = true;
        } 
        else if (event.type == SDL_EVENT_KEY_DOWN) {
            SDL_Scancode scancode = event.key.keysym.scancode;
            for (auto& binding : app.keyBindings) {
                if (binding.key == scancode) {
                    binding.func();
                    break;
                }
            }
        }
    }
}


#endif