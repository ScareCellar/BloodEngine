#pragma once
#include "../../Engine/Framework/Actor.h"
#include "../../Engine/Core/Math/Transform.h"

using namespace blood;

class Enemy : public Actor {
public:
	Enemy() = default;
	Enemy(const Transform& transform, std::shared_ptr<Model> model) :
		Actor{ transform, model } {
	};

	void Update(float dt) override;
	void Draw(Renderer& renderer) override;

	float speed{ 100 };
	float rotationRate{ 0 };

	float shootTimer = 1;

	// Inherited via Actor
	void OnCollision(Actor* other) override;
};