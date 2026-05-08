#include "../Enemy.h"
#include "../../System/Main/Scene/GameScene.h"
#include "NormalZombie.h"

void C_Normalzombie::Move()
{
	m_EnemyStatus.m_Pos.x -= rand() % 100 + 30;
}

void C_Normalzombie::Init()
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
	
	m_EnemyStatus.m_Alive = true;
	m_EnemyStatus.m_MoveFlg = false;
}
