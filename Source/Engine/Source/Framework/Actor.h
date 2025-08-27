#pragma once
#include "Object.h"
#include "../Framework/Component.h"
#include "../Renderer/Mesh.h"
#include "../Renderer/Texture.h"
#include "../Renderer/Renderer.h"

#include <memory>
#include <string>


namespace blood {
	class Actor : public Object {
	public:
		std::string tag;

		bool destroyed = false;

		float lifespan{ 0 };

		class Scene* scene{ nullptr };
	public:
		Actor() = default;
		~Actor() = default;
		Actor(const Transform& transform) : transform{ transform }{}
		


		virtual void Update(float dt);
		virtual void Draw(Renderer& renderer);

		virtual void OnCollision(Actor* other) {

		}

		void AddComponent(std::unique_ptr<Component> component);

		template<typename T>
		T* GetComponent();

		template<typename T>
		std::vector<T*> GetComponents();

		void Read(const json::value_t& value) override;
	public:
		Transform transform;

	protected:
		std::vector<std::unique_ptr<Component>> m_components;
	};


	template<typename T>
	inline T* Actor::GetComponent()
	{
		for (auto& component : m_components) {
			auto result = dynamic_cast<T*>(component.get());
			if (result) return result;
		}
		return nullptr;
	}

	template<typename T>
	inline std::vector<T*> Actor::GetComponents()
	{
		std::vector<T*> results;
		for (auto& component : m_components) {
			auto result = dynamic_cast<T*>(component.get());
			if (result) results.push_back(result);
		}
		
		return results;
	}
}