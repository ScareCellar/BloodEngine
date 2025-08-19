#pragma once
#include "RendererComponent.h"
#include <string>

namespace blood {
	class SpriteRenderer :public RendererComponent {
	public:
		std::string textureName;


		void Update(float dt) override;

		void Draw(Renderer& renderer) override;

	};
}