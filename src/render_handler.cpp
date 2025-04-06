#include <render_handler.hpp>

RenderHandler::RenderHandler() {
    SDL_CreateWindowAndRenderer("SandSim", 800, 600, SDL_WINDOW_MAXIMIZED | SDL_WINDOW_RESIZABLE, &window, &renderer);
}

RenderHandler::~RenderHandler() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void RenderHandler::preRender() {
    SDL_SetRenderDrawColorFloat(renderer, 0.f, 0.f, 0.f, 1.f);
    SDL_RenderClear(renderer);
}

void RenderHandler::postRender() {
    SDL_RenderPresent(renderer);
}