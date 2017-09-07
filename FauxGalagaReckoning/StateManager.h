#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include <SDL.h>
#include "Constants.h"
#include <vector>
#include <iostream>

void renderTexture(SDL_Texture*, SDL_Renderer*, int, int);
SDL_Texture* loadTexture(const std::string&, SDL_Renderer*);

class State;

class StateManager {
private:
	std::vector<State*> states;
	bool GRunning;
	int now, timepass;
public:
	StateManager() {
		GRunning = true;
		now = 0;
		timepass = 0;
	}
	SDL_Event Event;
	SDL_Renderer* SMRender;
	void Init(SDL_Renderer*);
	void Clear();

	void ChangeState(State*);
	void PushState(State*);
	void PopState();

	void Manage();
	void Update();
	void Draw();

	bool Running() {
		SDL_PollEvent(&Event);
		if (Event.type == SDL_QUIT) {
			Quit();
		}
		return GRunning;
	}
	SDL_Event* Happening() {
		return &Event;
	}
	void setNow() {
		now = SDL_GetTicks();
	}
	void setTimePass() {
		timepass = SDL_GetTicks();
	}

	int getNow() { return now; };

	int getTimepass() { return timepass; }

	void Quit() {
		SDL_Quit();
		GRunning = false;
	}
};

#endif