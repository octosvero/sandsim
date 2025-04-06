#include <event_handler.hpp>

EventHandler::EventHandler () {}

SDL_Event* EventHandler::getEvent () {
	return &event;
}

bool EventHandler::pollEvent () {
	return SDL_PollEvent(&event);
}