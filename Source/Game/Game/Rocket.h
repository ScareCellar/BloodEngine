#pragma once

#include "Source/Framework/Actor.h"


class Rocket : public blood::Actor {
public:
	Rocket(blood::Transform& transform) : Actor{transform} {};

	void Draw(blood::Renderer& renderer) override;
	void Update(float dt) override;
	void Explode();
	float speed{ -1000.0f };
	
	// Inherited via Actor
	void OnCollision(Actor* other) override;

private:
	bool exploded = false;
};