#pragma once
#include "Source/Framework/Actor.h"

using namespace blood;
class Turret :public Component {
public:
	Turret() = default;

	void Update(float dt) override;

	float rotationRate = 50;

	CLASS_PROTOTYPE(Turret)

	void Read(const blood::json::value_t& value) override;

private:
	float rocketShootTimer;
	float totalBullets;
	float maxBullets;
	float bulletShootTimer;
	float mortarShootTimer;
	float mortarDropTimer{ 3 };
};
