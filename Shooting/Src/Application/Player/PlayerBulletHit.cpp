#include"PlayerBulletHit.h"

bool C_PlayerBulletHit::HIT(float x1, float y1, int h1, float x2, float y2, int h2)
{
	float a = x1 - x2;    //’ê•Ó
	float b = y1 - y2;    //‚‚³
	float c = sqrt(a * a + b * b);
	if (c < h1 + h2) {
		return (1);
	}
}