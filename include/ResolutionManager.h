#ifndef RESOLUTIONMANAGER_H
#define RESOLUTIONMANAGER_H

#include <raylib.h>
#include <math.h>
#include <cmath>

class ResolutionManager
{
private:
	float screen_width;
	float screen_height;

	float screen_x_scale;
	float screen_y_scale;
	float screen_scale;

	Rectangle game_rect;
	Rectangle screen_rect;

	inline float getMaxXScale() const { return floor(screen_width / game_rect.width); };
	inline float getMaxYScale() const { return floor(screen_height / abs(game_rect.height)); };
	inline float getMaxScale() const { return fminf(getMaxXScale(), getMaxYScale()); };

	inline void generateScreenRect();
public:
	ResolutionManager();

	inline Rectangle& getGameRect() { return game_rect; };
	inline Rectangle& getScreenRect() { return screen_rect; };

	inline float getGameWidth() const { return game_rect.width; };
	inline float getGameHeight() const { return abs(game_rect.height); };

	inline float getScreenWidth() const { return screen_rect.width; };
	inline float getScreenHeight() const { return screen_rect.height; };


	inline float getScale() const { return screen_scale; };

	void increaseScale();
	void decreaseScale();
	inline void toggleFullscreen() const { ToggleFullscreen(); };
};

#endif // RESOLUTIONMANAGER_H

