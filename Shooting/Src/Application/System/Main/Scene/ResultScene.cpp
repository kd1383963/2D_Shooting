#include "ResultScene.h"
#include"SceneManager.h"
C_ResultScene::C_ResultScene()
{


}

C_ResultScene::~C_ResultScene()
{

}

void C_ResultScene::Init()
{


}

void C_ResultScene::Update()
{
	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		SCENEMANAGER.SetNextScene(SceneManager::SceneType::Title);

	}
}

void C_ResultScene::Draw()
{
	SHADER.m_spriteShader.SetMatrix(Math::Matrix::Identity);
	SHADER.m_spriteShader.DrawString(0, 0, "‚¨‚Â‚©‚ê‚³‚Ü", { 0,0,0,1.0f });
	SCENEMANAGER.DrawEndBegin();
}
