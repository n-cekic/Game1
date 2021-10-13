#pragma once

#include <iostream>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

class Game
{
private:
	sf::RenderWindow* window;
	sf::Event ev;
	sf::VideoMode videoMode;
	sf::RectangleShape enemy;


	// private functions
	void initVariables();
	void initWindow();
	void initEnemy();

public:
	// constructors and dstructors
	Game();
	virtual ~Game();

	// accessors
	const bool running() const;

	// functions
	void update();
	void render();
	void pollEvents();
};