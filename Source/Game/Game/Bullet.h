#pragma once
#include "Source/Framework/Component.h"
#include "Source/Renderer/Texture.h"

class Bullet : public blood::Component {
public:
	float speed{ 5.0f };
	bool exploded = false;

	
	void Update(float dt) override;

	// Inherited via Actor
	void OnCollision(class blood::Actor* other);

private:
};