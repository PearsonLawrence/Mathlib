#pragma once
#include "shapes.h"
#include "transform.h"
void drawcircle(const circle &c, unsigned color);
void drawAABB(const AABB & b,unsigned color);
void drawPlane(const plane & p, unsigned color);
void drawHull(const hull & h, unsigned color);