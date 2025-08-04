#pragma once
#include "../Core/Math/MathUtils.h"
#include "../Core/Math/Vector2.h"


#include <cstdlib>
#include <random>

namespace blood {
	namespace random {
		
        inline std::mt19937& generator() {
            static std::random_device rd;
            static std::mt19937 gen(rd());
            return gen;
        }

        inline void seed(unsigned int value) {
            generator().seed(value);
        }

        inline int getInt(int min, int max) {
            std::uniform_int_distribution<> dist(min, max);
            return dist(generator());
        }

        inline int getInt(int max) {
            return getInt(0, max - 1);
        }

        inline int getInt() {
            static std::uniform_int_distribution<> dist;
            return dist(generator());
        }

        template <typename T = float>
        inline T getReal(T min, T max) {
            std::uniform_real_distribution<T> dist(min, max);
            return dist(generator());
        }

        template <typename T = float>
        inline T getReal(T max) {
            return getReal(static_cast<T>(0), static_cast<T>(max));
        }

        template <typename T = float>
        inline T getReal() {
            static std::uniform_real_distribution<T> dist(static_cast<T>(0), static_cast<T>(1));
            return dist(generator());
        }

        inline bool getBool() {
            static std::bernoulli_distribution dist(0.5);
            return dist(generator());
        }

        /// <summary>
        /// Generates a 2D vector located on the unit circle.
        /// </summary>
        /// <returns>A vec2 representing a point on the unit circle, with x and y components corresponding to the cosine and sine of a random angle in radians.</returns>
        inline vec2 onUnitCircle() {
            float radians = getReal(math::twoPi);
            vec2 v;
            v.x = math::cosf(radians);
            v.y = math::sinf(radians);
            return v;
        }

        //end of new random
		
		/*inline int getRandomInt() {
			return rand();
		}

		inline int getRandomInt(int max) { 
			return rand() % max; 
		}

		inline int getRandomInt(int min, int max) {
			return min + getRandomInt(max - min + 1);
		}

		inline float getRandomFloat() {
			return rand() / (float)RAND_MAX;
		}*/
	}
}
