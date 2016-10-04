#pragma once

///.000001
bool fequals(float lhs, float rhs);

float deg2rad(float deg);
float rad2deg(float rad);

// basic curving stuff
float linearHalf(float x);

float slowStart(float x);

float fastStart(float x);

float constspeed(float x);

float bouncetop(float x);

float paraFlip(float x);

float lerp(float start, float end, float alpha);

float quadBezier(float start, float mid, float end, float alpha);

float hermitSpline(float start, float s_tan,
                                 	float end, float e_tan, float alpha);
float cardinalSpline(float start, float mid,
	                                float end, float tightness, float alpha);
float catRomSpline(float start, float mid, float end, float alpha);


