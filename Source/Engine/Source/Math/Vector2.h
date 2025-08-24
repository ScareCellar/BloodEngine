#pragma once
#include <cassert>
#include "MathUtils.h"
namespace blood {
	template<typename T>
	struct Vector2 {
		union {
			struct { T x, y; };
			struct { T u, v; };
		};

		Vector2() = default;

		Vector2(T x, T y) : x{ x }, y{ y } {}

		float& operator [] (unsigned int index) { assert(2 > index);  return (&x)[index]; }

		Vector2 operator +(const Vector2& v) const { return Vector2{ x + v.x, y + v.y }; }
		Vector2 operator -(const Vector2& v) const { return Vector2{ x - v.x, y - v.y }; }
		Vector2 operator *(const Vector2& v) const { return Vector2{ x * v.x, y * v.y }; }
		Vector2 operator /(const Vector2& v) const { return Vector2{ x / v.x, y / v.y }; }
		
		Vector2 operator +(float f) const { return Vector2{ x + f, y + f }; }
		Vector2 operator -(float f) const { return Vector2{ x - f, y - f }; }
		Vector2 operator *(float f) const { return Vector2{ x * f, y * f }; }
		Vector2 operator /(float f) const { return Vector2{ x / f, y / f }; }

		Vector2& operator +=(const Vector2& v) { x += v.x, y += v.y; return *this; };
		Vector2& operator -=(const Vector2& v) { x -= v.x, y -= v.y; return *this; };
		Vector2& operator *=(const Vector2& v) { x *= v.x, y *= v.y; return *this; };
		Vector2& operator /=(const Vector2& v) { x /= v.x, y /= v.y; return *this; };

		Vector2& operator +=(float f) const { return Vector2{ x += f, y += f }; return *this; }
		Vector2& operator -=(float f) const { return Vector2{ x -= f, y -= f }; return *this; }
		Vector2& operator *=(float f) const { return Vector2{ x *= f, y *= f }; return *this; }
		Vector2& operator /=(float f) const { return Vector2{ x /= f, y /= f }; return *this; }

		

		//pythagorean theorum
		float LengthSqr() const { 
			return ((x * x) + (y * y));
		}

		float Length() const { return math::sqrtf(LengthSqr()); }

		//normalizing distance
		Vector2 Normalized() const { return *this / Length(); }

		float Angle() const { return math::atan2f(y, x); };


		Vector2 Rotate(float radians) const {
			Vector2 v;

			v.x = x * math::cosf(radians) - y * math::sinf(radians);
			v.y = x * math::sinf(radians) + y * math::cosf(radians);

			return v;
		}

		static float Dot(const Vector2& a, const Vector2& b) {
			return a.x * b.x + a.y * b.y;
		}

		static float Cross(const Vector2& a, const Vector2& b) {
			return a.x* b.x - a.y * b.y;
		}

		static float AngleBetween(const Vector2& a, const Vector2& b) {
			return math::acosf(Dot(a, b));
		}

		static float SignedAngleBetween(const Vector2& a, const Vector2& b) {
			float x = Dot(a, b);
			float y = Cross(a, b);

			return math::atan2f(y, x);
		}

	};

	template<typename T>
	std::ostream& operator << (std::ostream& stream, const Vector2<T>& v) {
		stream << "{" << v.x << "," << v.y << "}";

		return stream;
	}

	template<typename T>
	std::istream& operator >> (std::istream& stream, Vector2<T>& v) {
		char ch = '\0';

		if ((stream >> std::ws >> ch) || ch != '{') {
			stream.setstate(std::ios::failbit);
			return stream;
		}
		if (!(stream >> std::ws >> v.x)) {
			stream.setstate(std::ios::failbit);
			return stream;
		}
		if ((stream >> std::ws >> ch) || ch != ',') {
			stream.setstate(std::ios::failbit);
			return stream;
		}
		if (!(stream >> std::ws >> v.y)) {
			stream.setstate(std::ios::failbit);
			return stream;
		}
		if ((stream >> std::ws >> ch) || ch != '}') {
			stream.setstate(std::ios::failbit);
			return stream;
		}


		return stream;
	}

	using ivec2 = Vector2<int>;
	using vec2 = Vector2<float>;
}