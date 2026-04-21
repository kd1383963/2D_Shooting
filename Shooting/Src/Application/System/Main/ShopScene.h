#pragma once
#include"State.h"
#include"Src/Application/Game/System/Menu.h"

class C_ShopScene :public C_State
{
public:
	C_ShopScene();
	~C_ShopScene();

	void Init()override;
	void Update()override;
	void Draw()override;

private:
	C_Menu		MENU;
};