#include "CatGame.h"

#include <iostream>
#include <algorithm>
#include <vector>

#include <raymath.h>

#include "GameStateManager.h"
#include "Input.h"
#include "OptionsManager.h"

CatGame::CatGame(std::shared_ptr<GameStateManager> game_state_manager, std::shared_ptr<OptionsManager> options_manager) : IGameState(game_state_manager, options_manager)
{
	std::shared_ptr<TextureManager> texture_manager = std::make_shared<TextureManager>();
	
	animal_generator = std::make_unique<AnimalGenerator>(texture_manager);
	world = std::make_unique<World>();
	map = std::make_unique<Map>("ForestMap");

	cats.push_back(animal_generator->generateCat("Leader"));
	cats.push_back(animal_generator->generateCat("Deputy"));

	cats.at(0).setBody(world->createBody(b2_kinematicBody, { 4.0f, 4.0f }));
	cats.at(1).setBody(world->createBody(b2_kinematicBody, { 0.0f, 4.0f }));

	world_camera.target = World::toPixel(cats.at(0).getBody()->GetPosition());
	world_camera.offset = Vector2{options_manager->getResolutionManager()->getGameWidth() / 2, options_manager->getResolutionManager()->getGameHeight() / 2 };
	world_camera.rotation = 0.0f;
	world_camera.zoom = 1.0f;

	/*INPUT_CODE
	input_manager->registerCallback("MoveUp", [&] (float dt)
		{
			cats.at(0).getBody()->SetLinearVelocity(b2Vec2 { 0.0f, -20.0f * dt });
		});
	input_manager->registerCallback("MoveDown", [&] (float dt)
		{
			cats.at(0).getBody()->SetLinearVelocity(b2Vec2{ 0.0f, 20.0f * dt });
		});
	input_manager->registerCallback("MoveRight", [&] (float dt)
		{
			cats.at(0).getBody()->SetLinearVelocity(b2Vec2{ 20.0f * dt, 0.0f });
		});
	input_manager->registerCallback("MoveLeft", [&](float dt)
		{
			cats.at(0).getBody()->SetLinearVelocity(b2Vec2{ -20.0f * dt, 0.0f });
		});
		*/
}

void CatGame::processInput(float dt)
{
	
}

void CatGame::update(float dt)
{
	world->update();
	for (auto& cat : cats)
	{
		cat.update(dt);
	}
	
	//world_camera.target = World::toPixel(cats.at(0).getBody()->GetPosition());
	cat_target = World::toPixel(cats.at(0).getBody()->GetPosition());

	//std::cout << GetMousePosition().x << "  " << GetMousePosition().y << std::endl;

	world_camera.target = Vector2Add(cat_target, Vector2Subtract(GetMousePosition(), world_camera.offset));

}

void CatGame::draw(float dt)
{
	ClearBackground(BLACK);

	/*
	DrawLine(options_manager->getResolutionManager()->getGameWidth() / 2, 0, 
		options_manager->getResolutionManager()->getGameWidth() / 2, options_manager->getResolutionManager()->getGameHeight(), WHITE);
	DrawLine(0, options_manager->getResolutionManager()->getGameHeight() / 2,
		options_manager->getResolutionManager()->getGameWidth(), options_manager->getResolutionManager()->getGameHeight() / 2, WHITE);
	*/


	BeginMode2D(world_camera);
	{
		map->draw(dt, cat_target);

		for (auto& cat : cats)
		{
			cat.draw(dt);
		}
	}
	EndMode2D();
}

void CatGame::leave()
{
}

void CatGame::enter()
{
}



////////////////////////////////////////