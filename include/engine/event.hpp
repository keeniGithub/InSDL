#ifndef EVENT
#define EVENT

#include <app.hpp>

void exitEvent(app& app) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            app.quit = true;
        }
    }
}

#endif