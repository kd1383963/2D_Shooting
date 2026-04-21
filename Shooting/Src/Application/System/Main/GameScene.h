#pragma once

#include"State.h"

class C_GameScene :public C_State
{
public:

	C_GameScene();
	~C_GameScene();

	void Init()override;
	void Update()override;
	void Draw()override;

	

private:

	


	

	

	

	std::shared_ptr<KdSoundEffect> bgm;
};