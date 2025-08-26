#include "Bullet.h"

#include "SpaceGame.h"
#include "../Engine/Source/Components/RigidBody.h"

FACTORY_REGISTER(Bullet)

void Bullet::OnCollision(blood::Actor* other){
	if (owner->tag != other->tag && other->name != "turret") {
		owner->destroyed = true;
		if (owner->tag == "enemy") {
			owner->scene->GetGame()->AddPoints(50);
		}
	}
	
}

void Bullet::Update(float dt) {
	/*blood::vec2 force = blood::vec2{ 1,0 }.Rotate(blood::math::degToRad(m_transform.rotation)) * speed;

	auto rb = owner->GetComponent<blood::RigidBody>();
	if (rb) {
		rb->velocity = (force * dt) * speed;
	}

	if (lifespan <= 0) {
		destroyed = true;
	}


	Actor::Update(dt);*/
}
