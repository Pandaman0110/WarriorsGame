#include "TileMap.h"

#include <iostream>

#include <toml.hpp>

TileMap::TileMap(std::string map_name) : height(-1), width(-1)
{
	texture_atlas = std::make_unique<TextureAtlas>(LoadTexture("tile_textures.png"), TILE_SIZE);

	this->loadMap(map_name);

	this->position = { 0, 0 };
} 


void TileMap::draw(const Vector2& position)
{
	for (auto row = tilemap.begin(); row < tilemap.end(); ++row)
	{	
		int y = (row - tilemap.begin());
		for (auto tile = row->begin(); tile < row->end(); ++tile)
		{
			int x = (tile - row->begin());

			this->position.x = x * TILE_SIZE;
			this->position.y = y * TILE_SIZE;

			texture_atlas->drawImage(*tile, this->position);
		}
	}
	
}

void TileMap::loadMap(std::string map_name)
{
	auto map = toml::parse_file(map_name + ".toml");

	auto tilemap_array = map["Tilemap"].as_array();

	for (auto i = tilemap_array->begin(); i < tilemap_array->end(); ++i)
	{
		auto row = i->as_array();

		std::vector<std::uint8_t> vec;
		tilemap.push_back(vec);

		for (auto j = row->begin(); j < row->end(); ++j)
		{
			tilemap.at(i - tilemap_array->begin()).push_back(*j->value<std::uint8_t>());
		}
	}

	width = tilemap.at(0).size();
	height = tilemap.size();
}

const void TileMap::printTileMap() const
{
	std::cout << std::endl;

	std::cout << "Map details: " << std::endl;

	std::cout << std::endl;

	std::cout << "Height in tiles: " << height << std::endl;
	std::cout << "Width in tiles: " << width << std::endl;

	std::cout << std::endl;

	std::cout << "Height in pixels: " << this->getMapPixelHeight() << std::endl;
	std::cout << "Width in pixels: " << this->getMapPixelWidth() << std::endl;

	std::cout << std::endl;

	std::cout << "Height in kilometers: " << this->getMapKilometersHeight() << std::endl;
	std::cout << "Width in kilometers: " << this->getMapKilometerWidth() << std::endl;

	std::cout << std::endl;

	std::cout << "Height in meters: " << this->getMapMetersHeight() << std::endl;
	std::cout << "Width in meters: " << this->getMapMeterWidth() << std::endl;

	std::cout << std::endl;

	for (auto& row : tilemap)
	{
		for (auto tile : row)
		{
			std::cout << tile << " ";
		}
		std::cout << std::endl;
	}
}