#pragma once
#include "transform.h"
#include "mat3.h"

class shipRender
{
public:
	shipRender();

	
	void draw(const transform & ShipTransform, const mat3 & camera);


};