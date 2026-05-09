#pragma once

class C_GameScene;

class C_EnemyBase;

class C_Enemy 
{
public:

	C_Enemy(){ }
	~C_Enemy(){}

	void Init();
	void Update();
	void Draw();

	void GiftTex(KdTexture* enemytex, KdTexture* hpbartex, KdTexture* hpbarbraektex, KdTexture* hpbarbacktex
		, KdTexture* attacktex, KdTexture* beamtex, KdTexture* numbertex, KdTexture* bulletlinetex);
	std::vector<std::shared_ptr<C_EnemyBase>> GetEnemyChara() { return m_EnemyChara; }
	
	

private:

	

	std::vector<std::shared_ptr<C_EnemyBase>> m_EnemyChara = {};

	KdTexture* m_EnemyTex;

	KdTexture* m_HpTex;
	KdTexture* m_HpBackTex;
	KdTexture* m_HpBreakTex;
	KdTexture* m_AttackIconTex;
	KdTexture* m_BeamIconTex;
	KdTexture* m_NumberTex;
	KdTexture* m_BulletLineTex;
};

