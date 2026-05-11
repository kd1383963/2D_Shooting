#pragma once

enum BackStatus
{
	Evening,
	Night,
	LateNight
};
class C_Back
{


public:

	
	~C_Back() {}

	void Init();
	void Update();
	void Draw();

	void SetBackStatus() {
		if (m_BackStatus == Evening)
		{
			m_BackStatus = Night;
		}
		else
		{
			m_BackStatus = LateNight;
		}
	}

private:

	KdTexture m_Back1Tex;
	KdTexture m_Back2Tex;
	KdTexture m_Back3Tex;

	Math::Matrix m_BackMat;

	BackStatus m_BackStatus;

	C_Back() {}

public:
	static C_Back& GetInstance()
	{
		static C_Back instance;
		return instance;
	}
};