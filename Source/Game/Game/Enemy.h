#pragma once
#include "Source/Framework/Actor.h"

using namespace blood;

class Enemy : public Actor {
public:
	Enemy() = default;
	Enemy(const Transform& transform, blood::res_t<blood::Texture> texture) :
		Actor{ transform } {
	};

	void Update(float dt) override;
	void Draw(Renderer& renderer) override;

	float speed{ 100 };
	float rotationRate{ 0 };

	float shootTimer = 1;

	// Inherited via Actor
	void OnCollision(Actor* other) override;
};