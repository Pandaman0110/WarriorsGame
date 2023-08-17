#include "Options.h"

#include <raylib.h>
#include <raygui.h>

#include <iostream>
#include <string>
#include <memory>

#include "GameStateManager.h"
#include "OptionsManager.h"
#include "MainMenu.h"

Options::Options(std::shared_ptr<GameStateManager> game_state_manager, std::shared_ptr<InputManager> input_manager, std::shared_ptr<OptionsManager> options_manager) : IGameState(game_state_manager, input_manager, options_manager)
{
}

void Options::processInput(float dt)
{

}

void Options::update(float dt)
{

}

void Options::draw(float dt)
{
	ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));

	if (GuiButton(Rectangle {10, 10, 80, 40}, "Windowed"))
	{
		options_manager->getResolutionManager()->toggleFullscreen();
	}
	if (GuiButton(Rectangle{ 10, 60, 80, 40 }, "Increase Scale"))
	{
		options_manager->getResolutionManager()->increaseScale();
	}
	if (GuiButton(Rectangle{ 10, 110, 80, 40 }, "Decrease Scale"))
	{
		options_manager->getResolutionManager()->decreaseScale();
	}
	if (GuiButton(Rectangle{ 10, 330, 40, 20 }, "Back"))
	{
		game_state_manager->changeState(std::make_unique<MainMenu>(game_state_manager, input_manager, options_manager));
	}
}

void Options::leave()
{

}

void Options::enter()
{

}

///////////////////////////////////