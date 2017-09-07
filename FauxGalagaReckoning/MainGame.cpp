// Tetris.cpp : Defines the entry point for the console application.
//
#include <string>
#include <iostream>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "StateManager.h"
#include "PlayState.h"
#undef main

int main(int, char**) {
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *window = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	StateManager game;
	game.Init(renderer);
	game.ChangeState(PlayState::Instance());
	SDL_Event Event;
	while (game.Running()) {
		game.Manage();
		game.Update();
		game.Draw();
	}
	return 0;
}