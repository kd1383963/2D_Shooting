#pragma once

class C_Turn
{
public:
	
	enum Turn
	{
		Null,
		Player,
		Enemy
	};

	void Init();
	void Update();

	void SetNextTurn(Turn a_nextturn){ NextTurn = a_nextturn; }
	
	Turn GetNowTurn() { return NowTurn; }

private:

	void ChangeTurn() { NowTurn = NextTurn; }

	Turn NowTurn	= Null;
	Turn NextTurn	= Null;

	C_Turn() {}
	~C_Turn() {}


public:
	static C_Turn& GetInstance()
	{
		static C_Turn instance;
		return instance;
	}
};



