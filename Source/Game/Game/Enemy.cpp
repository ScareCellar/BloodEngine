#include "../GamePCH.h"
#include "Enemy.h"
#include "Player.h"
#include "SpaceGame.h"
#include "GameData.h"
#include "Bullet.h"
#include "../Engine/Engine.h"
#include "../Engine/Source/Core/Random.h"

FACTORY_REGISTER(Enemy)

void Enemy::Start() {
    rigidBody = owner->GetComponent<sc::RigidBody>();
}

void Enemy::Update(float dt) {
    dt = math::min(dt, 0.2f);
    //bool playerSeen = false;

    Actor* player = owner->scene->GetActorByName<Actor>("tankplayer");
    if (player) {
        vec2 direction{ 0,0 };
        direction = player->transform.position - owner->transform.position;
        
        owner->transform.rotation = math::radToDeg(direction.Angle());
    }

    //
    //



    vec2 force = sc::vec2{ 1,0 }.Rotate(sc::math::degToRad(owner->transform.rotation* speed));
    
    
    auto rb = owner->GetComponent<sc::RigidBody>();
    if (rb) {
        rb->velocity = (force * dt) * speed;
    }

    ///*m_transform.position.x = math::wrap(m_transform.position.x, 0.0f, 1980.0f);
    //m_transform.position.y = math::wrap(m_transform.position.y, 0.0f, 1224.0f);*/

    shootTimer -= dt;

    if (shootTimer <= 0) {
        shootTimer = 3;
        auto bullet = Factory::Instance().Create<Actor>("bullet");
        bullet->lifespan = 3.5f;
        bullet->transform = owner->transform;
        bullet->GetComponent<RigidBody>()->velocity = bullet->GetComponent<RigidBody>()->velocity.Rotate(math::degToRad(bullet->transform.rotation));
        bullet->tag = "enemy";
        owner->scene->AddActor(std::move(bullet));
    }
}

void Enemy::OnCollision(Actor* other){
    if (other->tag == "player" || other->tag == "neutral") {
        if (other->GetComponent<CircleCollider2D>()->active) {
            owner->destroyed = true;
            sc::EventManager::Instance().Notify({ "add_points", 100 });
            sc::GetEngine().GetAudio().PlaySound("bass");
            for (int i = 0; i < 100; i++) {
                sc::Particle particle;
                particle.position = owner->transform.position;
                particle.velocity = sc::vec2{ sc::random::getReal(-200.0f, 200.0f), sc::random::getReal(-200.0f, 200.0f) };
                particle.color = sc::vec3{ 1, 1, 1 };
                particle.lifespan = 2;

                sc::GetEngine().GetPS().AddParticle(particle);
            }
        }
    }
}



