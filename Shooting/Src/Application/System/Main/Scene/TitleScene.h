#pragma once
#include"State.h"
class C_TitleScene :public C_State
{
public:
	C_TitleScene();
	~C_TitleScene();

	void Init()override;
	void Update()override;
	void Draw()override;

private:
	float m_Alufa = 0.0f;
	float m_AlufaAdd = 0.02f;

	Math::Vector2 m_TitlePos = { 0,170 };
	Math::Matrix m_TitleMat;
	KdTexture m_TitleTex;

	Math::Vector2 m_StartCmdPos = { 0,-300 };
	Math::Matrix m_StartCmdMat;
	KdTexture m_StartCmdTex;
};
