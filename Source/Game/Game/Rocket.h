#pragma once

#include "Source/Framework/Component.h"



class Rocket : public blood::Component {
public:
	//Rocket(blood::Transform& transform) : Actor{transform} {};

	void Update(float dt);
	void Explode();
	float speed{ -1000.0f };
	
	// Inherited via Actor
	void OnCollision(class blood::Actor* other);

private:
	bool exploded = false;
};