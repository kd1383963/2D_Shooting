#pragma once
#include "PlayerSkill.h"

class C_PlayerBullet
{
public:

	C_PlayerBullet() { Init(); }
	~C_PlayerBullet() {}

	void Init();
	void Update();
	void Draw();

	void Shot(Math::Vector2 pos1, Math::Vector2 pos2);

	void MoreShot(Math::Vector2 vec);

	void SetTex(KdTexture* tex);

	bool GetAlive() { return m_Alive; }

	bool HIT(Math::Vector2 pos, int h);

	SkillFlg* GetPlayerSkill() { return &PlayerSkill; }
	
	void SetPlayerSkill(SkillFlg a_playerskillflg) { PlayerSkill = a_playerskillflg; }

private:

	int CharaWidth  = 18;
	int CharaHeight = 18;

	SkillFlg PlayerSkill;

	const float m_MoveSpeed = 15.0f;

	const float m_Radius = 8;

	float m_Angle;

	KdTexture* m_Tex;
	Math::Vector2 m_Pos;
	Math::Vector2 vec;
	Math::Matrix m_Mat;

	int ignoreFrames = 0;

	bool m_Alive;

	
};