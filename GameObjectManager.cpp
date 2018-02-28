#include "stdafx.h"
#include "GameObjectManager.h"


GameObjectManager::GameObjectManager()
{
}


GameObjectManager::~GameObjectManager()
{
	std::for_each(_gameObjects.begin(), _gameObjects.end(), GameObjectDeallocator());
}

void GameObjectManager::add(std::string objectName, VisibleGameObject* gameObject) {
	_gameObjects.insert(std::pair<std::string, VisibleGameObject*>(objectName, gameObject));
}

void GameObjectManager::remove(std::string objectName) 
{
	std::map<std::string, VisibleGameObject*>::iterator results = _gameObjects.find(objectName);
	if (results != _gameObjects.end()) {
		delete results->second;
		_gameObjects.erase(results);
	}
}


VisibleGameObject* GameObjectManager::getObject(std::string name) const {
		
	std::map<std::string, VisibleGameObject*>::const_iterator results = _gameObjects.find(name);
	if (results == _gameObjects.end()) {
		return NULL;
	}
	return results->second;
}


int GameObjectManager::getObjectCount() const {
	return _gameObjects.size();
}

void GameObjectManager::drawAll(sf::RenderWindow& window) {

	std::map<std::string, VisibleGameObject*>::iterator objectIterator = _gameObjects.begin();
	while (objectIterator != _gameObjects.end()) {
		objectIterator->second->draw(window);
		objectIterator++;
	}
}

void GameObjectManager::updateAll() {

	float dt = getDt();//i should get dt at the item level cause every object has its time
	std::cout << "gameobjectman 55 " << dt << "\n";
	std::map<std::string, VisibleGameObject*>::const_iterator it = _gameObjects.begin();
	while (it != _gameObjects.end()){
		it->second->updatePosition(dt);
		//it->second->draw(Game::getWindow());
		it++;
	}
}

float GameObjectManager::getDt() {
	float elapsedTime = _objectsClock.getElapsedTime().asSeconds();
	_objectsClock.restart();
	return elapsedTime;
}