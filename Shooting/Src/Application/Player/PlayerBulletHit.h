#pragma once
class C_PlayerBulletHit
{
public:

	C_PlayerBulletHit() {}
	~C_PlayerBulletHit() {}

	void Init();
	void Update();

	bool HIT(float x1, float y1, int h1, float x2, float y2, int h2);

private:
	
};