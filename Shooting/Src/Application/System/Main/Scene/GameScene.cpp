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

	m_Enemy->Init();

	

	C_Player::GetInstance().Setowner(this);

	

	C_Turn::GetInstance().Init();
}

void C_GameScene::Update()
{
	C_Player::GetInstance().Update();
	
	m_Enemy->Update();
	
	C_Player::GetInstance().HitBulletEnemy();
	C_Turn::GetInstance().Update();
}

void C_GameScene::Draw()
{
	
	C_Player::GetInstance().Draw();
	
	m_Enemy->Draw();
	
}

void C_GameScene::TexLoad()
{
	m_PlayerTex.Load("Texture/Player/Player.png");
	m_BulletLineTex.Load("Texture/Player/Line.png");
	m_HpTex.Load("Texture/UI/Hp.png");
	m_HpBackTex.Load("Texture/UI/Hpback.png");
	m_HpBreakTex.Load("Texture/UI/-Hp.png");
	C_Player::GetInstance().SetTex(&m_PlayerTex, &m_BulletLineTex, &m_HpTex, &m_HpBreakTex,&m_HpBackTex);
	m_EnemyTex.Load("Texture/Enemy/enemy.png");
	
	m_Enemy->GiftTex(&m_EnemyTex,&m_HpTex, &m_HpBreakTex, &m_HpBackTex);
	

}

void C_GameScene::Release()
{
	m_PlayerTex.Release();
	m_BulletLineTex.Release();
	m_EnemyTex.Release();
	m_HpTex.Release();
	m_HpBackTex.Release();
	m_HpBreakTex.Release();
}
