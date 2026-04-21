#pragma once
class C_Enemy
{
public:

	
	~C_Enemy() {}

	void Init();
	void Update();
	void Draw();
	void SetTex(KdTexture* enemytex);

private:

	const float m_Radius = 32;

	KdTexture* m_EnemyTex;
	Math::Vector2 m_Pos;
	Math::Matrix m_EnemyMat;

	C_Enemy() {}

public:
	static C_Enemy& GetInstance()
	{
		static C_Enemy instance;
		return instance;
	}
};

#define ENEMY C_Enemy::GetInstance()