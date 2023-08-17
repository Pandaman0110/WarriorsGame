#include "AnimalGenerator.h"

#include <raylib.h>
#include <fstream>
#include <vector>
#include <iostream>

#include <toml.hpp>


AnimalGenerator::AnimalGenerator(std::shared_ptr<TextureManager> texture_manager)
{
	this->getNames();

	this->texture_manager = texture_manager;
}

Cat AnimalGenerator::generateCat(const std::string& role)
{
	Cat cat;

	cat.setTexture(texture_manager->getCatTextures());

	cat.setRole(role);
	cat.setName(this->generateCatName(role));
	cat.setAge(this->generateCatAge(role));

	return cat;
}

void AnimalGenerator::getNames()
{
	auto document = toml::parse_file("Names.toml");
	auto names = document["Names"];

	auto prefix_array = names["Prefixes"].as_array();
	auto suffix_array = names["Suffixes"].as_array();

	for (auto i = prefix_array->begin(); i < prefix_array->end(); i++)
	{
		std::string name = *i->value<std::string>();
		prefixes.push_back(name);
	}

	for (auto i = suffix_array->begin(); i < suffix_array->end(); i++)
	{
		std::string name = *i->value<std::string>();
		suffixes.push_back(name);
	}
}


std::string AnimalGenerator::generateCatName(const std::string& role)
{
	std::string prefix = prefixes.at(GetRandomValue(0, prefixes.size()));
	std::string suffix;
	
	if (role == "Leader")
		suffix = leader_suffix;
	else if (role == "Apprentice")
		suffix = apprentice_suffix;
	else if (role == "Kit")
		suffix = kit_suffix;
	else
	{
		suffix = suffixes.at(GetRandomValue(0, suffixes.size()));
	}

	std::string name = prefix + suffix;

	//RECURSION
	if (this->checkDuplicateName(name))
		return this->generateCatName(role);

	generated_names.emplace(name);

	return name;
}

int AnimalGenerator::generateCatAge(const std::string& role)
{
	//TODO
	int age;

	if (role == "Leader" or role == "Deputy")
		age = GetRandomValue(36, 96);
	else if (role == "Medicine" or role == "Warrior")
		age = GetRandomValue(12, 96);
	else if (role == "Apprentice")
		age = GetRandomValue(6, 12);
	else if (role == "Kit")
		age = GetRandomValue(0, 6);
	else if (role == "Elder")
		age = GetRandomValue(96, 120);
	else
		age = GetRandomValue(0, 120);


	return age;
}

bool AnimalGenerator::checkDuplicateName(const std::string& name)
{
	return generated_names.contains(name);
}

