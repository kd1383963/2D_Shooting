#include "MapScene.h"
#include "../../../Mouse.h"
#include "../../../Game/Map/Map.h"
#include "../../../Game/Map/MapHit.h"
#include"Src/Application/Game/Map/backGround.h"
#include"Src/Application/Game/System/Menu.h"
#include"Src/Application/Load.h"

C_MapScene::C_MapScene()
{
	LOAD.MapSceneTexLoad();
}

C_MapScene::~C_MapScene()
{
	LOAD.MapSceneTexRelease();
}

void C_MapScene::Init()
{
	BACKGROUND.Init();
	MOUSE.Init();
	MAP.Init();
	MENU.Init();
}

void C_MapScene::Update()
{
	BACKGROUND.Update();
	MOUSE.Update();
	MAP.Update();
	MAPHIT.MouseHit();
	MENU.Update();
}

void C_MapScene::Draw()
{
	BACKGROUND.Draw(23, 1280, 720);
	MOUSE.Draw();
	MAP.Draw();
	MENU.Draw();

}
