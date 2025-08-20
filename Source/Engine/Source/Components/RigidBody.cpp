#include "RigidBody.h"
#include "../Framework/Actor.h"

namespace blood {
	void RigidBody::Update(float dt) {
		owner->m_transform.position += velocity * dt;
		velocity = velocity * (1.0f - damping * dt);
	}
}
