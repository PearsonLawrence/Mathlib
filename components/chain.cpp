#include "chain.h"
#include "gamestate.h"
Chain::Chain()
{
	
	trans.m_scale = vec2{ 3,1 };


	renderer.offset = { 0,.5f };
	renderer.dimensions = { 1,1 };
	

	renderer.textureHandle = sfw::loadTextureMap("./res/attack6.png");

	vec2 hullvrts[] = { { -.1, 0 },
						{ .1, 0 },
						{ .1, 1 },
						{ -.1, 1 } };

	collider = Collider(hullvrts, 4);
}

/*
0-0-1
1-1-2
2-2-3

*/
void Chain::update(float deltatime, Gamestate & gs)
{
	int i = id;

	a = gs.bullet[i].trans.getGlobalPosition();
	b = gs.bullet[i+1].trans.getGlobalPosition();

		if (gs.bullet[i].isactive == true && gs.bullet[i + 1].isactive == true)
		{
			chainactive = true;
			
		}
		else	
	{
			chainactive = false;
			trans.m_position = { 0,0 };
			trans.m_scale.y = 0;
			trans.m_facing = 0;
	}	
		if (chainactive == true)
		{

			//vec2 hullvrts[] = { { a.x - .5 , a.y  },
			//					{ a.x + .5 , a.y  },
			//					{ b.x + .5 , b.y  },
			//					{ b.x - .5 , b.y  } };

			//collider = Collider(hullvrts, 4);

			trans.m_position = b;
			trans.m_scale.y = magnitude(a - b);
			trans.m_facing = -angle(a - b);


			//rigidbody.integrate(trans, deltatime);
			//loco.integrate(trans, rigidbody, deltatime);
		}
}

void Chain::draw(const mat3 & camera)
{
	if (chainactive == true)
	{
		//collider.DebugDraw(camera, trans);
		renderer.draw(camera, trans);
	}

	a = (camera * vec3{ a.x,a.y,1 }).xy;
	b = (camera * vec3{ b.x,b.y,1 }).xy;

	
}

//	H     H		IIIIII
//	H	  H		  II
//	H	  H		  II
//	HHHHHHH		  II
//	H	  H		  II
//  H	  H		  II
//	H	  H		IIIIII