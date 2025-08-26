#pragma once
#include "RendererComponent.h"
#include <string>

namespace blood {
	class SpriteRenderer : public RendererComponent {
	public:
		std::string textureName;


		void Update(float dt) override;

		void Draw(Renderer& renderer) override;


		// Inherited via Serializable
		void Read(const json::value_t& value) override;

	};
}