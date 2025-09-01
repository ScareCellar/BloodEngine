#include "Rocket.h"
#include "GameData.h"
#include "../Engine/Engine.h"
#include "../Engine/Source/Framework/Actor.h"
#include "../GamePCH.h"
#include "Enemy.h"



FACTORY_REGISTER(Rocket)

void Rocket::Update(float dt) {
	owner->lifespan -= dt;

	if (owner->lifespan <= 0) Explode();
}

void Rocket::Explode(){
	if (!exploded) {
		blood::GetEngine().GetAudio().PlaySound("explode");
		std::unique_ptr<blood::Mesh> explode;
		owner->GetComponent<blood::SpriteRenderer>()->textureName = "explode.png";
		owner->lifespan = 0.2f;
		owner->GetComponent<RigidBody>()->damping = 10;
		exploded = true;
	}
	else if (owner->lifespan <= 0 && exploded) {
		owner->destroyed = true;
	}
}

void Rocket::OnCollision(blood::Actor* other){
	if (owner->tag != other->tag && other->name != "turret") {
		Explode();
		
	}
}
