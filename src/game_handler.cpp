#include <game_handler.hpp>

GameHandler::GameHandler() : running(true) {
    renderHandler = new RenderHandler();
    eventHandler = new EventHandler();
}

GameHandler::~GameHandler() {
    delete renderHandler;
    delete eventHandler;
}

void GameHandler::beginLoop() {
    SDL_Event* event = eventHandler->getEvent();

    while (running) {
        while (eventHandler->pollEvent()) {
            // Event handling goes here (probably, we'll figure it out)

            if (event->type == SDL_EVENT_QUIT)
                running = false;
        }

        renderHandler->preRender();

        // Entity rendering goes here

        renderHandler->postRender();
    }
}