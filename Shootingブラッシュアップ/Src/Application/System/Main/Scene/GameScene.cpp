#include "GameScene.h"
#include "SceneManager.h"
#include "../../../Player/Player.h"
#include "../../../Enemy/Enemy.h"
#include "../../Battle/Turn.h"
#include "../../../Player/PlayerUpGrade.h"
#include "../../Audio.h"

C_GameScene::C_GameScene()
{
	
}

C_GameScene::~C_GameScene()
{
	Release();
}

void C_GameScene::Init()
{
	C_Audio::GetInstans().AddBgm("Asset/Sound/Battle1.wav", bgm );

	m_Enemy = std::make_shared<C_Enemy>();
	
	m_PlayerUpGrade = std::make_shared<C_PlayerUpGrade>();

	TexLoad();

	C_Player::GetInstance().Init();

	

	m_Enemy->Init(2, BattleWave);

	BattleWave++;

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
			if (BattleWave < 4)
			{
				m_Enemy->Init(5, BattleWave);
				BattleWave++;
				m_PlayerUpGradeFlg = false;
			}
			else if (BattleWave < 7)
			{
				m_Enemy->Init(8, BattleWave);
				BattleWave++;
				m_PlayerUpGradeFlg = false;
			}
			else if (BattleWave < 11)
			{
				m_Enemy->Init(11, BattleWave);
				BattleWave++;
				m_PlayerUpGradeFlg = false;
			}
			else 
			{
				m_Enemy->Init(13, BattleWave);
				BattleWave++;
				m_PlayerUpGradeFlg = false;
			}
		}
	}
}

void C_GameScene::Draw()
{
	
	C_Player::GetInstance().Draw();
	
	m_Enemy->Draw();

	C_Player::GetInstance().MiniUpDraw();

	if (C_Turn::GetInstance().GetNowTurn() == C_Turn::UpGrade)
	{
		m_PlayerUpGrade->Draw();
	}
}

void C_GameScene::TexLoad()
{
	m_BrackBackTex.Load("Asset/Texture/UI/Fade.png");
	m_UpGradeHpTex.Load("Asset/Texture/UI/HpUp.png");
	m_UpGradeAtkTex.Load("Asset/Texture/UI/AtkUp.png");
	m_UpGradeBulletWallBoundTex.Load("Asset/Texture/UI/BulletWallBound.png");
	m_UpGradeDoubleBulletTex.Load("Asset/Texture/UI/DoubleBullet.png");
	m_UpGradeBulletEnemyBoundTex.Load("Asset/Texture/UI/EnemyBound.png");
	m_UpGradeBulletSplitTex.Load("Asset/Texture/UI/BulletSplit.png");
	m_TurnAddTex.Load("Asset/Texture/UI/TurnAdd.png");
	m_HealHpTex.Load("Asset/Texture/UI/Heal.png");
	m_NumberTex.Load("Asset/Texture/UI/DNumber.png");
	m_CrossTex.Load("Asset/Texture/UI/Cross.png");

	m_PlayerUpGrade->SetTex(&m_UpGradeHpTex,&m_HealHpTex,&m_UpGradeAtkTex, &m_UpGradeBulletWallBoundTex,
		&m_UpGradeDoubleBulletTex, &m_UpGradeBulletEnemyBoundTex, &m_TurnAddTex,
		&m_UpGradeBulletSplitTex, &m_BrackBackTex);

	m_PlayerMoveTex.Load("Asset/Texture/Player/B_witch_run.bmp");
	m_PlayerAtkTex.Load("Asset/Texture/Player/B_witch_attack.bmp");
	m_PlayerHurtTex.Load("Asset/Texture/Player/B_witch_take_damage.bmp");
	m_PlayerDeadTex.Load("Asset/Texture/Player/B_witch_death.bmp");
	m_PlayerBulletLineTex.Load("Asset/Texture/Player/Line.png");
	m_HpTex.Load("Asset/Texture/UI/Hp.png");
	m_HpBackTex.Load("Asset/Texture/UI/Hpback.png");
	m_HpBreakTex.Load("Asset/Texture/UI/-Hp.png");
	m_HpNumBerTex.Load("Asset/Texture/UI/ber.png");
	m_PlayerCanMoveTex.Load("Asset/Texture/Player/CanMove.png");
	C_Player::GetInstance().SetTex( &m_PlayerMoveTex, &m_PlayerAtkTex,
		&m_PlayerHurtTex, &m_PlayerDeadTex,&m_PlayerBulletLineTex, &m_HpTex, &m_HpBreakTex,&m_HpBackTex,
		&m_UpGradeBulletWallBoundTex,&m_UpGradeDoubleBulletTex, &m_UpGradeBulletEnemyBoundTex,
		&m_UpGradeBulletSplitTex,&m_NumberTex,&m_HpNumBerTex,&m_BrackBackTex,&m_CrossTex,&m_PlayerCanMoveTex);

	m_EnemyIdleTex.Load("Asset/Texture/Enemy/IDLE.png");
	m_EnemyAtkTex.Load("Asset/Texture/Enemy/ATTACK.png");
	m_EnemyHurtTex.Load("Asset/Texture/Enemy/HURT.png");
	m_EnemyDeadTex.Load("Asset/Texture/Enemy/DEATH.png");
	m_AttackIconTex.Load("Asset/Texture/UI/AttackIcon.png");
	m_BeamIconTex.Load("Asset/Texture/UI/BeamIcon.png");
	m_EnemyBulletLineTex.Load("Asset/Texture/Enemy/Line.png");
	m_EnemyBulletTex.Load("Asset/Texture/Enemy/EnemyBullet.png");
	m_AtkExpTex.Load("Asset/Texture/Enemy/Exp.png");

	m_Enemy->GiftTex(&m_EnemyIdleTex, &m_EnemyAtkTex, &m_EnemyHurtTex, &m_EnemyDeadTex, &m_HpTex, &m_HpBreakTex, &m_HpBackTex, &m_AttackIconTex,
		&m_BeamIconTex, &m_NumberTex, &m_EnemyBulletLineTex, &m_EnemyBulletTex,&m_AtkExpTex,&m_HpNumBerTex);
	
	

}

void C_GameScene::Release()
{
	
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
	m_AtkExpTex.Release();
	m_HpNumBerTex.Release();
}
