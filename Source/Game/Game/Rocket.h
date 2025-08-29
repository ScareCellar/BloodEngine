#pragma once

#include "Source/Framework/Component.h"



class Rocket : public blood::Component {
public:
	float speed{ -1000.0f };

	CLASS_PROTOTYPE(Rocket)

	void Update(float dt);
	void Explode();
	
	// Inherited via Actor
	void OnCollision(class blood::Actor* other);

private:
	bool exploded = false;
};