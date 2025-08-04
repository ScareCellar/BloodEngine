#include "Bullet.h"
#include "Framework/Scene.h"

void Bullet::OnCollision(Actor* other){
	if (tag != other->tag) {
		destroyed = true;
	}
}

void Bullet::Update(float dt) {
	blood::vec2 force = blood::vec2{ 1,0 }.Rotate(blood::math::degToRad(m_transform.rotation)) * speed;
	velocity = force;

	lifespan -= dt;

	if (lifespan <= 0) {
		destroyed = true;
	}


	Actor::Update(dt);
}
