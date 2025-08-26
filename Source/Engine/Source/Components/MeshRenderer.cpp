#include "MeshRenderer.h"
#include "../../EnginePCH.h"

namespace blood {
	FACTORY_REGISTER(MeshRenderer)

	void MeshRenderer::Update(float dt)	{
		//
	}

	void MeshRenderer::Draw(Renderer& renderer)	{
		auto mesh = Resources().Get<Mesh>(meshName);
		
		if (mesh) {
			mesh->Load(meshName);
			mesh->Draw(renderer, owner->m_transform);
		}
	}
}
