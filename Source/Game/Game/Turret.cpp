#include "Turret.h"
#include "Framework/Scene.h"
#include "Input/InputSystem.h"
#include "Engine.h"
#include "Rocket.h"
#include "Bullet.h"
#include "Gamedata.h"


void Turret::Update(float dt) {
	//line up with player position
	Actor* player = scene->GetActorByName<Actor>("player");
	m_transform = player->m_transform;
	
	destroyed = player->destroyed;

	//make it point towards the user's mouse
	blood::vec2 mousePosition = blood::GetEngine().GetInput().GetMousePosition();

	vec2 direction{ 0,0 };
	direction = mousePosition - m_transform.position;

	m_transform.rotation = math::radToDeg(direction.Angle());

    rocketShootTimer -= dt;
    bulletShootTimer -= dt;

    if (blood::GetEngine().GetInput().GetMouseButtonDown(InputSystem::MouseButton::Right) && rocketShootTimer <= 0) {
        blood::GetEngine().GetAudio().PlaySound("launch");


        std::shared_ptr<blood::Model> rocketModel = std::make_shared<blood::Model>(GameData::rocketPoints, blood::vec3{ 1.0f, 1.0f, 0.0f });
        blood::Transform transform{ this->m_transform.position, this->m_transform.rotation, 10 };
        auto rocket = std::make_unique<Rocket>(transform, rocketModel);
        rocket->speed = -1000.0f;
        rocket->lifespan = 2.0f;
        rocket->name = "rocket";
        rocket->tag = "player";
        rocketShootTimer = 3.0f;
        scene->AddActor(std::move(rocket));
    }

    if (blood::GetEngine().GetInput().GetMouseButtonDown(InputSystem::MouseButton::Left) && bulletShootTimer <= 0) {
        blood::GetEngine().GetAudio().PlaySound("bullet");


        std::shared_ptr<blood::Model> bulletModel = std::make_shared<blood::Model>(GameData::bulletPoints, blood::vec3{ 1.0f, 1.0f, 0.0f });
        blood::Transform transform{ this->m_transform.position, this->m_transform.rotation, 10 };
        auto bullet = std::make_unique<Bullet>(transform, bulletModel);
        bullet->speed = 2000.0f;
        bullet->lifespan = 1.5f;
        bullet->name = "bullet";
        bullet->tag = "player";
        bulletShootTimer = 0.2f;
        scene->AddActor(std::move(bullet));
    }
}

void Turret::Draw(Renderer& renderer) {
	Actor::Draw(renderer);
}

void Turret::OnCollision(Actor* other) {

}