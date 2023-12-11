#pragma once
#include<SDL.h>
#include<stdio.h>
#include <iostream>
using namespace std;

class Game
{
public:
	Game();
	~Game();

	void init(const char* title,int x_pos,int y_pos,int width,int height,bool fullscreen);
	void update();
	void handleEvents();
	void render();
	void clean();
	bool running();

private:
	int count;
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
};

