#ifndef EVENT_HANDLER_HPP
#define EVENT_HANDLER_HPP

#include <SDL3/SDL.h>

class EventHandler {
private:
	SDL_Event event;

public:
	EventHandler();

	SDL_Event* getEvent();
	bool pollEvent();
};

#endif