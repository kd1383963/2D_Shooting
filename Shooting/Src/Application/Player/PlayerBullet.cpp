#include "PlayerBullet.h"

void C_PlayerBullet::Draw()
{
	if (!m_Alive)return;
	SHADER.m_spriteShader.SetMatrix(m_Mat);
	SHADER.m_spriteShader.DrawTex(m_Tex, Math::Rectangle{ 0,0,16,16 }, 1.0f);
}

void C_PlayerBullet::Shot(Math::Vector2 pos)
{
	m_Pos = pos;
	m_Alive = true;
}

void C_PlayerBullet::Update()
{
	if (!m_Alive)return;

	m_Pos.x += m_MoveSpeed;


	if (m_Pos.x > 640 + m_Radius || m_Pos.x < -640 - m_Radius
		|| m_Pos.y>360 + m_Radius || m_Pos.y < -360 - m_Radius)
	{
		m_Alive = false;
		
	}

	m_Mat = Math::Matrix::CreateTranslation(m_Pos.x, m_Pos.y, 1);
}

void C_PlayerBullet::Init()
{
	m_Pos.x = 0;
	m_Pos.y = 0;
	m_Alive = false;
}

void C_PlayerBullet::SetTex(KdTexture* tex)
{
	m_Tex = tex;
}