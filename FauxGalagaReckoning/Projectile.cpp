#include "Projectile.h"

std::vector<Projectile> Projectile::Bullets;

void Projectile::createProjectile(int x, int y, int w = LSR_W, int h = LSR_H) {
	Bullets.push_back(Projectile(x, y, w, h));
}

void Projectile::Draw(SDL_Texture** ammo, SDL_Renderer* ren, int shipX, int shipY) {
	SDL_SetRenderDrawColor(ren, 255, 255, 0, 255);
	for (Projectile &p : Bullets) {
		//SDL_Rect rect;
		//rect.x = p.x;
		//rect.y = p.y;
		//rect.w = p.w;
		//rect.h = p.h;
		//SDL_RenderFillRect(ren, &rect);
		renderTexture(ammo[LSHOT], ren, p.x, p.y);
		if(shipY - p.y < CHARGE_DIST){
			renderTexture(ammo[LCHARGE], ren, shipX + PLAYER_WIDTH / 2 - LSR_CHARGEW / 2, shipY - LSR_CHARGEH / 2);
		}
	}
	
}

void Projectile::Update() {
	std::vector<Projectile>present;
	for (Projectile &p : Bullets) {
		p.y -= LSR_SPEED;
		if (p.y > -LSR_W) {
			present.push_back(p);
		}
	}
	Bullets = present;
}