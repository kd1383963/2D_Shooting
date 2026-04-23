#pragma once
class C_Enemy
{
public:

	C_Enemy() {}
	~C_Enemy() {}

	void Init();
	void Update();
	void Draw();
	void SetTex(KdTexture* enemytex);

	bool GetAlive() { return m_Alive; }
	Math::Vector2 GetPos() { return m_Pos; }
	void SetAlive() { m_Alive = false; }

private:

	const float m_Radius = 32;

	KdTexture* m_EnemyTex;
	Math::Vector2 m_Pos;
	Math::Matrix m_EnemyMat;

	bool m_Alive;


};

