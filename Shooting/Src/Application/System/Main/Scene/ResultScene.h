#pragma once
#include"State.h"
class C_ResultScene :public C_State
{
public:
	C_ResultScene();
	~C_ResultScene();

	void Init()override;
	void Update()override;
	void Draw()override;

	void Release();

private:

	int EndTotalScore;

	float m_Alufa = 0.0f;
	float m_AlufaAdd = 0.02f;

	bool  m_ScoreNum10Flg  = false;
	bool  m_ScoreNum100Flg = false;

	static const int AddNumberPosX = 64;
	static const int NumberWidth = 64;

	Math::Vector2 m_ReturnCmdPos = { 0,-300 };
	Math::Matrix m_ReturnCmdMat;
	KdTexture m_ReturnCmdTex;

	Math::Vector2 m_ScorePos = { -300,190 };
	Math::Matrix m_ScoreMat;
	KdTexture m_ScoreTex;

	Math::Vector2 m_ScoreNum1Pos = { 300,180 };
	Math::Matrix m_ScoreNum1Mat;
	KdTexture m_ScoreNumTex;

	Math::Vector2 m_ScoreNum10Pos = { 250,180 };
	Math::Matrix m_ScoreNum10Mat;

	Math::Vector2 m_ScoreNum100Pos = { 200,180 };
	Math::Matrix m_ScoreNum100Mat;

	Math::Vector2 m_RankPos = { -300,-40 };
	Math::Matrix m_RankMat;
	KdTexture m_RankTex;

	Math::Vector2 m_RankAlfPos = { 300,-50 };
	Math::Matrix m_RankAlfMat;
	KdTexture m_RankAlfTex;

	Math::Vector2 m_ThankPos = { 0,-200 };
	Math::Matrix m_ThankMat;
	KdTexture m_ThankTex;
};
