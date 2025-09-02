#include "Engine.h"
#include "Source/Renderer/Renderer.h"
#include "Source/Input/InputSystem.h"
#include "Source/Core/Audio/AudioSystem.h"
#include "Source/Renderer/ParticleSystem.h"

namespace blood {

	bool Engine::Initialize() {
		m_renderer = std::make_unique<blood::Renderer>();
		m_renderer->Initialize();
		m_renderer->CreateWindow("Game", 1980, 1224, false);

		m_input = std::make_unique<blood::InputSystem>();
		m_input->Initialize();

		m_audio = std::make_unique<blood::AudioSystem>();
		m_audio->Initialize();

		m_particleSystem = std::make_unique<blood::ParticleSystem>();
		m_particleSystem->Initialize();

		m_physics = std::make_unique<Physics>();
		m_physics->Initialize();
		return true;
	}
	void Engine::Shutdown() {
		Resources().Clear();
		m_particleSystem->Shutdown();
		m_audio->Shutdown();
		m_input->ShutDown();
		m_renderer->Shutdown();
		m_physics->Shutdown();
		EventManager::Instance().RemoveAll();
		Factory::Instance().RemoveAll();
	}
	void Engine::Update() {
		m_time.Tick();
		m_input->Update();
		m_audio->Update();
		m_particleSystem->Update(m_time.GetDeltaTime());
		m_physics->Update(m_time.GetDeltaTime());
	}
}