#include "Map.h"

#include <raylib.h>
#include <raymath.h>
#include <toml.hpp>

#include "Options.h"

Map::Map(std::string map_name) : map_name(map_name)
{
	tilemap = std::make_unique<TileMap>(map_name);

	buffer = LoadRenderTexture(DRAW_TILE_WIDTH * TILE_SIZE, DRAW_TILE_HEIGHT * TILE_SIZE);

	//std::cout << tilemap->getMapPixelWidth() << "  " << tilemap->getMapPixelHeight() << std::endl;
	//std::abort();

	position = { 0, 0 };


	this->drawToBuffer(position);
}

void Map::draw(float dt, const Vector2& position)
{
	DrawTexture(buffer.texture, 0, 0, WHITE);
}

void Map::drawToBuffer(const Vector2& position)
{
	BeginTextureMode(buffer);
		tilemap->draw(position);
	EndTextureMode();
}
