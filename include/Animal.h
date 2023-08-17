#ifndef ANIMAL_H
#define ANIMAL_H

#include <memory>
#include <raylib.h>

#include "Entity.h"

class b2Body;

class Animal : public Entity
{
protected:

public:
	Animal();
	~Animal();
};

#endif //ANIMAL_H