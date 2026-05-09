#include "Enemy.h"
#include "Prism/Prism.h"
#include "EnemyBase.h"
#include "../System/Battle/Turn.h"

void C_Enemy::Draw()
{
	for (const auto& e : m_EnemyChara) {
		e->Draw();
	}
}


void C_Enemy::Update()
{
	for (const auto& e : m_EnemyChara) {
		e->Update();
	}
	m_EnemyChara.erase(
		std::remove_if(
			m_EnemyChara.begin(),
			m_EnemyChara.end(),
			[](const std::shared_ptr<C_EnemyBase>& e) {
				return!(e->GetAlive());  // Å© GetAlive Ç™ false ÇÃìGÇæÇØè¡Ç∑
			}
		),
		m_EnemyChara.end()
	);
	if (C_Turn::GetInstance().GetNowTurn() == C_Turn::Enemy)
	{
		for (const auto& e : m_EnemyChara) {
			if (!e->GetMoveFlg())
			{
				break;
			}
			for (const auto& e : m_EnemyChara) {
				e->SetMoveFlg(false);
			}
			C_Turn::GetInstance().SetNextTurn(C_Turn::Player);
		}
	}
}

void C_Enemy::Init()
{
	for (int i = 0; i < 3 ; i++)
	{
		m_EnemyChara.push_back(std::make_shared<C_Prism>());
		m_EnemyChara[i]->Setowner(this);
		m_EnemyChara[i]->PreInit();
		m_EnemyChara[i]->Init();
		m_EnemyChara[i]->SetTex(m_EnemyTex, m_HpTex, m_HpBreakTex, m_HpBackTex,m_AttackIconTex, m_BeamIconTex,m_NumberTex,m_BulletLineTex);
	}	
	std::sort(m_EnemyChara.begin(), m_EnemyChara.end(),
		[](const std::shared_ptr<C_EnemyBase>& a, const std::shared_ptr<C_EnemyBase>& b) {
			if (a->GetPos().y != b->GetPos().y)
				return a->GetPos().y > b->GetPos().y;  // y ç~èá
			return a->GetPos().x < b->GetPos().x;      // x è∏èá
		}
	);
}

void C_Enemy::GiftTex(KdTexture* enemytex, KdTexture* hpbartex, KdTexture* hpbarbraektex, KdTexture* hpbarbacktex
	, KdTexture* attacktex, KdTexture* beamtex, KdTexture* numbertex, KdTexture* bulletlinetex)
{
	m_EnemyTex = enemytex;
	m_HpTex = hpbartex;
	m_HpBreakTex = hpbarbraektex;
	m_HpBackTex = hpbarbacktex;
	m_AttackIconTex = attacktex;
	m_BeamIconTex = beamtex;
	m_NumberTex = numbertex;
	m_BulletLineTex = bulletlinetex;
}
