#include <SDL.h>
#include <iostream>
#include "PlayState.h"
#include "Player.h"
#include "PauseState.h"

SDL_Texture** PlayState::background;
PlayState PlayState::ActivePlayState;
Player person(300, 750 - PLAYER_HEIGHT);

void PlayState::Init(StateManager* game) {
	SDL_Texture** bg = new SDL_Texture*[NUM_BCKGRND];
	//Insert failsafe before assigning background!
	//loadTexture("test.bmp", game->SMRender);
	background = bg;
	background[0] = loadTexture("space11.bmp", game->SMRender);
	background[1] = loadTexture("space12.bmp", game->SMRender);
	background[2] = loadTexture("spaceship.bmp", game->SMRender);

	BG1Begin = 0;
	BG2Begin = BG_HEIGHT;
}

void PlayState::Clear() {

}

void PlayState::Update(StateManager* game) {
	auto keys = SDL_GetKeyboardState(NULL);
	person.Update(keys);
	Uint32 now_ms = SDL_GetTicks();


	SDL_PollEvent(game->Happening());
	if (game->Event.type == SDL_KEYDOWN) {
		if (game->Event.key.keysym.sym == SDLK_ESCAPE && game->getNow() <= game->getTimepass() - 1500) {
			game->setNow();
			game->PushState(PauseState::Instance());
		}
	}
	game->setTimePass();
}

void PlayState::Draw(StateManager* game) {
	SDL_RenderClear(game->SMRender);

	renderTexture(background[0], game->SMRender, 0, BG1Begin);
	renderTexture(background[1], game->SMRender, 0, BG2Begin);
	std::cout << BG1Begin;
	if (BG1Begin <= -BG_HEIGHT) BG1Begin = SCREEN_HEIGHT;
	if (BG2Begin <= -BG_HEIGHT) BG2Begin = SCREEN_HEIGHT;
	BG1Begin -= 3; BG2Begin -= 3;
	person.Draw(background[2],game->SMRender);
	SDL_RenderPresent(game->SMRender);
	//SDL_Delay(1);
}

void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y) {
	//Setup the destination rectangle to be at the position we want
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	//Query the texture to get its width and height to use
	SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
	SDL_RenderCopy(ren, tex, NULL, &dst);
}

SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren) {
	//Initialize to nullptr to avoid dangling pointer issues
	SDL_Texture *texture = nullptr;
	SDL_Surface *loadedImage = SDL_LoadBMP(file.c_str());
	texture = SDL_CreateTextureFromSurface(ren, loadedImage);
	SDL_FreeSurface(loadedImage);
	return texture;
}