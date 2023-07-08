#include "bg.hpp"

using namespace papaya;

bg::bg()
{
    verticesBg[0] = { Vector2(0.0f,  0.0f), Vector2(0.0f, 0.0f), Color(1.0f, 1.0f, 1.0f, 1.0f) };
    verticesBg[1] = { Vector2(2048.0f,  0.0f), Vector2(1.0f, 0.0f), Color(1.0f, 1.0f, 1.0f, 1.0f) };
    verticesBg[2] = { Vector2(2048.0f, 576.0f), Vector2(1.0f, 1.0f), Color(1.0f, 1.0f, 1.0f, 1.0f) };
    verticesBg[3] = { Vector2(0.0f, 576.0f), Vector2(0.0f, 1.0f), Color(1.0f, 1.0f, 1.0f, 1.0f) };

    verticesGround[0] = { Vector2(0.0f,  426.0f), Vector2(0.0f, 0.0f), Color(1.0f, 1.0f, 1.0f, 1.0f) };
    verticesGround[1] = { Vector2(2048.0f,  426.0f), Vector2(1.0f, 0.0f), Color(1.0f, 1.0f, 1.0f, 1.0f) };
    verticesGround[2] = { Vector2(2048.0f, 566.0f), Vector2(1.0f, 1.0f), Color(1.0f, 1.0f, 1.0f, 1.0f) };
    verticesGround[3] = { Vector2(0.0f, 566.0f), Vector2(0.0f, 1.0f), Color(1.0f, 1.0f, 1.0f, 1.0f) };
};

void bg::moveBg(float elapsed)
{
    for (int i = 0; i < 4; i++)
    {
        verticesBg[i].position_.x_ -= elapsed * 60.0f;
    }
    if (verticesBg[1].position_.x_ <= 1024.0f)
    {
        verticesBg[0] = { Vector2(0.0f,  0.0f), Vector2(0.0f, 0.0f), Color(1.0f, 1.0f, 1.0f, 1.0f) };
        verticesBg[1] = { Vector2(2048.0f,  0.0f), Vector2(1.0f, 0.0f), Color(1.0f, 1.0f, 1.0f, 1.0f) };
        verticesBg[2] = { Vector2(2048.0f, 576.0f), Vector2(1.0f, 1.0f), Color(1.0f, 1.0f, 1.0f, 1.0f) };
        verticesBg[3] = { Vector2(0.0f, 576.0f), Vector2(0.0f, 1.0f), Color(1.0f, 1.0f, 1.0f, 1.0f) };
    }
}

void bg::moveGround(float elapsed)
{
    for (int i = 0; i < 4; i++)
    {
        verticesGround[i].position_.x_ -= elapsed * 150.0f;
    }
    if (verticesGround[1].position_.x_ <= 1024.0f)
    {
        verticesGround[0] = { Vector2(0.0f,  426.0f), Vector2(0.0f, 0.0f), Color(1.0f, 1.0f, 1.0f, 1.0f) };
        verticesGround[1] = { Vector2(2048.0f,  426.0f), Vector2(1.0f, 0.0f), Color(1.0f, 1.0f, 1.0f, 1.0f) };
        verticesGround[2] = { Vector2(2048.0f, 566.0f), Vector2(1.0f, 1.0f), Color(1.0f, 1.0f, 1.0f, 1.0f) };
        verticesGround[3] = { Vector2(0.0f, 566.0f), Vector2(0.0f, 1.0f), Color(1.0f, 1.0f, 1.0f, 1.0f) };
    }
}