#ifndef GAME_HANDLER_HPP
#define GAME_HANDLER_HPP

#include <render_handler.hpp>
#include <event_handler.hpp>

class GameHandler {
private:
    RenderHandler* renderHandler;
    EventHandler* eventHandler;

    bool running;

public:
    GameHandler();
    ~GameHandler();

    void beginLoop();
};

#endif