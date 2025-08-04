#include "ParticleSystem.h"
#include "Renderer.h"

namespace blood {
	


	bool ParticleSystem::Initialize() {
		m_particles.resize(1000);
		
		return true;
	}

	void ParticleSystem::Shutdown() {
		m_particles.clear();
	}

	void ParticleSystem::Update(float dt) {
		for (auto& particle : m_particles) {
			if (particle.active) {
				particle.lifespan -= dt;
				if (particle.lifespan <= 0) { particle.active = false; }
				particle.position += particle.velocity * dt;
			}
		}
	}

	void ParticleSystem::Draw(Renderer& renderer) {
		for (auto& particle : m_particles) {
			if (particle.active) {
				renderer.SetColorFloat(particle.color.r, particle.color.g, particle.color.b);
				renderer.DrawPoint(particle.position.x * 255, particle.position.y* 255);
			}
		}
	}
	void ParticleSystem::AddParticle(const Particle& particle) {
		Particle* pParticle = GetFreeParticle();
		if (pParticle != nullptr) {
			*pParticle = particle;
			pParticle->active = true;
		}
	}
	Particle* ParticleSystem::GetFreeParticle() {
		for (auto& particle : m_particles) {
			if (!particle.active)  return &particle; 
		}

		return nullptr;
	}
}