#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h>
#include "Constants.h"
#include "PlayState.h"
#include "Projectile.h"

class Player {
private:
	static int x, y, w, h, health, state;
	int now, timepass, dmgnow, dmgpass;
public:
	Player(int x, int y, int w = PLAYER_WIDTH, int h = PLAYER_HEIGHT) {
		this->x = x;
		this->y = y;
		this->w = w;
		this->h = h;
		dmgnow = 0;
		dmgpass = 0;
		timepass = 0;
		health = 100;
		state = 0;
	}
	void Update(const Uint8*, Mix_Chunk*[]);
	void Draw(SDL_Texture**, SDL_Renderer*);
	static void takeDamage(int);
	static void resetStats();
	static int getHealth();
	static int getX();
	static int getY();
	static int getW();
	static int getH();
};

#endif