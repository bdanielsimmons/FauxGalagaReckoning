#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "State.h"
#include "Player.h"
#include "PauseState.h"

const int NUM_BCKGRND = 2;
const int NUM_GAMEART = 6;

class PlayState : public State
{
private:
	static PlayState ActivePlayState;
	SDL_Texture **background,**gameArt;
	int BG1Begin, BG2Begin;
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

	static PlayState* Instance() {
		return &ActivePlayState;
	}
};

#endif