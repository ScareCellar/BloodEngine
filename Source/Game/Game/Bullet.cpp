#include "Bullet.h"
#include "Enemy.h"
#include "SpaceGame.h"
#include "../Engine/Source/Components/RigidBody.h"
#include "../GamePCH.h"

FACTORY_REGISTER(Bullet)

void Bullet::OnCollision(blood::Actor* other){
	if (owner->tag != other->tag && other->name != "turret") {
		owner->destroyed = true;
		if (other->GetComponent<Enemy>()) {
			owner->scene->GetGame()->AddPoints(50);
		}
	}
	
}

void Bullet::Update(float dt) {
}
