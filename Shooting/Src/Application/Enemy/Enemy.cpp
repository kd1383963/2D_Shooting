#include "Enemy.h"
#include "../System/Battle/Turn.h"

void C_Enemy::Draw()
{
	for (int i = 0; i < EnemyNum; i++)
	{
		if (m_Alive[i])
		{
			SHADER.m_spriteShader.SetMatrix(m_EnemyMat[i]);
			SHADER.m_spriteShader.DrawTex(m_EnemyTex, { 0,0,64,64 }, 1.0f);
		}
	}
}

void C_Enemy::Update()
{
	for (int i = 0; i < EnemyNum; i++)
	{
		if (m_Alive[i])
		{
			if (C_Turn::GetInstance().GetNowTurn() == C_Turn::Enemy && !m_MoveFlg[i])
			{
				m_Pos[i].x -= 5;
				m_MoveFlg[i] = true;
				C_Turn::GetInstance().SetNextTurn(C_Turn::Player);
			}
			m_EnemyMat[i] = Math::Matrix::CreateTranslation(m_Pos[i].x, m_Pos[i].y, 0);
		}
	}

	

}

void C_Enemy::Init()
{
	for (int i = 0; i < EnemyNum; i++)
	{
		m_Pos[i].x = 400;
		m_Pos[i].y = rand() % 400 - 200;
		m_Alive[i] = true;
		m_MoveFlg[i] = false;
	}
}

void C_Enemy::SetTex(KdTexture* enemytex)
{
	m_EnemyTex = enemytex;
}