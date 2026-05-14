#pragma once

enum SkillStatus
{
	TurnAdd,
	UpHp,
	HealHp,
	UpAtk,
	UpBulletWallBound,
	DoubleBullet,
	BulletEnemyBound,
	BulletSplit
};

struct UpGradeStatus
{
	Math::Vector2 m_Pos;
	Math::Matrix  m_Mat;
	SkillStatus	  m__SkillStatus;
	bool		  m_MouseHit;
};

class C_GameScene;

class C_PlayerUpGrade
{
public:
	C_PlayerUpGrade() {}
	~C_PlayerUpGrade() {}

	void Init();
	bool Update();
	void Draw();

	void SetTex(KdTexture* uphptex, KdTexture* healhptex, KdTexture* upatktex, KdTexture* upbwallboundtex,
		KdTexture* updoubletex, KdTexture* enemyboundtex, KdTexture* turnaddtex,
		KdTexture* upgradebulletsplittex,KdTexture* brackback);

	void Setowner(C_GameScene* a_owner) { m_owner = a_owner; }

private:

	C_GameScene* m_owner;

	Math::Matrix m_BrackBackMat;
	KdTexture* m_BrackBackTex;
	
	KdTexture* m_UpGradeHpTex;
	KdTexture* m_HealHpTex;
	KdTexture* m_UpGradeAtkTex;
	KdTexture* m_UpGradeBulletWallBoundTex;
	KdTexture* m_UpGradeDoubleBulletTex;
	KdTexture* m_UpGradeBulletEnemyBoundTex;
	KdTexture* m_UpGradeBulletSplitTex;
	KdTexture* m_TurnAddTex;

	static const int m_Radius = 32;

	static const int UpGradeStatuNum = 3;

	const float m_Scale = 4.0f;
	const float m_ScaleAdd = 1.5f;

	UpGradeStatus   m_UpGradeStatu[UpGradeStatuNum];
	bool			CursorHitFlg[UpGradeStatuNum] = {false,false,false};

	bool ShuffleOkFlg = false;
	

};