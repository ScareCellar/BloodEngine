#pragma once
#include "Source/Framework/Actor.h"


using namespace blood;

class Player : public Component {
public:
	Player() = default;
	

	void Update(float dt) override;
	

	float speed = 1000;
	float rotationRate = 50;
	
	
	void OnCollision(Actor* other);

	void Read(const blood::json::value_t& value) override;

private:
	float shootTimer{ 0.4f };

};