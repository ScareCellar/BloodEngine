#pragma once

namespace blood {
	class Object {
	public:
		std::string name;
		bool active = true;

		Object() = default;
		virtual ~Object() = default;
	};
}