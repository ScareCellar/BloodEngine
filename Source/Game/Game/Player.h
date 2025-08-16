#pragma once
#include "Framework/Actor.h"


using namespace blood;

class Player : public Actor {
public:
	Player() = default;
	Player(const Transform& transform, res_t<Texture> texture) {
		m_transform = transform;
		m_texture = texture;

		
	}

	void Update(float dt) override;
	void Draw(Renderer& renderer) override;

	float speed = 1000;
	float rotationRate = 50;
	
	// Inherited via Actor
	void OnCollision(Actor* other) override;

private:
	float shootTimer{ 0.4f };

};