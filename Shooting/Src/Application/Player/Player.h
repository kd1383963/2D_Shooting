#pragma once
//#include"PlayerBullet.h"

class C_GameScene;

class C_PlayerBullet;

struct Status
{
	bool	m_PnullFlg = false;
	bool	m_Alive;
	float 	m_Hp;
	float 	m_MaxHp;
	float	m_BreakHp;
	int		m_Atk;
	float alpha = 1.0f;


	Math::Vector2 Pos;
	Math::Vector2 HpAddPos = {0,42};
	Math::Vector2 Anim;
	bool MoveFlg;

	bool m_DamageFlg = false;
	int Damage = 0;
	bool m_HealFlg = false;
	int Heal = 0;
};

struct SkillFlg
{
	int m_BulletBoundFlg;

};

class C_Player
{
public:

	
	~C_Player();

	void Init();
	void Update();
	void Draw();
	void SetTex(KdTexture* playertex,KdTexture* bulletlinetex,
		KdTexture* hpbartex, KdTexture* hpbarbraektex, KdTexture* hpbarbacktex);

	void SetShotFlg(bool a_flg) { m_ShotFlg = a_flg; }

	void HitDamege(int a_Damaege) {
		m_CharaStatus.m_DamageFlg = true;
		m_CharaStatus.m_Hp -= a_Damaege;
	}

	Math::Vector2 GetPos() { return m_CharaStatus.Pos; }

	void HitBulletEnemy();

	void SetHitSkill();




	void Setowner(C_GameScene* owner) { m_owner = owner; }
private:

	C_GameScene* m_owner;

	const float m_MoveSpeed = 10.0f;

	const float m_Radius = 32;

	KdTexture* m_PlayerTex;
	KdTexture* m_BulletLineTex;
	KdTexture* m_HpTex;
	KdTexture* m_HpBackTex;
	KdTexture* m_HpBreakTex;
	
	Math::Matrix m_PlayerMat;
	Math::Matrix m_LineMat;
	Math::Matrix m_HpMat;
	Math::Matrix m_HpBackMat;
	Math::Matrix m_HpBreakMat;

	bool m_ShotFlg;

	float m_LineBlinking;
	float m_LineBlinkingAdd;

	
	SkillFlg PlayerSkill;
	SkillFlg PlayerSkillBase;



	KdTexture m_BulletTex;
	std::vector<std::shared_ptr<C_PlayerBullet>> m_Bullet = {};

	Status m_CharaStatus;

	C_Player();

public:
	static C_Player& GetInstance()
	{
		static C_Player instance;
		return instance;
	}
};



