#pragma once
#include"State.h"
class C_ResultScene :public C_State
{
public:
	C_ResultScene();
	~C_ResultScene();

	void Init()override;
	void Update()override;
	void Draw()override;

private:



};
