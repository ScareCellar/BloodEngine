#pragma once

#include "../Engine/Framework/Actor.h"


class Rocket : public blood::Actor {
public:
	Rocket(blood::Transform& transform, blood::res_t<blood::Texture> texture) : Actor{transform, texture} {};

	void Draw(blood::Renderer& renderer) override;
	void Update(float dt) override;
	void Explode();
	float speed{ -1000.0f };
	
	// Inherited via Actor
	void OnCollision(Actor* other) override;

private:
	bool exploded = false;
};