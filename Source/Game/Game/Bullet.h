#pragma once
#include "Source/Framework/Actor.h"
#include "Source/Renderer/Texture.h"

class Bullet : public blood::Actor{
public:
	Bullet(blood::Transform& transform) : blood::Actor{ transform} {};

	
	void Update(float dt) override;
	
	float speed{ 2000.0f };

	// Inherited via Actor
	void OnCollision(Actor* other) override;

private:
	bool exploded = false;
};