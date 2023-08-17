#ifndef TEXTUREATLAS_H
#define TEXTUREATLAS_H

#include <raylib.h>

class TextureAtlas
{
private:
	Texture texture;

	Rectangle current_image;

	int num_row_images, num_column_images;
	int image_size;

public:
	TextureAtlas(Texture texture_atlas, int image_size);

	Texture& getTexture() { return texture; };
	void drawImage(int image_num, Vector2& position);
};

#endif