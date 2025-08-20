#pragma once
#include "../Framework/Component.h"

namespace blood {
	class ColliderComponent :public Component {
	public:
		virtual bool CheckCollision(ColliderComponent& other) = 0;
	};
}