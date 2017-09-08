#ifndef BOX_H
#define BOX_H

#include <SDL.h>
#include <vector>
#include "Constants.h"
#include "Player.h"
#include "Box.h"
#include "Enemy.h"

bool CheckCollision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);

#endif