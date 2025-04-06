#ifndef EVENT_HANDLER_HPP
#define EVENT_HANDLER_HPP

#include <SDL3/SDL.h>

#include <map>
#include <functional>

// C++, this is a bad decision, why can't we just make a pointer to ANY kind of function
// typedef void (*EventF) (SDL_Event* event);

class EventHandler {
private:
	SDL_Event event;

	// Replacement for a map
	// Because some C++ features are just complicated
	SDL_EventType* eventF_k;
	std::function<void(SDL_Event*)>* eventF_v;
	uint32_t       eventF_c;

	// Pain
	// std::map<SDL_EventType, EventF> mapEventF;
	int eventF_get(SDL_EventType type);

public:
	EventHandler();
	~EventHandler();

	void linkEvent(SDL_EventType type, std::function<void(SDL_Event*)> eventf);
	void unlinkEvent(SDL_EventType type);

	void processEvents();

	SDL_Event* getEvent();
	bool pollEvent();
};

#endif