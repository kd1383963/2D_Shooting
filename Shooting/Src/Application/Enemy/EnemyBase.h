#pragma once

class C_Enemy;

class C_EnemyBase
{
public:
	enum MoveCmd
	{
		MCNull,
		Attack,
		Beam,
		Shield,
		Heel
	};

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
		MoveCmd m_MoveCmd;

		Math::Vector2 m_Pos;
		Math::Vector2 m_HpAddPos;
		Math::Vector2 m_IconAddPos;
		Math::Vector2 m_IconNumberAddPos = { 10,-10 };
		Math::Vector2 m_Anim;
		bool m_MoveFlg = false;
		bool m_ShotFlg = false;

		bool m_PosInitOkFlg = true;

		bool AttackDamageFlg = false;
		int  AttackDamage = 0;

		bool m_DamageFlg = false;
		int m_Damage = 0;
		bool m_HealFlg = false;
		int m_Heal = 0;

		int EnemyDrawSort;

	};

	
	C_EnemyBase() {}
	~C_EnemyBase() {}

	virtual void Init()=0;
	void PreInit();
	void Update();
	void Draw();
	void SetTex(KdTexture* enemytex,KdTexture* hpbartex, KdTexture* hpbarbraektex, KdTexture* hpbarbacktex
				,KdTexture* attacktex, KdTexture* beamtex,KdTexture* numbertex,KdTexture* bulletlinetex);

	virtual void Move()=0;

	bool GetMoveFlg() { return m_EnemyStatus.m_MoveFlg; }
	void SetMoveFlg(bool a_flg) { m_EnemyStatus.m_MoveFlg = a_flg; }

	bool GetAlive() { return m_EnemyStatus.m_Alive; }
	Math::Vector2 GetPos() { return m_EnemyStatus.m_Pos; }
	void SetAlive() { m_EnemyStatus.m_Alive = false; }
	int  GetRadius() { return m_EnemyStatus.m_Radius; }

	void HitDamege(int a_Damaege) {
		m_EnemyStatus.m_DamageFlg = true;
		m_EnemyStatus.m_Hp -= a_Damaege;
	}

	void ShotBeam();

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

	KdTexture* m_AttackIconTex;
	KdTexture* m_BeamIconTex;
	Math::Matrix m_IconMat;

	KdTexture* m_BulletLineTex;
	Math::Matrix m_LineMat;
	float m_LineBlinking;
	float m_LineBlinkingAdd;

	KdTexture* m_NumberTex;
	Math::Matrix m_IconScaleMat;
	Math::Matrix m_IconTransMat;
	Math::Matrix m_IconNumber1Mat;
	Math::Matrix m_IconNumber10Mat;
	

	EnemyStatus m_EnemyStatus;



};