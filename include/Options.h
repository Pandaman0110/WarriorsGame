#ifndef OPTIONS_H
#define OPTIONS_H

#include "IGameState.h"

const float GAME_WIDTH = 640;
const float GAME_HEIGHT = 360;

class Options : public IGameState
{
private:

public:
	Options(std::shared_ptr<GameStateManager> game_state_manager, std::shared_ptr<OptionsManager> options_manager);

	void processInput(float dt) override;
	void update(float dt) override;
	void draw(float dt) override;
	void leave() override;
	void enter() override;
};

#endif // !OPTIONS_H

