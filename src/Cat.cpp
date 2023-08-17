#include "Cat.h"

#include <raylib.h>
#include <iostream>
#include <string>

#include "World.h"

Cat::Cat()
{
	pelt = Pelt::DARK_BROWN;
}

void Cat::update(float dt)
{

}

void Cat::draw(float dt)
{
	Vector2 position = World::toPixel(this->body->GetPosition());
	position.x -= 16.0f;
	position.y -= 16.0f;

	//TODO change this to right textures
	texture_atlas->drawImage(0, position);
}

void Cat::draw(float dt, Vector2& position)
{
	texture_atlas->drawImage(0, position);
}

void Cat::drawDebug(float dt)
{
	Vector2 position = World::toPixel(this->body->GetPosition());
	b2Fixture* fixture = body->GetFixtureList();
	b2Shape* circle = fixture->GetShape();
	float radius = World::toPixelScalar(circle->m_radius);

	DrawCircle(static_cast<int>(position.x), static_cast<int>(position.y), radius, WHITE);
}
