#include "Turn.h"


void C_Turn::Init()
{
	SetNextTurn(Player);
}

void C_Turn::Update()
{
	if (NowTurn == NextTurn)return;
	NowTurn = NextTurn;
}

