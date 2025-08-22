#pragma once
#include "../../Source/Math/Vector2.h"
#include "../../Source/Math/Vector3.h"
#include "../../Source/Math/Transform.h"
#include "../Resources/Resource.h"
#include "../../EnginePCH.h"


#include <vector>
namespace blood {
	class Mesh : public Resource {
	public:
		Mesh() = default;
		Mesh(const std::vector<vec2> points, const vec3& color) {
			m_points = points;
			m_color = color;
			CalculateRadius();
		}

		bool Load(const std::string filename);

		void Draw(class Renderer& renderer, const vec2& position, float rotations, float scale);
		void Draw(class Renderer& renderer, const Transform& transform);
		float GetRadius() const {
			return m_radius;
		}



	public:

	private:
		void CalculateRadius();


		float m_radius;
		std::vector<vec2> m_points;
		vec3 m_color{ 1,1,1 };
	};
}