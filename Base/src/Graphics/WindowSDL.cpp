#include "Graphics/WindowSDL.h"

#include <SDL_image.h>

void WindowSDL::initialize(const char* name, int xpos, int ypos, int width, int height, bool fullscreen) {
	WINDOW_DEBUG("Initialize Started")
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_VIDEO) == 0) {
		WINDOW_DEBUG("SDL Video Initialized")

		window = SDL_CreateWindow(name, xpos, ypos, width, height, flags);
		if (window) {
			WINDOW_DEBUG("Window Initialized")
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			WINDOW_DEBUG("Renderer Initialized")
		}

		int imgFlags = IMG_INIT_PNG;
		if (!(IMG_Init(imgFlags) & imgFlags)) {
			// TODO Failed IMG_INIT call
		}
	}
	nextID = 0;
	WINDOW_DEBUG("Initialize Complete")
}

void WindowSDL::update() {
	WINDOW_DEBUG("Update Started")
	SDL_RenderClear(renderer);
	renderTexture(loadTexture("assets/Back.bmp"));
	SDL_RenderPresent(renderer);
	WINDOW_DEBUG("Update Complete")
}

void WindowSDL::cleanup() {
	WINDOW_DEBUG("Cleanup Started")
	for (auto const& texture : textureMap)
		SDL_DestroyTexture(texture.second);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	IMG_Quit();
	WINDOW_DEBUG("Cleanup Complete")
}

int WindowSDL::loadTexture(std::string path) {
	WINDOW_DEBUG("Loading Texture - " + path)
	auto temp = textureIDs.find(path);
	if (temp != textureIDs.end()) {
		WINDOW_DEBUG("Found Texture - " + path)
		return temp->second;
	}
	
	SDL_Texture* texture = IMG_LoadTexture(renderer, path.c_str());
	if (texture) {
		WINDOW_DEBUG("Failed Texture Load")
		// TODO Failed load error handling
	}
	textureIDs[path] = nextID;
	textureMap[nextID] = texture;

	WINDOW_DEBUG("Generated Texture - " + path)
	return nextID++;
}

void WindowSDL::renderTexture(unsigned int id) {
	WINDOW_DEBUG("Rendering Texture - " << id)
	auto texture = textureMap.find(id);
	if (texture == textureMap.end()) {
		WINDOW_DEBUG("Texture Missing - " + id)
		// TODO Failed to find texture in TextureMaps
		return;
	}
	if (SDL_RenderCopy(renderer, texture->second, NULL, NULL)) {
		WINDOW_DEBUG("Failed Texture Render")
		// TODO Failed creation error handling
	}
}