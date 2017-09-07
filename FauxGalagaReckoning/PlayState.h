#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "State.h"

const int NUM_BCKGRND = 3;

class PlayState : public State
{
private:
	static PlayState ActivePlayState;
	static SDL_Texture** background;
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

	bool occupiedPanel(int, int);
	bool colliding();
	bool falling();
	void emptyLine(int);
	void clearLine(int);
	void spawnPiece();
	void UpdatePiece();

	static PlayState* Instance() {
		return &ActivePlayState;
	}
};

#endif