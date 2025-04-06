#include <game_handler.hpp>

GameHandler::GameHandler() : running(true) {
    renderHandler = new RenderHandler();
    eventHandler = new EventHandler();

    eventHandler->linkEvent(SDL_EVENT_QUIT, [&](SDL_Event* event) {onQuit(event);});
}

GameHandler::~GameHandler() {
    delete renderHandler;
    delete eventHandler;
}

void GameHandler::beginLoop() {
    while (running) {
        // Process Events
        eventHandler->processEvents();

        renderHandler->preRender();

        // Entity rendering goes here

        renderHandler->postRender();
    }
}

void GameHandler::onQuit(SDL_Event* event) {
    running = false;
}