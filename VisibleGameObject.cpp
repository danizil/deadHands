#include "stdafx.h"
#include "VisibleGameObject.h"


VisibleGameObject::Rect::Rect(sf::Vector2f meas):_measurements(meas) {
	
}


VisibleGameObject::VisibleGameObject():_isLoaded(false)
{
}


VisibleGameObject::~VisibleGameObject()
{
}

void VisibleGameObject::load(std::string filename) {
	if (!_texture.loadFromFile(filename)) {
		_filename = "";
		_isLoaded = false;
	}
	else {
		_filename = filename;
		_sprite.setTexture(_texture);
		_sprite.setOrigin(_texture.getSize().x / 2, _texture.getSize().y / 2);
		
		_isLoaded = true;
	}
}

void VisibleGameObject::draw(sf::RenderWindow& window) {
	if (_isLoaded) {
		window.draw(_sprite);
	}
}


void VisibleGameObject::setPosition(float x, float y) {
	if (_isLoaded) {
		_sprite.setPosition(x, y);
	}
}


void VisibleGameObject::updatePosition(float elapsedTime){}


sf::Vector2f VisibleGameObject::getPosition() const {
	if (_isLoaded) {
		return _sprite.getPosition();
	}
	return sf::Vector2f();
}

sf::Vector2f VisibleGameObject::getOrigin() const {
	return _sprite.getOrigin();
}

sf::Sprite& VisibleGameObject::getSprite() {
	return _sprite;
}

bool VisibleGameObject::isLoaded() { 
	return _isLoaded; }


bool VisibleGameObject::Rect::inDomain(float x, float y) {
	//do the rotation transformation
	
	std::cout << "visiGameObj64 finish inDomain function\n";
	return true;
}