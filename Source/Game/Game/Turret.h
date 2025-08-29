#pragma once
#include "Source/Framework/Actor.h"

using namespace blood;
class Turret :public Component {
public:
	Turret() = default;

	void Update(float dt) override;

	float rotationRate = 50;

	CLASS_PROTOTYPE(Turret)

	// Inherited via Actor
	void OnCollision(Actor* other);

	void Read(const blood::json::value_t& value) override;

private:
	float rocketShootTimer{ 3.0f };
	float bulletShootTimer{ 0.2f };
	

	


private:


};
