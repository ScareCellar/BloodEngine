#include "SpriteRenderer.h"
#include "../Renderer/Renderer.h"
//#include "../Framework/Actor.h"
#include "../Resources/ResourceManager.h"

namespace blood {
	void SpriteRenderer::Update(float dt) {
		//
	}

	void SpriteRenderer::Draw(Renderer& renderer) {
		renderer.DrawTexture(Resources().Get<Texture>(textureName, renderer).get(), owner->m_transform.position.x, owner->m_transform.position.y);
	}
}
