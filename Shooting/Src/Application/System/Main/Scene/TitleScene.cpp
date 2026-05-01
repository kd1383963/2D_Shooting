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
	SHADER.m_spriteShader.DrawString(0,0,"int",{0,0,0,0});
}
