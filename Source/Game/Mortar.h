#pragma once

#include "GamePCH.h"

class Mortar : public blood::Component, public blood::ICollidable {
public:
	float dropTime;
	float explosionTime;

	CLASS_PROTOTYPE(Mortar)

	// Inherited via Component
	void Update(float dt) override;

	void Explode(float dt);

	void Read(const blood::json::value_t& value) override;


	// Inherited via ICollidable
	void OnCollision(blood::Actor* other) override;

};