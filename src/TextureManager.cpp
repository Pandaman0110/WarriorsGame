#include "TextureManager.h"

#include <iostream>

TextureManager::TextureManager()
{
	cat_textures = std::make_shared<TextureAtlas>(LoadTexture("cat_textures.png"), 32);
}
