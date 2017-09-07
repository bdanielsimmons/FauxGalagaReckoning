#include "Player.h"

int now, timepass;

int Player::getX() {
	return x;
}
int Player::getY() {
	return y;
}
int Player::getW() {
	return w;
}
int Player::getH() {
	return h;
}

void Player::Update(const Uint8* keys) {
	if (keys[SDL_SCANCODE_UP]) y -= DOT_VEL;
	if (keys[SDL_SCANCODE_DOWN]) y += DOT_VEL;
	if (keys[SDL_SCANCODE_LEFT]) x -= DOT_VEL;
	if (keys[SDL_SCANCODE_RIGHT]) x += DOT_VEL;
	if (x < 0) x = 0;
	if (x >(SCREEN_WIDTH - w)) x = SCREEN_WIDTH - w;
	if (y < 0) y = 0;
	if (y > SCREEN_HEIGHT - h) y = SCREEN_HEIGHT - h;
}

void Player::Draw(SDL_Texture* ship, SDL_Renderer* ren) {
	SDL_SetRenderDrawColor(ren, 255, 0, 0, 255);
	renderTexture(ship, ren, x, y);
}