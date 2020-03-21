#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;
	Balltext.loadFromFile("gfx/Beach_Ball.png");
	Ball1.setSize(sf::Vector2f(50, 50));
	Ball1.setPosition(200, 200);
	Ball1.setTexture(&Balltext);
	Ball1.setVelocity(50, 50);
	Ball1.setCollisionBox(sf::FloatRect(5, 5, 30, 30));

	Ball2.setSize(sf::Vector2f(50, 50));
	Ball2.setPosition(300, 300);
	Ball2.setTexture(&Balltext);
	Ball2.setVelocity(30, 30);
    Ball2.setCollisionBox(sf::FloatRect(5, 5, 30, 30));
	// initialise game objects

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

}

// Update game objects
void Level::update(float dt)
{
	Ball1.update(dt);
	Ball2.update(dt);
	if (Collision::checkBoundingBox(&Ball1, &Ball2))
	{
		Ball1.collisionResponse(NULL);
		Ball2.collisionResponse(NULL);
	}
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(Ball1);
	window->draw(Ball2);
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