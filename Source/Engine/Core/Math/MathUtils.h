#pragma once
#include <SDL3/SDL.h>
#include <algorithm>
#include <cmath>

namespace blood {
	namespace math {
		constexpr float pi = 3.1415926535897932384626433832795f;
		constexpr float twoPi = pi * 2;
		constexpr float halfPi = pi / 2;

		constexpr float radToDeg(float rad) { return rad * (180 / pi); }
		constexpr float degToRad(float deg) { return deg * (pi / 180); }
		
		inline float square(float num) { return num * num; }

		inline float wrap(float value, float min, float max) {
			float range = max - min;
			float result = std::fmodf(value - min, range);
			if (result < 0) result += range;

			return min + result;
		}

		template<typename T>
		inline T sign(T v) {
			return (v < 0) ? (T)-1 : (v > 0) ? (T)1 : (T)0;
		}

		using namespace std;
	}
}