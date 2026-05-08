#pragma once

class C_Enemy;

class C_EnemyBase
{
public:
	struct EnemyStatus
	{
		//bool	m_EnullFlg = false;
		bool	m_Alive;
		float 	m_Hp;
		float 	m_MaxHp;
		float	m_BreakHp;
		int		m_Atk;
		float alpha = 1.0f;
		float m_Radius = 32;

		Math::Vector2 m_Pos;
		Math::Vector2 m_HpAddPos = { 0,42 };
		Math::Vector2 m_Anim;
		bool m_MoveFlg;

		bool m_PosInitOkFlg = true;

		bool m_DamageFlg = false;
		int m_Damage = 0;
		bool m_HealFlg = false;
		int m_Heal = 0;

		int EnemyDrawSort;

	};
	C_EnemyBase() {}
	~C_EnemyBase() {}

	virtual void Init()=0;
	void Update();
	void Draw();
	void SetTex(KdTexture* enemytex,KdTexture* hpbartex, KdTexture* hpbarbraektex, KdTexture* hpbarbacktex);

	virtual void Move()=0;

	bool GetAlive() { return m_EnemyStatus.m_Alive; }
	Math::Vector2 GetPos() { return m_EnemyStatus.m_Pos; }
	void SetAlive() { m_EnemyStatus.m_Alive = false; }
	int  GetRadius() { return m_EnemyStatus.m_Radius; }

	void Setowner(C_Enemy* owner) { m_owner = owner; }

protected:

	
	C_Enemy* m_owner;


	KdTexture* m_EnemyTex;
	Math::Matrix m_EnemyMat;
	KdTexture* m_HpTex;
	KdTexture* m_HpBackTex;
	KdTexture* m_HpBreakTex;
	Math::Matrix m_HpMat;
	Math::Matrix m_HpBackMat;
	Math::Matrix m_HpBreakMat;

	EnemyStatus m_EnemyStatus;



};