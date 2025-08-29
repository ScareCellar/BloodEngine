#include "Turret.h"
#include "Rocket.h"
#include "Bullet.h"
#include "Gamedata.h"
#include "Engine.h"
#include "../GamePCH.h"
#include "../../Engine/Source/Core/Audio/AudioSystem.h"

FACTORY_REGISTER(Turret)

void Turret::Update(float dt) {
	//line up with player position
	Actor* player = owner->scene->GetActorByName<Actor>("player");
	if (player) {
		owner->transform.position = player->transform.position;

		owner->destroyed = player->destroyed;
	}
	//make it point towards the user's mouse
	blood::vec2 mousePosition = blood::GetEngine().GetInput().GetMousePosition();

	vec2 direction{ 0,0 };
	direction = mousePosition - owner->transform.position;

	owner->transform.rotation = math::radToDeg(direction.Angle());

    rocketShootTimer -= dt;
    bulletShootTimer -= dt;

	if (blood::GetEngine().GetInput().GetMouseButtonDown(InputSystem::MouseButton::Right) && rocketShootTimer <= 0) {
		blood::GetEngine().GetAudio().PlaySound(*blood::Resources().Get<AudioClip>("rocketLaunch.mp3", blood::GetEngine().GetAudio()));
		rocketShootTimer = 3.0f;

		auto rocket = blood::Factory::Instance().Create<Actor>("rocket");
		rocket->lifespan = 3.5f;
		owner->scene->AddActor(std::move(rocket));
	}


 //       std::shared_ptr<blood::Mesh> rocketModel = std::make_shared<blood::Mesh>(GameData::rocketPoints, blood::vec3{ 1.0f, 1.0f, 0.0f });
 //       blood::Transform transform{ this->m_transform.position, this->m_transform.rotation, 2 };
 //       auto rocket = std::make_unique<Rocket>(transform);// , blood::Resources().Get<blood::Texture>("rocket.png", blood::GetEngine().GetRenderer()));
 //       rocket->speed = 1000.0f;
 //       rocket->lifespan = 2.0f;
 //       rocket->name = "rocket";
 //       rocket->tag = "player";
 //       rocketShootTimer = 3.0f;

 //       auto spriteRenderer = std::make_unique<blood::SpriteRenderer>();
 //       spriteRenderer->textureName = "rocket.png";

 //       auto rigidBody = std::make_unique<blood::RigidBody>();

 //       auto collider = std::make_unique<blood::CircleCollider2D>();
 //       collider->radius = 50.0f;

 //       rocket->AddComponent(std::move(spriteRenderer));
 //       rocket->AddComponent(std::move(rigidBody));
 //       rocket->AddComponent(std::move(collider));
 //       scene->AddActor(std::move(rocket));
 //   }

 //   if (blood::GetEngine().GetInput().GetMouseButtonDown(InputSystem::MouseButton::Left) && bulletShootTimer <= 0) {
 //       //blood::GetEngine().GetAudio().PlaySound("bullet");
 //       blood::GetEngine().GetAudio().PlaySound(*blood::Resources().Get<AudioClip>("bullet.mp3", blood::GetEngine().GetAudio()));


 //       std::shared_ptr<blood::Mesh> bulletModel = std::make_shared<blood::Mesh>(GameData::bulletPoints, blood::vec3{ 1.0f, 1.0f, 0.0f });
 //       blood::Transform transform{ this->m_transform.position, this->m_transform.rotation, 2 };
 //       auto bullet = std::make_unique<Bullet>(transform);// , blood::Resources().Get<blood::Texture>("bullet.png", blood::GetEngine().GetRenderer()));
 //       bullet->speed = 1000.0f;
 //       bullet->lifespan = 1.5f;
 //       bullet->name = "bullet";
 //       bullet->tag = "player";
 //       bulletShootTimer = 0.2f;

 //       auto spriteRenderer = std::make_unique<blood::SpriteRenderer>();
 //       spriteRenderer->textureName = "bullet.png";

 //       auto rigidBody = std::make_unique<blood::RigidBody>();
 //       rigidBody->damping = 0.0f;

 //       auto collider = std::make_unique<blood::CircleCollider2D>();
 //       collider->radius = 50.0f;

 //       
 //       bullet->AddComponent(std::move(spriteRenderer));
 //       bullet->AddComponent(std::move(rigidBody));
 //       bullet->AddComponent(std::move(collider));

 //       scene->AddActor(std::move(bullet));
 //   }
}

void Turret::OnCollision(Actor* other) {

}

void Turret::Read(const blood::json::value_t& value) {
	Object::Read(value);

	JSON_READ(value, rocketShootTimer);
	JSON_READ(value, bulletShootTimer);
}
