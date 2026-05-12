#include "ResultScene.h"
#include"SceneManager.h"
#include"../../Utility/KeyManager.h"
#include "../../../Player/Player.h"
C_ResultScene::C_ResultScene()
{


}

C_ResultScene::~C_ResultScene()
{
	Release();
}

void C_ResultScene::Init()
{
	m_ScoreNum100Flg = false;
	m_ScoreNum10Flg = false;
	m_ReturnCmdTex. Load("Texture/UI/StartCmd.png");
	m_ScoreTex.		Load("Texture/UI/Score.png");
	m_ScoreNumTex.	Load("Texture/UI/ScoreNumber.png");
	m_RankTex.		Load("Texture/UI/Rank.png");
	m_RankAlfTex.	Load("Texture/UI/RankAlp.png");
	m_ThankTex.		Load("Texture/UI/Thank.png");

	EndTotalScore = C_Player::GetInstance().GetTotalScore();

	if (EndTotalScore / 100 >= 1)
	{
		m_ScoreNum100Flg = true;
		m_ScoreNum10Flg = true;
	}
	else if (EndTotalScore / 10 >= 1)
	{
		m_ScoreNum10Flg = true;
	}

	m_RankAlfScale = 3.0f;
	m_RankAlfAlufa = -1.0f;
	ScoreEndWait = 0;
	ScoreEndFlg = false;
	m_RankAlfEnd = false;
}

void C_ResultScene::Update()
{
	m_Alufa -= m_AlufaAdd;
	if (m_Alufa > 1.0f || m_Alufa < 0.0f)
	{
		m_AlufaAdd *= -1;
	}

	if (ScoreEndFlg)
	{
		m_RankAlfScale -= 0.1f;
		m_RankAlfAlufa += 0.1f;
		if (m_RankAlfScale <= 1.0f)
		{
			m_RankAlfScale = 1.0f;
		}
		if (m_RankAlfAlufa > 1.0f)
		{
			m_RankAlfAlufa = 1.0f;

			m_RankAlfEnd = true;
		}
	}
	if (m_RankAlfEnd)
	{
		if (C_KeyManager::GetInstance().GetSpaceKey())
		{
			SCENEMANAGER.SetNextScene(SceneManager::SceneType::Title);

		}
	}
	else
	{
		m_Alufa = 0.0f;
	}
	m_ReturnCmdMat = Math::Matrix::CreateScale(0.5f, 0.5f, 0) * Math::Matrix::CreateTranslation(m_ReturnCmdPos.x, m_ReturnCmdPos.y, 0);
	m_ScoreMat = Math::Matrix::CreateScale(0.5f, 0.5f, 0) * Math::Matrix::CreateTranslation(m_ScorePos.x, m_ScorePos.y, 0);
	m_RankMat = Math::Matrix::CreateScale(0.5f, 0.5f, 0) * Math::Matrix::CreateTranslation(m_RankPos.x, m_RankPos.y, 0);
	m_RankAlfMat = Math::Matrix::CreateScale(m_RankAlfScale, m_RankAlfScale, 0) * Math::Matrix::CreateTranslation(m_RankAlfPos.x, m_RankAlfPos.y, 0);
	m_ThankMat = Math::Matrix::CreateScale(0.5f, 0.5f, 0) * Math::Matrix::CreateTranslation(m_ThankPos.x, m_ThankPos.y, 0);


	if (m_ScoreNum100Flg && m_ScoreNum10Flg)
	{
		m_ScoreNum100Mat = Math::Matrix::CreateTranslation(m_ScoreNum100Pos.x, m_ScoreNum1Pos.y, 0);
		m_ScoreNum10Mat = Math::Matrix::CreateTranslation(m_ScoreNum100Pos.x+ AddNumberPosX, m_ScoreNum100Pos.y, 0);
		m_ScoreNum1Mat = Math::Matrix::CreateTranslation(m_ScoreNum100Pos.x+ AddNumberPosX*2, m_ScoreNum100Pos.y, 0);
	}
	else if (m_ScoreNum10Flg)
	{
		m_ScoreNum10Mat = Math::Matrix::CreateTranslation(m_ScoreNum10Pos.x, m_ScoreNum10Pos.y, 0);
		m_ScoreNum1Mat = Math::Matrix::CreateTranslation(m_ScoreNum10Pos.x + AddNumberPosX, m_ScoreNum10Pos.y, 0);
	}
	else
	{
		m_ScoreNum1Mat = Math::Matrix::CreateTranslation(m_ScoreNum1Pos.x, m_ScoreNum1Pos.y, 0);
	}

}

