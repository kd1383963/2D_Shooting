#include "GameScene.h"
#include "SceneManager.h"
#include "../../../Player/Player.h"
#include "../../../Enemy/Enemy.h"
#include "../../Battle/Turn.h"

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
	
	TexLoad();

	C_Player::GetInstance().Init();

	m_Enemy->Init(5);

	

	C_Player::GetInstance().Setowner(this);

	

	C_Turn::GetInstance().Init();
}

void C_GameScene::Update()
{
	
	
	C_Player::GetInstance().HitBulletEnemy();

	m_Enemy->Update();
	
	C_Player::GetInstance().Update();
	
	C_Turn::GetInstance().Update();
}

void C_GameScene::Draw()
{
	
	C_Player::GetInstance().Draw();
	
	m_Enemy->Draw();
	
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

	m_Enemy->GiftTex(&m_EnemyIdleTex,&m_EnemyAtkTex ,&m_EnemyHurtTex,&m_EnemyDeadTex,&m_HpTex, &m_HpBreakTex, &m_HpBackTex,&m_AttackIconTex,
		&m_BeamIconTex ,&m_NumberTex,&m_EnemyBulletLineTex,&m_EnemyBulletTex);
	

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
}
