#include "PlayState.h"

SDL_Color color(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
PlayState PlayState::ActivePlayState;
Player person((SCREEN_WIDTH - PLAYER_WIDTH) / 2, SCREEN_HEIGHT - PLAYER_HEIGHT);
int PlayState::gameScore;

void PlayState::Init(StateManager* game) {
	gameScore = 0;
	gameLives = 3;
	usedFonts = new TTF_Font*[NUM_FONT];
	usedFonts[ARCADE] = TTF_OpenFont("arcade.ttf", ARCADE_FONTSZ);
	SDL_Color gameTextColor = { 255,255,255,255 };

	message = new SDL_Surface*[NUM_TXT];
	message[HEALTH] = TTF_RenderText_Solid(usedFonts[ARCADE], "HEALTH", gameTextColor);
	message[SCORE] = TTF_RenderText_Solid(usedFonts[ARCADE], "SCORE", gameTextColor);
	message[SCORE_TEXT] = TTF_RenderText_Solid(usedFonts[ARCADE], std::to_string(gameScore).c_str(), gameTextColor);
	message[LIVES] = TTF_RenderText_Solid(usedFonts[ARCADE], "LIVES", gameTextColor);
	message[LIVES_TEXT] = TTF_RenderText_Solid(usedFonts[ARCADE], std::to_string(gameLives).c_str(), gameTextColor);

	SDL_Texture** bg = new SDL_Texture*[NUM_BCKGRND];
	//Insert failsafe before assigning background!
	//loadTexture("test.bmp", game->SMRender);
	SDL_Texture** baseArt = new SDL_Texture*[NUM_GAMEART];
	SDL_Texture** baseTxt = new SDL_Texture*[NUM_TXT];
	background = bg;
	gameArt = baseArt;
	gameText = baseTxt;

	SDL_Surface* bgcolor = IMG_Load("starBackgroundLarge.png");
	background[SCROLL1] = SDL_CreateTextureFromSurface(game->SMRender, bgcolor);
	background[SCROLL2] = SDL_CreateTextureFromSurface(game->SMRender, bgcolor);
	gameText[HEALTH] = SDL_CreateTextureFromSurface(game->SMRender, message[HEALTH]);
	gameText[SCORE] = SDL_CreateTextureFromSurface(game->SMRender, message[SCORE]);
	gameText[SCORE_TEXT] = SDL_CreateTextureFromSurface(game->SMRender, message[SCORE_TEXT]);
	gameText[LIVES] = SDL_CreateTextureFromSurface(game->SMRender, message[LIVES]);
	gameText[LIVES_TEXT] = SDL_CreateTextureFromSurface(game->SMRender, message[LIVES_TEXT]);
	SDL_FreeSurface(bgcolor);
	SDL_FreeSurface(message[HEALTH]);
	SDL_FreeSurface(message[SCORE]);
	SDL_FreeSurface(message[SCORE_TEXT]);
	SDL_FreeSurface(message[LIVES]);
	SDL_FreeSurface(message[LIVES_TEXT]);


	SDL_Surface* spaceship = IMG_Load("player.png");
	SDL_Surface* shipLeft = IMG_Load("playerLeft.png");
	SDL_Surface* shipRight = IMG_Load("playerRight.png");
	SDL_Surface* shipDam = IMG_Load("playerDamaged.png");
	SDL_Surface* laserCharge = IMG_Load("laserGreenShot.png");
	SDL_Surface* laserShot = IMG_Load("laserGreen.png");
	gameArt[PLAYER] = SDL_CreateTextureFromSurface(game->SMRender, spaceship);
	gameArt[PLEFT] = SDL_CreateTextureFromSurface(game->SMRender, shipLeft);
	gameArt[PRIGHT] = SDL_CreateTextureFromSurface(game->SMRender, shipRight);
	gameArt[PDAMAGED] = SDL_CreateTextureFromSurface(game->SMRender, shipDam);
	gameArt[LSHOT] = SDL_CreateTextureFromSurface(game->SMRender, laserShot);
	gameArt[LCHARGE] = SDL_CreateTextureFromSurface(game->SMRender, laserCharge);
	SDL_FreeSurface(spaceship);
	SDL_FreeSurface(shipLeft);
	SDL_FreeSurface(shipRight);
	SDL_FreeSurface(shipDam);
	SDL_FreeSurface(laserShot);
	SDL_FreeSurface(laserCharge);


	BG1Begin = 0;
	BG2Begin = BG_HEIGHT;
}

void PlayState::Clear() {

}

void PlayState::Update(StateManager* game) {
	auto keys = SDL_GetKeyboardState(NULL);
	person.Update(keys);
	Uint32 now_ms = SDL_GetTicks();

	SDL_Color gameTextColor = { 255,255,255,255 };

	message[SCORE_TEXT] = TTF_RenderText_Solid(usedFonts[ARCADE], std::to_string(gameScore).c_str(), gameTextColor);
	message[LIVES_TEXT] = TTF_RenderText_Solid(usedFonts[ARCADE], std::to_string(gameLives).c_str(), gameTextColor);
	gameText[SCORE_TEXT] = SDL_CreateTextureFromSurface(game->SMRender, message[SCORE_TEXT]);
	gameText[LIVES_TEXT] = SDL_CreateTextureFromSurface(game->SMRender, message[LIVES_TEXT]);
	SDL_FreeSurface(message[SCORE_TEXT]);
	SDL_FreeSurface(message[LIVES_TEXT]);

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
	renderTexture(background[SCROLL1], game->SMRender, 0, BG1Begin);
	renderTexture(background[SCROLL2], game->SMRender, 0, BG2Begin);
	if (BG1Begin >= SCREEN_HEIGHT) BG1Begin = -BG_HEIGHT;
	if (BG2Begin >= SCREEN_HEIGHT) BG2Begin = -BG_HEIGHT;
	BG1Begin += SCROLL_SPEED; BG2Begin += SCROLL_SPEED;
	person.Draw(gameArt, game->SMRender);
	renderHPBar(game, 115, SCREEN_HEIGHT - 50, -100, 40, (person.getHealth()) / static_cast<float>(MAX_HEALTH), color(255, 255, 0, 255), color(255, 0, 0, 255));
	renderTexture(gameText[HEALTH], game->SMRender, 15, SCREEN_HEIGHT - 60 - ARCADE_FONTSZ);
	renderTexture(gameText[SCORE], game->SMRender, 15, ARCADE_FONTSZ);
	renderTexture(gameText[SCORE_TEXT], game->SMRender, 15, ARCADE_FONTSZ * 2);
	renderTexture(gameText[LIVES], game->SMRender, SCREEN_WIDTH - 15 - (5 * ARCADE_FONTSZ), ARCADE_FONTSZ);
	renderTexture(gameText[LIVES_TEXT], game->SMRender, SCREEN_WIDTH - 15 - (5 * ARCADE_FONTSZ), ARCADE_FONTSZ * 2);
	SDL_RenderPresent(game->SMRender);
	SDL_Delay(1);
}

void PlayState::increaseScore(int points) {
	gameScore += points;
}

void PlayState::renderHPBar(StateManager* game, int x, int y, int w, int h, float Percent, SDL_Color FGColor, SDL_Color BGColor) {
	Percent = Percent > 1.f ? 1.f : Percent < 0.f ? 0.f : Percent;
	SDL_Color old;
	SDL_GetRenderDrawColor(game->SMRender, &old.r, &old.g, &old.g, &old.a);
	SDL_Rect bgrect = { x, y, w, h };
	SDL_SetRenderDrawColor(game->SMRender, BGColor.r, BGColor.g, BGColor.b, BGColor.a);
	SDL_RenderFillRect(game->SMRender, &bgrect);
	SDL_SetRenderDrawColor(game->SMRender, FGColor.r, FGColor.g, FGColor.b, FGColor.a);
	int pw = (int)((float)w * Percent);
	int px = x + (w - pw);
	SDL_Rect fgrect = { px, y, pw, h };
	SDL_RenderFillRect(game->SMRender, &fgrect);
	SDL_SetRenderDrawColor(game->SMRender, old.r, old.g, old.b, old.a);
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

SDL_Color color(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
	SDL_Color col = { r,g,b,a };
	return col;
}