#include "GameScene.h"
#include "SceneManager.h"
#include "../../../Player/Player.h"
#include "../../../Enemy/Enemy.h"
#include "../../Battle/Turn.h"
#include "../../../Player/PlayerUpGrade.h"

C_GameScene::C_GameScene()
{
	
}

C_GameScene::~C_GameScene()
{
	Release();
}

void C_GameScene::Init()
{
	m_Enemy = std::make_shared<C_Enemy>();
	
	m_PlayerUpGrade = std::make_shared<C_PlayerUpGrade>();

	TexLoad();

	C_Player::GetInstance().Init();

	BattleWave++;

	m_Enemy->Init(2, BattleWave);

	

	C_Player::GetInstance().Setowner(this);

	
	m_PlayerUpGrade->Setowner(this);
	C_Turn::GetInstance().Init();
}

void C_GameScene::Update()
{
	
	
	C_Player::GetInstance().HitBulletEnemy();

	m_Enemy->Update();
	
	C_Player::GetInstance().Update();
	
	C_Turn::GetInstance().Update();

	if (C_Turn::GetInstance().GetNowTurn() == C_Turn::UpGrade)
	{
		if (!m_PlayerUpGradeFlg)
		{
			m_PlayerUpGrade->Init();
			m_PlayerUpGradeFlg = true;
		}
		if (m_PlayerUpGrade->Update())
		{
			if (BattleWave < 3)
			{
				m_Enemy->Init(5, BattleWave);
			}
			else if (BattleWave < 6)
			{
				m_Enemy->Init(9, BattleWave);
			}
			else if (BattleWave < 9)
			{
				m_Enemy->Init(13, BattleWave);
			}
			else
			{
				m_Enemy->Init(18, BattleWave);
			}
			BattleWave++;
			m_PlayerUpGradeFlg = false;
		}
	}
}

void C_GameScene::Draw()
{
	
	C_Player::GetInstance().Draw();
	
	m_Enemy->Draw();
	if (C_Turn::GetInstance().GetNowTurn() == C_Turn::UpGrade)
	{
		m_PlayerUpGrade->Draw();
	}
}

void C_GameScene::TexLoad()
{
	m_PlayerIdleTex.Load("Texture/Player/B_witch_idle.bmp");
	m_PlayerMoveTex.Load("Texture/Player/B_witch_run.bmp");
	m_PlayerAtkTex.Load("Texture/Player/B_witch_attack.bmp");
	m_PlayerHurtTex.Load("Texture/Player/B_witch_take_damage.bmp");
	m_PlayerDeadTex.Load("Texture/Player/B_witch_death.bmp");
	m_PlayerBulletLineTex.Load("Texture/Player/Line.png");
	m_HpTex.Load("Texture/UI/Hp.png");
	m_HpBackTex.Load("Texture/UI/Hpback.png");
	m_HpBreakTex.Load("Texture/UI/-Hp.png");
	C_Player::GetInstance().SetTex(&m_PlayerIdleTex, &m_PlayerMoveTex, &m_PlayerAtkTex,
		&m_PlayerHurtTex, &m_PlayerDeadTex,&m_PlayerBulletLineTex, &m_HpTex, &m_HpBreakTex,&m_HpBackTex);

	m_EnemyIdleTex.Load("Texture/Enemy/IDLE.png");
	m_EnemyAtkTex.Load("Texture/Enemy/ATTACK.png");
	m_EnemyHurtTex.Load("Texture/Enemy/HURT.png");
	m_EnemyDeadTex.Load("Texture/Enemy/DEATH.png");
	m_AttackIconTex.Load("Texture/UI/AttackIcon.png");
	m_BeamIconTex.Load("Texture/UI/BeamIcon.png");
	m_NumberTex.Load("Texture/UI/DNumber.png");
	m_EnemyBulletLineTex.Load("Texture/Enemy/Line.png");
	m_EnemyBulletTex.Load("Texture/Enemy/EnemyBullet.png");
	m_AtkExpTex.Load("Texture/Enemy/Exp.png");

	m_Enemy->GiftTex(&m_EnemyIdleTex, &m_EnemyAtkTex, &m_EnemyHurtTex, &m_EnemyDeadTex, &m_HpTex, &m_HpBreakTex, &m_HpBackTex, &m_AttackIconTex,
		&m_BeamIconTex, &m_NumberTex, &m_EnemyBulletLineTex, &m_EnemyBulletTex,&m_AtkExpTex);
	
	m_BrackBackTex.Load("Texture/UI/Fade.png");
	m_UpGradeHpTex.Load("Texture/UI/HpUp.png");
	m_UpGradeAtkTex.Load("Texture/UI/AtkUp.png");
	m_UpGradeBulletWallBoundTex.Load("Texture/UI/BulletWallBound.png");
	m_UpGradeDoubleBulletTex.Load("Texture/UI/DoubleBullet.png");
	m_UpGradeBulletEnemyBoundTex.Load("Texture/UI/EnemyBound.png");
	m_UpGradeBulletSplitTex.Load("Texture/UI/BulletSplit.png");
	m_TurnAddTex.Load("Texture/UI/TurnAdd.png");
	
	m_PlayerUpGrade->SetTex(&m_UpGradeHpTex,&m_UpGradeAtkTex,&m_UpGradeBulletWallBoundTex,
		&m_UpGradeDoubleBulletTex,&m_UpGradeBulletEnemyBoundTex,&m_TurnAddTex,
		&m_UpGradeBulletSplitTex ,&m_BrackBackTex);

}

void C_GameScene::Release()
{
	m_PlayerIdleTex.Release();
	m_PlayerMoveTex.Release();
	m_PlayerAtkTex.Release();
	m_PlayerHurtTex.Release();
	m_PlayerDeadTex.Release();
	m_PlayerBulletLineTex.Release();
	m_EnemyIdleTex.Release();
	m_EnemyAtkTex.Release();
	m_EnemyHurtTex.Release();
	m_EnemyDeadTex.Release();
	m_HpTex.Release();
	m_HpBackTex.Release();
	m_HpBreakTex.Release();
	m_AttackIconTex.Release();
	m_BeamIconTex.Release();
	m_NumberTex.Release();
	m_EnemyBulletLineTex.Release();
	m_BrackBackTex.Release();
	m_UpGradeHpTex.Release();
	m_UpGradeAtkTex.Release();
	m_UpGradeBulletWallBoundTex.Release();
	m_UpGradeDoubleBulletTex.Release();
	m_UpGradeBulletEnemyBoundTex.Release();
	m_UpGradeBulletSplitTex.Release();
	m_TurnAddTex.Release();
}
