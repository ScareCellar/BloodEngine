#include "Rocket.h"
#include "GameData.h"
#include "../Engine/Engine.h"
#include "../Engine/Source/Components/RigidBody.h"
#include "../Engine/Source/Framework/Actor.h"
#include "../GamePCH.h"



FACTORY_REGISTER(Rocket)

void Rocket::Update(float dt) {
	/*blood::vec2 force = blood::vec2{ 1,0 }.Rotate(blood::math::degToRad(m_transform.rotation)) * speed;
	auto rb = GetComponent<blood::RigidBody>();
	if (rb) {
		rb->velocity = force;
	}
	
	lifespan -= dt;
	
	if (lifespan <= 0) {
		Explode();
	}
	Actor::Update(dt);*/
}

void Rocket::Explode(){
	if (!exploded) {
		blood::GetEngine().GetAudio().PlaySound("explode");
		std::unique_ptr<blood::Mesh> explode;
		//m_texture = blood::Resources().Get<blood::Texture>("explode.png", blood::GetEngine().GetRenderer());
		owner->lifespan = 0.2f;
		speed = 0;
		exploded = true;
	}
	else if (owner->lifespan <= 0 && exploded) {
		owner->destroyed = true;
	}
}

void Rocket::OnCollision(blood::Actor* other){
	if (owner->tag != other->tag && !owner->destroyed) {
		Explode();
	}
}
