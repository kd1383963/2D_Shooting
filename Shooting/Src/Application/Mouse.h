#pragma once
class C_Mouse 
{
public:

	~C_Mouse() {}

	void Init();
	void Update();
	void Draw();

	POINT GetMousePos();
	float GetRadius() { return m_Radius; }

private:
	//画面サイズ
	static const int ScrWidth = 1280;
	static const int ScrHeight = 720;

	//マウス操作
	POINT m_Mouse;

	float		m_Radius = 5;
private:

	C_Mouse() {}

public:
	static C_Mouse& GetInstance()
	{
		static C_Mouse instance;
		return instance;
	}
};

#define MOUSE C_Mouse::GetInstance()
