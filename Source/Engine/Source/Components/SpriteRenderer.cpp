#include "SpriteRenderer.h"
#include "../Renderer/Renderer.h"
#include "../Framework/Actor.h"
#include "../Resources/ResourceManager.h"

namespace blood {
	FACTORY_REGISTER(SpriteRenderer)


	void SpriteRenderer::Update(float dt) {
		//
	}

	void SpriteRenderer::Draw(Renderer& renderer) {
		auto texture = Resources().Get<Texture>(textureName, renderer).get();

		if (texture) {
			renderer.DrawTexture(*texture,
				owner->m_transform.position.x,
				owner->m_transform.position.y,
				owner->m_transform.rotation,
				owner->m_transform.scale);
		}
	}
	void SpriteRenderer::Read(const json::value_t& value) {
		Object::Read(value);
		JSON_READ(value, textureName);
	}
}
