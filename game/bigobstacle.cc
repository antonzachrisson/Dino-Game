#include "bigobstacle.hpp"

using namespace papaya;

bigobstacle::bigobstacle()
{
    verticesBig[0] = { Vector2(1024.0f,  394.0f), Vector2(0.0f, 0.0f), Color(1.0f, 1.0f, 1.0f, 1.0f) };
    verticesBig[1] = { Vector2(1055.0f,  394.0f), Vector2(1.0f, 0.0f), Color(1.0f, 1.0f, 1.0f, 1.0f) };
    verticesBig[2] = { Vector2(1055.0f, 454.0f), Vector2(1.0f, 1.0f), Color(1.0f, 1.0f, 1.0f, 1.0f) };
    verticesBig[3] = { Vector2(1024.0f, 454.0f), Vector2(0.0f, 1.0f), Color(1.0f, 1.0f, 1.0f, 1.0f) };

    for (int i = 0; i < 4; i++)
    {
        startBig[i] = verticesBig[i];
    }

    active = false;
};
