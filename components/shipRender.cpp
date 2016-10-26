#include "shipRender.h"
#include "vec3.h"
#include "shapes.h"
#include "shapedraw.h"
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

	drawAABB(camera * ship * AABB{ 0, .25, .13f, .25f }, WHITE);

	sfw::drawLine(p1.x, p1.y, p2.x, p2.y, WHITE);
	sfw::drawLine(p2.x, p2.y, p4.x, p4.y, WHITE);
	sfw::drawLine(p4.x, p4.y, p3.x, p3.y, WHITE);
	sfw::drawLine(p3.x, p3.y, p1.x, p1.y, WHITE);




	vec3 left = camera * ship * vec3{ -.25, -.25, 1 };
	vec3 down = camera * ship * vec3{ .25, -.25, 1 };
	vec3 right   = camera * ship * vec3{ .25, .75 ,1 };
	vec3 up  = camera * ship * vec3{ -.25,.75,1 };


	/*sfw::drawLine(left.x, left.y, up.x, up.y, MAGENTA);
	sfw::drawLine(up.x, up.y, right.x, right.y, MAGENTA);
	
	sfw::drawLine(left.x, left.y, down.x, down.y, MAGENTA);
	sfw::drawLine(down.x, down.y, right.x, right.y, MAGENTA);*/
}
