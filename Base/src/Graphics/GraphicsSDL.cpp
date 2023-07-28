#include "Graphics/GraphicsSDL.h"

#include <SDL_image.h>

void GraphicsSDL::initialize(const char* name, int xpos, int ypos, int width, int height, bool fullscreen) {
	GRAPHICS_DEBUG("Initialize Started")
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_VIDEO) == 0) {
		GRAPHICS_DEBUG("SDL Video Initialized")

		window = SDL_CreateWindow(name, xpos, ypos, width, height, flags);
		WINDOW_WIDTH = width;
		WINDOW_HEIGHT = height;
		if (window) {
			GRAPHICS_DEBUG("Window Initialized")
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			GRAPHICS_DEBUG("Renderer Initialized")
		}

		int imgFlags = IMG_INIT_PNG;
		if (!(IMG_Init(imgFlags) & imgFlags)) {
			// TODO Failed IMG_INIT call
		}
	}
	nextID = 0;
	GRAPHICS_DEBUG("Initialize Complete")
}

void GraphicsSDL::update() {
	GRAPHICS_DEBUG("Update Started")
	SDL_RenderClear(renderer);
	// TODO Replace with Proper Rendering
	renderTexture(loadTexture("assets/Back.bmp"), 100, 100, 100, 100);
	SDL_RenderPresent(renderer);
	GRAPHICS_DEBUG("Update Complete")
}

void GraphicsSDL::cleanup() {
	GRAPHICS_DEBUG("Cleanup Started")
	for (auto const& texture : textureMap)
		SDL_DestroyTexture(texture.second);
	textureIDs.clear();
	textureMap.clear();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	IMG_Quit();
	GRAPHICS_DEBUG("Cleanup Complete")
}

int GraphicsSDL::loadTexture(std::string path) {
	GRAPHICS_DEBUG("Loading Texture - " + path)
	auto temp = textureIDs.find(path);
	if (temp != textureIDs.end()) {
		GRAPHICS_DEBUG("Found Texture - " + path)
		return temp->second;
	}
	
	SDL_Texture* texture = IMG_LoadTexture(renderer, path.c_str());
	if (texture) {
		GRAPHICS_DEBUG("Failed Texture Load")
		// TODO Failed load error handling
	}
	textureIDs[path] = nextID;
	textureMap[nextID] = texture;

	GRAPHICS_DEBUG("Generated Texture - " + path)
	return nextID++;
}

void GraphicsSDL::renderTexture(unsigned int id, float x, float y, float w, float h, bool centered) {
	GRAPHICS_DEBUG("Rendering Texture - " << id)
	
	SDL_Rect dstrect;
	if (x != floor(x) && x < 1)
		dstrect.x = WINDOW_WIDTH * x;
	else
		dstrect.x = x;
	if (y != floor(y) && y < 1)
		dstrect.y = WINDOW_HEIGHT * y;
	else
		dstrect.y = y;
	if (w != floor(w) && w < 1)
		dstrect.w = WINDOW_WIDTH * w;
	else
		dstrect.w = w;
	if (h != floor(h) && h < 1)
		dstrect.h = WINDOW_HEIGHT * h;
	else
		dstrect.h = h;
	
	if (centered) {
		dstrect.x = dstrect.x - (dstrect.w / 2);
		dstrect.y = dstrect.y - (dstrect.h / 2);
	}
	
	renderSDLTexture(getSDLTexture(id), nullptr, &dstrect);
}

void GraphicsSDL::renderTextureFill(unsigned int id) {
	GRAPHICS_DEBUG("Rendering Fill Texture - " << id)
	renderSDLTexture(getSDLTexture(id), nullptr, nullptr);
}

SDL_Texture* GraphicsSDL::getSDLTexture(unsigned int id) {
	auto texture = textureMap.find(id);
	if (texture == textureMap.end()) {
		GRAPHICS_DEBUG("Texture Missing - " << id)
			// TODO Failed to find texture in TextureMaps
		return nullptr;
	}
	return texture->second;
}

void GraphicsSDL::renderSDLTexture(SDL_Texture* texture, SDL_Rect* src, SDL_Rect* dst) {
	if (SDL_RenderCopy(renderer, texture, src, dst)) {
		GRAPHICS_DEBUG("Failed SDL Texture Render")
			// TODO Failed creation error handling
	}
} 