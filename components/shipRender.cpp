#include "shipRender.h"
#include "vec3.h"


shipRender::shipRender()
{
}

void shipRender::draw(const transform & ShipTransform, const mat3 & camera)
{
	mat3 ship = ShipTransform.getGlobalTransform();

	vec3 p1 = camera * ship * vec3{ 0, .75,1 };
	vec3 p2 = camera * ship * vec3{ -.25, 0,1 };
	vec3 p3 = camera * ship * vec3{ .25, 0,1 };
	vec3 p4 = camera * ship * vec3{ 0, -.25,1 };

	sfw::drawLine(p1.x, p1.y, p2.x, p2.y, WHITE);
	sfw::drawLine(p2.x, p2.y, p4.x, p4.y, WHITE);
	sfw::drawLine(p4.x, p4.y, p3.x, p3.y, WHITE);
	sfw::drawLine(p3.x, p3.y, p1.x, p1.y, WHITE);
}
