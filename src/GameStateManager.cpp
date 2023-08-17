#include "GameStateManager.h"

#include <iostream>

void GameStateManager::changeState(std::unique_ptr<IGameState> gamestate) {
	if (!gamestate_stack.empty())
	{
		gamestate_stack.top()->leave();
		gamestate_stack.pop();
	}
	gamestate->enter();
	gamestate_stack.push(std::move(gamestate));
}

void GameStateManager::processInput(float dt) const
{
	this->gamestate_stack.top()->processInput(dt);
}

void GameStateManager::update(float dt) const
{
	this->gamestate_stack.top()->update(dt);
}

void GameStateManager::draw(float dt) const
{
	this->gamestate_stack.top()->draw(dt);
}

