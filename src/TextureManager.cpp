#include "TextureManager.h"

#include <iostream>

TextureManager::TextureManager()
{
	cat_textures = std::make_shared<TextureAtlas>(LoadTexture("assets/art/cat_textures.png"), 32);
}
