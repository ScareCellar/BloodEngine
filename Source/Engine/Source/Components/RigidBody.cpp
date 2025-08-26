#include "RigidBody.h"
#include "../Framework/Actor.h"

namespace blood {
	FACTORY_REGISTER(RigidBody)

	void RigidBody::Update(float dt) {
		owner->m_transform.position += velocity * dt;
		velocity = velocity * (1.0f - damping * dt);
	}
}
