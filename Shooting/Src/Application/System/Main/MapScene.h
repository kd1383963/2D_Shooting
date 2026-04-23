#pragma once
#include"State.h"

class C_MapScene :public C_State
{
public:
	C_MapScene();
	~C_MapScene();

	void Init()override;
	void Update()override;
	void Draw()override;

private:
	//ƒ}ƒbƒv

	
};