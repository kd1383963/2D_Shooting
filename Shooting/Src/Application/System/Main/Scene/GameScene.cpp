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
	m_PlayerTex.Load("Texture/Player/B_witch_idle.bmp");
	m_PlayerBulletLineTex.Load("Texture/Player/Line.png");
	m_HpTex.Load("Texture/UI/Hp.png");
	m_HpBackTex.Load("Texture/UI/Hpback.png");
	m_HpBreakTex.Load("Texture/UI/-Hp.png");
	C_Player::GetInstance().SetTex(&m_PlayerTex, &m_PlayerBulletLineTex, &m_HpTex, &m_HpBreakTex,&m_HpBackTex);
	m_EnemyTex.Load("Texture/Enemy/enemy.png");
	m_AttackIconTex.Load("Texture/UI/AttackIcon.png");
	m_BeamIconTex.Load("Texture/UI/BeamIcon.png");
	m_NumberTex.Load("Texture/UI/DNumber.png");
	m_EnemyBulletLineTex.Load("Texture/Enemy/Line.png");
	m_EnemyBulletTex.Load("Texture/Enemy/EnemyBullet.png");

	m_Enemy->GiftTex(&m_EnemyTex,&m_HpTex, &m_HpBreakTex, &m_HpBackTex,&m_AttackIconTex, 
		&m_BeamIconTex ,&m_NumberTex,&m_EnemyBulletLineTex,&m_EnemyBulletTex);
	

}

void C_GameScene::Release()
{
	m_PlayerTex.Release();
	m_PlayerBulletLineTex.Release();
	m_EnemyTex.Release();
	m_HpTex.Release();
	m_HpBackTex.Release();
	m_HpBreakTex.Release();
	m_AttackIconTex.Release();
	m_BeamIconTex.Release();
	m_NumberTex.Release();
	m_EnemyBulletLineTex.Release();
}
