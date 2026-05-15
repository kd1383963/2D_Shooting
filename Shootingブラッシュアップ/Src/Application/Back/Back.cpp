#include "Back.h"

void C_Back::Init()
{
	m_Back1Tex.Load("Asset/Texture/Back/Back1.png");
	m_Back2Tex.Load("Asset/Texture/Back/Back2.png");
	m_Back3Tex.Load("Asset/Texture/Back/Back3.png");
	m_BackStatus = Evening;
}

void C_Back::Update()
{
	m_BackMat = Math::Matrix::CreateTranslation(0, 0, 0);
}

void C_Back::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_BackMat);
	switch (m_BackStatus)
	{
	case Evening:
		SHADER.m_spriteShader.DrawTex(&m_Back1Tex, { 0,0,1280,720 }, 1.0f);
		break;
	case Night:
		SHADER.m_spriteShader.DrawTex(&m_Back2Tex, { 0,0,1280,720 }, 1.0f);
		break;
	case LateNight:
		SHADER.m_spriteShader.DrawTex(&m_Back3Tex, { 0,0,1280,720 }, 1.0f);
		break;
	}
	
	
	
}

