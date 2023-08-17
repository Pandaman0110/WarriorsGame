#ifndef LEVELEDITOR_H
#define LEVELEDITOR_H

#include "IGameState.h"

class LevelEditor : public IGameState
{
private:

public:
	LevelEditor(std::shared_ptr<GameStateManager> game_state_manager, std::shared_ptr<InputManager> input_manager, std::shared_ptr<OptionsManager> options_manager);

	void processInput(float dt) override;
	void update(float dt) override;
	void draw(float dt) override;
	void leave() override;
	void enter() override;
};





#endif // LEVELEDITOR_H
