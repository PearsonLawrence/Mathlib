#include "camera.h"
#include "gamestate.h"
Camera::Camera()
{
	projection = translate(600, 600) * scale(2, 2);

}

mat3 Camera::getCameraMatrix()
{
	return projection * inverse(Transform.getGlobalTransform());
}

void Camera::update(float deltatime, Gamestate & gs)
{
	Transform.m_position = gs.player.trans.getGlobalPosition();
}
