#include "GameData.h"

namespace GameData {
    std::vector<blood::vec2> drillPoints
    {
        { -4, -3 },
        { 4, -3 },
        { 4, 3 },
        { -4, 3 },
        { -4, 3 },
        { -4, -3 },
        { -3, -3 },
        { -3, -4 },
        { 3, -4 },
        { 3, -3 },
        { 4, -3 },
        { 8, 0 },
        { 4, 3 },
        { 3, 3 },
        { 3, 4 },
        { -3, 4 },
        { -3, 3 },
    };

    std::vector<blood::vec2> turretPoints
    {
        { -0.83f, -0.33f },
        { -0.67f, -0.67f },
        { 0.0f, -1.0f },
        { 0.67f, -0.67f },
        { 1.67f, -0.67f },
        { 0.67f, -0.67f },
        { 1.0f, 0.0f },
        { 0.67f, 0.67f },
        { 1.67f, 0.67f },
        { 0.67f, 0.67f },
        { 0.0f, 1.0f },
        { -0.67f, 0.67f },
        { -0.83f, 0.33f },
        { -1.67f, 0.33f },
        { -1.33f, 0.0f },
        { -1.67f, -0.33f },
        { -0.83f, -0.33f },
        { -1.0f, 0.0f },
        { -0.83f, 0.33f },
    };
    extern std::vector<blood::vec2> rocketPoints
    {
        { -0.333f, 0.0f },
        { 0.0f, -0.333f },
        { 0.667f, -0.333f },
        { 0.333f, 0.0f },
        { 0.667f, 0.333f },
        { 0.0f, 0.333f },
        { -0.333f, 0.0f },
    };
    extern std::vector<blood::vec2> bulletPoints
    {
        {0,0},
        {1,0}
    };
    extern std::vector<blood::vec2> explodePoints
    {
        { 0, -9 },
        { 6, -6 },
        { 9, 0 },
        { 6, 6 },
        { 0, 9 },
        { -6, 6 },
        { -9, 0 },
        { -6, -6 },
        { 0, -9 },
    };
}