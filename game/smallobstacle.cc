#include "smallobstacle.hpp"

using namespace papaya;

smallobstacle::smallobstacle()
{
    verticesSmall[0] = { Vector2(1024.0f,  409.0f), Vector2(0.0f, 0.0f), Color(1.0f, 1.0f, 1.0f, 1.0f) };
    verticesSmall[1] = { Vector2(1069.0f,  409.0f), Vector2(1.0f, 0.0f), Color(1.0f, 1.0f, 1.0f, 1.0f) };
    verticesSmall[2] = { Vector2(1069.0f, 454.0f), Vector2(1.0f, 1.0f), Color(1.0f, 1.0f, 1.0f, 1.0f) };
    verticesSmall[3] = { Vector2(1024.0f, 454.0f), Vector2(0.0f, 1.0f), Color(1.0f, 1.0f, 1.0f, 1.0f) };

    for (int i = 0; i < 4; i++)
    {
        startSmall[i] = verticesSmall[i];
    }

    active = false;
};