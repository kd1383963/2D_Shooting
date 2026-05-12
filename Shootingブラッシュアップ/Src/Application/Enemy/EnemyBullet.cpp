#include "EnemyBullet.h"
#include "../System/Main/Scene/SceneManager.h"

void C_EnemyBullet::Draw()
{
	if (!m_Alive)return;
	SHADER.m_spriteShader.SetMatrix(m_Mat);
	SHADER.m_spriteShader.DrawTex(m_Tex, Math::Rectangle{ 0,0,18,18 }, 1.0f);
}

void C_EnemyBullet::Shot(Math::Vector2 a_pos,Math::Vector2 vec1)
{
	m_Pos = a_pos;
	m_Alive = true;
	vec = vec1;
	vec.Normalize();
}



void C_EnemyBullet::Update()
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

void C_EnemyBullet::Init()
{
	m_Pos.x = 0;
	m_Pos.y = 0;
	m_Alive = false;
}

void C_EnemyBullet::SetTex(KdTexture* tex)
{
	m_Tex = tex;
}

bool C_EnemyBullet::HIT(Math::Vector2 pos, int hx1, int hy1)
{
	float dx = m_Pos.x - pos.x;
	float dy = m_Pos.y - pos.y;

	// ‡¬”¼Œai‘È‰~“¯Žm‚È‚Ì‚Å‘«‚µŽZj
	float rx = m_Radius + hx1 / 2;
	float ry = m_Radius + hy1 / 2;

	// ”»’èŽ®
	float value =
		(dx * dx) / (rx * rx) +
		(dy * dy) / (ry * ry);
	if (value <= 1.0f)
	{
		return true;
	}
	else
	{
		return false;
	}
}
