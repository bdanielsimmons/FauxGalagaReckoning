#include <SDL.h>
#include <iostream>
#include "PlayState.h"
#include "PauseState.h"

//void renderTexture(SDL_Texture*, SDL_Renderer, int, int);
//SDL_Texture* loadTexture(const std::string&, SDL_Renderer);

PauseState PauseState::ActivePauseState;
SDL_Texture* PauseState::background;

void PauseState::Init(StateManager* game) {
	SDL_Texture* bg = loadTexture("house.bmp", game->SMRender);
	background = bg;
}

void PauseState::Clear() {

}

void PauseState::Update(StateManager* game) {
	auto keys = SDL_GetKeyboardState(NULL);
	SDL_PollEvent(game->Happening());
	int now = game->getNow();
	std::cout << game->getNow() << "<-----NOW!\n";
	std::cout << game->getTimepass() << "<------ Passed!\n";
	game->setTimePass();
	if (game->Event.type == SDL_KEYDOWN) {
		if (game->Event.key.keysym.sym == SDLK_ESCAPE && now <= game->getTimepass() - 1000) {
			game->PopState();
		}
	}
	//if (keys[SDL_SCANCODE_ESCAPE]) {
	//	game->PopState() ;
	//}
}

void PauseState::Draw(StateManager* game) {
	SDL_RenderClear(game->SMRender);
	renderTexture(background, game->SMRender, 0, 0);
	SDL_RenderPresent(game->SMRender);
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