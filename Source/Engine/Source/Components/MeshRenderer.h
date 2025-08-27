#pragma once
#include "RendererComponent.h"
#include <string>

namespace blood {
	class MeshRenderer : public RendererComponent {
	public:
		std::string meshName;

		void Update(float dt) override;
		void Draw(Renderer& renderer) override;

		void Read(const json::value_t& value) override;
	};
}