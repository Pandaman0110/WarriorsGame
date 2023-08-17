#ifndef WORLD_H
#define WORLD_H

#include <memory>

#include <box2d/box2d.h>
#include <raylib.h>


class World
{
private:
	std::unique_ptr<b2World> world;
public:
	World();
	
	b2Body* createBody(b2BodyType type, const b2Vec2 &world_position);

	void update();

	static b2Vec2 toWorld(const Vector2 &pixel_position);
	static float toWorldScalar(const float &scalar);
	static Vector2 toPixel(const b2Vec2 &world_position);
	static float toPixelScalar(const float &scalar);
};

#endif //WORLD_H