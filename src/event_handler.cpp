#include <event_handler.hpp>

EventHandler::EventHandler () {
	eventF_k = new SDL_EventType[16];
	eventF_v = new std::function<void(SDL_Event*)>[16];
	eventF_c = 0;
	// mapEventF = std::map<SDL_EventType, EventF>(0, 16);
}

EventHandler::~EventHandler() {
	delete[] eventF_k;
	delete[] eventF_v;
}

int EventHandler::eventF_get(SDL_EventType type) {
	for (int i = 0; i < eventF_c; i++) {
		if (eventF_k[i] == type) {
			return i;
		}
	}

	return -1;
}

void EventHandler::linkEvent (SDL_EventType type, std::function<void(SDL_Event*)> eventf) {
	// mapEventF.insert(type);
	// mapEventF.at(type) = eventf;
	eventF_k[eventF_c] = type;
	eventF_v[eventF_c] = eventf;
	eventF_c++;
}

void EventHandler::unlinkEvent (SDL_EventType type) {
	// mapEventF.erase(type);
	return;
}

void EventHandler::processEvents () {
	while (pollEvent()) {
		// mapEventF.at((SDL_EventType)event.type)(&event);
		int eventfIdx = eventF_get((SDL_EventType)event.type);

		if (eventfIdx == -1) {
			continue;
		}

		std::function<void(SDL_Event*)> eventf = eventF_v[eventfIdx];

		eventf(&event);
	}
}

SDL_Event* EventHandler::getEvent () {
	return &event;
}

bool EventHandler::pollEvent () {
	return SDL_PollEvent(&event);
}