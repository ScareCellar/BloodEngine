#pragma once
#include "Framework/Actor.h"
#include "../Engine/Renderer/Texture.h"

class Bullet : public blood::Actor{
public:
	Bullet(blood::Transform& transform, blood::res_t<blood::Texture> texture) : blood::Actor{ transform, texture } {};

	
	void Update(float dt) override;
	
	float speed{ 2000.0f };

	// Inherited via Actor
	void OnCollision(Actor* other) override;

private:
	bool exploded = false;
};