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

	int  GetNum() { return EnemyNum; }
	bool GetAlive(int i) { return m_Alive[i]; }
	Math::Vector2 GetPos(int i) { return m_Pos[i]; }
	void SetAlive(int i) { m_Alive[i] = false; }
	int  GetRadius() { return m_Radius; }
private:

	const float m_Radius = 32;

	static const int EnemyNum = 5;

	KdTexture* m_EnemyTex;
	Math::Vector2 m_Pos[EnemyNum];
	Math::Matrix m_EnemyMat[EnemyNum];

	bool m_Alive[EnemyNum];

	bool m_MoveFlg[EnemyNum];


};

