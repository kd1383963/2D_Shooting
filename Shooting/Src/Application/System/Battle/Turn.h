#pragma once

class C_Trun
{
public:
	C_Trun() {}
	~C_Trun() {}

	enum Trun
	{
		Player,
		Enemy
	};


	void ChangeTrun(Trun a_nexttrun) { NextTrun = a_nexttrun; }
	Trun GetNowTrun() { return NowTrun; }

private:

	Trun NowTrun ;
	Trun NextTrun ;


};