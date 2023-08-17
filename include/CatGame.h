#ifndef CATGAME_H
#define CATGAME_H

#include <memory>
#include <vector>

#include <box2d/box2d.h>
#include <raylib.h>

#include "IGameState.h"

#include "AnimalGenerator.h"
#include "World.h"
#include "Cat.h"
#include "Map.h"


class CatGame : public IGameState
{
private:
	Camera2D world_camera { 0 };

	std::unique_ptr<AnimalGenerator> animal_generator;
	std::unique_ptr<World> world;
	std::unique_ptr<Map> map;


	std::vector<Cat> cats;
public:
	CatGame(std::shared_ptr<GameStateManager> game_state_manager, std::shared_ptr<InputManager> input_manager, std::shared_ptr<OptionsManager> options_manager);

	void processInput(float dt) override;
	void update(float dt) override;
	void draw(float dt) override;
	void leave() override;
	void enter() override;
};

#endif // CATGAME_H