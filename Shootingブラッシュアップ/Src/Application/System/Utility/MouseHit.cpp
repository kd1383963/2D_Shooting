#include"MouseHit.h"
#include"../../Mouse.h"

bool C_MouseHit::MouseBlockHit(Math::Vector2 pos, float radiusX, float radiusY)
{

	const float menuRight = pos.x + radiusX;
	const float menuLeft = pos.x - radiusX;
	const float menuTop = pos.y + radiusY;
	const float menuBottom = pos.y - radiusY;

	

	const float x = C_Mouse::GetInstance().GetMousePos().x;
	const float y = C_Mouse::GetInstance().GetMousePos().y;

	if (x< menuRight && x>menuLeft && y< menuTop && y>menuBottom)
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool C_MouseHit::MouseCircleHit(Math::Vector2 pos, float radius,bool halfFlg)
{
	

	if (halfFlg)
	{
		pos.y = pos.y + radius / 2;
	}
	const float x = C_Mouse::GetInstance().GetMousePos().x - pos.x;
	const float y = C_Mouse::GetInstance().GetMousePos().y - pos.y;
	const float z = sqrt(x * x + y * y);

	if (z < radius)
	{
		return true;
	}
	else
	{
		return false;
	}
}
