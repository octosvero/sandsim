#include <game_handler.hpp>

GameHandler::GameHandler() : running(true), time(0) {
    renderHandler = new RenderHandler();
    eventHandler = new EventHandler();

    eventHandler->linkEvent(SDL_EVENT_QUIT, [&](SDL_Event* event) {onQuit(event);});

    cellChunk = new CellChunk(100, 100);
    cellChunk_timemod = 50; // Each 50th tick cellChunk will update
}

GameHandler::~GameHandler() {
    delete renderHandler;
    delete eventHandler;
    delete cellChunk;
}

void GameHandler::beginLoop() {
    while (running) {
        // Process Events
        eventHandler->processEvents();

        /* Update
         */

        if (time % cellChunk_timemod == 0) {
            cellChunk->update();

            Cell sand(CellID_Sand);
            cellChunk->setCell(2, 1, sand);
        }

        /* Render
         */

        renderHandler->preRender();

            // Entity rendering goes here
            cellChunk->render(renderHandler);

        renderHandler->postRender();

        /* Post-Loop
         */

        // Increment time
        time++;
    }
}

void GameHandler::onQuit(SDL_Event* event) {
    running = false;
}