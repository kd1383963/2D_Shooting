#include "EnemyBase.h"
#include "../System/Battle/Turn.h"

void C_EnemyBase::Draw()
{
	if (!m_EnemyStatus.m_Alive)return;
	SHADER.m_spriteShader.SetMatrix(m_EnemyMat);
	SHADER.m_spriteShader.DrawTex(m_EnemyTex, { 0,0,64,64 }, 1.0f);

	int HpBerCnt;

	//HPˆ—
	SHADER.m_spriteShader.SetMatrix(m_HpBackMat);
	SHADER.m_spriteShader.DrawTex(m_HpBackTex, { 0,0,66,8 }, 1.0f);
	HpBerCnt = (m_EnemyStatus.m_MaxHp - m_EnemyStatus.m_BreakHp);
	if (HpBerCnt > m_EnemyStatus.m_MaxHp)
	{
		HpBerCnt = m_EnemyStatus.m_MaxHp;
	}
	SHADER.m_spriteShader.SetMatrix(m_HpBreakMat);
	SHADER.m_spriteShader.DrawTex(m_HpBreakTex, { 0,0,(66 - (int)(66 * (HpBerCnt / m_EnemyStatus.m_MaxHp))),8 }, 1.0f);
	HpBerCnt = (m_EnemyStatus.m_MaxHp - m_EnemyStatus.m_Hp);
	if (HpBerCnt > m_EnemyStatus.m_MaxHp)
	{
		HpBerCnt = m_EnemyStatus.m_MaxHp;
	}
	SHADER.m_spriteShader.SetMatrix(m_HpMat);
	SHADER.m_spriteShader.DrawTex(m_HpTex, { 0,0,(66 - (int)(66 * (HpBerCnt / m_EnemyStatus.m_MaxHp))),8 }, 1.0f);
}

void C_EnemyBase::Update()
{
	if (!m_EnemyStatus.m_Alive)return;

	if (C_Turn::GetInstance().GetNowTurn() == C_Turn::Enemy && !m_EnemyStatus.m_MoveFlg)
	{
		//Move();
		//m_MoveFlg = true;
		C_Turn::GetInstance().SetNextTurn(C_Turn::Player);
	}
	m_HpMat = Math::Matrix::CreateTranslation(m_EnemyStatus.m_Pos.x - ((int)(66 * (((m_EnemyStatus.m_MaxHp - m_EnemyStatus.m_Hp) / 2) / m_EnemyStatus.m_MaxHp))), m_EnemyStatus.m_Pos.y + m_EnemyStatus.m_HpAddPos.y, 0);
	m_HpBackMat = Math::Matrix::CreateTranslation(m_EnemyStatus.m_Pos.x, m_EnemyStatus.m_Pos.y + m_EnemyStatus.m_HpAddPos.y, 0);
	m_HpBreakMat = Math::Matrix::CreateTranslation(m_EnemyStatus.m_Pos.x - ((int)(66 * (((m_EnemyStatus.m_MaxHp - m_EnemyStatus.m_BreakHp) / 2) / m_EnemyStatus.m_MaxHp))), m_EnemyStatus.m_Pos.y + m_EnemyStatus.m_HpAddPos.y, 0);
	m_EnemyMat = Math::Matrix::CreateTranslation(m_EnemyStatus.m_Pos.x, m_EnemyStatus.m_Pos.y, 0);




}



void C_EnemyBase::SetTex(KdTexture* enemytex,KdTexture* hpbartex, KdTexture* hpbarbraektex, KdTexture* hpbarbacktex)
{
	m_EnemyTex = enemytex;
	m_HpTex = hpbartex;
	m_HpBreakTex = hpbarbraektex;
	m_HpBackTex = hpbarbacktex;
}