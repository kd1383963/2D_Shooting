#pragma once



class C_PlayerBullet
{
public:

	C_PlayerBullet() { Init(); }
	~C_PlayerBullet() {}

	void Init();
	void Update();
	void Draw();

	void Shot(Math::Vector2 pos1, Math::Vector2 pos2);

	void MoreShot(Math::Vector2 vec);

	void SetTex(KdTexture* tex);

	bool GetAlive() { return m_Alive; }

	bool HIT(Math::Vector2 pos, int h);

	void HitSkill();

	

private:

	
	const float m_MoveSpeed = 15.0f;

	const float m_Radius = 8;

	float m_Angle;

	KdTexture* m_Tex;
	Math::Vector2 m_Pos;
	Math::Vector2 vec;
	Math::Matrix m_Mat;

	bool m_Alive;

};