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

	void GiftTex(KdTexture* enemytex, KdTexture* hpbartex, KdTexture* hpbarbraektex, KdTexture* hpbarbacktex);

	std::vector<std::shared_ptr<C_EnemyBase>> GetEnemyChara() { return m_EnemyChara; }
	
	

private:

	

	std::vector<std::shared_ptr<C_EnemyBase>> m_EnemyChara = {};

	KdTexture* m_EnemyTex;

	KdTexture* m_HpTex;
	KdTexture* m_HpBackTex;
	KdTexture* m_HpBreakTex;
};

