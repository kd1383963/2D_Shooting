#pragma once



class Scene
{
private:

	

public:

	// 初期設定
	void Init();

	// 解放
	void Release();

	// 更新処理
	void Update();

	// 描画処理
	void Draw2D();

	// GUI処理
	void ImGuiUpdate();

	// 画像ロード処理
	void TexLoad();


private:

	KdTexture m_PlayerTex;
	KdTexture m_BulletLineTex;
	KdTexture m_EnemyTex;

	int asdfag;

	Scene() {}

public:
	static Scene& GetInstance()
	{
		static Scene instance;
		return instance;
	}
};

#define SCENE Scene::GetInstance()
