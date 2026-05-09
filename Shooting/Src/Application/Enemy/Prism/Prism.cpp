#include "../Enemy.h"
#include "../../Player/Player.h"
#include "../../System/Main/Scene/GameScene.h"
#include "Prism.h"

void C_Prism::Move()
{
	switch (m_EnemyStatus.m_MoveCmd)
	{
	case Attack:
		C_Player::GetInstance().HitDamege(m_EnemyStatus.m_Atk);
		m_EnemyStatus.m_MoveFlg = true;
		break;
	case Beam:
		m_EnemyStatus.m_ShotFlg = true;
		ShotBeam();
		break;
	}
}

void C_Prism::Init()
{
	std::vector<std::shared_ptr<C_EnemyBase>> EnemyChara = m_owner->GetEnemyChara();

	m_EnemyStatus.m_Radius = 32;

	do {
		m_EnemyStatus.m_Pos.x = rand() % (640 - 64);
		m_EnemyStatus.m_Pos.y = rand() % (720 - 80 * 2) - (320 - 64);
		m_EnemyStatus.m_PosInitOkFlg = true;
		for (int i = 0; i < EnemyChara.size() - 1; i++)
		{
			Math::Vector2 v = m_EnemyStatus.m_Pos - EnemyChara[i]->GetPos();
			if (v.Length() < m_EnemyStatus.m_Radius + EnemyChara[i]->GetRadius() + 30)
			{
				m_EnemyStatus.m_PosInitOkFlg = false;

			}
		}
	}while(!m_EnemyStatus.m_PosInitOkFlg);
	
	m_EnemyStatus.m_Hp = 100;
	m_EnemyStatus.m_MaxHp = m_EnemyStatus.m_Hp;
	m_EnemyStatus.m_BreakHp = m_EnemyStatus.m_Hp ;
	m_EnemyStatus.m_Atk = 10;
	if (rand() % 2 == 0)
	{
		m_EnemyStatus.m_MoveCmd = Attack;
		m_EnemyStatus.AttackDamage = m_EnemyStatus.m_Atk;
	}
	else
	{
		m_EnemyStatus.m_MoveCmd = Beam;
		m_EnemyStatus.AttackDamage = m_EnemyStatus.m_Atk * 2;
	}
	m_EnemyStatus.m_Alive = true;
	m_EnemyStatus.m_MoveFlg = false;
	m_EnemyStatus.m_HpAddPos = { 0,-42 };
	m_EnemyStatus.m_IconAddPos = { 0,47 };
	
}
