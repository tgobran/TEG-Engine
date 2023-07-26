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

	void renderTexture(unsigned int id, float x, float y, float w, float h, bool centered=false);
	void renderTextureFill(unsigned int id);
	
private:
	SDL_Texture* getSDLTexture(unsigned int id);
	void renderSDLTexture(SDL_Texture* texture, SDL_Rect* source, SDL_Rect* destination);

	SDL_Window* window;
	int WINDOW_WIDTH;
	int WINDOW_HEIGHT;

	SDL_Renderer* renderer;

	unsigned int nextID;
	std::map<std::string, unsigned int> textureIDs;
	std::map<unsigned int, SDL_Texture*> textureMap;
};