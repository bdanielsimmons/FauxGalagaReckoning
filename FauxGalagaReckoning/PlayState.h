#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "State.h"
#include "Player.h"
#include "Box.h"
#include "Enemy.h"
#include "PauseState.h"

const int NUM_BCKGRND = 2,
NUM_TXT = 6, 
NUM_FONT = 2, 
NUM_PLYRART = 7, 
NUM_ENEMYART = 2,
NUM_FX = 1,
NUM_MUSIC = 2;

class PlayState : public State
{
private:
	int now, timepass, deathCounter;
	Mix_Chunk** gameEffects;
	Mix_Music** gameMusic;
	static PlayState ActivePlayState;
	SDL_Texture **background,**playerArt, **gameText, **enemyArt;
	SDL_Color gameTextColor;
	int BG1Begin, BG2Begin, gameLives;
	static int gameScore;
	TTF_Font** usedFonts;
	SDL_Surface** message;
public:
	PlayState() {}
	void Init(StateManager* game);
	void reInit(StateManager* game);
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