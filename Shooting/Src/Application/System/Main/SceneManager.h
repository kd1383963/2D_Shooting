#pragma once
#include"GameScene.h"
#include"OptionScene.h"
#include"MapScene.h"
#include"TitleScene.h"
#include"ShopScene.h"
#include"../Utility/KeyManager.h"

enum FadeType
{
	Fade_no,
	Fade_out,
	Fade_in
};

class C_SceneManager
{
public:

	~C_SceneManager();

	void ChangeState(C_State* newState);

	void OptionState(C_State* newState, bool Flg);

	void OptionClose();

	void ChangeFade(C_State* newState);
	void UpdateFade();

	void Init();

	void Update();

	void Draw();

	bool GetTitleFlg() { return TitleFlg; }

	//bool GetOption() { return OptionFlg; }

	void SetPlayerNo(int PNo) { PlayerNo = PNo; }
	int  GetPlayerNo() { return PlayerNo; }

	void SetNewDataFlg(bool a_flg) { NewDataFlg = a_flg; }
	bool GetNewDataFlg() { return NewDataFlg; }


	void SetLoadDataFlg(bool a_flg) { LoadDataFlg = a_flg; }
	bool GetLoadDataFlg() { return LoadDataFlg; }


	void DrawEndBegin()
	{
		SHADER.m_spriteShader.End();
		SHADER.m_spriteShader.Begin();
	}

private:

	C_SceneManager()
	{
		BrackTex.Load("Texture/UI/System/Fade.png");
		
	}

	KdTexture BrackTex;
	Math::Matrix m_mat;

	C_State* currentState = nullptr;
	C_State* optionState = nullptr;

	C_State* NextState = nullptr;
	//C_Audio m_audio;

	FadeType NowFade = Fade_no;

	bool OptionFlg = false;

	int PlayerNo;

	bool NewDataFlg;
	bool LoadDataFlg;

	bool TitleFlg = false;

	float FadeAlpha = 0.0f;

public:

	static C_SceneManager& GetInstans()
	{
		static C_SceneManager instans;
		return instans;
	}

};

#define SCENEMANAGER C_SceneManager::GetInstans()