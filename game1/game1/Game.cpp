#include "Game.h"

// private functions
void Game::initVariables()
{
	this->window = nullptr;
}

void Game::initWindow()
{
	this->videoMode.height = 500;
	this->videoMode.width = 500;
	this->window = new sf::RenderWindow(this->videoMode, "my first game", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(30);
}

void Game::initEnemy()
{
	this->enemy.setPosition(sf::Vector2f(10.f, 10.f));
	this->enemy.setFillColor(sf::Color::Red);
	this->enemy.setSize(sf::Vector2f(50.f, 50.f));
	this->enemy.setScale(sf::Vector2f(1.f, 1.f));
	this->enemy.setOutlineColor(sf::Color::Yellow);
	this->enemy.setOutlineThickness(2.f);
}

// constructors and destructors
Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initEnemy();
}

Game::~Game()
{
	delete this->window;
}

// accessors

const bool Game::running() const
{
	return this->window->isOpen();
}


// functions

void Game::update()
{
	this->pollEvents();

	/*
	* move enemy with mouse
	*/
	sf::Vector2i mousePos = sf::Mouse::getPosition(*this->window);
	if (mousePos.x < 0.f)
		mousePos.x = 0.f;
	if (mousePos.x > this->window->getSize().x - this->enemy.getSize().x)
		mousePos.x = this->window->getSize().x - this->enemy.getSize().x;
	if (mousePos.y > this->window->getSize().y - this->enemy.getSize().y)
		mousePos.y = this->window->getSize().y - this->enemy.getSize().y;
	if (mousePos.y < 0.f)
		mousePos.y = 0.f;
	// std::cout << mousePos.x << " " << mousePos.y << std::endl;
	this->enemy.setPosition(sf::Vector2f(mousePos));
	
}

void Game::render()
{
	/*
		clear old
		render new
		display
	*/

	this->window->clear(sf::Color::Green);

	// draw game
	this->window->draw(this->enemy);

	this->window->display();
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}
