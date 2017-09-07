#ifndef STATE_H
#define STATE_H

#include "StateManager.h"

class State {
protected:
	State() {}
public:
	virtual void Init(StateManager* game) = 0;
	virtual void Clear() = 0;

	virtual void Pause() = 0;
	virtual void Resume() = 0;

	virtual void Manage(StateManager* game) = 0;
	virtual void Update(StateManager* game) = 0;
	virtual void Draw(StateManager* game) = 0;

	void ChangeState(StateManager* game, State* state) {
		game->ChangeState(state);
	}
};

#endif