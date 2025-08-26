#include "Scene.h"
#include "../Renderer/Renderer.h"
#include "../Components/Collider.h"
#include "../Engine/Source/Core/Factory.h"

namespace blood{

	void Scene::Update(float dt) {
		for (auto& actor : m_actors) {
			if (actor->active) actor->Update(dt);
		}
		//remove destroyed actors
		for (auto iter = m_actors.begin(); iter != m_actors.end();) {
			if ((*iter)->destroyed) {
				iter = m_actors.erase(iter);
			}
			else {
				iter++;
			}
		}

		//check for collisions
		for (auto& actorA : m_actors) {
			for (auto& actorB : m_actors) {
				if (actorA == actorB || (actorA->destroyed || actorB->destroyed)) continue;

				auto colliderA = actorA->GetComponent<ColliderComponent>();
				auto colliderB = actorB->GetComponent<ColliderComponent>();

				if (!colliderA || !colliderB) continue;

				float distance = (actorA->m_transform.position - actorB->m_transform.position).Length();

				if (colliderA->CheckCollision(*colliderB)) {
					actorA->OnCollision(actorB.get());
					actorB->OnCollision(actorA.get());
				}
			}
		}
	}

	void Scene::Draw(Renderer& renderer) {
		for (auto& actor : m_actors) {
			if (actor->active) actor->Draw(renderer);
		}
	}
	void Scene::AddActor(std::unique_ptr<Actor> actor){
		actor->scene = this;
		m_actors.push_back(std::move(actor));
	}

	void Scene::Read(const json::value_t& value){
		for (auto& actorValue : value["actors"].GetArray()) {
			auto actor = Factory::Instance().Create<Actor>("Actor");
			actor->Read(actorValue);

			AddActor(std::move(actor));
		}
	}
	
	
}