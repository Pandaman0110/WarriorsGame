#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <vector>
#include <memory>

#include <raylib.h>

#include "World.h"
#include "TileMap.h"

class Map
{
public:
	Map(std::string map_name);

	//const std::vector<std::vector<int>>& getMap() const { return tilemap; };
	const std::string_view getMapName() const { return map_name; };

	void draw(float dt, const Vector2& position);

private:
	std::string map_name;

	RenderTexture2D buffer;
	Vector2 position;

	std::unique_ptr<TileMap> tilemap;

	void drawToBuffer(const Vector2& position);
};

#endif