#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h>
#include "Constants.h"
#include "PlayState.h"
#include "Projectile.h"

class Player {
private:
	int x, y, w, h, state, now, timepass, dmgnow, dmgpass;
	int health;
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
	void Update(const Uint8*);
	void Draw(SDL_Texture**, SDL_Renderer*);
	void takeDamage(int);
	int getHealth();
	int getX();
	int getY();
	int getW();
	int getH();
};

#endif