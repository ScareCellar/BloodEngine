#pragma once
#include "../Framework/Component.h"

namespace blood {
	class RendererComponent :public Component {
	public:
		virtual void Draw(class Renderer& renderer) = 0;
	};
}