#pragma once

#include"State.h"



class C_Enemy;

class C_GameScene :public C_State
{
public:

	C_GameScene();
	~C_GameScene();

	void Init()override;
	void Update()override;
	void Draw()override;

	void Release();

	void TexLoad();

	std::shared_ptr<C_Enemy> GetEnemy() { return m_Enemy; }

private:

	

	KdTexture m_PlayerTex;
	KdTexture m_PlayerBulletLineTex;
	KdTexture m_EnemyTex;
	KdTexture m_HpTex;
	KdTexture m_HpBackTex;
	KdTexture m_HpBreakTex;
	KdTexture m_AttackIconTex;
	KdTexture m_BeamIconTex;
	KdTexture m_NumberTex;
	KdTexture m_EnemyBulletLineTex;
	
	std::shared_ptr<C_Enemy> m_Enemy=nullptr;
	

	

	std::shared_ptr<KdSoundEffect> bgm;
};