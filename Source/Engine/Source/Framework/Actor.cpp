#include "Actor.h"
#include "../Renderer/Renderer.h"
#include "../Components/RendererComponent.h"

namespace blood {


    void Actor::Update(float dt)
    {
        if(destroyed) return;
        //m_transform.position += velocity * dt;
        //velocity = velocity * (1.0f - damping * dt);
        if (lifespan != 0) {
            lifespan -= dt;
            destroyed = lifespan <= 0;
        }

        for (auto& component : m_components) {
            if (component->active) {
                component->Update(dt);
            }
        }
    }

    void Actor::Draw(Renderer& renderer) {
        if (destroyed) return;

        for (auto& component : m_components) {
            if (component->active) {
                auto rendererComponent = dynamic_cast<RendererComponent*>(component.get());
                if (rendererComponent) {
                    rendererComponent->Draw(renderer); 
                }
            }
        }
        renderer.DrawTexture(m_texture.get(), m_transform.position.x, m_transform.position.y, m_transform.rotation, m_transform.scale);
    }

    float Actor::GetRadius() {
       return (m_texture) ? m_texture->GetSize().Length() * 0.5f * m_transform.scale * 0.5f : 0;
    }

    void Actor::AddComponent(std::unique_ptr<Component> component) {
        component->owner = this;
        m_components.push_back(std::move(component));
    }
}