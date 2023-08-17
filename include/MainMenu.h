#ifndef MAINMENU_H
#define MAINMENU_H

#include "IGameState.h"

class MainMenu : public IGameState
{
private:
	bool play_toggle;
public:
	MainMenu(std::shared_ptr<GameStateManager> game_state_manager, std::shared_ptr<InputManager> input_manager, std::shared_ptr<OptionsManager> options_manager);

	void processInput(float dt) override;
	void update(float dt) override;
	void draw(float dt) override;
	void leave() override;
	void enter() override;
};

#endif 
