#include "MainMenu.h"

#include <iostream>
#include <string>
#include <memory>


#include <raylib.h>
#include <raygui.h>

#include "GameStateManager.h"
#include "Options.h"
#include "LevelEditor.h"
#include "CatGame.h"

MainMenu::MainMenu(std::shared_ptr<GameStateManager> game_state_manager, std::shared_ptr<OptionsManager> options_manager) : IGameState(game_state_manager, options_manager)
{
	play_toggle = false;
}

void MainMenu::processInput(float dt)
{

}

void MainMenu::update(float dt)
{

}

void MainMenu::draw(float dt)
{
	ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));

	GuiToggle(Rectangle{ 10, 210, 80, 40 }, "Play", &play_toggle);

	if (play_toggle)
	{
		if (GuiButton(Rectangle{ 100, 210, 80, 40 }, "New Game"))
		{
			game_state_manager->changeState(std::make_unique<CatGame>(game_state_manager, options_manager));
		}
		if (GuiButton(Rectangle{ 100, 260, 80, 40 }, "Load Game"))
		{
			//game_state_manager->changeState(std::make_unique<LoadGame>(game_state_manager, input_manager, options_manager));
		}
 	}
	if (GuiButton(Rectangle{ 10, 260, 80, 40 }, "Editor"))
	{
		game_state_manager->changeState(std::make_unique<LevelEditor>(game_state_manager, options_manager));
	}
	if (GuiButton(Rectangle{ 10, 310, 80, 40 }, "Options"))
	{
		game_state_manager->changeState(std::make_unique<Options>(game_state_manager, options_manager));
	}
}

void MainMenu::leave()
{

}

void MainMenu::enter()
{

}

///////////////////////////////////