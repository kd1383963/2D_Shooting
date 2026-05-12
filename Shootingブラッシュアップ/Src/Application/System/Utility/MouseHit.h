#pragma once

class C_Option;

class C_MouseHit
{
public:

	~C_MouseHit() {}

	bool MouseBlockHit(Math::Vector2 pos,float radiusX,float radiusY);

	bool MouseCircleHit(Math::Vector2	pos,
						float			radius,
						bool			HalfFlg);//”¼‰~‚©‚Ç‚¤‚©

private:

public:
	static C_MouseHit& GetInstance()
	{
		static C_MouseHit instance;
		return instance;
	}
};

#define MOUSEHIT C_MouseHit::GetInstance()