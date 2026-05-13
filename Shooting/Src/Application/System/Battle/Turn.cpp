#include "Turn.h"
#include "../../Enemy/Enemy.h"

void C_Turn::Init()
{
	SetNextTurn(EnemyInit);
}

void C_Turn::Update()
{
	if (NowTurn == NextTurn)return;
	NowTurn = NextTurn;
}

