#include "Player.h"
#include "GameData.h"
#include "Rocket.h"
#include "SpaceGame.h"
#include "../Engine/Engine.h"
#include "../Engine/Source/Components/RigidBody.h"


using namespace sc;

FACTORY_REGISTER(Player)

void Player::Update(float dt) {
    ////1980, 1224
    sc::Particle particle;
    particle.position = owner->transform.position;
    particle.velocity = sc::vec2{ 200,0 };
    particle.color = sc::vec3{ 1,1,1 };
    particle.lifespan = 2.0f;
    GetEngine().GetPS().AddParticle(particle);


    float rotate = 0;
  
    if (GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_A)) rotate = -1;//100 * time.GetDeltaTime();
    if (GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_D)) rotate = +1;//100 * time.GetDeltaTime();

    owner->transform.rotation += (rotate * rotationRate) * dt;

    //thrust
    float thrust = 0;
    if (GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_W)) thrust = +1;
    if (GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_S)) thrust = -1;

    vec2 direction{ 1,0 };
    vec2 force = direction.Rotate(math::degToRad(owner->transform.rotation)) * thrust * speed;

    auto* rb = owner->GetComponent<sc::RigidBody>();
    if (rb) {
        rb->velocity += force * dt;
    }
    owner->transform.position.x = math::wrap(owner->transform.position.x, 0.0f, 1980.0f);
    owner->transform.position.y = math::wrap(owner->transform.position.y, 0.0f, 1224.0f);
    
    //
    GetEngine().GetPS().Draw(Engine::Instance().GetRenderer());
}


void Player::OnCollision(sc::Actor* other) {
    
    if (owner->tag != other->tag) {
        owner->destroyed = true;
        sc::EventManager::Instance().Notify(sc::Event{ "player_dead", true });

        dynamic_cast<SpaceGame*>(owner->scene->GetGame())->OnPlayerDestroyed();
    }
}

void Player::Read(const sc::json::value_t& value) {
    Object::Read(value);

    JSON_READ(value, speed);
    JSON_READ(value, rotationRate);
    JSON_READ(value, shootTimer);
}
