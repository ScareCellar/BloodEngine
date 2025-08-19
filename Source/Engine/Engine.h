#pragma once
#include "Source/Core/Time.h"
#include "Source/Core/Audio/AudioSystem.h"
#include "Source/Input/InputSystem.h"
#include "Source/Renderer/Renderer.h"
#include "Source/Renderer/ParticleSystem.h"
#include "Source/Core/Singleton.h"
#include <memory>

namespace blood {
	class Renderer;
	class InputSystem;
	class AudioSystem;
	class ParticleSystem;
	class Engine : public Singleton<Engine>{
	public:

		bool Initialize();
		void Shutdown();

		void Update();
		void Draw();

		Renderer& GetRenderer() { return *m_renderer; }
		AudioSystem& GetAudio() { return *m_audio; }
		InputSystem& GetInput() { return *m_input; }
		ParticleSystem& GetPS() { return *m_particleSystem; }
		Time GetTime() { return time; }


	private:
		friend Singleton<Engine>;

		Engine() = default;

		Time time;
		std::unique_ptr<Renderer> m_renderer;
		std::unique_ptr<InputSystem> m_input;
		std::unique_ptr<AudioSystem> m_audio;
		std::unique_ptr<ParticleSystem> m_particleSystem;
	};

	inline Engine& GetEngine() {
		return Engine::Instance();
	}
}
