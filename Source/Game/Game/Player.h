#pragma once
#include "Source/Framework/Actor.h"


using namespace sc;

class Player : public Component, public sc::ICollidable {
public:
	Player() = default;
	

	void Update(float dt) override;
	

	float speed = 1000;
	float rotationRate = 50;
	
	CLASS_PROTOTYPE(Player)
	
	void OnCollision(Actor* other) override;

	void Read(const sc::json::value_t& value) override;

private:
	float shootTimer{ 0.4f };

};