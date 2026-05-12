#pragma once

class C_EnemyBullet
{
public:

	C_EnemyBullet() { Init(); }
	~C_EnemyBullet() {}

	void Init();
	void Update();
	void Draw();

	void Shot(Math::Vector2 a_pos,Math::Vector2 vec);

	void SetTex(KdTexture* tex);

	bool GetAlive() { return m_Alive; }
	void SetAlive(bool a_flg) { m_Alive = a_flg; }

	bool HIT(Math::Vector2 pos, int hy1,int hx1);





private:


	const float m_MoveSpeed = 24.0f;

	const float m_Radius = 9;

	float m_Angle;

	KdTexture* m_Tex;
	Math::Vector2 m_Pos;
	Math::Vector2 vec;
	Math::Matrix m_Mat;

	bool m_Alive;


};