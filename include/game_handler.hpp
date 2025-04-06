#ifndef GAME_HANDLER_HPP
#define GAME_HANDLER_HPP

#include <render_handler.hpp>

class GameHandler {
private:
    RenderHandler* renderHandler;

    // TODO: Abstract event into a separate EventHandler class, that allows us to enqueue different events at startup to minimize overhead
    bool running;
    SDL_Event event;

public:
    GameHandler();
    ~GameHandler();

    void beginLoop();
};

#endif