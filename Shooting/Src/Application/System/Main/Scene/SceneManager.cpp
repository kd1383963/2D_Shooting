#include "SceneManager.h"
#include "TitleScene.h"
#include "GameScene.h"

void SceneManager::PreUpdate()
{
	//シーン切り替え
	if (m_CurrentSceneType != m_nextSceneType)
	{
		ChangeScene(m_nextSceneType);
		m_CurrentScene->Init();
	}
}

void SceneManager::Update()
{
	// ポリモーフィズム
	// 同じ関数名であっても、呼び出すオブジェクトによって処理内容が変わることも
	m_CurrentScene->Update();
}

void SceneManager::Draw()
{
	m_CurrentScene->Draw();
}

void SceneManager::Init()
{
	ChangeScene(m_CurrentSceneType);
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
	}
	//②フラグを更新
	m_CurrentSceneType = _sceneType;
}
