#include "World.h"

#include <iostream>

const float PIXELS_PER_METER = 1.0f / 50.0;
const float TIME_STEP = 1.0f / 60.0f;
const uint8_t VELOCITY_ITERATIONS = 8;
const uint8_t POSITION_ITERATIONS = 3;

World::World()
{
	b2Vec2 gravity(0.0f, 0.0f);
	world = std::make_unique<b2World>(gravity);
}

b2Body* World::createBody(b2BodyType type, const b2Vec2 &world_position)
{
	b2BodyDef body_def;
	body_def.type = type;
	body_def.position.Set(world_position.x, world_position.y);
	body_def.angle = 0;

	b2Body* body = world->CreateBody(&body_def); 

	b2CircleShape circle_shape;

	circle_shape.m_radius = 0.25f;
	circle_shape.m_p.Set(0, 0);

	b2FixtureDef fixture_def;
	fixture_def.density = 5.0f;
	fixture_def.shape = &circle_shape;
	fixture_def.friction = 0.0f;

	body->CreateFixture(&fixture_def);

	return body;
}

void World::update()
{
	world->Step(TIME_STEP, VELOCITY_ITERATIONS, POSITION_ITERATIONS);
}

b2Vec2 World::toWorld(const Vector2 &pixel_position)
{
	return b2Vec2(pixel_position.x * PIXELS_PER_METER, pixel_position.x * PIXELS_PER_METER);
}

float World::toWorldScalar(const float &scalar)
{
	return static_cast<float>(scalar * PIXELS_PER_METER);
}

Vector2 World::toPixel(const b2Vec2 &world_position)
{
	return Vector2(world_position.x / PIXELS_PER_METER, world_position.y / PIXELS_PER_METER);
}

float World::toPixelScalar(const float &scalar)
{
	return static_cast<float>(scalar / PIXELS_PER_METER);
}
