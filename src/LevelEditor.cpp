#include "LevelEditor.h"

#include <raylib.h>
#include <raygui.h>

#include "GameStateManager.h"

LevelEditor::LevelEditor(std::shared_ptr<GameStateManager> game_state_manager, std::shared_ptr<OptionsManager> options_manager) : IGameState(game_state_manager, options_manager)
{
	
}

void LevelEditor::processInput(float dt)
{

}

void LevelEditor::update(float dt)
{

}

void LevelEditor::draw(float dt)
{
	ClearBackground(BLANK);


}

void LevelEditor::leave()
{
}

void LevelEditor::enter()
{
}
