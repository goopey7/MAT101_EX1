#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	play = true;

	ballTexture.loadFromFile("gfx/Beach_Ball.png");
	ball.setSize(sf::Vector2f(100, 100));
	ball.setPosition(0, 300);
	ball.setTexture(&ballTexture);
	ball.setInput(input);


}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	//The class that provides access to the keyboard state is sf::Keyboard.It only contains one function, isKeyPressed, which checks the current state of a key(pressed or released).It is a static function, so you don't need to instanciate sf::Keyboard to use it.
		//This function directly reads the keyboard state, ignoring the focus state of your window.This means that isKeyPressed may return true even if your window is inactive.
	if (input->isKeyJustDown(sf::Keyboard::Escape))
	{
		input->setKeyUp(sf::Keyboard::Escape);
		window->close();
	}
	if (input->isKeyJustDown(sf::Keyboard::Return))
	{
		
		play = !play;
	}
}

// Update game objects
void Level::update(float dt)
{
	if (play)
	{
		ball.update(dt);
	}
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(ball);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}