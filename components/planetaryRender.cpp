#include "planetaryRender.h"
#include "flops.h"
#include "vec3.h"
PlanetaryRender::PlanetaryRender(unsigned a_color, float a_size)
{
	color = a_color;
	size = a_size;

}

void PlanetaryRender::draw(const mat3 &t, transform & planetTrans)
{


	mat3 glob = t * planetTrans.getGlobalTransform();

	float xRad = magnitude(glob * vec3{ size,0,0 });
	float yRad = magnitude(glob * vec3{ 0,size,0 });

	vec2 pos = glob[2].xy;

	float rad = xRad > yRad ? xRad : yRad;

	sfw::drawCircle(pos.x, pos.y, rad, 12U, color);


}
