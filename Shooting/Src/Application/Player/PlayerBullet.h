#pragma once

class C_Enemy;

class C_PlayerBullet
{
public:

	C_PlayerBullet(){}
	~C_PlayerBullet(){}

	void Init();
	void Update();
	void Draw();

	void Shot(Math::Vector2 pos);

	void SetTex(KdTexture* tex);

	bool GetAlive() { return m_Alive;  }

	bool HIT(float x1, float y1, int h1, float x2, float y2, int h2);


	Math::Vector2 Getpos(){}

private:

	const float m_MoveSpeed = 15.0f;

	const float m_Radius = 8;

	float m_Angle;

	KdTexture* m_Tex;
	Math::Vector2 m_Pos;
	Math::Matrix m_Mat;
	
	bool m_Alive;

	C_Enemy* Enemy;
};