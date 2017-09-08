#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <vector>
#include <SDL.h>
#include "Constants.h"
#include "PlayState.h"

class Projectile {
public:
	int x, y, w, h;
	bool drawn;
	static std::vector<Projectile> Bullets;
	Projectile(int x, int y, int w = LSR_W, int h = LSR_H) {
		this->x = x;
		this->y = y;
		this->w = w;
		this->h = h;
		drawn = true;
	}
	static void noDraw(Projectile&);
	static void createProjectile(int, int, int, int);
	static void Draw(SDL_Texture**, SDL_Renderer* ren, int, int);
	static void Update();

};

#endif
