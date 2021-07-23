#pragma once
#include <AL\al.h>

namespace AaronEngine {
	class SoundSource {
	public:
		SoundSource();
		~SoundSource();

		void Play(const ALuint buffer_to_play);

	private:
		ALuint p_Source;
		ALuint p_Buffer = 0;
	};
}


