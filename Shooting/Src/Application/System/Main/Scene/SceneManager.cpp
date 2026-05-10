#include "SceneManager.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "ResultScene.h"
#include "../../../Back/Back.h"

void SceneManager::PreUpdate()
{
	//シーン切り替え
	if (NowFade != FadeType::Fade_no)
	{
		UpdateFade();
	}
}

void SceneManager::Update()
{
	C_Back::GetInstance().Update();
	// ポリモーフィズム
	// 同じ関数名であっても、呼び出すオブジェクトによって処理内容が変わることも
	m_CurrentScene->Update();
	m_mat = Math::Matrix::CreateTranslation(0, 0, 0);
}

void SceneManager::UpdateFade()
{
	if (NowFade == Fade_out)
	{
		FadeAlpha += 0.05f;

		if (FadeAlpha >= 1.0f)
		{

			FadeAlpha += 1.0f;
			ChangeScene(m_nextSceneType);

			NowFade = FadeType::Fade_in;
		}

	}
	else if (NowFade == Fade_in)
	{
		FadeAlpha -= 0.05f;

		if (FadeAlpha <= 0.0f)
		{
			FadeAlpha = 0.0f;
			NowFade = FadeType::Fade_no;
		}
	}
}


void SceneManager::Draw()
{
	C_Back::GetInstance().Draw();
	m_CurrentScene->Draw();

	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex(&BrackTex, Math::Rectangle{ 0,0,1280,720 }, FadeAlpha);

}

void SceneManager::Init()
{
	C_Back::GetInstance().Init();
	ChangeScene(m_CurrentSceneType);
	BrackTex.Load("Texture/UI/Fade.png");
	
}

void SceneManager::Release()
{

}

void SceneManager::ChangeScene(SceneType _sceneType)
{
	//①次のシーンを作成し,②フラグを更新する
	switch (_sceneType)
	{
	case SceneType::Title:
		// アップキャスト
		m_CurrentScene = std::make_shared<C_TitleScene>();
		break;
	case SceneType::Game:
		// アップキャスト
		m_CurrentScene = std::make_shared<C_GameScene>();
		break;
	case SceneType::Result:
		m_CurrentScene = std::make_shared<C_ResultScene>();
		break;
	}
	//②フラグを更新
	m_CurrentSceneType = _sceneType;

	m_CurrentScene->Init();
}
