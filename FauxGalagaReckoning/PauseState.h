#ifndef PAUSESTATE_H
#define PAUSESTATE_H

#include "State.h"

class PauseState : public State
{
private:
	static PauseState ActivePauseState;
	static SDL_Texture* background;
public:
	PauseState() {}
	void Init(StateManager* game);
	void Clear();

	void Pause() {};
	void Resume() {};

	void Manage(StateManager* game) {};
	void Update(StateManager* game);
	void Draw(StateManager* game);

	static PauseState* Instance() {
		return &ActivePauseState;
	}
};

#endif