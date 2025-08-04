#include "SpaceGame.h"
#include "Core/Math/Vector2.h"
#include "Renderer/Model.h"
#include "Renderer/Renderer.h"
#include "Renderer/ParticleSystem.h"
#include "Player.h"
#include "Engine.h"
#include "Core/Random.h"
#include "Input/InputSystem.h"
#include "../Game/Game/GameData.h"
#include "../Game/Enemy.h"

#include <vector>
#include <iostream>
#include <memory>

bool SpaceGame::Initialize()
{
    m_scene = std::make_unique<Scene>(this);

    m_titleFont = std::make_shared<blood::Font>();
    m_titleFont->Load("wingding.ttf", 128);

    m_uiFont = std::make_shared<blood::Font>();
    m_uiFont->Load("wingding.ttf", 64);

    m_titleText = std::make_unique<blood::Text>(m_titleFont);
    m_scoreText = std::make_unique<blood::Text>(m_uiFont);
    m_livesText = std::make_unique<blood::Text>(m_uiFont);
    //make enemies
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
        

        // create player
        std::shared_ptr<blood::Model> model = std::make_shared<blood::Model>(GameData::drillPoints, blood::vec3{ 1.0f, 1.0f, 0.0f });
        blood::Transform transform{ blood::vec2{ blood::GetEngine().GetRenderer().GetWidth() * 0.5f, blood::GetEngine().GetRenderer().GetHeight() * 0.5f }, 0, 20 };
        auto player = std::make_unique<Player>(transform, model);
        player->speed = 5000.0f;
        player->rotationRate = 30.0f;
        player->damping = 10.0f;
        player->name = "player";
        player->tag = "player";

        m_scene->AddActor(std::move(player));

        std::shared_ptr<blood::Model> turretModel = std::make_shared<blood::Model>(GameData::turretPoints, blood::vec3{ 0.0f, 0.0f, 1.0f });
        blood::Transform turretTransform{ blood::vec2{ blood::GetEngine().GetRenderer().GetWidth() * 0.5f, blood::GetEngine().GetRenderer().GetHeight() * 0.5f }, 0, 20 };
        auto turret = std::make_unique<Turret>(turretTransform, turretModel);
        turret->name = "turret";
        turret->tag = "player";

        m_scene->AddActor(std::move(turret));

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
    Actor* player = m_scene->GetActorByName<Actor>("player");
    if (player) {
        m_spawnTime -= 0.1f;
        if (m_spawnTime < 0.5f) m_spawnTime = 0.5f;

        blood::vec2 position = player->m_transform.position + blood::random::onUnitCircle();

        std::shared_ptr<Model> enemyModel = std::make_shared<blood::Model>(GameData::drillPoints, vec3{ 1,0,0 });
        Transform transform{ vec2{ random::getReal() * GetEngine().GetRenderer().GetWidth(), random::getReal() * GetEngine().GetRenderer().GetHeight() }, 0, 10 };
        std::unique_ptr<Enemy> enemy = std::make_unique<Enemy>(transform, enemyModel);
        enemy->damping = 0.2f;
        enemy->speed = 50;
        enemy->tag = "enemy";
        m_scene->AddActor(std::move(enemy));
    }
}

void SpaceGame::OnPlayerDestroyed(){
    m_gamestate = GameState::PlayerDead;
    m_stateTimer = 2;
}


