#pragma once

#include "mat3.h"
#include "transform.h"

class SpriteRenderer
{
public:
	vec2 offset;
	vec2 dimensions;

	int textureHandle;

	void draw(const mat3 & camera, const transform& T);
};