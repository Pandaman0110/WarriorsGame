#include "TextureAtlas.h"

TextureAtlas::TextureAtlas(Texture texture_atlas, int image_size) : texture(texture_atlas), image_size(image_size), 
num_column_images(texture.height / image_size), num_row_images(texture.width / image_size)
{
	current_image = { 0, 0, static_cast<float>(image_size), static_cast<float>(image_size) };
	
}

void TextureAtlas::drawImage(int image_num, Vector2& position)
{
	current_image.x = (image_num % num_row_images) * image_size;
	current_image.y = (image_num / num_column_images) * image_size;

	DrawTextureRec(texture, current_image, position, WHITE);
}

