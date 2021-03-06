#include "Projectile.h"

std::vector<Projectile> Projectile::Bullets;

void Projectile::createProjectile(int x, int y, int w = LSR_W, int h = LSR_H) {
	Bullets.push_back(Projectile(x, y, w, h));
}

void Projectile::noDraw(Projectile& bullet) {
	bullet.drawn = false;
}

void Projectile::Draw(SDL_Texture** ammo, SDL_Renderer* ren, int shipX, int shipY) {
	SDL_SetRenderDrawColor(ren, 255, 255, 0, 255);
	for (Projectile &p : Bullets) {
		//This is for when there is no art present
		//SDL_Rect rect;
		//rect.x = p.x;
		//rect.y = p.y;
		//rect.w = p.w;
		//rect.h = p.h;
		//SDL_RenderFillRect(ren, &rect);
		renderTexture(ammo[LSHOT], ren, p.x, p.y);
		if (shipY - p.y < CHARGE_DIST) {
			renderTexture(ammo[LCHARGE], ren, shipX + PLAYER_WIDTH / 2 - LSR_CHARGEW / 2, shipY - LSR_CHARGEH / 2);
		}
	}

}

void Projectile::Update() {
	std::vector<Projectile>present;
	for (Projectile &p : Bullets) {
		if (p.drawn) {
			p.y -= LSR_SPEED;
			if (p.y > -LSR_W) {
				present.push_back(p);
			}
		}
	}
	Bullets = present;

	////(todo - dasim) I indeed broke this just now
	//std::vector<Projectile>::iterator p = Bullets.begin();
	////while (p != Bullets.end()) {

	////}
	//for (p; p != Bullets.end(); ++p) {
	//	if ((*p).drawn && (*p).y - LSR_SPEED > -LSR_H) {
	//		(*p).y -= LSR_SPEED;
	//	}
	//	else {
	//		p = Bullets.erase(p);
	//		if (p != Bullets.begin()) {
	//			p = std::prev(p);
	//			continue;
	//		}
	//	}
	//}
}