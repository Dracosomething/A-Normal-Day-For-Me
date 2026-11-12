#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <iostream>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

#define FPS 0 // 0 means that it runs at the browser refresh rate

const static char* cspApp_name = "A Normal Day For Me";
const static char* cspApp_version = "0.1";
const static char* cspApp_identifier = "nl.hellscodebase.a-normal-day-for-me";

static SDL_Window* spWindow = NULL;
static SDL_Renderer* spRenderer = NULL;

void initialize_game(void) {
    if (!SDL_SetAppMetadata(scApp_name, scApp_version, scApp_identifier)) {
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Encountered error when setting app metadata: %s", SDL_GetError());
		exit(1);
    }
#ifdef __EMSCRIPTEN__
    emscripten_set_window_title(scApp_name);
#endif

    if (!SDL_Init(SDL_INIT_VIDEO)) {
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Encountered error when initializing video: %s", SDL_GetError());
		exit(1);
    }

#ifdef __EMSCRIPTEN__
    int width;
    int height;
    emscripten_get_screen_size(&width, &height);
#else
    int width = 1920;
    int height = 1080;
#endif

    if (!SDL_CreateWindowAndRenderer(scApp_name, width, height, SDL_WINDOW_FULLSCREEN, &sWindow, &sRenderer)) {
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Encountered error when creating window/renderer: %s", SDL_GetError());
		exit(1);
    }

    if (!SDL_SetRenderLogicalPresentation(sRenderer, width, height, SDL_LOGICAL_PRESENTATION_LETTERBOX)) {
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Encountered error when settimg renderer logical presentation: %s", SDL_GetError());
		exit(1);
    }
}

static void mainloop(void) {
    // We check if we have a quit event and exit the game
    if (SDL_HasEvent(SDL_EVENT_QUIT)) {
    #ifdef __EMSCRIPTEN__
		emscripten_cancel_main_loop();
    #else
		exit(0);
    #endif
    }

    // true game logic
}

int main(int argc, char** argv) {
    initialize_game();

#ifdef __EMSCRIPTEN__
    emscripten_set_main_loop(mainloop, FPS, true);
#else
    for (;;) { mainloop(); }
#endif

    return 0;
}
