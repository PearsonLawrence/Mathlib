#include "spriterenderer.h"
#include "sfwdraw.h"

void SpriteRenderer::draw(const mat3 & camera, const transform & T)
{
	vec2 renderPos = (camera * T.getGlobalTransform()).c[2].xy;
	vec2 renderDims = (camera * vec3{ T.m_scale.x, T.m_scale.y, 1 }).xy;

	mat3 drawMatrix = camera * T.getGlobalTransform() * translate(offset.x, offset.y) * scale(dimensions.x, dimensions.y);

	sfw::drawTextureMatrix3(textureHandle, 0, WHITE, drawMatrix.m);

	//sfw::drawTexture(textureHandle,					// texture
	//				 renderPos.x, renderPos.y,		// position
	//				 renderDims.x, renderDims.y,	// size
	//				 T.getGlobalAngle());			// rotation
}