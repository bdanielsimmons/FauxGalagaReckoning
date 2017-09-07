#include "StateManager.h"
#include "State.h"

void StateManager::Init(SDL_Renderer* ren) {
	SMRender = ren;
	bool GRunning = true;
}

void StateManager::Clear() {
	while (!states.empty()) {
		states.back()->Clear();
		states.pop_back();
	}
	std::cout << "Game Quitting. Cleanup Complete.\n";
	SDL_Quit();
}

void StateManager::ChangeState(State* GameState) {
	if (!states.empty()) {
		states.back()->Clear();
		states.pop_back();
	}

	states.push_back(GameState);
	states.back()->Init(this);
}

void StateManager::PushState(State* GameState) {
	if (!states.empty()) {
		states.back()->Pause();
	}

	states.push_back(GameState);
	states.back()->Init(this);
}

void StateManager::PopState() {

	if (!states.empty()) {
		states.back()->Clear();
		states.pop_back();
	}

	if (!states.empty()) {
		states.back()->Resume();
	}
}

void StateManager::Manage() {
	states.back()->Manage(this);
}

void StateManager::Update() {
	states.back()->Update(this);
}

void StateManager::Draw() {
	states.back()->Draw(this);
}