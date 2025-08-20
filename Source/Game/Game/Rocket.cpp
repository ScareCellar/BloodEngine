#include "Rocket.h"
#include "GameData.h"
#include "../Engine/Engine.h"
#include "../Engine/Source/Components/RigidBody.h"




void Rocket::Draw(blood::Renderer& renderer)
{

}

void Rocket::Update(float dt) {
	blood::vec2 force = blood::vec2{ 1,0 }.Rotate(blood::math::degToRad(m_transform.rotation)) * speed;

	auto rb = GetComponent<blood::RigidBody>();
	if (rb) {
		rb->velocity = force;
	}
	
	
	lifespan -= dt;
	
	if (lifespan <= 0) {
		Explode();
	}
	

	Actor::Update(dt);
}

void Rocket::Explode(){
	if (!exploded) {
		blood::GetEngine().GetAudio().PlaySound("explode");
		std::unique_ptr<blood::Model> explode;
		//m_texture = blood::Resources().Get<blood::Texture>("explode.png", blood::GetEngine().GetRenderer());
		lifespan = 0.2f;
		speed = 0;
		exploded = true;
	}
	else if (lifespan <= 0 && exploded) {
		destroyed = true;
	}
}

void Rocket::OnCollision(Actor* other){
	if (tag != other->tag && !destroyed) {
		Explode();
	}
}
