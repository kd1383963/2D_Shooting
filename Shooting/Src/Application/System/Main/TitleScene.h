#pragma once
#include"State.h"
class C_TitleScene :public C_State
{
public:
	C_TitleScene();
	~C_TitleScene();

	void Init()override;
	void Update()override;
	void Draw()override;

private:

	std::shared_ptr<KdSoundEffect> bgm;

};
