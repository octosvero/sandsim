#include <event_handler.hpp>

int32_t EventHandler::findEvent(EventType type) {
	for (int32_t i = 0; i < linkedEvents_k.size(); i++) {
		if (linkedEvents_k.at(i) == type)
			return i;
	}

	return -1;
}

EventHandler::EventHandler () {
	// linkedEvents = std::map(SDL_EVENT_FIRST, SDL_EVENT_LAST);
	linkedEvents_c = 0;
}

void EventHandler::linkEvent (EventType type, EventFunc func) {
	linkedEvents_k.at(linkedEvents_c) = type;
	linkedEvents_v.at(linkedEvents_c) = func;
	linkedEvents_c++;
}

void EventHandler::unlinkEvent (EventType type) {
	// int32_t eventIdx = findEvent(type);
	// linkedEvents_k.erase(linkedEvents_k.begin() + eventIdx);
	// linkedEvents_v.erase(linkedEvents_v.begin() + eventIdx);
	return;
}

void EventHandler::processEvents () {
	while (pollEvent()) {
		int32_t eventIdx = findEvent((EventType)event.type);

		// I tried using std::map, std::unordered_map, std::vector,
		// std::array, a basic C array just to find out I forgot to put this
		// here.
		// Thank you, C++.
		// And actually thank you a basic C array for letting me know it's
		// not actually std::out_of_bounds but rather std::bad_function_call.
		if (eventIdx == -1)
			continue;

		linkedEvents_v.at(eventIdx)(&event);
	}
}

SDL_Event* EventHandler::getEvent () {
	return &event;
}

bool EventHandler::pollEvent () {
	return SDL_PollEvent(&event);
}