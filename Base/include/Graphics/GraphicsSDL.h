#pragma once
#include "Graphics/Graphics.h"

#include <map>

#include "SDL.h"

#include "Error.h"

class GraphicsSDL : public Graphics {

public:
	void initialize(const char* name, int xpos, int ypos, int width, int height, bool fullscreen);

	void update();
	
	void cleanup();

	int loadTexture(std::string path);
	void renderTexture(unsigned int id);

private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	unsigned int nextID;
	std::map<std::string, unsigned int> textureIDs;
	std::map<unsigned int, SDL_Texture*> textureMap;
};