#ifndef EVENT
#define EVENT

#include <app.hpp>
#include <functional>

using namespace std;

/* only for processing the exit */
void exitEvent(app& app) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            app.quit = true;
        }
    }
}

/* to process everything */
void handleEvent(app& app) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            app.quit = true;
        } 
         else if (event.type == SDL_EVENT_KEY_DOWN) {
            SDL_Scancode scancode = event.key.scancode;
            for (auto& binding : app.keyBindings) {
                if (binding.key == scancode) {
                    binding.func();
                    break;
                }
            }
        }
        else if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
            for (const auto& binding : app.mouseBindings) {
                if (binding.button == event.button.button) {
                    binding.func();
                    break;
                }
            }
        }
        else if (event.type == SDL_EVENT_MOUSE_MOTION) {
            int x = event.motion.x;
            int y = event.motion.y;
            for (const auto& binding : app.mouseMotionBindings) {
                binding.func(x, y);
            }
        }
    }
}

#endif