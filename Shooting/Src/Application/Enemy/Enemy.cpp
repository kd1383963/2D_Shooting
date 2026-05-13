#include "Enemy.h"
#include "../Player/Player.h"
#include "Prism/Prism.h"
#include "EnemyBase.h"
#include "../System/Battle/Turn.h"
#include"../System/Utility/KeyManager.h"

void C_Enemy::Draw()
{
	for (const auto& e : m_EnemyChara) {
		e->Draw();
	}
}


void C_Enemy::Update()
{
	TotalEnemyMove = 0;
	TotalEnemy = m_EnemyChara.size();
	for (const auto& e : m_EnemyChara) {
		e->Update();
	}
	m_EnemyChara.erase(
		std::remove_if(
			m_EnemyChara.begin(),
			m_EnemyChara.end(),
			[](const std::shared_ptr<C_EnemyBase>& e) {
				return(e->GetDead()); 
			}
		),
		m_EnemyChara.end()
	);
	if (C_Turn::GetInstance().GetNowTurn() == C_Turn::Enemy)
	{
		for (const auto& e : m_EnemyChara) {
			if (e->GetMoveFlg())
			{
				TotalEnemyMove++;
			}
			
			
		}
	}
	if (C_KeyManager::GetInstance().GetLKey())
	{
		for (const auto& e : m_EnemyChara) {
			e->SetEAnimStatus(EDead);
		}
	}
	if (TotalEnemyMove == TotalEnemy)
	{
		for (const auto& e : m_EnemyChara) {
			e->SetAttackFlg();
			e->SetAttackCmd();
		}
		C_Turn::GetInstance().SetNextTurn(C_Turn::Player);
		C_Player::GetInstance().SetCanMove(true);
	}
	if(m_EnemyChara.size()==0)
	{
		C_Turn::GetInstance().SetNextTurn(C_Turn::UpGrade);
	}

}

void C_Enemy::Init(int enemynum,int wave)
{
	for (int i = 0; i < enemynum; i++)
	{
		m_EnemyChara.push_back(std::make_shared<C_Prism>());
		m_EnemyChara[i]->Setowner(this);
		m_EnemyChara[i]->PreInit();
		m_EnemyChara[i]->Init(wave,i);
		m_EnemyChara[i]->SetTex(m_EnemyIdleTex,m_EnemyAtkTex, m_EnemyHurtTex, m_EnemyDeadTex, m_HpTex, m_HpBreakTex,
			m_HpBackTex, m_AttackIconTex,
			m_BeamIconTex, m_NumberTex, m_BulletLineTex, m_BulletTex,m_AtkExpTex,m_HpBerTex);
		TotalEnemy++;
	}	
	std::sort(m_EnemyChara.begin(), m_EnemyChara.end(),
		[](const std::shared_ptr<C_EnemyBase>& a, const std::shared_ptr<C_EnemyBase>& b) {
			if (a->GetPos().y != b->GetPos().y)
				return a->GetPos().y > b->GetPos().y;  // y ç~èá
			return a->GetPos().x < b->GetPos().x;      // x è∏èá
		}
	);
}

void C_Enemy::GiftTex(KdTexture* enemyidletex, KdTexture* enemyatktex, KdTexture* enemyhurttex, KdTexture* enemydeadtex,
	KdTexture* hpbartex, KdTexture* hpbarbraektex, KdTexture* hpbarbacktex
	, KdTexture* attacktex, KdTexture* beamtex, KdTexture* numbertex, KdTexture* bulletlinetex
	, KdTexture* bullettex, KdTexture* atkexptex, KdTexture* hpbertex)
{
	m_EnemyIdleTex = enemyidletex;
	m_EnemyAtkTex = enemyatktex;
	m_EnemyHurtTex = enemyhurttex;
	m_EnemyDeadTex = enemydeadtex;
	m_HpTex = hpbartex;
	m_HpBreakTex = hpbarbraektex;
	m_HpBackTex = hpbarbacktex;
	m_AttackIconTex = attacktex;
	m_BeamIconTex = beamtex;
	m_NumberTex = numbertex;
	m_BulletTex = bullettex;
	m_BulletLineTex = bulletlinetex;
	m_AtkExpTex = atkexptex;
	m_HpBerTex = hpbertex;
}
