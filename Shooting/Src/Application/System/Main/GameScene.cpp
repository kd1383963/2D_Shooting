#include "GameScene.h"
#include "SceneManager.h"
#include "../../Player/Player.h"
#include "../../Enemy/Enemy.h"

C_GameScene::C_GameScene()
{
	
}

C_GameScene::~C_GameScene()
{
	Release();
	delete Enemy;
}

void C_GameScene::Init()
{
	
	PLAYER.Init();
	
	Enemy = new C_Enemy;
	Enemy->Init();

	TexLoad();
}

void C_GameScene::Update()
{
	PLAYER.Update();
	Enemy->Update();
	
}

void C_GameScene::Draw()
{
	
	PLAYER.Draw();
	Enemy->Draw();
}

void C_GameScene::TexLoad()
{
	m_PlayerTex.Load("Texture/Player/Player.png");
	m_BulletLineTex.Load("Texture/Player/Line.png");
	PLAYER.SetTex(&m_PlayerTex, &m_BulletLineTex);
	m_EnemyTex.Load("Texture/Enemy/enemy.png");
	Enemy->SetTex(&m_EnemyTex);

}

void C_GameScene::Release()
{
	m_PlayerTex.Release();
	m_BulletLineTex.Release();
	m_EnemyTex.Release();
}
