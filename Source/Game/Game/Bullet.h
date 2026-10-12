#pragma once
#include "Source/Framework/Component.h"
#include "Source/Renderer/Texture.h"

class Bullet : public sc::Component, public sc::ICollidable {
public:
	float speed{ 5.0f };
	bool exploded = false;

	CLASS_PROTOTYPE(Bullet)

	void Update(float dt) override;

	// Inherited via Actor
	void OnCollision(class sc::Actor* other) override;

private:
};