#ifndef TILEMAP_H
#define TILEMAP_H

#include <vector>
#include <string>
#include <memory>

#include <raylib.h>

#include "World.h"
#include "TextureAtlas.h"

const int DRAW_TILE_WIDTH = 30;
const int DRAW_TILE_HEIGHT = 20;

const int TILE_SIZE = 32;

class TileMap
{
private:
	std::unique_ptr<TextureAtlas> texture_atlas;
	int height, width;

	Rectangle texture_rect;
	Vector2 position;

	std::vector<std::vector<std::uint8_t>> tilemap;

	void loadMap(std::string map_name);
public:
	TileMap(std::string map_name);

	void draw(const Vector2& position);

	//size returns
	const float getMapTileWidth() const { return width; };
	const float getMapTileHeight() const { return height; };
	const float getMapPixelWidth() const { return width * TILE_SIZE; };
	const float getMapPixelHeight() const { return height * TILE_SIZE; };

	//these return actual distances using box2d world
	const float getMapMeterWidth() const { return World::toWorldScalar(width * TILE_SIZE); };
	const float getMapMetersHeight() const { return World::toWorldScalar(height * TILE_SIZE); };
	const float getMapKilometerWidth() const { return World::toWorldScalar(width * TILE_SIZE) / 1000; };
	const float getMapKilometersHeight() const { return World::toWorldScalar(height * TILE_SIZE) / 1000; };

	const void printTileMap() const;
};

#endif //TILEMAP_H