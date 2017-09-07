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
	/*SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	dst.w = w;
	dst.h = h;
	SDL_RenderFillRect(ren, &dst);*/
	renderTexture(ship, ren, x, y);
}
//void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y) {
//	//Setup the destination rectangle to be at the position we want
//	SDL_Rect dst;
//	dst.x = x;
//	dst.y = y;
//	//Query the texture to get its width and height to use
//	SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
//	SDL_RenderCopy(ren, tex, NULL, &dst);
//}
//
//SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren) {
//	//Initialize to nullptr to avoid dangling pointer issues
//	SDL_Texture *texture = nullptr;
//	SDL_Surface *loadedImage = SDL_LoadBMP(file.c_str());
//	texture = SDL_CreateTextureFromSurface(ren, loadedImage);
//	SDL_FreeSurface(loadedImage);
//	return texture;
//}