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

private:

	
	KdTexture m_PlayerTex;
	KdTexture m_BulletLineTex;
	KdTexture m_EnemyTex;

	
	C_Enemy* Enemy;
	

	

	std::shared_ptr<KdSoundEffect> bgm;
};