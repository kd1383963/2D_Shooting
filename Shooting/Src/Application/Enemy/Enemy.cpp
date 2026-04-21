#include "Enemy.h"

void C_Enemy::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_EnemyMat);
	SHADER.m_spriteShader.DrawTex(m_EnemyTex, { 0,0,64,64 }, 1.0f);

}

void C_Enemy::Update()
{
	m_EnemyMat = Math::Matrix::CreateTranslation(m_Pos.x, m_Pos.y, 0);
}

void C_Enemy::Init()
{
	m_Pos.x = rand() % 360 + 150;
	m_Pos.y = rand() % 400 - 200;
}

void C_Enemy::SetTex(KdTexture* enemytex)
{
	m_EnemyTex = enemytex;
}