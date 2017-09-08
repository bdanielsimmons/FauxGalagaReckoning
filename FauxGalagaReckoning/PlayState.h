#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "State.h"
#include "Player.h"
#include "Box.h"
#include "Enemy.h"
#include "PauseState.h"

const int NUM_BCKGRND = 2,
NUM_TXT = 5, 
NUM_FONT = 1, 
NUM_PLYRART = 7, 
NUM_ENEMYART = 2;

class PlayState : public State
{
private:
	int now, timepass;
	static PlayState ActivePlayState;
	SDL_Texture **background,**playerArt, **gameText, **enemyArt;
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