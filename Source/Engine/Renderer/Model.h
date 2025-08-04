#pragma once
#include "../Core/Math/Vector2.h"
#include "../Core/Math/Vector3.h"
#include "../Core/Math/Transform.h"


#include <vector>
namespace blood {
	class Model {
	public:
		Model() = default;
		Model(const std::vector<vec2> points, const vec3& color) {
			m_points = points;
			m_color = color;
			CalculateRadius();
		}

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