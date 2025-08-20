#pragma once
#include "Collider.h"
namespace blood {
	class CircleCollider2D :public ColliderComponent {
	public:
		void Update(float dt) override;

		bool CheckCollision(ColliderComponent& other) override;

	};
}