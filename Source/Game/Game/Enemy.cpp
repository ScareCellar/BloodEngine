#include "../GamePCH.h"
#include "Enemy.h"
#include "Player.h"
#include "SpaceGame.h"
#include "GameData.h"
#include "Bullet.h"
#include "../Engine/Engine.h"
#include "../Engine/Source/Core/Random.h"

FACTORY_REGISTER(Enemy)

void Enemy::Update(float dt) {
    //bool playerSeen = false;

    //Actor* player = owner->scene->GetActorByName<Actor>("player");
    //if (player) {
    //    vec2 direction{ 0,0 };
    //    direction = player->m_transform.position - owner->m_transform.position;
    //    
    //    owner->m_transform.rotation = math::radToDeg(direction.Angle());
    //}

    //
    //



    //vec2 force = blood::vec2{ 1,0 }.Rotate(blood::math::degToRad(owner->m_transform.rotation* speed));
    //
    //
    //auto rb = owner->GetComponent<blood::RigidBody>();
    //if (rb) {
    //    rb->velocity = (force * dt) * speed;
    //}

    ///*m_transform.position.x = math::wrap(m_transform.position.x, 0.0f, 1980.0f);
    //m_transform.position.y = math::wrap(m_transform.position.y, 0.0f, 1224.0f);*/

    //shootTimer -= dt;

    //if (shootTimer <= 0) {
    //    std::shared_ptr<blood::Mesh> rocketModel = std::make_shared<blood::Mesh>(GameData::rocketPoints, blood::vec3{ 1.0f, 1.0f, 0.0f });
    //    blood::Transform transform{ owner->m_transform.position, this->m_transform.rotation, 10 };
    //    auto bullet = std::make_unique<Actor>(transform); //, blood::Resources().Get<blood::Texture>("bullet.png", blood::GetEngine().GetRenderer()));
    //    bullet->speed = 500.0f;
    //    bullet->lifespan = 5.0f;
    //    bullet->name = "bullet";
    //    bullet->tag = "enemy";
    //    shootTimer = 2.0f;

    //    auto spriteRenderer = std::make_unique<blood::SpriteRenderer>();
    //    spriteRenderer->textureName = "bullet.png";

    //    auto rigidBody = std::make_unique<blood::RigidBody>();

    //    auto collider = std::make_unique<blood::CircleCollider2D>();
    //    collider->radius = 50.0f;

    //    bullet->AddComponent(std::move(spriteRenderer));
    //    bullet->AddComponent(std::move(rigidBody));
    //    bullet->AddComponent(std::move(collider));

    //    owner->scene->AddActor(std::move(bullet));
    //}

    //owner->Actor::Update(dt); 
}

void Enemy::OnCollision(Actor* other){
    if (other->tag == "player") {
        owner->destroyed = true;
        owner->scene->GetGame()->AddPoints(100);
        blood::GetEngine().GetAudio().PlaySound("bass");
        for (int i = 0; i < 100; i++) {
            blood::Particle particle;
            particle.position = owner->m_transform.position;
            particle.velocity = blood::vec2{ blood::random::getReal(-200.0f, 200.0f), blood::random::getReal(-200.0f, 200.0f) };
            particle.color = blood::vec3{ 1, 1, 1 };
            particle.lifespan = 2;

            blood::GetEngine().GetPS().AddParticle(particle);
        }
    }
}



