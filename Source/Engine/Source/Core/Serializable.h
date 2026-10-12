#pragma once
#include "Source/Core/Json.h"

namespace sc {
	class ISerializable {
	public:
		virtual ~ISerializable() = default;

		virtual void Read(const json::value_t& value) = 0;
	};
}