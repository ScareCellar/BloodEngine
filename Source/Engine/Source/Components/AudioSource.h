#pragma once
#include "../../EnginePCH.h"
#include "../Framework/Component.h"
namespace blood {
	class AudioSource : public Component {
	public:
		std::string audioClipName;

		void Update(float dt) override;

		void Play();

		void Read(const json::value_t& value) override;
	};
}
