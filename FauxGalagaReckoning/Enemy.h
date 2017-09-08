#ifndef ENEMY_H
#define ENEMY_H

#include "Constants.h"
#include "Player.h"
#include <SDL.h>
#include <vector>

class Enemy {
private:
	int x, y, w, h;
public:
	static std::vector<Enemy> Enemies;
	Enemy(int x, int y, int w = SPCENEMY_W, int h = SPCENEMY_H) {
		this->x = x;
		this->y = y;
		this->w = w;
		this->h = h;
	}
	static void createEnemy(int, int, int, int);
	static void Draw(SDL_Texture**, SDL_Renderer*);
	static void Update();

};

#endif