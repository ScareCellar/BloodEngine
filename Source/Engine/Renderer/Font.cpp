#include "Font.h"
#include "../Core/Logger.h"
#include <SDL3_ttf/SDL_textengine.h>
#include <iostream>
namespace blood {
	Font::~Font() {
		if (m_ttfFont != nullptr) {
			TTF_CloseFont(m_ttfFont);
		}
	}

	bool Font::Load(const std::string& name, float fontSize) {
		m_ttfFont = TTF_OpenFont(name.c_str(), fontSize);
		if (m_ttfFont == nullptr) {
			Logger::Log(LogLevel::Warning, "Could not load font: " + name);
			return false;
		}

		return true;
	}
}
