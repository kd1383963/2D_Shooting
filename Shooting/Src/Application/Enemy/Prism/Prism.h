#pragma once
#include"../EnemyBase.h"



class C_Prism :public C_EnemyBase
{
public:

	C_Prism() {  }
	~C_Prism() {}


	void Move()override;

	void Init(int wave)override;

	void SetAttackCmd()override;

private:




};

