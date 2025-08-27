#include "RigidBody.h"
#include "../Framework/Actor.h"

namespace blood {
	FACTORY_REGISTER(RigidBody)

	void RigidBody::Update(float dt) {
		owner->transform.position += velocity * dt;
		velocity = velocity * (1.0f - damping * dt);
	}
	void RigidBody::Read(const json::value_t& value)
	{
		JSON_READ(value, velocity);
		JSON_READ(value, damping);
	}
}
