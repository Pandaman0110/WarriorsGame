#include <raylib.h>

#define RAYGUI_IMPLEMENTATION
#include <raygui.h>
#include <raymath.h>

#include <iostream>
#include <string>
#include <memory>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <functional>
#include <thread>

#include "GameStateManager.h"
#include "Input.h"
#include "OptionsManager.h"

#include "Startup.h"
#include "Options.h"

#include <toml.hpp>

#include "Map.h"


int main()
{
    std::cout << "Number of threads " << std::thread::hardware_concurrency() << std::endl;

    InitWindow(0, 0, "WarriorsGame");
    SetTargetFPS(150);

    //Font stuff
    Font font = LoadFontEx("fonts/poco.ttf", 12, NULL, 0);
    GuiLoadStyle("warriorsgame.rgs");
    GuiSetFont(font);

    //Input loading 
    input = Input();
   
    //Game stuff
    std::shared_ptr<GameStateManager> game_state_manager = std::make_shared<GameStateManager>();
    
    std::shared_ptr<OptionsManager> options_manager = std::make_shared<OptionsManager>();
    
    //options_manager->getResolutionManager()->toggleFullscreen();
    Rectangle game_rect = options_manager->getResolutionManager()->getGameRect();
    Rectangle screen_rect = options_manager->getResolutionManager()->getScreenRect();
    int scale = options_manager->getResolutionManager()->getScale();
    RenderTexture framebuffer = LoadRenderTexture(game_rect.width, abs(game_rect.height));

    /*
    input_manager->registerCallback("ToggleFullscreen", [&] (float dt) {options_manager->getResolutionManager()->toggleFullscreen(); });
    input_manager->registerCallback("IncreaseScale",
        [&] (float dt)
        {
            options_manager->getResolutionManager()->increaseScale();
        });
    input_manager->registerCallback("DecreaseScale",
        [&] (float dt)
        {
            options_manager->getResolutionManager()->decreaseScale();
        });
    */
    game_state_manager->changeState(std::make_unique<Startup>(game_state_manager, options_manager));

    Texture custom_cursor = LoadTexture("cursor_catpaw.png");
    HideCursor();



    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();
        std::string fps = std::to_string(GetFPS());

        screen_rect = options_manager->getResolutionManager()->getScreenRect();

        //Input
        input.pollInputs(dt);
        game_state_manager->processInput(dt);
       
        // Update
        game_state_manager->update(dt);
        
        // Draw
        ClearBackground(BLANK);

        BeginTextureMode(framebuffer);
            DrawText(fps.c_str(), 5, 5, 12, WHITE);
            game_state_manager->draw(dt);
        EndTextureMode();

        BeginDrawing();
            DrawTexturePro(framebuffer.texture, game_rect, screen_rect, Vector2 { 0, 0 }, 0.0f, WHITE);

            //there is probably a better way to do this
            SetMouseScale(1, 1);
            DrawTexture(custom_cursor, GetMouseX() - 6 + screen_rect.x, GetMouseY() - 4 + screen_rect.y, WHITE);
            SetMouseScale(1 / options_manager->getResolutionManager()->getScale(), 1 / options_manager->getResolutionManager()->getScale());
        EndDrawing();
    }


    UnloadRenderTexture(framebuffer);

    CloseWindow();

    return 0;
}