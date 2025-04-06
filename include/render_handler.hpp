#ifndef RENDER_HANDLER_HPP
#define RENDER_HANDLER_HPP  

#include <SDL3/SDL.h>

class RenderHandler {
    SDL_Window* window;
    SDL_Renderer* renderer;
public:
    RenderHandler();
    ~RenderHandler();

    // GameHandler will call preRender() after handling events
    void preRender();
    // Render functions for all entities will be called before the GameHandler calls postRender()
    void postRender();
};

#endif