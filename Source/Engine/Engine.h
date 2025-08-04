#pragma once
#include "Core/Time.h"
#include "Core/Audio/AudioSystem.h"
#include "Input/InputSystem.h"
#include "Renderer/Renderer.h"
#include "Renderer/ParticleSystem.h"
#include <memory>

namespace blood {
	class Renderer;
	class InputSystem;
	class AudioSystem;
	class ParticleSystem;
	class Engine {
	public:
		Engine() = default;

		bool Initialize();
		void Update();
		void Shutdown();

		void Draw();

		Renderer& GetRenderer() { return *m_renderer; }
		AudioSystem& GetAudio() { return *m_audio; }
		InputSystem& GetInput() { return *m_input; }
		ParticleSystem& GetPS() { return *m_particleSystem; }
		Time GetTime() { return time; }


	private:
		Time time;
		std::unique_ptr<Renderer> m_renderer;
		std::unique_ptr<InputSystem> m_input;
		std::unique_ptr<AudioSystem> m_audio;
		std::unique_ptr<ParticleSystem> m_particleSystem;
	};

	Engine& GetEngine();
	inline Renderer& GetRenderer() { return GetEngine().GetRenderer(); }
}
