#pragma once

#include"State.h"

enum GameStage
{
	Normal,
	Hard,
	VeryHard
};
enum GameFadeType
{
	GFade_no,
	GFade_out,
	GFade_in
};
class C_PlayerUpGrade;

class C_Enemy;



class C_GameScene :public C_State
{
public:

	C_GameScene();
	~C_GameScene();

	void Init()override;
	void Update()override;
	void Draw()override;

	void Release();

	void TexLoad();

	GameStage GetBattleStage() { return BattleStage; }

	std::shared_ptr<C_Enemy> GetEnemy() { return m_Enemy; }

private:

	int BattleWave = 0;
	GameStage BattleStage = Normal;

	KdTexture m_PlayerIdleTex;
	KdTexture m_PlayerMoveTex;
	KdTexture m_PlayerAtkTex;
	KdTexture m_PlayerHurtTex;
	KdTexture m_PlayerDeadTex;
	KdTexture m_PlayerBulletLineTex;

	KdTexture m_EnemyIdleTex;
	KdTexture m_EnemyAtkTex;
	KdTexture m_EnemyHurtTex;
	KdTexture m_EnemyDeadTex;
	KdTexture m_AtkExpTex;

	KdTexture m_HpTex;
	KdTexture m_HpBackTex;
	KdTexture m_HpBreakTex;
	KdTexture m_HpNumBerTex;

	KdTexture m_AttackIconTex;
	KdTexture m_BeamIconTex;
	KdTexture m_NumberTex;

	KdTexture m_EnemyBulletLineTex;
	KdTexture m_EnemyBulletTex;
	
	KdTexture m_BrackBackTex;
	KdTexture m_UpGradeHpTex;
	KdTexture m_UpGradeAtkTex;
	KdTexture m_UpGradeBulletWallBoundTex;
	KdTexture m_UpGradeDoubleBulletTex;
	KdTexture m_UpGradeBulletEnemyBoundTex;
	KdTexture m_UpGradeBulletSplitTex;
	KdTexture m_TurnAddTex;
	KdTexture m_HealHpTex;

	
	GameFadeType m_FadeType = GFade_no;
	float FadeAlpha = 0.0f;
	KdTexture BrackTex;
	Math::Matrix m_BrackMat;

	std::shared_ptr<C_Enemy> m_Enemy=nullptr;
	
	std::shared_ptr<C_PlayerUpGrade> m_PlayerUpGrade = nullptr;
	bool m_PlayerUpGradeFlg = false;

	std::shared_ptr<KdSoundEffect> bgm;
};