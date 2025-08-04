//#include <SDL3/SDL.h>
#include <iostream>
#include <vector>
#include <fmod.hpp>
#include <memory>

#include "Game/Player.h"
#include "Game/SpaceGame.h"

#include "Core/Random.h"
#include "Core/Math/MathUtils.h"
#include "Core/Math/Vector2.h"
#include "Renderer/Renderer.h"
#include "Input/InputSystem.h"
#include "Core/Audio/AudioSystem.h" 
#include "Core/Math/Vector3.h"
#include "Renderer/Model.h"
#include "Core/Time.h"
#include "Framework/Actor.h"
#include "Engine.h"
#include "Framework/Scene.h"
#include "Renderer/Font.h"
#include "Renderer/Text.h"
#include "../Engine/Core/File.h"



using namespace blood;

int main(int argc, char* argv[]) { 

    blood::file::SetCurrentDirectory("Assets");

    //create systems
    GetEngine().Initialize();
    

    std::unique_ptr<SpaceGame> game = std::make_unique<SpaceGame>();

    game->Initialize();

    bool quit = false;

    SDL_Event e;




    //initialize sounds
    GetEngine().GetAudio().AddSound("test.wav", "test");
    GetEngine().GetAudio().AddSound("bass.wav", "bass");
    GetEngine().GetAudio().AddSound("snare.wav", "snare");
    GetEngine().GetAudio().AddSound("clap.wav", "clap");
    GetEngine().GetAudio().AddSound("close-hat.wav", "close-hat");
    GetEngine().GetAudio().AddSound("open-hat.wav", "open-hat");
    GetEngine().GetAudio().AddSound("bullet.mp3", "bullet");
    GetEngine().GetAudio().AddSound("spanish.mp3", "spanish");
    GetEngine().GetAudio().AddSound("rocketLaunch.mp3", "launch");
    GetEngine().GetAudio().AddSound("explode.mp3", "explode");
    
    Font* font = new Font();
    font->Load("wingding.ttf", 100);

    /*Text* text = new Text(font);
    text->Create(GetEngine().GetRenderer(), "Hello World!", vec3{ 1,1,1 });*/
    

    //GetEngine().GetAudio().PlaySound("clap");

    vec3 color(0, 0, 0);

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

        game->Draw(GetRenderer());
        //text->Draw(GetEngine().GetRenderer(), 40.0f, 40.0f);

        GetEngine().GetRenderer().Present(); // Render the screen

    }
    //delete pointers
    game->Shutdown();
    game.release();

    //shutdown systems
    GetEngine().Shutdown();

    return 0;
}