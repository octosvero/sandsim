#include <SDL3/SDL.h>

#include <iostream>
#include <math.h>

SDL_Window* window;
SDL_Surface* canvas; // Remove if unneccessary
SDL_Renderer* renderer;
bool should_quit;

/* Init/Quit methods
 */

void init() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "Could not initialize SDL3: " << SDL_GetError() << "\n";
		std::exit(1);
	}

	window = SDL_CreateWindow(
		"SandSim :P",
		800, 600,
		SDL_WINDOW_RESIZABLE);

	if (window == NULL) {
		std::cout << "Could not create SDL3 window: " << SDL_GetError() << "\n";
		std::exit(1);
	}

	// canvas = SDL_GetWindowSurface(window);

	renderer = SDL_CreateRenderer(window, NULL);

	if (renderer == NULL) {
		std::cout << "Could not create SDL3 renderer: " << SDL_GetError() << "\n";
		std::exit(1);
	}
}

void quit() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

/* Loop Methods
 */

float time = 0.0f;
// This variable is for testing, remove it later
float clearColor[4] = {0.0f, 0.0f, 0.0f, 1.0f};

void update() {
	clearColor[0] = sin(time / 100) / 2 + 0.5f;
	clearColor[1] = cos(time / 100) / 2 + 0.5f;
	clearColor[2] = (sin(time / 100) * cos(time / 100)) / 4 + 0.5f;

	time += 0.1f;
}

void render() {
	// Clear the screen with a slightly-dark color
	SDL_SetRenderDrawColorFloat(renderer, clearColor[0], clearColor[1], clearColor[2], 1.0f);
	SDL_RenderClear(renderer);

	SDL_RenderPresent(renderer);
}

void loop() {
	SDL_Event event;

	while (!should_quit) {
		// Process Events
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_EVENT_QUIT)
				should_quit = true;
		}

		// Main Loop
		update();
		render();
	}
}

/* Main
 */

int main() {
	window = NULL;
	canvas = NULL;
	renderer = NULL;
	should_quit = false;

	init();
	loop();
	quit();
    return 0;
}