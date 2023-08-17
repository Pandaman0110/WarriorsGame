#ifndef ENTITY_H
#define ENTITY_H

#include <memory>

#include <box2d/box2d.h>
#include <raylib.h>

#include "TextureAtlas.h"

class Entity
{
protected:
	std::shared_ptr<TextureAtlas> texture_atlas;
	b2Body* body;

public:
	Entity();
	~Entity();

	inline b2Body* getBody() { return this->body; };
	inline void setBody(b2Body* body) { this->body = body; };

	void printPosition() const;

	virtual void update(float dt) = 0;

	virtual void draw(float dt) = 0;
	virtual void draw(float dt, Vector2& position) = 0;

	virtual void drawDebug(float dt) = 0;

	inline void setTexture(std::shared_ptr<TextureAtlas> texture_atlas) { this->texture_atlas = texture_atlas; };
};

#endif //ENTITY_H