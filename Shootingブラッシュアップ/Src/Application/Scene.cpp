#include "main.h"
#include "Scene.h"
#include "System/Main/Scene/SceneManager.h"

void Scene::Draw2D()
{
	SCENEMANAGER.Draw();
	
}

void Scene::Update()
{

	SCENEMANAGER.PreUpdate();

	SCENEMANAGER.Update();
}

void Scene::Init()
{
	srand(timeGetTime());
	
	ShowCursor(FALSE);

	
}


void Scene::Release()
{
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

