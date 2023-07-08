#pragma once

#include <papaya.hpp>

using namespace papaya;

class smallobstacle
{
public:
	smallobstacle();
	Vertex verticesSmall[4];
	Vertex startSmall[4];
	bool active;
};
