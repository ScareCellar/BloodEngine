#pragma once
#include "../Core/Math/Vector2.h"
#include "../Resources/Resource.h"
#include <string>


namespace blood {
	class Texture : public Resource {
	public:
		Texture() = default;
		~Texture();

		bool Load(const std::string& filename, class Renderer& renderer);

		vec2 GetSize();

		friend class Renderer;

	private:
		struct SDL_Texture* m_texture{ nullptr };
	};
}