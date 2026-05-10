#include "PlayerBullet.h"
#include "Player.h"
#include "../System/Main/Scene/SceneManager.h"

void C_PlayerBullet::Draw()
{
	if (!m_Alive)return;
	SHADER.m_spriteShader.SetMatrix(m_Mat);
	SHADER.m_spriteShader.DrawTex(m_Tex, Math::Rectangle{ 0,0,18,18 }, 1.0f);
}

void C_PlayerBullet::Shot(Math::Vector2 pos1, Math::Vector2 pos2)
{
	ignoreFrames = 10;
	m_Pos = pos1;
	m_Alive = true;
	vec = pos1 - pos2;
	vec.Normalize();
}

void C_PlayerBullet::MoreShot(Math::Vector2 vec1)
{
	ignoreFrames = 10;
	m_Alive = true;
	vec = vec1;
	vec.Normalize();
}

void C_PlayerBullet::Update()
{
	if (!m_Alive)return;
	
	

	

	m_Pos -= vec * m_MoveSpeed;

	//if(SCENEMANAGER.)

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
	ignoreFrames = 10;
}

void C_PlayerBullet::SetTex(KdTexture* tex)
{
	m_Tex = tex;
}

bool C_PlayerBullet::HIT(Math::Vector2 pos, int h)
{
	if (ignoreFrames > 0) {
		ignoreFrames--;
		return(false);
	}
	float a = m_Pos.x - pos.x;    //’ê•Ó
	float b = m_Pos.y - pos.y;    //‚‚³
	float c = sqrt(a * a + b * b);
	if (c < h + m_Radius) {
		m_Alive = false;

		
		return (true);
		
	}
	else
	{
		return(false);
	}
}
