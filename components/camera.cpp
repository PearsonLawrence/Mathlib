#include "camera.h"
#include "gamestate.h"
Camera::Camera()
{
	
	projection = translate(800, 450) * ScaleC;

}

mat3 Camera::getCameraMatrix()
{
	return projection * translate(-Transform.m_position.x, -Transform.m_position.y);

	//return projection * inverse(Transform.getGlobalTransform());
}

void Camera::update(float deltatime, Gamestate & gs)
{
	
	Transform.m_position = lerp(Transform.m_position,
		gs.player.trans.getGlobalPosition(), 0.05f);

	ScaleC = scale(scalenum, scalenum);
	projection = translate(800, 450) * ScaleC;
}
