#pragma once

#include "PlayerSkill.h" //enumÇBulletÇ∆ã§óLÇ™ÇµÇΩÇ¢ÇΩÇﬂÇ…include
class C_GameScene;

class C_PlayerBullet;

enum AnimStatus
{
	Move,
	Atk,
	Hurt,
	Dead,
};

struct Status
{
	bool	m_PnullFlg = false;
	bool	m_Alive;
	float 	m_Hp;
	float 	m_MaxHp;
	float	m_BreakHp;
	int		m_Atk;
	float alpha = 1.0f;

	AnimStatus m_AnimStatus;
	Math::Vector2 Pos;
	Math::Vector2 HpAddPos = {0,42};
	Math::Vector2 Anim;
	bool MoveFlg;

	bool m_AtkFlg = false;

	bool m_DamageFlg = false;
	int Damage = 0;
	bool m_HealFlg = false;
	int Heal = 0;

	float offset = 0.3f; // ç∂âEÇ…çLÇ∞ÇÈäpìx
};


class C_Player
{
public:

	
	~C_Player();

	void Init();
	void Update();
	void Draw();
	void SetTex(KdTexture* playeridletex, KdTexture* playermovetex, KdTexture* playeratktex, 
		KdTexture* playerhurttex, KdTexture* playerdeadtex, KdTexture* bulletlinetex,
		KdTexture* hpbartex, KdTexture* hpbarbraektex, KdTexture* hpbarbacktex);

	void SetShotFlg(bool a_flg) { m_ShotFlg = a_flg; }

	void HitDamege(int a_Damaege) {
		m_CharaStatus.m_DamageFlg = true;
		m_CharaStatus.m_Hp -= a_Damaege;
		SetAnimStatus(Hurt);
	}

	Math::Vector2 GetPos() { return m_CharaStatus.Pos; }

	void HitBulletEnemy();

	
	Math::Vector2 Rotate(Math::Vector2& v, float angle);
	
	void TotalScorePlus() { TotalScore++; }

	int GetTotalScore() { return TotalScore; }

	void HpUp() { m_CharaStatus.m_MaxHp += 20; }
	void AtkUp() { m_CharaStatus.m_Atk += 10; }
	void AddBulletShot() { PlayerSkillBase.m_DoubleShot++; }
	void AddWallbounce() { PlayerSkillBase.m_WallbounceLeft++; }
	void AddEnemyBounce() { PlayerSkillBase.m_BulletEnemyBoundFlg++; }
	void SetShot3way() { PlayerSkillBase.Shot3way = true; }
	void SetShot5way() { PlayerSkillBase.Shot5way = true; }

	bool GetShot3way() { return PlayerSkillBase.Shot3way; }
	bool GetShot5way() { return PlayerSkillBase.Shot5way; }

	bool GetAlive()  { return m_CharaStatus.m_Alive; }
	int  GetWidth()  { return CharaWidth; }
	int  GetHegiht() { return CharaHeight; }

	void SetCanMove(bool a_flg) { m_CanMoveFlg = a_flg; }

	void SetAnimStatus(AnimStatus a_status) {
		m_CharaStatus.m_AnimStatus = a_status;
		switch (m_CharaStatus.m_AnimStatus)
		{
		case Move:
		case Hurt:
		case Dead:
			CharaWidth = 32;
			CharaHeight = 48;
			break;
		case Atk:
			CharaWidth = 32;
			CharaHeight = 46;
			break;

		}
		CharaAnimCnt = 0.0f;
	}

	void Setowner(C_GameScene* owner) { m_owner = owner; }
private:

	C_GameScene* m_owner;

	Math::Vector2 m_ShotVec;
	float		  m_ShotAngle;

	bool m_CanMoveFlg;

	int TotalScore;

	const float m_MoveSpeed = 10.0f;

	const float m_Radius = 32;

	int CharaWidth = 32;
	int CharaHeight = 48;

	float CharaAnimCnt;
	KdTexture* m_PlayerIdleTex;
	KdTexture* m_PlayerMoveTex;
	KdTexture* m_PlayerAtkTex;
	KdTexture* m_PlayerHurtTex;
	KdTexture* m_PlayerDeadTex;
	KdTexture* m_BulletLineTex;
	KdTexture* m_HpTex;
	KdTexture* m_HpBackTex;
	KdTexture* m_HpBreakTex;
	
	Math::Matrix m_PlayerScaleMat;
	Math::Matrix m_PlayerMat;
	Math::Matrix m_Line1Mat;
	Math::Matrix m_Line2Mat;
	Math::Matrix m_Line3Mat;
	Math::Matrix m_Line4Mat;
	Math::Matrix m_Line5Mat;
	Math::Matrix m_HpMat;
	Math::Matrix m_HpBackMat;
	Math::Matrix m_HpBreakMat;

	bool m_ShotFlg;

	float m_LineBlinking;
	float m_LineBlinkingAdd;

	int ShotWait;
	int MultiShotCnt;
	
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



