#include "TitleScene.h"
#include"SceneManager.h"
#include"../../Utility/KeyManager.h"
C_TitleScene::C_TitleScene()
{
	

}

C_TitleScene::~C_TitleScene()
{
	
}

void C_TitleScene::Init()
{

	m_Alufa = 1.0f;
	m_TitleTex.Load("Texture/UI/Title.png");
	m_StartCmdTex.Load("Texture/UI/StartCmd.png");
}

void C_TitleScene::Update()
{
	m_Alufa -= m_AlufaAdd;
	if (m_Alufa > 1.0f || m_Alufa < 0.3f)
	{
		m_AlufaAdd *= -1;
	}
	if (C_KeyManager::GetInstance().GetSpaceKey())
	{
		SCENEMANAGER.SetNextScene(SceneManager::SceneType::Game);
		
	}
	m_TitleMat = Math::Matrix::CreateTranslation(m_TitlePos.x, m_TitlePos.y, 0);
	m_StartCmdMat = Math::Matrix::CreateScale(0.5f, 0.5f, 0) * Math::Matrix::CreateTranslation(m_StartCmdPos.x, m_StartCmdPos.y, 0);
}

void C_TitleScene::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_TitleMat);
	SHADER.m_spriteShader.DrawTex(&m_TitleTex, { 0,0,880,216 }, 1.0f);
	SHADER.m_spriteShader.SetMatrix(m_StartCmdMat);
	SHADER.m_spriteShader.DrawTex(&m_StartCmdTex, { 0,0,784,146 }, m_Alufa);
}
