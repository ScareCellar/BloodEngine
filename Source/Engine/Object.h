#pragma once

namespace blood {
	class Object {
	public:
		std::string name;
		bool active = false;
	private:
		Object() = default;
		virtual ~Object() = default;
	};
}