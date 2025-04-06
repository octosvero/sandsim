#ifndef EVENT_HANDLER_HPP
#define EVENT_HANDLER_HPP

#include <SDL3/SDL.h>

#include <array>
#include <functional>

// C++, this is a bad decision, why can't we just make a pointer to ANY kind of function
// typedef void (*EventF) (SDL_Event* event);
typedef SDL_EventType EventType;
typedef std::function<void(SDL_Event*)> EventFunc;

class EventHandler {
private:
	SDL_Event event;

	std::array<EventType, 16> linkedEvents_k;
	std::array<EventFunc, 16> linkedEvents_v;
	uint32_t linkedEvents_c;

	int32_t findEvent(EventType type);

public:
	EventHandler();

	void linkEvent(EventType type, EventFunc func);
	void unlinkEvent(EventType type);

	void processEvents();

	SDL_Event* getEvent();
	bool pollEvent();
};

#endif