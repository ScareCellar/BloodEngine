#pragma once
#include "../../Resources/Resource.h"
#include <fmod.hpp>
#include <string>

namespace blood {
	class AudioClip : public Resource {
	public:
		AudioClip() = default;
		~AudioClip();

		bool Load(const std::string& filename, class AudioSystem& audio);

	private:
		FMOD::Sound* m_sound = nullptr;
		
		friend class AudioSystem;
	};
}