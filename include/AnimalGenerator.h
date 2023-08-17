#ifndef ANIMALGENERATOR_H
#define ANIMALGENERATOR_H

#include <vector>
#include <string>
#include <memory>
#include <unordered_set>

#include "Cat.h"
#include "TextureManager.h"

class AnimalGenerator
{
private:
	inline static std::string leader_suffix = "star";
	inline static std::string apprentice_suffix = "paw";
	inline static std::string kit_suffix = "kit";

	std::vector<std::string> prefixes, suffixes;
	std::unordered_set<std::string> generated_names;

	std::shared_ptr<TextureManager> texture_manager;

	//gen functions
	std::string generateCatName (const std::string& role);
	int generateCatAge(const std::string& role);


	//helper funtions
	inline bool checkDuplicateName(const std::string& name);

	//data
	void getNames();
public:
	AnimalGenerator(std::shared_ptr<TextureManager> texture_manager);

	Cat generateCat(const std::string& role);
};

#endif //ANIMAL_GENERATOR