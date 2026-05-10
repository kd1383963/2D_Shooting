#include "TitleScene.h"
#include"SceneManager.h"
C_TitleScene::C_TitleScene()
{
	

}

C_TitleScene::~C_TitleScene()
{
	
}

void C_TitleScene::Init()
{
	

}

void C_TitleScene::Update()
{
	if (GetAsyncKeyState(VK_RETURN)&0x8000)
	{
		SCENEMANAGER.SetNextScene(SceneManager::SceneType::Game);
		
	}
}

void C_TitleScene::Draw()
{
	SHADER.m_spriteShader.SetMatrix(Math::Matrix::Identity);
	SHADER.m_spriteShader.DrawString(0, 0, "ŠX‚ğç‚êI–‚•¨‘Ş¡‘åìíI", { 0,0,0,1.0f });
	SCENEMANAGER.DrawEndBegin();
}
