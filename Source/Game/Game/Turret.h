#pragma once
#include "Source/Framework/Actor.h"

using namespace blood;
class Turret :public Actor {
public:
	Turret() = default;
	Turret(const Transform& transform) : Actor{ transform } {};

	void Update(float dt) override;
	void Draw(class Renderer& renderer) override;

	float speed = 1000;
	float rotationRate = 50;

	// Inherited via Actor
	void OnCollision(Actor* other) override;

private:
	float rocketShootTimer{ 3.0f };
	float bulletShootTimer{ 0.2f };

	


private:


};
