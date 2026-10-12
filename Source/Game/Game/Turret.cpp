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
	Actor* player = owner->scene->GetActorByName<Actor>("tankplayer");
	if (player) {
		owner->transform.position = player->transform.position;

		owner->destroyed = player->destroyed;
	}
	//make it point towards the user's mouse
	sc::vec2 mousePosition = sc::GetEngine().GetInput().GetMousePosition();

	vec2 direction{ 0,0 };
	direction = mousePosition - owner->transform.position;

	owner->transform.rotation = math::radToDeg(direction.Angle());

    bulletShootTimer -= dt;
	totalBullets += 2 * dt;
	if (totalBullets > maxBullets) totalBullets = maxBullets;
    rocketShootTimer -= dt;
    mortarShootTimer -= dt;

	if (sc::GetEngine().GetInput().GetMouseButtonDown(InputSystem::MouseButton::Right) && rocketShootTimer <= 0) {
		sc::GetEngine().GetAudio().PlaySound(*sc::Resources().Get<AudioClip>("rocketLaunch.mp3", sc::GetEngine().GetAudio()));
		rocketShootTimer = 3.0f;

		auto rocket = sc::Factory::Instance().Create<Actor>("rocket");
		rocket->lifespan = 3.5f;
		rocket->transform = owner->transform;
		rocket->GetComponent<RigidBody>()->velocity = rocket->GetComponent<RigidBody>()->velocity.Rotate(math::degToRad(rocket->transform.rotation));
		rocket->tag = "player";
		owner->scene->AddActor(std::move(rocket));
	}


	if (sc::GetEngine().GetInput().GetMouseButtonDown(InputSystem::MouseButton::Left) && bulletShootTimer <= 0 && totalBullets >= 1) {
		sc::GetEngine().GetAudio().PlaySound(*sc::Resources().Get<AudioClip>("bullet.mp3", sc::GetEngine().GetAudio()));
		bulletShootTimer = 0.2f;
		totalBullets--;

		auto bullet = sc::Factory::Instance().Create<Actor>("bullet");
		bullet->lifespan = 3.5f;
		bullet->transform = owner->transform;
		bullet->GetComponent<RigidBody>()->velocity = bullet->GetComponent<RigidBody>()->velocity.Rotate(math::degToRad(bullet->transform.rotation));
		bullet->tag = "player";
		owner->scene->AddActor(std::move(bullet));
	}

	//Fire Mortar
	if (sc::GetEngine().GetInput().GetMouseButtonDown(InputSystem::MouseButton::Middle) && mortarShootTimer <= 0) {
		sc::GetEngine().GetAudio().PlaySound(*sc::Resources().Get<AudioClip>("bullet.mp3", sc::GetEngine().GetAudio()));
		mortarShootTimer = 5.0f;

		auto mortar = sc::Factory::Instance().Create<Actor>("mortar_weapon");
		mortar->lifespan = 0.0f;
		//mortar->transform = owner->transform;
		mortar->transform.position = GetEngine().GetInput().GetMousePosition();
		//mortar->GetComponent<RigidBody>()->velocity = mortar->GetComponent<RigidBody>()->velocity.Rotate(math::degToRad(mortar->transform.rotation));
		mortar->tag = "neutral";
		mortar->destroyed = false;
		owner->scene->AddActor(std::move(mortar));
	}
}

void Turret::Read(const sc::json::value_t& value) {
	Object::Read(value);

	JSON_READ(value, bulletShootTimer);
	JSON_READ(value, maxBullets);
	JSON_READ(value, rocketShootTimer);
	JSON_READ(value, mortarShootTimer);
	totalBullets = maxBullets;
}
