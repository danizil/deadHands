#include "stdafx.h"
#include "GameBall.h"


GameBall::GameBall():_velocity(0,0)
{
	load("images/ball.png");
	assert(isLoaded());
}


GameBall::~GameBall()
{
}

void GameBall::setVelocity(sf::Vector2f v) {
	_velocity = v;
}

sf::Vector2f GameBall::getVelocity() const {
	return _velocity;
}

sf::Vector2f GameBall::getPosition() const {
	return _sprite.getPosition();
}

void GameBall::updatePosition(float elapsedTime) {
	
	sf::Vector2f pos = getPosition();
	sf::Vector2f acceleration(-5 * pow(pos.x - Game::SCREEN_WIDTH / 2, 1) - 3 * _velocity.x, -5 * pow(pos.y - Game::SCREEN_HEIGHT / 2, 1));
	sf::Vector2f dv = acceleration * elapsedTime;
	_velocity += dv;
	setPosition(pos.x + _velocity.x * elapsedTime, pos.y + _velocity.y * elapsedTime);
}