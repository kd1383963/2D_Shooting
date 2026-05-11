#include "ResultScene.h"
#include"SceneManager.h"
#include"../../Utility/KeyManager.h"
#include "../../../Player/Player.h"
C_ResultScene::C_ResultScene()
{


}

C_ResultScene::~C_ResultScene()
{

}

void C_ResultScene::Init()
{
	m_ReturnCmdTex.Load("Texture/UI/StartCmd.png");
	m_ScoreTex.Load("Texture/UI/Score.png");
	m_ScoreTex.Load("Texture/UI/ScoreNumber.png");
	m_RankTex.Load("Texture/UI/Rank.png");
	m_RankAlfTex.Load("Texture/UI/RankAlf.png");
	m_ThankTex.Load("Texture/UI/Thank.png");
}

void C_ResultScene::Update()
{
	m_Alufa -= m_AlufaAdd;
	if (m_Alufa > 1.0f || m_Alufa < 0.0f)
	{
		m_AlufaAdd *= -1;
	}

	if (C_KeyManager::GetInstance().GetSpaceKey())
	{
		SCENEMANAGER.SetNextScene(SceneManager::SceneType::Title);

	}
	m_ReturnCmdMat = Math::Matrix::CreateScale(0.5f, 0.5f, 0) * Math::Matrix::CreateTranslation(m_ReturnCmdPos.x, m_ReturnCmdPos.y, 0);
	m_ScoreMat = Math::Matrix::CreateTranslation(m_ScorePos.x, m_ScorePos.y, 0);
	m_RankMat = Math::Matrix::CreateScale(2,2,0)*Math::Matrix::CreateTranslation(m_RankPos.x, m_RankPos.y, 0);
	m_RankAlfMat = Math::Matrix::CreateTranslation(m_RankAlfPos.x, m_RankAlfPos.y, 0);
	m_ThankMat = Math::Matrix::CreateTranslation(m_ThankPos.x, m_ThankPos.y, 0);


}

void C_ResultScene::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_ReturnCmdMat);
	SHADER.m_spriteShader.DrawTex(&m_ReturnCmdTex, { 0,0,784,146 }, m_Alufa);

	SHADER.m_spriteShader.SetMatrix(m_ScoreMat);
	SHADER.m_spriteShader.DrawTex(&m_ScoreTex, { 0,0,570,128 }, 1.0f);

	SHADER.m_spriteShader.SetMatrix(m_RankMat);
	SHADER.m_spriteShader.DrawTex(&m_RankTex, { 0,0,188,52 }, 1.0f);

	SHADER.m_spriteShader.SetMatrix(m_RankAlfMat);
	SHADER.m_spriteShader.DrawTex(&m_RankAlfTex, { 0,0,176,80 }, 1.0f);

	SHADER.m_spriteShader.SetMatrix(m_ThankMat);
	SHADER.m_spriteShader.DrawTex(&m_ThankTex, { 0,0,610,64 }, 1.0f);



}
