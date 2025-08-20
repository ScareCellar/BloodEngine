#include "../Audio/AudioClip.h"
#include "AudioSystem.h"
namespace blood {
	AudioClip::~AudioClip() {
		if(&m_sound) m_sound->release();
	}

	bool AudioClip::Load(const std::string& filename, AudioSystem& audio) {
		FMOD_RESULT result = audio.m_system->createSound(filename.c_str(), FMOD_DEFAULT, 0, &m_sound);

		if (!AudioSystem::CheckFMODResult(result)) return false;
	}
}