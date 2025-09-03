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
	/*	std::erase_if(m_actors, [](auto actor) {
			return (actor->destroyed);
		});*/

		//check for collisions
		for (auto& actorA : m_actors) {
			for (auto& actorB : m_actors) {
				if (actorA == actorB || (actorA->destroyed || actorB->destroyed)) continue;

				auto colliderA = actorA->GetComponent<ColliderComponent>();
				auto colliderB = actorB->GetComponent<ColliderComponent>();

				if (!colliderA || !colliderB) continue;

				float distance = (actorA->transform.position - actorB->transform.position).Length();

				if (colliderA->CheckCollision(*colliderB)) {
					if (actorA->name == "tankplayer" || actorB->name == "tankplayer")
						Logger::Debug("{} colliding with {}", actorA->name, actorB->name);
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
		actor->Start();
		m_actors.push_back(std::move(actor));
	}

	bool Scene::Load(const std::string& sceneName) {
		blood::json::document_t document;
		if (!blood::json::Load(sceneName, document)) {
			Logger::Error("Could not load Scene {}", sceneName);
			return false;
		}
		Read(document);

		//start actors
		for (auto& actor : m_actors) {
			actor->Start();
		}

		return true;
	}

	void Scene::Read(const json::value_t& value){
		if (JSON_HAS(value, prototypes)) {
			for (auto& actorValue : JSON_GET(value, prototypes).GetArray()) {
				auto actor = Factory::Instance().Create<Actor>("Actor");
				actor->Read(actorValue);

				std::string actorName = actor->name;
				Factory::Instance().RegisterPrototype<Actor>(actorName, std::move(actor));
			}
		}

		if (JSON_HAS(value, actors)) {
			for (auto& actorValue : JSON_GET(value, actors).GetArray()) {
				auto actor = Factory::Instance().Create<Actor>("Actor");
				actor->Read(actorValue);

				AddActor(std::move(actor));
			}
		}
	}
	
	
}