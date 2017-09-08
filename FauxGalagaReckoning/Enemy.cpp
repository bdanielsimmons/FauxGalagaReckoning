#include "Enemy.h"

std::vector<Enemy> Enemy::Enemies;
int ran = SDL_GetTicks();

void Enemy::createEnemy(int x, int y, int w = SPCENEMY_W, int h = SPCENEMY_H) {
	Enemies.push_back(Enemy(x, y, w, h));
}

void Enemy::Draw(SDL_Texture** enemy, SDL_Renderer* ren) {
	for (Enemy &p : Enemies) {
		/*SDL_Rect recta;
		recta.x = p.x;
		recta.y = p.y;
		recta.w = p.w;
		recta.h = p.h;
		SDL_RenderFillRect(ren, &recta);
		if (p.drawn) {*/
		renderTexture(enemy[MAIN_SHIP], ren, p.x, p.y);
		//}
	}
}

void Enemy::Update() {
	std::vector<Enemy>present;
	for (Enemy &a : Enemies) {
		a.y += SPCENEMY_S;
		bool c = false;
		bool d = false;
		bool e = false;
		for (Projectile &p : Projectile::Bullets) {
			c = c || (CheckCollision(a.x, a.y, a.w, a.h, p.x, p.y, p.w, p.h));
			if (c) {
				Projectile::noDraw(p);
				PlayState::increaseScore(10);
				break;
			}
		}
		for (Enemy &b : present) {
			e = e || (CheckCollision(a.x, a.y, a.w, a.h, b.x, b.y, b.w, b.h));
		}
		d = d || (CheckCollision(a.x, a.y, a.w, a.h, Player::getX(), Player::getY(), Player::getW(), Player::getH()));
		if (d) {
			Player::takeDamage(10);
		}
		if (a.x + a.w > 0 && !c && a.x + a.w > 0 && !d && !e) {
			present.push_back(a);
		}
	}
	Enemies = present;
}
