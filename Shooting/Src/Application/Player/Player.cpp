#include "Player.h"
#include"PlayerBullet.h"
#include "../System/Main/Scene/GameScene.h"
#include "../Enemy/Enemy.h"
#include "../System/Battle/Turn.h"

C_Player::C_Player()
{
}

C_Player::~C_Player()
{
}

void C_Player::Draw()
{
	if (C_Turn::GetInstance().GetNowTurn() == C_Turn::Player)
	{
		if (!m_ShotFlg)
		{
			SHADER.m_spriteShader.SetMatrix(m_LineMat);
			SHADER.m_spriteShader.DrawTex(m_BulletLineTex, { 0,0,1280,16 }, m_LineBlinking);
		}
	}
	SHADER.m_spriteShader.SetMatrix(m_PlayerMat);
	SHADER.m_spriteShader.DrawTex(m_PlayerTex, { 0,0,64,64 }, 1.0f);
	
	

	for (int i = 0; i < m_PlayerBulletNum; i++)
	{
		m_Bullet[i]->Draw();
	}
}

void C_Player::Update()
{
	if (C_Turn::GetInstance().GetNowTurn() == C_Turn::Player)
	{
		if (!m_ShotFlg)
		{
			if (GetAsyncKeyState('W') & 0x8000)
			{
				m_Pos.y += m_MoveSpeed;
			}
			if (GetAsyncKeyState('S') & 0x8000)
			{
				m_Pos.y -= m_MoveSpeed;
			}
			if (GetAsyncKeyState(VK_SPACE) & 0x8000)
			{
				for (int i = 0; i < m_PlayerBulletNum; i++)
				{
					if (!m_Bullet[i]->GetAlive())
					{
						m_Bullet[i]->Shot(m_Pos);
						m_ShotFlg = true;
						break;
					}
				}
			}
			m_LineBlinking += m_LineBlinkingAdd;
			if (m_LineBlinking >= 0.4f || m_LineBlinking <= 0.1f)
			{
				m_LineBlinkingAdd *= -1;
			}

		}
		else
		{
			for (int i = 0; i < m_PlayerBulletNum; i++)
			{
				if (m_Bullet[i]->GetAlive())
				{
					break;
				}
				m_ShotFlg = false;
				C_Turn::GetInstance().SetNextTurn(C_Turn::Enemy);

			}
		}
		if (m_Pos.y > 360 - 32)
		{
			m_Pos.y = 360 - 32;
		}
		if (m_Pos.y < -360 + 32)
		{
			m_Pos.y = -360 + 32;
		}

		m_LineMat = Math::Matrix::CreateTranslation(m_Pos.x + 640, m_Pos.y, 0);

	}

	m_PlayerMat = Math::Matrix::CreateTranslation(m_Pos.x, m_Pos.y, 0);
	
	for (int i = 0; i < m_PlayerBulletNum; i++)
	{
		m_Bullet[i]->Update();
	}

}

void C_Player::Init()
{
	m_Pos.x = -500;
	m_Pos.y = 0;
	m_ShotFlg = false;
	m_LineBlinking = 0.1f;
	m_LineBlinkingAdd = 0.01f;
	for (int i = 0; i < m_PlayerBulletNum; i++)
	{
		m_Bullet[i] = new C_PlayerBullet;
		m_Bullet[i]->Init();
		m_Bullet[i]->SetTex(&m_BulletTex);
		
	}
}

void C_Player::SetTex(KdTexture* playertex,KdTexture* bulletlinetex)
{
	m_BulletTex.Load("Texture/Player/bullet.png");
	m_PlayerTex = playertex;
	m_BulletLineTex = bulletlinetex;
}

void C_Player::HitBulletEnemy()
{
	C_Enemy* Enemy = m_owner->GetEnemy();



	for (int i = 0; i < Enemy->GetNum(); i++)
	{
		if (Enemy->GetAlive(i))
		{
			for (int j = 0; j < m_PlayerBulletNum; j++)
			{
				if (m_Bullet[j]->GetAlive())
				{
					if (m_Bullet[j]->HIT(Enemy->GetPos(i), Enemy->GetRadius()))
					{
						Enemy->SetAlive(i);
						return;
					}
				}
			}
		}
	}
}
