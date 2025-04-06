#include <game_handler.hpp>

GameHandler::GameHandler() : running(true) {
    renderHandler = new RenderHandler();
}

GameHandler::~GameHandler() {
    delete renderHandler;
}

void GameHandler::beginLoop() {
    while (running) {
        while (SDL_PollEvent(&event)) {
            // Event handling goes here (probably, we'll figure it out)

            if (event.type == SDL_EVENT_QUIT)
                running = false;
        }

        renderHandler->preRender();

        // Entity rendering goes here

        renderHandler->postRender();
    }
}