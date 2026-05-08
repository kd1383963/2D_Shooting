#include "Enemy.h"
#include "Zombie/NormalZombie.h"
#include "EnemyBase.h"

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
				return!(e->GetAlive());  // © GetAlive ‚ª false ‚Ì“G‚¾‚¯Á‚·
			}
		),
		m_EnemyChara.end()
	);
}

void C_Enemy::Init()
{
	for (int i = 0; i < 20; i++)
	{
		m_EnemyChara.push_back(std::make_shared<C_Normalzombie>());
		m_EnemyChara[i]->Setowner(this);
		m_EnemyChara[i]->Init();
		m_EnemyChara[i]->SetTex(m_EnemyTex, m_HpTex, m_HpBreakTex, m_HpBackTex);
	}	
	std::sort(m_EnemyChara.begin(), m_EnemyChara.end(),
		[](const std::shared_ptr<C_EnemyBase>& a, const std::shared_ptr<C_EnemyBase>& b) {
			if (a->GetPos().y != b->GetPos().y)
				return a->GetPos().y > b->GetPos().y;  // y ~‡
			return a->GetPos().x < b->GetPos().x;      // x ¸‡
		}
	);
}

void C_Enemy::GiftTex(KdTexture* enemytex, KdTexture* hpbartex, KdTexture* hpbarbraektex, KdTexture* hpbarbacktex)
{
	m_EnemyTex = enemytex;
	m_HpTex = hpbartex;
	m_HpBreakTex = hpbarbraektex;
	m_HpBackTex = hpbarbacktex;
}
