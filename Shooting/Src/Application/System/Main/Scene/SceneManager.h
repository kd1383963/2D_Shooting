#pragma once

//前方宣言
class C_State;

class SceneManager
{
public:


	//シーン情報
	//enum=列挙型・・・複数の定数をまとめて管理するための型
	//入る値は0から順番にint型で割り当てられる
	enum SceneType
	{
		Title,
		Game
	};
	//Updateの前に実行するUpdate
	void PreUpdate();

	void Update();
	void Draw();

	// 外部から次のシーンをSetする関数
	// ※この関数ではシーンは切り替わらない
	void SetNextScene(SceneType _nextScene)
	{
		m_nextSceneType = _nextScene;
	}

	// 現在のシーンを取得する関数
	SceneType GetCurrentScene() const
	{
		return m_CurrentSceneType;
	}


private:

	// 初期化や開放は自分でする
	void Init();
	void Release();
	// シーン切り替えの関数
	void ChangeScene(SceneType _sceneType);

	// 現在のシーンを管理するポインタ変数
	std::shared_ptr<C_State> m_CurrentScene;

	// 現在のシーンを管理するフラグ変数
	SceneType m_CurrentSceneType = SceneType::Title;
	// 次のシーンを管理するフラグ変数
	SceneType m_nextSceneType = m_CurrentSceneType;

	//シングルトンパターン
	// 実体が一つしかないことを証明するためのパターン
	// なんでもかんでもシングルトンにするな！！！
private:

	// 外で変数宣言できない
	SceneManager() { Init(); }
	~SceneManager() { Release(); }
public:


	static SceneManager& Instance()
	{
		// 自分で自分を作る　
		static SceneManager instance;
		return instance;
	}

}; 
#define SCENEMANAGER SceneManager::Instance()


