#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <memory>

#include <raylib.h>

#include "TextureAtlas.h"

class TextureManager
{
private:
	std::shared_ptr<TextureAtlas> cat_textures;

public:
	TextureManager();

	inline std::shared_ptr<TextureAtlas> getCatTextures() { return cat_textures; };
};

#endif