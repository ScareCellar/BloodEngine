#pragma once
#include "Source/Core/Serializable.h"

namespace blood {
	class Object : public Serializable{
	public:
		std::string name;
		bool active = true;

		Object() = default;
		virtual ~Object() = default;

		// Inherited via Serializable
		void Read(const json::value_t& value) override;
	};
}