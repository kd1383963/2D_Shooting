#include"ShopScene.h"
#include"Src/Application/Game/Event/Shop.h"
#include"Src/Application/Game/Event/ShopHit.h"
#include"Src/Application/Game/Map/backGround.h"
#include"Src//Application/Game/Item/Item.h"
#include"Src/Application/Game/Item/ItemTrash.h"
#include"Src/Application/Load.h"
#include"Src/Application/Game/System/Menu.h"

C_ShopScene::C_ShopScene()
{
	LOAD.ShopSceneTexLoad();
}

C_ShopScene::~C_ShopScene()
{
	LOAD.ShopSceneTexRelease();
}

void C_ShopScene::Init()
{
	BACKGROUND.Init();
	SHOP.Init();
	ITEMTRASH.Init();
	ITEM.ItemLoad();
	MENU.Init();
}

void C_ShopScene::Update()
{
	BACKGROUND.Update();
	ITEMTRASH.Update();
	MENU.Update();
	if (SHOP.Update())return;
	
	//SHOPHIT.ShopItemHit();
	
}

void C_ShopScene::Draw()
{
	BACKGROUND.Draw(23, 1420, 799);
	SHOP.Draw();
	ITEMTRASH.Draw();
	MENU.Draw();
}