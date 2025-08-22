#include "AudioSource.h"
#include "../Core/Audio/AudioClip.h"
#include "../../Engine.h"

namespace blood {
	void AudioSource::Update(float dt) {
		//
	}
	void AudioSource::Play() {
		auto clip = Resources().Get<AudioClip>(audioClipName, GetEngine().GetAudio());

		if (clip) {
			GetEngine().GetAudio().PlaySound(*clip);
		}
	}
}
