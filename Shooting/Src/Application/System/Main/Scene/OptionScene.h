#pragma once
#include"State.h"


class C_OptionScene :public C_State
{
public:

	C_OptionScene();
	~C_OptionScene();

	void Init()override;
	void Update()override;
	void Draw()override;

	

private:

	//メニューアイコン
	const float MenuRadius = 64.0f;

	
	KdTexture OptionTex;
	KdTexture BackTex;
	KdTexture IconBackTex;

};