void C_ResultScene::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_ReturnCmdMat);
	SHADER.m_spriteShader.DrawTex(&m_ReturnCmdTex, { 0,0,784,146 }, m_Alufa);

	SHADER.m_spriteShader.SetMatrix(m_ScoreMat);
	SHADER.m_spriteShader.DrawTex(&m_ScoreTex, { 0,0,964,254 }, 1.0f);

	SHADER.m_spriteShader.SetMatrix(m_RankMat);
	SHADER.m_spriteShader.DrawTex(&m_RankTex, { 0,0,784,244 }, 1.0f);

	if (EndTotalScore >= 120)
	{
		SHADER.m_spriteShader.SetMatrix(m_RankAlfMat);
		SHADER.m_spriteShader.DrawTex(&m_RankAlfTex, { 176 * 0,0,176,80 }, m_RankAlfAlufa);
	}
	else if (EndTotalScore >= 90)
	{
		SHADER.m_spriteShader.SetMatrix(m_RankAlfMat);
		SHADER.m_spriteShader.DrawTex(&m_RankAlfTex, { 176 * 1,0,176,80 }, m_RankAlfAlufa);
	}
	else if (EndTotalScore >= 60)
	{
		SHADER.m_spriteShader.SetMatrix(m_RankAlfMat);
		SHADER.m_spriteShader.DrawTex(&m_RankAlfTex, { 176 * 2,0,176,80 }, m_RankAlfAlufa);
	}
	else if(EndTotalScore >= 35)
	{
		SHADER.m_spriteShader.SetMatrix(m_RankAlfMat);
		SHADER.m_spriteShader.DrawTex(&m_RankAlfTex, { 176 * 3,0,176,80 }, m_RankAlfAlufa);
	}
	else 
	{
		SHADER.m_spriteShader.SetMatrix(m_RankAlfMat);
		SHADER.m_spriteShader.DrawTex(&m_RankAlfTex, { 176 * 4,0,176,80 }, m_RankAlfAlufa);
	}
	SHADER.m_spriteShader.SetMatrix(m_ThankMat);
	SHADER.m_spriteShader.DrawTex(&m_ThankTex, { 0,0,1408,132 }, 1.0f);

	if (ScoreEndFlg)
	{
		int i = EndTotalScore;
		SHADER.m_spriteShader.SetMatrix(m_ScoreNum1Mat);
		SHADER.m_spriteShader.DrawTex(&m_ScoreNumTex, { NumberWidth * (i % 10),0,64,64 }, 1.0f);
		if (m_ScoreNum10Flg)
		{
			i = i / 10;
			SHADER.m_spriteShader.SetMatrix(m_ScoreNum10Mat);
			SHADER.m_spriteShader.DrawTex(&m_ScoreNumTex, { NumberWidth * (i % 10),0,64,64 }, 1.0f);
		}
		if (m_ScoreNum100Flg)
		{
			i = i / 10;
			SHADER.m_spriteShader.SetMatrix(m_ScoreNum100Mat);
			SHADER.m_spriteShader.DrawTex(&m_ScoreNumTex, { NumberWidth * i,0,64,64 }, 1.0f);
		}
	}
	else
	{
		int i = rand() % 1000;
		SHADER.m_spriteShader.SetMatrix(m_ScoreNum1Mat);
		SHADER.m_spriteShader.DrawTex(&m_ScoreNumTex, { NumberWidth * (i % 10),0,64,64 }, 1.0f);
		if (m_ScoreNum10Flg)
		{
			i = i / 10;
			SHADER.m_spriteShader.SetMatrix(m_ScoreNum10Mat);
			SHADER.m_spriteShader.DrawTex(&m_ScoreNumTex, { NumberWidth * (i % 10),0,64,64 }, 1.0f);
		}
		if (m_ScoreNum100Flg)
		{
			i = i / 10;
			SHADER.m_spriteShader.SetMatrix(m_ScoreNum100Mat);
			SHADER.m_spriteShader.DrawTex(&m_ScoreNumTex, { NumberWidth * i,0,64,64 }, 1.0f);
		}
		ScoreEndWait++;
		if (ScoreEndWait > 60)
		{
			ScoreEndFlg = true;
		}
	}
}

void C_ResultScene::Release()
{
	m_ReturnCmdTex.Release();
	m_ScoreTex.Release();
	m_ScoreNumTex.Release();
	m_RankTex.Release();
	m_RankAlfTex.Release();
	m_ThankTex.Release();
}