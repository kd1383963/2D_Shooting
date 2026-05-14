#pragma once

class C_Enemy;

class C_EnemyBullet;

class C_GameScene;

enum EAnimStatus
{
	EStart,
	EIdle,
	EAtk,
	EHurt,
	EDead,
};

class C_EnemyBase
{
public:
	enum MoveCmd
	{
		MCNull,
		Attack,
		Beam,
		Beam3,
		Beam5,
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

		bool AtkFlg = false;

		bool AttackDamageFlg = false;
		int  AttackDamage = 0;

		int m_DeadTexWidthMax;

		bool m_DeadFlg = false;

		bool m_DamageFlg = false;
		int m_Damage = 0;
		bool m_HealFlg = false;
		int m_Heal = 0;

		int EnemyDrawSort;
		float offset = 0.3f; // ç∂âEÇ…çLÇ∞ÇÈäpìx
		EAnimStatus m_EAnimStatus;
	};

	
	C_EnemyBase() {}
	~C_EnemyBase() {}

	virtual void Init(int wave, int num)=0;
	void PreInit();
	void Update();
	void Draw();
	void SetTex(KdTexture* enemyidletex, KdTexture* enemyatktex, KdTexture* enemyhurttex, KdTexture* enemydeadtex,
		KdTexture* hpbartex, KdTexture* hpbarbraektex, KdTexture* hpbarbacktex
		, KdTexture* attacktex, KdTexture* beamtex, KdTexture* numbertex, KdTexture* bulletlinetex
		, KdTexture* bullettex,KdTexture* atkexptex,KdTexture* m_hpbertex);
	virtual void Move()=0;

	bool GetMoveFlg() { return m_EnemyStatus.m_MoveFlg; }
	void SetMoveFlg(bool a_flg) { m_EnemyStatus.m_MoveFlg = a_flg; }

	bool GetAlive() { return m_EnemyStatus.m_Alive; }
	bool GetDead() { return m_EnemyStatus.m_DeadFlg; }
	Math::Vector2 GetPos() { return m_EnemyStatus.m_Pos; }
	void SetAlive();
	int  GetRadius() { return m_EnemyStatus.m_Radius; }

	void HitDamege(int a_Damaege) {
		m_EnemyStatus.m_DamageFlg = true;
		m_EnemyStatus.m_Hp -= a_Damaege;
		SetEAnimStatus(EHurt);
		if (m_EnemyStatus.m_Hp <= 0)
		{
			m_EnemyStatus.m_Alive = false;
			SetEAnimStatus(EDead);
		}
	}

	void SetEAnimStatus(EAnimStatus a_status) { m_EnemyStatus.m_EAnimStatus = a_status;
												CharaAnimCnt = 0.0f;}

	void BulletTotalMainer() { m_BulletTotal--; }

	void ShotBeam();

	void ShootWay(int a_way);

	Math::Vector2 Rotate(Math::Vector2& v, float angle);

	void BulletHitPlayer();

	void Setowner(C_Enemy* owner) { m_owner = owner; }

	void SetAttackFlg() {
		m_EnemyStatus.m_MoveFlg = false;
		m_EnemyStatus.m_ShotFlg = false;
	}

	virtual void SetAttackCmd() = 0;
protected:

	int CharaWidth = 81;
	int CharaHeight = 71;

	float CharaAnimCnt;
	
	C_Enemy* m_owner;

	static const int NumberWidth = 64;

	KdTexture* m_EnemyIdleTex;
	KdTexture* m_EnemyAtkTex;
	KdTexture* m_EnemyHurtTex;
	KdTexture* m_EnemyDeadTex;
	Math::Matrix m_EnemyMat;
	KdTexture* m_HpTex;
	KdTexture* m_HpBackTex;
	KdTexture* m_HpBreakTex;
	Math::Matrix m_HpMat;
	Math::Matrix m_HpBackMat;
	Math::Matrix m_HpBreakMat;

	float m_IconScale  = 0.8f;
	KdTexture* m_AttackIconTex;
	KdTexture* m_BeamIconTex;
	Math::Matrix m_IconMat;

	KdTexture* m_AtkExpTex;
	Math::Matrix m_AtkExpMat;
	float  m_AtkExpAnimCnt;
	int	 m_AtkExpAnimDia = 128;
	bool m_AtkExpFlg = false;

	KdTexture* m_BulletTex;
	Math::Matrix m_BulletMat;
	KdTexture* m_BulletLineTex;
	Math::Matrix m_Line1Mat;
	Math::Matrix m_Line2Mat;
	Math::Matrix m_Line3Mat;
	Math::Matrix m_Line4Mat;
	Math::Matrix m_Line5Mat;
	float m_LineBlinking;
	float m_LineBlinkingAdd;
	Math::Vector2 m_Vec;
	std::vector<std::shared_ptr<C_EnemyBullet>> m_EnemyBullet;

	int m_BulletTotal = 0;

	KdTexture* m_NumberTex;
	Math::Matrix m_IconScaleMat;
	Math::Matrix m_IconTransMat;
	Math::Matrix m_IconNumber1Mat;
	Math::Matrix m_IconNumber10Mat;
	Math::Matrix m_IconNumber100Mat;
	
	KdTexture* m_HpNumTex;
	KdTexture* m_HpBerTex;

	Math::Vector2 AddHpNumPos = { -10, -16 };

	bool m_NowHp100Flg;
	bool m_NowHp10Flg;
	bool m_MaxHp100Flg;
	float m_HpNumScale = 0.2f;
	Math::Matrix m_HpMax1Mat;
	Math::Matrix m_HpMax10Mat;
	Math::Matrix m_HpMax100Mat;
	Math::Matrix m_HpBerMat;
	Math::Matrix m_NowHp1Mat;
	Math::Matrix m_NowHp10Mat;
	Math::Matrix m_NowHp100Mat;

	EnemyStatus m_EnemyStatus;

	

};