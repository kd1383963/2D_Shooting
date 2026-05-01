#pragma once
//#include"PlayerBullet.h"

class C_GameScene;

class C_PlayerBullet;

class C_Player
{
public:

	
	~C_Player();

	void Init();
	void Update();
	void Draw();
	void SetTex(KdTexture* playertex,KdTexture* bulletlinetex);

	void SetShotFlg(bool a_flg) { m_ShotFlg = a_flg; }

	C_PlayerBullet* GetBullet() { return *m_Bullet; }

	void Setowner(C_GameScene* owner) { m_owner = owner; }

	void HitBulletEnemy();

private:

	C_GameScene* m_owner;

	const float m_MoveSpeed = 10.0f;

	const float m_Radius = 32;

	KdTexture* m_PlayerTex;
	KdTexture* m_BulletLineTex;
	Math::Vector2 m_Pos;
	Math::Matrix m_PlayerMat;
	Math::Matrix m_LineMat;

	bool m_ShotFlg;

	float m_LineBlinking;
	float m_LineBlinkingAdd;

	static const int m_PlayerBulletNum = 10;

	KdTexture m_BulletTex;
	C_PlayerBullet* m_Bullet[m_PlayerBulletNum];

	C_Player();

public:
	static C_Player& GetInstance()
	{
		static C_Player instance;
		return instance;
	}
};

#define PLAYER C_Player::GetInstance()

