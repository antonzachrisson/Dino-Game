#include "dino.hpp"

dino::dino()
{
    verticesDino[0] = { Vector2(30.0f,  400.0f), Vector2(0.0f, 0.0f), Color(1.0f, 1.0f, 1.0f, 1.0f) };
    verticesDino[1] = { Vector2(81.0f,  400.0f), Vector2(1.0f, 0.0f), Color(1.0f, 1.0f, 1.0f, 1.0f) };
    verticesDino[2] = { Vector2(81.0f, 454.0f), Vector2(1.0f, 1.0f), Color(1.0f, 1.0f, 1.0f, 1.0f) };
    verticesDino[3] = { Vector2(30.0f, 454.0f), Vector2(0.0f, 1.0f), Color(1.0f, 1.0f, 1.0f, 1.0f) };
};

