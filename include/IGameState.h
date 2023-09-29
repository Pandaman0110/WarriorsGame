#ifndef IGAMESTATE_H
#define IGAMESTATE_H

#include <iostream>
#include <memory>

class GameStateManager;
class Input;
class OptionsManager;

class IGameState
{
protected:
	std::shared_ptr<GameStateManager> game_state_manager;
	std::shared_ptr<OptionsManager> options_manager;
public:
	IGameState() {};
	IGameState(std::shared_ptr<GameStateManager> game_state_manager, std::shared_ptr<OptionsManager> options_manager)
	{
		this->game_state_manager = game_state_manager;
		this->options_manager = options_manager;
	};
	
	virtual void processInput(float dt) = 0;
	virtual void update(float dt) = 0;
	virtual void draw(float dt) = 0;
	virtual void leave() = 0;
	virtual void enter() = 0;
};

#endif // IGAMESTATE_H