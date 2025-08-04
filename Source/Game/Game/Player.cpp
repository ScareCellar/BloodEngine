#include "Player.h"
#include "Engine.h"
#include "Input/InputSystem.h"
#include "Core/Audio/AudioSystem.h"
#include "Renderer/Renderer.h"
#include "Renderer/ParticleSystem.h"
#include "GameData.h"
#include "Renderer/Model.h"
#include "Framework/Scene.h"
#include "Rocket.h"
#include "SpaceGame.h"



using namespace blood;

void Player::Update(float dt) {
    //1980, 1224
    blood::Particle particle;
    particle.position = m_transform.position;
    particle.velocity = blood::vec2{ 200,0 };
    particle.color = blood::vec3{ 1,1,1 };
    particle.lifespan = 2.0f;
    GetEngine().GetPS().AddParticle(particle);


    float rotate = 0;
  
    if (GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_A)) rotate = -1;//100 * time.GetDeltaTime();
    if (GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_D)) rotate = +1;//100 * time.GetDeltaTime();

    m_transform.rotation += (rotate * rotationRate) * dt;

    //thrust
    float thrust = 0;
    if (GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_W)) thrust = +1;
    if (GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_S)) thrust = -1;

    vec2 direction{ 1,0 };
    vec2 force = direction.Rotate(math::degToRad(m_transform.rotation)) * thrust * speed;
    velocity += force * dt;

    m_transform.position.x = math::wrap(m_transform.position.x, 0.0f, 1980.0f);
    m_transform.position.y = math::wrap(m_transform.position.y, 0.0f, 1224.0f);
    

    //fire rockets
    GetEngine().GetPS().Draw(GetRenderer());

    Actor::Update(dt);
}
void Player::Draw(Renderer& renderer) {
    Actor::Draw(renderer);
}

void Player::OnCollision(Actor* other)
{
    if (tag != other->tag) {
        destroyed = true;
        dynamic_cast<SpaceGame*>(scene->GetGame())->OnPlayerDestroyed();
    }
}
