#pragma once

namespace blood {
	class ICollidable {
	public:
		virtual void OnCollision(class Actor* other) = 0;
	};
}