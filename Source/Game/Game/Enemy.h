#pragma once
#include "Source/Framework/Actor.h"

using namespace blood;

class Enemy : public Component {
public:
	Enemy() = default;
	float speed{ 100 };
	float rotationRate{ 0 };
	float shootTimer = 1;

	blood::RigidBody* rigidBody;

	CLASS_PROTOTYPE(Enemy)

	void Start() override;

	void Update(float dt) override;
	void OnCollision(Actor* other);
};