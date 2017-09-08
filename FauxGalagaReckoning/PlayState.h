#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "State.h"
#include "Player.h"
#include "PauseState.h"

const int NUM_BCKGRND = 2;
const int NUM_TXT = 5;
const int NUM_FONT = 1;
const int NUM_GAMEART = 6;

class PlayState : public State
{
private:
	static PlayState ActivePlayState;
	SDL_Texture **background,**gameArt, **gameText;
	int BG1Begin, BG2Begin, gameLives;
	static int gameScore;
	TTF_Font** usedFonts;
	SDL_Surface** message;
public:
	PlayState() {}
	void Init(StateManager* game);
	void Clear();

	void Pause() {};
	void Resume() {};

	void Manage(StateManager* game) {};
	void Update(StateManager* game);
	void Draw(StateManager* game);
	void renderHPBar(StateManager* game, int, int, int, int, float, SDL_Color, SDL_Color);
	static void increaseScore(int);

	static PlayState* Instance() {
		return &ActivePlayState;
	}
};

#endif