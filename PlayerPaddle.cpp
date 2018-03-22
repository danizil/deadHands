#include "stdafx.h"
#include "PlayerPaddle.h"
#include "Game.h"

PlayerPaddle::PlayerPaddle():_velocity(0,0)
{
	load("images/paddle.png");
	assert(isLoaded());
	
}


PlayerPaddle::~PlayerPaddle()
{
}

sf::Vector2f PlayerPaddle::getVelocity() const {
	return _velocity;
}


void PlayerPaddle::getUserInput() {
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		_velocity.x -= 5.0f;// + 0.3*_velocity;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		_velocity.x += 5.0f;// -0.3*_velocity;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
		_velocity.x = 0.0f; _velocity.y = 0.0f;
		//setPosition(this->getPosition().y, this->getPosition().x);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		_velocity.y -= 5.0f;// + 0.3*_velocity;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		_velocity.y += 5.0f;// -0.3*_velocity;
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		_sprite.rotate(-2);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		_sprite.rotate(2);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
		_sprite.setRotation(0);
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) Game::showMenu();

}


void PlayerPaddle::setVelocity(sf::Vector2f v) {
	_velocity = v;
}

void PlayerPaddle::updatePosition(float elapsedTime) {
	
	sf::Vector2f pos = this->getPosition();
	printf("playerpaddle47 pos.x = %f, pos.y = %f pow(pos.x, 6): %f\n 0.3*velocity = %f\n", pos.x, pos.y, pow(pos.x, 6), 0.3 * _velocity.x);
	//adding 1/r^2 rejection from the wall, and dynamic airfriction dv= F/m *elapsedTime

	sf::Vector2f acceleration(-5*pow(pos.x - Game::SCREEN_WIDTH/2, 1) - 3 * _velocity.x ,  -5 * pow(pos.y - Game::SCREEN_HEIGHT / 2, 1) - 3 * _velocity.y);
	sf::Vector2f dv = acceleration*elapsedTime ;
	_velocity += dv;
	setPosition(pos.x + _velocity.x * elapsedTime, pos.y + _velocity.y * elapsedTime);
}