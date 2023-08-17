#include "Entity.h"

#include <iostream>

Entity::Entity()
{
	this->body = nullptr;
}

Entity::~Entity()
{

}

//Printing Functions

void Entity::printPosition() const
{
	b2Vec2 position = this->body->GetPosition();
	std::cout << "Position: " << "x - " << position.x << " y - " << position.y << std::endl;
}

