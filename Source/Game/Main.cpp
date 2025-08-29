//#include <SDL3/SDL.h>
#include <iostream>
#include <vector>
#include "Game/Player.h"
#include "Game/SpaceGame.h"
#include "GamePCH.h"

using namespace blood;

int main(int argc, char* argv[]) { 
    blood::file::SetCurrentDirectory("Assets");

    std::cout << argc << std::endl;

    for (int i = 0; i < argc; i++) {
        std::cout << argv[i] << std::endl;
    }

    //create systems
    Logger::Info("Initialize Engine... ");
    GetEngine().Initialize();

    std::unique_ptr<SpaceGame> game = std::make_unique<SpaceGame>();

    game->Initialize();

    bool quit = false;

    SDL_Event e;

    //initialize sounds
    GetEngine().GetAudio().AddSound("bullet.mp3", "bullet");
    GetEngine().GetAudio().AddSound("spanish.mp3", "spanish");
    GetEngine().GetAudio().AddSound("rocketLaunch.mp3", "launch");
    GetEngine().GetAudio().AddSound("explode.mp3", "explode");
    
    Font* font = new Font();
    font->Load("wingding.ttf", 100);

    vec3 color(0, 0, 0);

    float rotate = 0;

    //main loop
    while (!quit) {
        
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        } 
        //update necessary systems
        GetEngine().Update();
        game->Update(GetEngine().GetTime().GetDeltaTime());

        //shutdown when user presses escape button
        if (GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_ESCAPE)) {
            break;
        }

        //draw
        GetEngine().GetRenderer().SetColorFloat(color.r, color.g, color.b);
        GetEngine().GetRenderer().Clear(); // Clear the screen

        //Spanish Button
        if (GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_P)) GetEngine().GetAudio().PlaySound("spanish");


        game->Draw(Engine::Instance().GetRenderer());
        rotate += 90 * GetEngine().GetTime().GetDeltaTime();
        //text->Draw(GetEngine().GetRenderer(), 40.0f, 40.0f);
       // GetEngine().GetRenderer().DrawTexture(texture.get(), 300, 300, rotate, 20);

        GetEngine().GetRenderer().Present(); // Render the screen

    }
    //delete pointers
    game->Shutdown();
    game.release();

    //shutdown systems
    GetEngine().Shutdown();

    return 0;
}