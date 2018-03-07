#include "stdafx.h"
#include "PlayerPaddle.h"
#include "Game.h"

PlayerPaddle::PlayerPaddle():_velocity(0)
{
	load("images/paddle.png");
	assert(isLoaded());
	
}


PlayerPaddle::~PlayerPaddle()
{
}

float PlayerPaddle::getVelocity() const {
	return _velocity;
}


void PlayerPaddle::getUserInput() {
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		_velocity -= 5.0f;// + 0.3*_velocity;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		_velocity += 5.0f;// -0.3*_velocity;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
		_velocity = 0.0f;
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) Game::showMenu();

}


void PlayerPaddle::setVelocity(float v) {
	_velocity = v;
}

void PlayerPaddle::updatePosition(float elapsedTime) {
	/*
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		_velocity -= 5.0f;// + 0.3*_velocity;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		_velocity += 5.0f;// -0.3*_velocity;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
		_velocity = 0.0f;
	}
	*/
	/*using event poll: much much slower and shitty
	sf::Event paddleEvent;
	while (Game::getWindow().pollEvent(paddleEvent)) {
		if (paddleEvent.type == sf::Event::KeyPressed) {
			if (paddleEvent.key.code == sf::Keyboard::Left)
				_velocity -= 5.0f;// + 0.3*_velocity;

			if (paddleEvent.key.code == sf::Keyboard::Right) {
				_velocity += 5.0f;// -0.3*_velocity;
			}
			if (paddleEvent.key.code == sf::Keyboard::BackSpace) {
				_velocity = 0.0f;
			}

		}
	}
	*/
	sf::Vector2f pos = this->getPosition();
	printf("playerpaddle38 pos: (%d, %d)\n", pos.x, pos.y);
	//adding 1/r^2 rejection from the wall, and dynamic airfriction dv= F/m *elapsedTime 
	float acceleration = pow(1 / pos.x, 2) - pow(1 / (Game::SCREEN_WIDTH - pos.x), 2) - 0.3 * _velocity;
	float dv = acceleration*elapsedTime ;
	_velocity += dv;
	setPosition(pos.x + _velocity * elapsedTime, pos.y);
}