#ifndef CAT_H
#define CAT_H

#include <raylib.h>
#include <string>
#include <memory>

#include "Animal.h"

enum Pelt
{
	DARK_BROWN,
	CALICO,
	GREY,
	GREY_WHITE,
	TORTIESHELL
};

class Cat :public Animal
{
private:
	Pelt pelt;

	std::string name;
	std::string role;
	int age;
public:
	Cat();

	void update(float dt) override;

	void draw(float dt) override;
	void draw(float dt, Vector2& position) override;

	void drawDebug(float dt) override;

	inline const std::string& getName() const { return name; } 
	inline const std::string& getRole() const { return role; }
	inline const int getAge() const { return age; }
	
	inline void setRole(std::string role) { this->role = role; }
	inline void setName(std::string name) { this->name = name; }
	inline void setAge(int age) { this->age = age; }
};

#endif //CAT_H
