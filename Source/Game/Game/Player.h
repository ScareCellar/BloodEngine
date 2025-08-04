#pragma once
#include "Framework/Actor.h"
#include "Turret.h"
#include "GameData.h"
#include "Engine.h"
#include "Framework/Scene.h"

using namespace blood;

class Player : public Actor {
public:
	Player() = default;
	Player(const Transform& transform, std::shared_ptr<Model> model) {
		m_transform = transform;
		m_model = model;

		
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