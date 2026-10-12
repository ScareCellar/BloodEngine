#pragma once

namespace sc {
	class ICollidable {
	public:
		virtual void OnCollision(class Actor* other) = 0;
	};
}