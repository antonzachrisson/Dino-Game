#pragma once

#include <papaya.hpp>

using namespace papaya;

class bigobstacle
{
public:
	bigobstacle();
	Vertex verticesBig[4];
	Vertex startBig[4];
	bool active;
};
