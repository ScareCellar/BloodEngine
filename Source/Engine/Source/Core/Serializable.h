#pragma once
#include "Source/Core/Json.h"

namespace blood {
	class Serializable {
	public:
		virtual ~Serializable() = default;

		virtual void Read(const json::value_t& value) = 0;
	};
}