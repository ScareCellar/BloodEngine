#pragma once
#include "Collider.h"
namespace blood {
	class CircleCollider2D :public ColliderComponent {
	public:
		float radius = 0;


		void Update(float dt) override;
		bool CheckCollision(ColliderComponent& other) override;
		void Read(const json::value_t& value) override;

	};
}