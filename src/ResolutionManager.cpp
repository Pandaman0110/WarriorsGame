#include "ResolutionManager.h"

#include <raylib.h>

#include <algorithm>
#include <math.h>
#include <iostream>

const int GAME_WIDTH = 640;
const int GAME_HEIGHT = 360;

ResolutionManager::ResolutionManager()
{
	screen_width = GetScreenWidth();
	screen_height = GetScreenHeight();

	game_rect.x = 0;
	game_rect.y = 0;

	game_rect.width = GAME_WIDTH;
	game_rect.height = -GAME_HEIGHT;

	screen_x_scale = getMaxXScale();
	screen_y_scale = getMaxYScale();
	screen_scale = getMaxScale();
		
	this->generateScreenRect();

	SetMouseOffset(-screen_rect.x, -screen_rect.y);
	SetMouseScale(1 / screen_scale, 1 / screen_scale);
}

void ResolutionManager::increaseScale()
{
	if (screen_scale != getMaxScale())
	{
		++screen_scale;
		++screen_x_scale;
		++screen_y_scale;

		this->generateScreenRect();

		SetMouseOffset(-screen_rect.x, -screen_rect.y);
		SetMouseScale(1 / screen_scale, 1 / screen_scale);
	}
}

void ResolutionManager::decreaseScale()
{
	if (screen_scale != 1)
	{
		--screen_scale;
		--screen_x_scale;
		--screen_y_scale;

		this->generateScreenRect();

		SetMouseOffset(-screen_rect.x, -screen_rect.y);
		SetMouseScale(1 / screen_scale, 1 / screen_scale);
	}
}

void ResolutionManager::generateScreenRect()
{
	screen_rect.x = (screen_width - (game_rect.width * screen_x_scale)) * 0.5f;
	screen_rect.y = (screen_height - (abs(game_rect.height) * screen_y_scale)) * 0.5f;

	screen_rect.width = game_rect.width * screen_scale;
	screen_rect.height = abs(game_rect.height) * screen_scale;
}