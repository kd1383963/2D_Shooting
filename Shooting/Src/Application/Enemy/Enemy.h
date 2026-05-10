#pragma once

class C_GameScene;

class C_EnemyBase;

class C_Enemy 
{
public:

	C_Enemy(){ }
	~C_Enemy(){}

	void Init(int enemynum);
	void Update();
	void Draw();

	void GiftTex(KdTexture* enemyidletex, KdTexture* enemyatktex, KdTexture* enemyhurttex, KdTexture* enemydeadtex,
		KdTexture* hpbartex, KdTexture* hpbarbraektex, KdTexture* hpbarbacktex
		, KdTexture* attacktex, KdTexture* beamtex, KdTexture* numbertex, KdTexture* bulletlinetex
		, KdTexture* bullettex);
	std::vector<std::shared_ptr<C_EnemyBase>> GetEnemyChara() { return m_EnemyChara; }
	
	void TotalEnemyMainer() { TotalEnemy--; }

private:

	int TotalEnemy = 0;
	int TotalEnemyMove = 0;

	std::vector<std::shared_ptr<C_EnemyBase>> m_EnemyChara = {};

	KdTexture* m_EnemyIdleTex;
	KdTexture* m_EnemyAtkTex;
	KdTexture* m_EnemyHurtTex;
	KdTexture* m_EnemyDeadTex;

	KdTexture* m_HpTex;
	KdTexture* m_HpBackTex;
	KdTexture* m_HpBreakTex;
	KdTexture* m_AttackIconTex;
	KdTexture* m_BeamIconTex;
	KdTexture* m_NumberTex;
	KdTexture* m_BulletTex;
	KdTexture* m_BulletLineTex;
};

