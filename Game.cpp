#include "Game.h"

Game::Game()
{

}
Game::~Game()
{

}

void Game::init(const char* title, int x_pos, int y_pos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
		flags == SDL_WINDOW_FULLSCREEN;
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		cout << " Subsystems initialized \n";
		window = SDL_CreateShapedWindow(title, x_pos, y_pos, width, height, flags);
		if (window)
		{
			cout << " Window Created successfully \n";
		}
		renderer = SDL_CreateRenderer(window, -1, flags);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			cout << " Renderer Created successfully \n";
		}
		isRunning = true;
	}
	else
		isRunning = false;
}

void Game:: update()
{
	while (count <= 100)
	{
		count++;
		cout << count << endl;
	}
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::render()
{
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_QUIT;
	cout << " GAME CLEANED \n";
}

bool Game::running()
{
	return isRunning;
}
