
#include "CircleCollider2D.h"
#include "../Framework/Actor.h"

namespace blood {
	FACTORY_REGISTER(CircleCollider2D)

	void CircleCollider2D::Update(float dt) {
		//
	}

	bool CircleCollider2D::CheckCollision(ColliderComponent& other) {
		float distance = (owner->m_transform.position - other.owner->m_transform.position).Length();
		auto collider = dynamic_cast<CircleCollider2D*>(&other);
		if (collider) {
			float radii = radius + collider->radius;
			if (distance <= radii) {
				return true;
			}
		}
		/*if (distance <= owner->GetRadius() + other.owner->GetRadius()) {}*/
		return false;
	}
}
