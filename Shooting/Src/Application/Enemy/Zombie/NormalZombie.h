#pragma once
#include"../EnemyBase.h"



class C_Normalzombie :public C_EnemyBase
{
public:

	C_Normalzombie() {  }
	~C_Normalzombie() {}


	void Move()override;

	void Init()override;

private:




};

