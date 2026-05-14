#include "PlayerBullet.h"
#include "Player.h"
#include "../System/Main/Scene/SceneManager.h"

void C_PlayerBullet::Draw()
{
	if (!m_Alive)return;
	SHADER.m_spriteShader.SetMatrix(m_Mat);
	SHADER.m_spriteShader.DrawTex(m_Tex, Math::Rectangle{ 0,0,18,18 }, 1.0f);
}

void C_PlayerBullet::Shot(Math::Vector2 pos1, Math::Vector2 vec1)
{
	ignoreFrames = 10;
	m_Pos = pos1;
	m_Alive = true;
	vec = -vec1 ;
	vec.Normalize();
}

void C_PlayerBullet::MoreShot(Math::Vector2 pos1,Math::Vector2 vec1)
{
	ignoreFrames = 10;
	m_Pos = pos1;
	m_Alive = true;
	vec = vec1;
	vec.Normalize();
}

void C_PlayerBullet::Update()
{
	if (!m_Alive)return;
	
	

	

	m_Pos -= vec * m_MoveSpeed;

	//if(SCENEMANAGER.)

	bool bounced = false;

	// ç∂âEÇÃï«
	if (m_Pos.x - m_Radius < -640.0f)
	{
		m_Pos.x = m_Radius - 640.0f;      // ÇﬂÇËçûÇ›ï‚ê≥
		vec.x = -vec.x;        // Xë¨ìxîΩì]
		bounced = true;
	}
	else if (m_Pos.x + m_Radius > 640.0f)
	{
		m_Pos.x = 640.0f - m_Radius;
		vec.x = -vec.x;
		bounced = true;
	}

	// è„â∫ÇÃï«
	if (m_Pos.y - m_Radius < -360.0f)
	{
		m_Pos.y = m_Radius - 360.0f;
		vec.y = -vec.y;        // Yë¨ìxîΩì]
		bounced = true;
	}
	else if (m_Pos.y + m_Radius > 360.0f)
	{
		m_Pos.y = 360.0f - m_Radius;
		vec.y = -vec.y;
		bounced = true;
	}

	// îΩéÀÇµÇΩÇÁâÒêîÇå∏ÇÁÇ∑
	if (bounced)
	{
		PlayerSkill.m_WallbounceLeft--;

		if (PlayerSkill.m_WallbounceLeft < 0)
		{
			m_Alive = false; // Ç±ÇÍà»è„îΩéÀÇ≈Ç´Ç»Ç¢ÇÃÇ≈è¡Ç∑
		}
	}

	m_Mat = Math::Matrix::CreateTranslation(m_Pos.x, m_Pos.y, 1);
}

void C_PlayerBullet::Init()
{
	m_Pos.x = 0;
	m_Pos.y = 0;
	m_Alive = false;
	ignoreFrames = 3;
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
	float a = m_Pos.x - pos.x;    //íÍï”
	float b = m_Pos.y - pos.y;    //çÇÇ≥
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
