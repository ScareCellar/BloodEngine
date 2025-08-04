#include "Actor.h"
#include "../Renderer/Model.h"
#include "../Renderer/Renderer.h"

namespace blood {


    void Actor::Update(float dt)
    {

        if (destroyed) return;
        m_transform.position += velocity * dt;
        velocity = velocity * (1.0f - damping * dt);
        if (lifespan != 0) {
            lifespan -= dt;
            destroyed = lifespan <= 0;
        }
        
    }

    void Actor::Draw(Renderer& renderer)
    {
        if (destroyed) return;
        m_model->Draw(renderer, m_transform);
    }
    float Actor::GetRadius()
    {
        return (m_model) ? m_model->GetRadius() * m_transform.scale * 0.5f : 0;
    }
}