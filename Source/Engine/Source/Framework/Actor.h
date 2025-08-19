#pragma once
#include "Object.h"
#include "../Framework/Component.h"
#include "../Renderer/Model.h"
#include "../Renderer/Texture.h"
#include "../Renderer/Renderer.h"

#include <memory>
#include <string>


namespace blood {
	class Actor : public Object{
	public:
		std::string tag;

		vec2 velocity{ 0, 0 };
		float damping{ 10.0f };
		
		bool destroyed = false;

		float lifespan{ 0 };

		class Scene* scene{ nullptr };
	public:
		Actor() = default;
		~Actor() = default;
		Actor(const Transform& transform) : m_transform{ transform }{}
		


		virtual void Update(float dt);
		virtual void Draw(Renderer& renderer);

		virtual void OnCollision(Actor* other) = 0;

		float GetRadius();

		void AddComponent(std::unique_ptr<Component> component);

	public:
		Transform m_transform;

	protected:
		std::vector<std::unique_ptr<Component>> m_components; 

	};
}