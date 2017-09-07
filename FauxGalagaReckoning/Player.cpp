#include "Player.h"

//int Player::health;

int Player::getHealth() {
	return health;
}
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

void Player::takeDamage(int dmg) {
	health -= dmg;
	state = PDAMAGED;
}

void Player::Update(const Uint8* keys) {
	if (keys[SDL_SCANCODE_UP])	y -= PLAYER_VEL;
	if (keys[SDL_SCANCODE_DOWN]) y += PLAYER_VEL;
	if (keys[SDL_SCANCODE_LEFT]) {
		x -= PLAYER_VEL; 
		state = PLEFT;
	}
	if (keys[SDL_SCANCODE_RIGHT]) {
		x += PLAYER_VEL;
		state = PRIGHT;
	}
	if (keys[SDL_SCANCODE_SPACE]) {
		now = SDL_GetTicks();
		if (now > timepass + 50) {
			Projectile::createProjectile(x + w/2 - LSR_W/2, y-LSR_H/2, LSR_W, LSR_H);
			takeDamage(10);
		}
		timepass = now;
	}
	if (!(keys[SDL_SCANCODE_LEFT] || keys[SDL_SCANCODE_RIGHT])) {
		state = PLAYER;
	}

	if (x < 0) x = 0;
	if (x >(SCREEN_WIDTH - w)) x = SCREEN_WIDTH - w;
	if (y < 0) y = 0;
	if (y > SCREEN_HEIGHT - h) y = SCREEN_HEIGHT - h;

	Projectile::Update();
}

void Player::Draw(SDL_Texture** ship, SDL_Renderer* ren) {
	SDL_SetRenderDrawColor(ren, 94, 63, 107, 255);
	renderTexture(ship[state], ren, x, y);
	Projectile::Draw(ship, ren);
}