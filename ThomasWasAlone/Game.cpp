#include "stdafx.h"

#include <iostream>
using namespace std;


#include "Game.h"


const int SCREEN_FPS = 60;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;


Game::Game()
{
	pause = false;
	quit = false;
}


Game::~Game()
{
}


bool Game::init() {	
	Size2D winSize(800,600);

	//creates our renderer, which looks after drawing and the window
	renderer.init(winSize,"Threading A*");

	//set up the viewport
	//we want the vp centred on origin and 20 units wide
	float aspectRatio = winSize.w / winSize.h;
	float vpWidth = 20;
	Size2D vpSize(vpWidth, vpWidth /aspectRatio);
	Point2D vpBottomLeft( -vpSize.w / 2, - vpSize.h / 2);

	Rect vpRect(vpBottomLeft,vpSize);
	renderer.setViewPort(vpRect);
	//want game loop to pause
	//inputManager.AddListener(EventListener::Event::PAUSE, this);
	//inputManager.AddListener(EventListener::Event::QUIT, this);

	return true;

}

//** calls update on all game entities*/
void Game::update()
{
}

//** calls render on all game entities*/

void Game::render()
{
	renderer.clear(Colour(0,0,0));// prepare for new frame
	


	renderer.present();// display the new frame (swap buffers)
}

/** update and render game entities*/
void Game::loop()
{

	int frameNum = 0;
	while (!quit) { //game loop

		inputManager.ProcessInput();

		if(!pause) //in pause mode don't bother updateing
			update();
		render();
	}
}

void Game::onEvent(EventListener::Event evt) {

	if (evt == EventListener::Event::PAUSE) {
		pause = !pause;
	}
	
	if (evt == EventListener::Event::QUIT) {
		quit=true;
	}

}
