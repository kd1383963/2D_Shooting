#include "main.h"
#include "Scene.h"
#include "System/Main/Scene/SceneManager.h"
#include "System/GameState.h"
#include "Mouse.h"

void Scene::Draw2D()
{
	SCENEMANAGER.Draw();
	SHADER.m_spriteShader.SetMatrix(m_CursorMat);
	SHADER.m_spriteShader.DrawTex(&m_CursorTex, Math::Rectangle{ 0,0,32,32 }, 1.0f);
}

void Scene::Update()
{
	m_CursorMat = Math::Matrix::CreateTranslation(C_Mouse::GetInstance().GetMousePos().x,
		C_Mouse::GetInstance().GetMousePos().y, 0);
	if (!GameState::isActive)return;
	SCENEMANAGER.PreUpdate();

	SCENEMANAGER.Update();
}

void Scene::Init()
{
	srand(timeGetTime());
	
	ShowCursor(FALSE);

	m_CursorTex.Load("Texture/UI/Cursor.png");
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

