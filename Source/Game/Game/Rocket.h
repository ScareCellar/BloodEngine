#pragma once

#include "Source/Framework/Component.h"
#include "Source/Physics/ICollidable.h"
#include "Source/Framework/Actor.h"


class Rocket : public blood::Component, blood::ICollidable {
public:
	float speed{ -1000.0f };

	CLASS_PROTOTYPE(Rocket)

	void Update(float dt);
	void Explode();
	
	// Inherited via Actor
	void OnCollision(blood::Actor* other) override;

private:
	bool exploded = false;
};