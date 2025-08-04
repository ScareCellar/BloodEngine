#pragma once
#include "../Core/Math/Vector2.h"
#include "../Core/Math/Vector3.h"

#include <vector>

namespace blood {
	struct Particle {
		bool active = false;

		vec2 position;
		vec2 velocity;

		vec3 color;

		float lifespan = 1;
	};

	class ParticleSystem {
	public:

		ParticleSystem() = default;

		bool Initialize();
		void Shutdown();

		void Update(float dt);
		void Draw(class Renderer& renderer);

		void AddParticle(const Particle& particle);

	private:
		Particle* GetFreeParticle();

		std::vector<Particle> m_particles;
	};
}