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
		m_EnemyStatus.m_ShotFlg = true;
		break;
	case Beam:
		if (!m_EnemyStatus.m_ShotFlg)ShotBeam();
		break;
	case Beam3:
		if (!m_EnemyStatus.m_ShotFlg)ShootWay(3);
		break;
	case Beam5:
		if (!m_EnemyStatus.m_ShotFlg)ShootWay(5);
		break;
	}
}

void C_Prism::Init(int wave,int num)
{
	std::vector<std::shared_ptr<C_EnemyBase>> EnemyChara = m_owner->GetEnemyChara();

	m_EnemyStatus.m_Radius = 32;
	m_EnemyStatus.m_EAnimStatus = EIdle;
	CharaAnimCnt = 0;

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
	if (wave == 1)
	{
		if (num == 1)
		{
			m_EnemyStatus.m_Hp = 40;
			m_EnemyStatus.m_MaxHp = m_EnemyStatus.m_Hp;
			m_EnemyStatus.m_BreakHp = m_EnemyStatus.m_Hp;
			m_EnemyStatus.m_Atk = 5 + 10 * (wave / 2);
			m_EnemyStatus.m_MoveCmd = Attack;
			m_EnemyStatus.AttackDamage = m_EnemyStatus.m_Atk;
			m_EnemyStatus.m_Alive = true;
			m_EnemyStatus.m_MoveFlg = false;
			m_EnemyStatus.m_HpAddPos = { 0,-42 };
			m_EnemyStatus.m_IconAddPos = { 0,47 };
		}
		else
		{
			m_EnemyStatus.m_Hp = 40;
			m_EnemyStatus.m_MaxHp = m_EnemyStatus.m_Hp;
			m_EnemyStatus.m_BreakHp = m_EnemyStatus.m_Hp;
			m_EnemyStatus.m_Atk = 5 + 10 * (wave / 2);
			m_EnemyStatus.m_MoveCmd = Beam;
			m_Vec = m_EnemyStatus.m_Pos - C_Player::GetInstance().GetPos();
			m_EnemyStatus.AttackDamage = m_EnemyStatus.m_Atk * 2;
			m_EnemyStatus.m_Alive = true;
			m_EnemyStatus.m_MoveFlg = false;
			m_EnemyStatus.m_HpAddPos = { 0,-42 };
			m_EnemyStatus.m_IconAddPos = { 0,47 };
		}
	}
	else
	{
		m_EnemyStatus.m_Hp = 80 + 50 * (wave / 3);
		m_EnemyStatus.m_MaxHp = m_EnemyStatus.m_Hp;
		m_EnemyStatus.m_BreakHp = m_EnemyStatus.m_Hp;
		m_EnemyStatus.m_Atk = 10 + 10 * (wave / 2);
		SetAttackCmd();
		m_EnemyStatus.m_Alive = true;
		m_EnemyStatus.m_MoveFlg = false;
		m_EnemyStatus.m_HpAddPos = { 0,-42 };
		m_EnemyStatus.m_IconAddPos = { 0,47 };
	}
}

void C_Prism::SetAttackCmd()
{
	int Rand = rand() % 100;
	if (Rand < 30)
	{
		m_EnemyStatus.m_MoveCmd = Attack;
		m_EnemyStatus.AttackDamage = m_EnemyStatus.m_Atk;
	}
	else if (Rand < 60)
	{
		m_Vec = m_EnemyStatus.m_Pos - C_Player::GetInstance().GetPos();
		m_EnemyStatus.m_MoveCmd = Beam;
		m_EnemyStatus.AttackDamage = m_EnemyStatus.m_Atk * 2;
	}
	else if (Rand < 80)
	{
		m_EnemyStatus.m_MoveCmd = Beam3;
		m_EnemyStatus.AttackDamage = m_EnemyStatus.m_Atk * 2;
	}
	else
	{
		m_EnemyStatus.m_MoveCmd = Beam5;
		m_EnemyStatus.AttackDamage = m_EnemyStatus.m_Atk * 2;
	}
}
