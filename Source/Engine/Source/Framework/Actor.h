#pragma once
#include "../Renderer/Model.h"
#include "../Renderer/Texture.h"

#include <memory>
#include <string>


namespace blood {
	class Actor {
	public:
		std::string name;
		std::string tag;

		vec2 velocity{ 0, 0 };
		float damping{ 10.0f };
		
		bool destroyed = false;

		float lifespan{ 0 };

		class Scene* scene{ nullptr };
	public:
		Actor() = default;
		~Actor() = default;
		Actor(const Transform& transform, res_t<Texture> texture) : m_transform{ transform }, m_texture{ texture } {}
		


		virtual void Update(float dt);
		virtual void Draw(Renderer& renderer);

		virtual void OnCollision(Actor* other) = 0;

		float GetRadius();

	public:
		Transform m_transform;
		res_t<Texture> m_texture;
		//std::shared_ptr<Model> m_model;


	};
}