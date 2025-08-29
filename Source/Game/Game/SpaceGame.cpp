#include "SpaceGame.h"
#include "Player.h"
#include "Turret.h"
#include "../Game/Game/GameData.h"
#include "../Game/Enemy.h"
#include "../../Engine/EngineMinimal.h"
#include "../../Engine/Engine.h"
#include "../GamePCH.h"

#include <vector>
#include <iostream>
#include <memory>

bool SpaceGame::Initialize()
{
    m_scene = std::make_unique<Scene>(this);

    blood::json::document_t document;
    blood::json::Load("scene.json", document);
    m_scene->Read(document);

    m_titleText = std::make_unique<blood::Text>(blood::Resources().GetWithID<blood::Font>("title_font", "wingding.ttf", 128.0f));
    m_scoreText = std::make_unique<blood::Text>(blood::Resources().GetWithID<blood::Font>("ui_font", "wingding.ttf", 64.0f));
    m_livesText = std::make_unique<blood::Text>(blood::Resources().GetWithID<blood::Font>("ui_font", "wingding.ttf", 64.0f));

    return true;
}

void SpaceGame::Update(float dt) {
    
    switch (m_gamestate)
    {
    case SpaceGame::GameState::Initialize:
        m_gamestate = GameState::Title;
        break;
    case SpaceGame::GameState::Title:
        if (blood::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_SPACE)) m_gamestate = GameState::StartGame;
        break;
    case SpaceGame::GameState::StartGame:
        m_score = 0;
        m_lives = 3;
        m_spawnTime = 4;
        m_gamestate = GameState::StartRound;
        break;
    case SpaceGame::GameState::StartRound:
    {
        m_scene->RemoveAllActors();

        auto player = blood::Factory::Instance().Create<Actor>("player");
        if (player) m_scene->AddActor(std::move(player));

        auto turret = blood::Factory::Instance().Create<Actor>("turret");
        if (turret) m_scene->AddActor(std::move(turret));

        auto enemy = blood::Factory::Instance().Create<Actor>("enemy");
        if (enemy) m_scene->AddActor(std::move(enemy));
        

        m_gamestate = GameState::Game;
    }
    break;
    case SpaceGame::GameState::Game:
        m_enemySpawnTimer -= dt;
        if (m_enemySpawnTimer <= 0) {
            m_enemySpawnTimer = m_spawnTime;
            SpawnEnemy();
        }
        break;
    case SpaceGame::GameState::PlayerDead:
        m_scene->RemoveAllActors();
        m_stateTimer -= dt;
        if (m_stateTimer <= 0) {
            m_lives -= 1;

            if (m_lives == 0) {
                m_gamestate = GameState::GameOver;
                m_stateTimer = 4;
            }
            else {
                m_gamestate = GameState::StartRound;
            }
        }
        break;
        
    case SpaceGame::GameState::GameOver:
        if (GetEngine().GetInput().GetKeyPressed(SDL_SCANCODE_R)) m_gamestate = GameState::Title;
        break;
    }
    m_scene->Update(dt);
}

void SpaceGame::Draw(blood::Renderer& renderer) {
    if (m_gamestate == GameState::Title) {
        m_titleText->Create(renderer, "Blood", blood::vec3{ 1,0,0 });
        m_titleText->Draw(renderer, (float)renderer.GetWidth() / 2- 250, (float)renderer.GetHeight() / 2);
    }
    if (m_gamestate == GameState::GameOver) {
        m_titleText->Create(renderer, "Game Over", blood::vec3{ 1,0,0 });
        m_titleText->Draw(renderer, (float)renderer.GetWidth() / 2 - 500, (float)renderer.GetHeight() / 2);
    }

    m_scoreText->Create(renderer, std::to_string(GetPoints()), {1,1,1});
    m_scoreText->Draw(renderer, 20, 20);

    m_scoreText->Create(renderer, std::to_string(GetLives()), {1,1,1});
    m_scoreText->Draw(renderer, (float)renderer.GetWidth() - 100, (float)renderer.GetHeight() - 100);

    blood::GetEngine().GetPS().Draw(renderer);
    m_scene->Draw(renderer);

}

void SpaceGame::Shutdown() {

}

void SpaceGame::SpawnEnemy() {
    //x
    Transform trans(vec2((float)random::getReal<float>(GetEngine().GetRenderer().GetWidth()), 
        //y
        (float)random::getReal<float>(GetEngine().GetRenderer().GetHeight())), 
        //rotation and scale
        random::getReal(360.0f), 2.0f);

    auto enemy = blood::Instantiate("enemy", trans);
    if (enemy) m_scene->AddActor(std::move(enemy));
    //1hour:36mins into video.
}

void SpaceGame::OnPlayerDestroyed(){
    m_gamestate = GameState::PlayerDead;
    m_stateTimer = 2;
}


