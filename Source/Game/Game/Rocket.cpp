#include "Rocket.h"
#include "Core/Math/MathUtils.h"
#include "GameData.h"
#include "Engine.h"

#include <memory>




void Rocket::Update(float dt) {
	blood::vec2 force = blood::vec2{ 1,0 }.Rotate(blood::math::degToRad(m_transform.rotation)) * speed;
	velocity = force;
	
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
		m_model = std::make_shared<blood::Model>(GameData::explodePoints, blood::vec3{ 1.0f, 1.0f, 0.0f });
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
