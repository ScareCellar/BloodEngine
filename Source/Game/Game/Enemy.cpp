#include "Enemy.h"
#include "Player.h"
#include "SpaceGame.h"
#include "GameData.h"
#include "Bullet.h"
#include "../Engine/Engine.h"
#include "../Engine/Source/Core/Random.h"
#include "../Engine/Source/Components/SpriteRenderer.h"

void Enemy::Update(float dt) {
    bool playerSeen = false;

    Actor* player = scene->GetActorByName<Actor>("player");
    if (player) {
        vec2 direction{ 0,0 };
        direction = player->m_transform.position - m_transform.position;

        /*direction = direction.Normalized();
        blood::vec2 forward = blood::vec2{ 1,0 }.Rotate(blood::math::degToRad(m_transform.rotation));
        float angle = blood::math::radToDeg(blood::vec2::AngleBetween(forward, direction));
        angle = blood::vec2::SignedAngleBetween(forward, direction);
        angle = blood::math::sign(angle);
        m_transform.rotation += blood::math::radToDeg(angle * 5 * dt);*/
        
        m_transform.rotation = math::radToDeg(direction.Angle());
    }

    
    



    vec2 force = blood::vec2{ 1,0 }.Rotate(blood::math::degToRad(m_transform.rotation* speed));
    velocity = force * dt;
    
    /*m_transform.position.x = math::wrap(m_transform.position.x, 0.0f, 1980.0f);
    m_transform.position.y = math::wrap(m_transform.position.y, 0.0f, 1224.0f);*/

    shootTimer -= dt;

    if (shootTimer <= 0) {
        std::shared_ptr<blood::Model> rocketModel = std::make_shared<blood::Model>(GameData::rocketPoints, blood::vec3{ 1.0f, 1.0f, 0.0f });
        blood::Transform transform{ this->m_transform.position, this->m_transform.rotation, 10 };
        auto bullet = std::make_unique<Bullet>(transform); //, blood::Resources().Get<blood::Texture>("bullet.png", blood::GetEngine().GetRenderer()));
        bullet->speed = 500.0f;
        bullet->lifespan = 5.0f;
        bullet->name = "rocket";
        bullet->tag = "enemy";
        shootTimer = 2.0f;

        auto spriteRenderer = std::make_unique<blood::SpriteRenderer>();
        spriteRenderer->textureName = "bullet.png";

        bullet->AddComponent(std::move(spriteRenderer));

        scene->AddActor(std::move(bullet));
    }

    Actor::Update(dt);
}

void Enemy::OnCollision(Actor* other){
    if (other->tag == "player") {
        destroyed = true;
        scene->GetGame()->AddPoints(100);
        blood::GetEngine().GetAudio().PlaySound("bass");
        for (int i = 0; i < 100; i++) {
            blood::Particle particle;
            particle.position = m_transform.position;
            particle.velocity = blood::vec2{ blood::random::getReal(-200.0f, 200.0f), blood::random::getReal(-200.0f, 200.0f) };
            particle.color = blood::vec3{ 1, 1, 1 };
            particle.lifespan = 2;

            blood::GetEngine().GetPS().AddParticle(particle);
        }
    }
}

void Enemy::Draw(Renderer& renderer) {
    Actor::Draw(renderer);
}

