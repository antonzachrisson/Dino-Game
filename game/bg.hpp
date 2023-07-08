#pragma once

#include <papaya.hpp>

using namespace papaya;

class bg
{
public:
	bg();
	Vertex verticesBg[4];
	Vertex verticesGround[4];
	void moveBg(float elapsed);
	void moveGround(float elapsed);
};