#pragma once
#include "Object.h"

namespace blood {
	class Component : public Object {
	public:
		class Actor* owner{ nullptr };

		Component() = default;

		virtual void Update(float dt) = 0;
	};
}