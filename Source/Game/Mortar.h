#pragma once

#include "GamePCH.h"

class Mortar : public sc::Component, public sc::ICollidable {
public:
	float dropTime;
	float explosionTime;

	CLASS_PROTOTYPE(Mortar)

	// Inherited via Component
	void Update(float dt) override;

	void Explode(float dt);

	void Read(const sc::json::value_t& value) override;


	// Inherited via ICollidable
	void OnCollision(sc::Actor* other) override;

};