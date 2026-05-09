#include "Player.h"
#include"PlayerBullet.h"
#include "../System/Main/Scene/GameScene.h"
#include "../Enemy/Prism/Prism.h"
#include "../Enemy/Enemy.h"
#include "../System/Battle/Turn.h"
#include "../Mouse.h"

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
			SHADER.m_spriteShader.DrawTex(m_BulletLineTex, { 0,0,2560,16 }, m_LineBlinking);
		}
	}
	SHADER.m_spriteShader.SetMatrix(m_PlayerMat);
	SHADER.m_spriteShader.DrawTex(m_PlayerTex, { 0,0,64,64 }, 1.0f);
	
	int HpBerCnt;

	//HPˆ—
	SHADER.m_spriteShader.SetMatrix(m_HpBackMat);
	SHADER.m_spriteShader.DrawTex(m_HpBackTex, { 0,0,66,8 }, 1.0f);
	HpBerCnt = (m_CharaStatus.m_MaxHp - m_CharaStatus.m_BreakHp);
	if (HpBerCnt > m_CharaStatus.m_MaxHp)
	{
		HpBerCnt = m_CharaStatus.m_MaxHp;
	}
	SHADER.m_spriteShader.SetMatrix(m_HpBreakMat);
	SHADER.m_spriteShader.DrawTex(m_HpBreakTex, { 0,0,(66 - (int)(66 * (HpBerCnt / m_CharaStatus.m_MaxHp))),8 }, 1.0f);
	HpBerCnt = (m_CharaStatus.m_MaxHp - m_CharaStatus.m_Hp);
	if (HpBerCnt > m_CharaStatus.m_MaxHp)
	{
		HpBerCnt = m_CharaStatus.m_MaxHp;
	}
	SHADER.m_spriteShader.SetMatrix(m_HpMat);
	SHADER.m_spriteShader.DrawTex(m_HpTex, { 0,0,(66 - (int)(66 * (HpBerCnt / m_CharaStatus.m_MaxHp))),8 }, 1.0f);
	

	for (int i = 0; i < m_Bullet.size(); i++)
	{
		m_Bullet[i]->Draw();
	}
}

void C_Player::Update()
{
	if (m_CharaStatus.m_DamageFlg)
	{
		m_CharaStatus.m_BreakHp -= 1;
	}
	if (m_CharaStatus.m_Hp == m_CharaStatus.m_BreakHp)
	{
		m_CharaStatus.m_DamageFlg = false;
	}

	if (m_CharaStatus.m_Hp <= 0)
	{
		m_CharaStatus.m_Alive = false;
	}
	if (C_Turn::GetInstance().GetNowTurn() == C_Turn::Player)
	{
		Math::Vector2 MousePos = {(float) C_Mouse::GetInstance().GetMousePos().x,(float) C_Mouse::GetInstance().GetMousePos().y };
		Math::Vector2 vec = m_CharaStatus.Pos - MousePos;
		float angle= atan2(vec.y,vec.x);
		if (!m_ShotFlg)
		{
			
			if (GetAsyncKeyState('W') & 0x8000)
			{
				m_CharaStatus.Pos.y += m_MoveSpeed;
			}
			if (GetAsyncKeyState('S') & 0x8000)
			{
				m_CharaStatus.Pos.y -= m_MoveSpeed;
			}
			if (GetAsyncKeyState(VK_SPACE) & 0x8000)
			{
				m_Bullet.push_back(std::make_shared<C_PlayerBullet>());
				for (int i = 0; i < m_Bullet.size(); i++)
				{
					if (!m_Bullet[i]->GetAlive())
					{
						m_Bullet[i]->SetTex(&m_BulletTex);
						m_Bullet[i]->Shot(m_CharaStatus.Pos, MousePos);
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
			for (int i = 0; i < m_Bullet.size(); i++)
			{
				if (m_Bullet[i]->GetAlive())
				{
					break;
				}
				m_ShotFlg = false;
				C_Turn::GetInstance().SetNextTurn(C_Turn::Enemy);

			}
		}
		if (m_CharaStatus.Pos.y > 360 - 32)
		{
			m_CharaStatus.Pos.y = 360 - 32;
		}
		if (m_CharaStatus.Pos.y < -360 + 32)
		{
			m_CharaStatus.Pos.y = -360 + 32;
		}
		 
		m_LineMat = Math::Matrix::CreateRotationZ(angle) * Math::Matrix::CreateTranslation(m_CharaStatus.Pos.x , m_CharaStatus.Pos.y, 0);

	}
	m_HpMat = Math::Matrix::CreateTranslation(m_CharaStatus.Pos.x - ((int)(66 * (((m_CharaStatus.m_MaxHp - m_CharaStatus.m_Hp) / 2) / m_CharaStatus.m_MaxHp))), m_CharaStatus.Pos.y + m_CharaStatus.HpAddPos.y, 0);
	m_HpBackMat = Math::Matrix::CreateTranslation(m_CharaStatus.Pos.x, m_CharaStatus.Pos.y + m_CharaStatus.HpAddPos.y, 0);
	m_HpBreakMat = Math::Matrix::CreateTranslation(m_CharaStatus.Pos.x - ((int)(66 * (((m_CharaStatus.m_MaxHp - m_CharaStatus.m_BreakHp) / 2) / m_CharaStatus.m_MaxHp))), m_CharaStatus.Pos.y + m_CharaStatus.HpAddPos.y, 0);
	m_PlayerMat = Math::Matrix::CreateTranslation(m_CharaStatus.Pos.x, m_CharaStatus.Pos.y, 0);
	
	for (int i = 0; i < m_Bullet.size(); i++)
	{
		m_Bullet[i]->Update();
	}

}

void C_Player::Init()
{
	m_CharaStatus.Pos.x = -500;
	m_CharaStatus.Pos.y = 0;
	m_ShotFlg = false;
	m_LineBlinking = 0.1f;
	m_LineBlinkingAdd = 0.01f;
	m_CharaStatus.m_Hp = 100;
	m_CharaStatus.m_MaxHp = m_CharaStatus.m_Hp;
	m_CharaStatus.m_BreakHp = m_CharaStatus.m_Hp;
	m_CharaStatus.m_Atk = 50;
		
		
	
}

void C_Player::SetTex(KdTexture* playertex,
	KdTexture* bulletlinetex, KdTexture* hpbartex,
	KdTexture* hpbarbraektex, KdTexture* hpbarbacktex)
{
	m_BulletTex.Load("Texture/Player/bullet.png");
	m_PlayerTex = playertex;
	m_BulletLineTex = bulletlinetex;
	m_HpTex = hpbartex;
	m_HpBreakTex = hpbarbraektex;
	m_HpBackTex = hpbarbacktex;
}

void C_Player::HitBulletEnemy()
{
	std::shared_ptr<C_Enemy> Enemy = m_owner->GetEnemy();

	std::vector<std::shared_ptr<C_EnemyBase>> EnemyChara = Enemy->GetEnemyChara();


	for (auto& e : EnemyChara) {
		if (e->GetAlive())
		{
			for (int j = 0; j < m_Bullet.size(); j++)
			{
				if (m_Bullet[j]->GetAlive())
				{
					if (m_Bullet[j]->HIT(e->GetPos(), e->GetRadius()))
					{
						e->HitDamege(m_CharaStatus.m_Atk);
						
					
						return;
					}
				}
			}
		}


	}
}


void C_Player::SetHitSkill()
{
	PlayerSkill = PlayerSkillBase;
}
