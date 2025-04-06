#ifndef GAME_HANDLER_HPP
#define GAME_HANDLER_HPP

#include <render_handler.hpp>
#include <event_handler.hpp>
#include <cells/cell_chunk.hpp>

class GameHandler {
private:
    RenderHandler* renderHandler;
    EventHandler* eventHandler;

    CellChunk* cellChunk;
    uint32_t cellChunk_timemod;

    bool running;
    uint64_t time;

public:
    GameHandler();
    ~GameHandler();

    void beginLoop();

    void onQuit(SDL_Event* event);
};

#endif