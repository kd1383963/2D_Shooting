#include "main.h"
#include "Scene.h"
#include "Player/Player.h"
#include "Enemy/Enemy.h"

void Scene::Draw2D()
{
	PLAYER.Draw();
	ENEMY.Draw();
}

void Scene::Update()
{
	PLAYER.Update();
	ENEMY.Update();
}

void Scene::Init()
{
	srand(timeGetTime());
	PLAYER.Init();
	ENEMY.Init();
	TexLoad();
}

void Scene::TexLoad()
{
	m_PlayerTex.Load("Texture/Player/Player.png");
	m_BulletLineTex.Load("Texture/Player/Line.png");
	PLAYER.SetTex(&m_PlayerTex,&m_BulletLineTex);
	m_EnemyTex.Load("Texture/Enemy/enemy.png");
	ENEMY.SetTex(&m_EnemyTex);

}


void Scene::Release()
{
	m_PlayerTex.Release();
	m_BulletLineTex.Release();
}

void Scene::ImGuiUpdate()
{
	return;

	ImGui::SetNextWindowPos(ImVec2(20, 20), ImGuiSetCond_Once);
	ImGui::SetNextWindowSize(ImVec2(200, 100), ImGuiSetCond_Once);

	// デバッグウィンドウ
	if (ImGui::Begin("Debug Window"))
	{
		ImGui::Text("FPS : %d", APP.m_fps);
	}
	ImGui::End();
}

