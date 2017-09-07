#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h>
#include "Constants.h"
#include "PlayState.h"
#include <vector>

class Player {
private:
	int x, y, w, h;
public:
	Player(int x, int y, int w = PLAYER_WIDTH, int h = PLAYER_HEIGHT) {
		this->x = x;
		this->y = y;
		this->w = w;
		this->h = h;
	}
	void Update(const Uint8*);
	void Draw(SDL_Texture*, SDL_Renderer*);
	int getX();
	int getY();
	int getW();
	int getH();
};

#endif