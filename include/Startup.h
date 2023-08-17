#ifndef STARTUP_H
#define STARTUP_H

#include "raylib.h"

#include "IGameState.h"

#include <vector>
#include <string>

class Startup : public IGameState
{
private:
	std::vector<std::string> quotes;
	Font font;
	size_t current_quote;

public:
	Startup(std::shared_ptr<GameStateManager> game_state_manager, std::shared_ptr<InputManager> input_manager, std::shared_ptr<OptionsManager> options_manager);

	void processInput(float dt) override;
	void update(float dt) override;
	void draw(float dt) override;
	void leave() override;
	void enter() override;

	void loadQuotes();
private:

};

#endif // STARTUP_H
