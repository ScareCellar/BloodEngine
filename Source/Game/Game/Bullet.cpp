#include "Bullet.h"
#include "Framework/Scene.h"
#include "SpaceGame.h"

void Bullet::OnCollision(Actor* other){
	if (tag != other->tag && other->name != "turret") {
		destroyed = true;
		if (tag == "enemy") {
			scene->GetGame()->AddPoints(50);
		}
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
