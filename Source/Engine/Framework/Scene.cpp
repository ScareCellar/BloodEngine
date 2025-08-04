#include "Scene.h"
#include "../Renderer/Renderer.h"
#include "../Core/StringHelper.h"


namespace blood {

	void Scene::Update(float dt) {
		for (auto& actor : m_actors) {
			actor->Update(dt);
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

				float distance = (actorA->m_transform.position - actorB->m_transform.position).Length();

				if (distance <= actorA->GetRadius() + actorB->GetRadius()) {
					actorA->OnCollision(actorB.get());
					actorB->OnCollision(actorA.get());
				}

			}
		}
	}

	void Scene::Draw(Renderer& renderer) {
		for (auto& actor : m_actors) {
			actor->Draw(renderer);
		}
	}
	void Scene::AddActor(std::unique_ptr<Actor> actor){
		actor->scene = this;
		m_actors.push_back(std::move(actor));
	}
	
	
}