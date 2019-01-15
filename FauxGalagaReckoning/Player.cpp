#include "Player.h"

int Player::health;
int Player::state;
int Player::x;
int Player::w;
int Player::y;
int Player::h;

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

void Player::resetStats() {
	health = MAX_HEALTH;
	state = PLAYER;
	x = (SCREEN_WIDTH - PLAYER_WIDTH) / 2;
	y = SCREEN_HEIGHT - PLAYER_HEIGHT;
}

void Player::Update(const Uint8* keys, Mix_Chunk* effects[]) {
	if (state == PDAMAGED) {
		dmgnow = SDL_GetTicks();
	}
	if (!dmgpass) {
		dmgpass = dmgnow;
	}
	std::cout << "TIMENOW -- " << dmgnow << std::endl;
	std::cout << "TIMEPASS -- " << dmgpass << std::endl;
	if (state == PDAMAGED && dmgnow > dmgpass + 400) {
		state = PLAYER;
	}
	if (state != PDAMAGED) {
		dmgpass = dmgnow = 0;
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
				Projectile::createProjectile(x + (w - LSR_W) / 2, y - LSR_H / 2, LSR_W, LSR_H);
				Mix_VolumeChunk(effects[LASER], MIX_MAX_VOLUME / 4);
				Mix_PlayChannel(-1, effects[LASER], 0);
			}
			timepass = now;
		}
		if (!(keys[SDL_SCANCODE_LEFT] || keys[SDL_SCANCODE_RIGHT])) {
			state = PLAYER;
		}
	}

	if (x < 0) x = 0;
	if (x > (SCREEN_WIDTH - w)) x = SCREEN_WIDTH - w;
	if (y < 0) y = 0;
	if (y > SCREEN_HEIGHT - h) y = SCREEN_HEIGHT - h;

	Projectile::Update();
}

void Player::Draw(SDL_Texture** ship, SDL_Renderer* ren) {
	SDL_SetRenderDrawColor(ren, 94, 63, 107, 255);
	renderTexture(ship[state], ren, x, y);
	//CHANGE DIST TO ACCOUNT FOR NEW SPDLINE SIZE
	//CHOICE: Keep speed lines or not? Currently disabled.
	/*renderTexture(ship[SPEED_LINE], ren, x + (w - SPDLINE_W / 2), y + h - 10);
	renderTexture(ship[SPEED_LINE], ren, x, y + h - 10);
	renderTexture(ship[SPEED_LINE], ren, x + (w / 2) - SPDLINE_W/2, y + h);*/
	Projectile::Draw(ship, ren, x, y);
}