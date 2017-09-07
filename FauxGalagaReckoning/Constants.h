#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <SDL.h>
#include <string>
const int SCREEN_WIDTH = 600,
SCREEN_HEIGHT = 750,
BG_HEIGHT = 750,
PLAYER_VEL = 4,
PLAYER_WIDTH = 50,
PLAYER_HEIGHT = 38,
LSR_W = 9,
LSR_H = 33,
LSR_SPEED = 15,
MAX_HEALTH = 100,
ARCADE_FONTSZ = 15,
SCROLL_SPEED = 15;
enum bkgs { SCROLL1, SCROLL2 };
enum playerText { HEALTH, SCORE, LIVES};
enum gameFont { ARCADE };
enum playerArt { PLAYER, PLEFT, PRIGHT, PDAMAGED, LCHARGE, LSHOT };

#endif