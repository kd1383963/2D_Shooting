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
		SCENEMANAGER.ChangeState(new C_GameScene);
		
	}
}

void C_TitleScene::Draw()
{
	
}
